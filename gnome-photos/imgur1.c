#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <libsoup/soup.h>
#include <oauth.h>
#include <json-glib/json-glib.h>

static void
add_string_member (JsonBuilder *builder, const gchar *name, const gchar *value)
{
    json_builder_set_member_name (builder, name);
    json_builder_add_string_value (builder, value);
}


static void
set_request (SoupMessage *message, JsonBuilder *builder)
{
    JsonGenerator *generator = json_generator_new ();
    json_generator_set_root (generator, json_builder_get_root (builder));
    gsize length;
    gchar *data = json_generator_to_data (generator, &length);
    soup_message_set_request (message, "application/json", SOUP_MEMORY_TAKE, data, length);
    g_object_unref (generator);
}



void
add_image (const gchar *base64) {
	const gchar *token_name = "upload-to-imgur";
	const gchar *id;
	int success;

    SoupSession *session = soup_session_new_with_options (SOUP_SESSION_USER_AGENT, token_name, NULL);

	// Dummy app client_id and client_secret
    gchar *client_id = "Client-ID fd00ff352bab7ea";
    // gchar *client_secret = "46532b9747f17325d8815dcf691a0d37c863dfea";

    SoupMessage *message = soup_message_new (SOUP_METHOD_POST, "https://api.imgur.com/3/upload");

    soup_message_headers_append (message->request_headers, "Authorization", client_id);

    JsonBuilder *builder = json_builder_new ();
    json_builder_begin_object (builder);
    add_string_member (builder, "image", base64);
    json_builder_end_object (builder);
    set_request (message, builder);
    g_object_unref (builder);

    guint status_code = soup_session_send_message (session, message);
    g_assert (status_code == SOUP_STATUS_OK)

    /* Parse response */
    JsonParser *parser = json_parser_new ();
    gboolean result = json_parser_load_from_data (parser, message->response_body->data, -1, NULL);
    g_assert (result);
    JsonNode *root = json_parser_get_root (parser);
    g_assert (JSON_NODE_HOLDS_OBJECT (root));
    JsonObject *object = json_node_get_object (root);
    JsonObject *data = json_object_get_object_member (object, "data");

    id = json_object_get_string_member (data, "id");

    printf("http://imgur.com/%s\n", id, status_code);

    g_object_unref (message);
    g_object_unref (parser);
}


int
main(int argc, char const *argv[])
{
	FILE *image = fopen ("image.jpg", "rb");

	struct stat info;
	stat ("image.jpg", &info);
	int size = info.st_size;

	char *buffer = malloc (size);

	fread (buffer, 1, size, image);

	/*
	FILE *image2 = fopen ("image2.jpg", "w+b");
	fwrite (buffer, 1, size, image2);

	fclose (image2);
	*/

	/*
	Will use
	g_base64_encode_step ()
	once code is up and running
	*/

	gchar *encoded_buffer = malloc (size * 2);
	encoded_buffer = g_base64_encode ( buffer,
                 size);

	add_image (encoded_buffer);

	fclose (image);
	return 0;
}