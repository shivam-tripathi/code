#include <gtk/gtk.h>
#include <string.h>

typedef struct _Media
{
    GObject parent_instance;

    guint inv_nr;
    GString *location;
    GString *title;
    gboolean orig_package;
} Media;


typedef struct _MediaClass
{
    GObjectClass parent_class;
    // Signals
    void (*unpacked)(Media *media);
    void (*throw_out)(Media *media, gboolean permanent);
} MediaClass;

#define TYPE_MEDIA (media_get_type())

#define MEDIA(object) \
    (G_TYPE_CHECK_INSTANCE_CAST((object), TYPE_MEDIA, Media))

#define MEDIA_CLASS(klass) \
    (G_TYPE_CHECK_CLASS_CAST((klass), TYPE_MEDIA, MediaClass))

#define IS_MEDIA(object) \
    (G_TYPE_CHECK_INSTANCE_TYPE((object), TYPE_MEDIA))

#define IS_MEDIA_CLASS(klass) \
    (G_TYPE_CHECK_CLASS_TYPE((klass), TYPE_MEDIA))

#define MEDIA_GET_CLASS(object) \
    (G_TYPE_INSTANCE_GET_CLASS((object), TYPE_MEDIA, MediaClass))

static void media_class_init(MediaClass *klass);

GType media_get_type()
{
    static GType media_type = 0;
    if(!media_type)
    {
        static const GTypeInfo media_info = {
            sizeof(MediaClass),
            NULL,
            NULL,
            (GClassInitFunc)media_class_init,
            NULL,
            NULL,
            sizeof(Media),
            16,
            NULL,
            NULL
        };
        media_type = g_type_register_static(
            G_TYPE_OBJECT,
            "Media",
            &media_info,
            0);
    }
    return media_type;
}

enum {
    PROP_MEDIA_0,
    PROP_INV_NR,
    PROP_ORIG_PACKAGE
};

static void media_set_property(GObject *object,
    guint prop_id,
    const GValue *value,
    GParamSpec *pspec);
static void media_get_property(GObject *object,
    guint prop_id,
    GValue *value,
    GParamSpec *pspec);

enum {
    UNPACKED,
    THROW_OUT,
    LAST_SIGNAL 
};

static guint media_signal[LAST_SIGNAL] = {0,0};

static void media_unpacked(Media *media);

static void media_throw_out(Media *media, gboolean permanent);

static void media_class_init(MediaClass *klass)
{
    // GParamSpec structure for instance properties
    GParamSpec *inv_nr_param;
    GParamSpec *orig_package_param;
    GObjectClass *g_object_class;

    // Override class' signals
    klass->unpacked = media_unpacked;
    klass->throw_out = media_throw_out;

    // Handle to create Base class Object
    g_object_class = G_OBJECT_CLASS(klass);

    // Initialize GParamSpec structures for properties
    inv_nr_param = g_param_spec_uint("inventory-id", /* identifier */
        "inventory number", /* nickname */
        "number on inventory label", /* description */
        0, /* minimum */
        UINT_MAX, /* maximum */
        0, /* default */
        G_PARAM_READWRITE); /* flags */
    orig_package_param = g_param_spec_boolean("orig-package",
        "original package?",
        "is item in its original package?",
        FALSE,
        G_PARAM_READWRITE);

    // Override set_property and get_property functions of base class
    g_object_class->set_property = media_set_property;
    g_object_class->get_property = media_get_property;

    // Install properties 
    g_object_class_install_property(g_object_class,
        PROP_INV_NR,
        inv_nr_param);
    g_object_class_install_property(g_object_class,
        PROP_ORIG_PACKAGE,
        orig_package_param);

    // Install signals
    media_signal[UNPACKED] = g_signal_new("unpacked", 
        TYPE_MEDIA,
        G_SIGNAL_RUN_LAST|G_SIGNAL_DETAILED,
        G_STRUCT_OFFSET(MediaClass, unpacked),
        NULL, NULL, 
        g_cclosure_marshal_VOID__VOID,
        G_TYPE_NONE,
        0);

    media_signal[THROW_OUT] = g_signal_new("thow_out",
        TYPE_MEDIA, 
        G_SIGNAL_DETAILED|G_SIGNAL_RUN_LAST,
        G_STRUCT_OFFSET(MediaClass, thow_out),
        NULL, NULL,
        g_cclosure_marshal_VOID__BOOLEAN,
        G_TYPE_NONE,
        1,
        G_TYPE_BOOLEAN);

}

static void media_set_property(GObject *object, guint prop_id, 
    const GValue *value, GParamSpec *pspec)
{
    Media *media;
    guint new_inv_nr;
    gboolean new_orig_package;
    media = MEDIA(object);
    switch(prop_id){
        case PROP_INV_NR:
            new_inv_nr = g_value_get_uint(value);
            if(media->inv_nr != new_inv_nr){
                media->inv_nr = new_inv_nr;
            }
            break;
        case PROP_ORIG_PACKAGE:        
            new_orig_package = g_value_get_boolean(value);
            if(media->orig_package != new_orig_package){
                media->orig_package = new_orig_package;
            }
            break;
        default: 
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, prop_id, pspec);
            break;
    }

}

static void media_get_property(GObject *object, guint prop_id, GValue *value,
    GParamSpec *pspec)
{
    Media *media;
    media = MEDIA(object);
    switch(prop_id)
    {
        case PROP_INV_NR:
            g_value_set_uint(value, media->inv_nr);
            break;
        case PROP_ORIG_PACKAGE:
            g_value_set_boolean(value, media->orig_package);
            break;
        default:
            G_OBJECT_WARN_INVALID_PROPERTY_ID(object, prop_id, pspec);
            break;
    }
}

static void media_unpacked(Media *media)
{
    if(media->orig_package)
    {
        g_object_set(media, "orig-package", FALSE, NULL);
        g_print("Media unpacked\n");
    } else {
        g_print("Media already unpacked\n");
    }
}

static void media_throw_out(Media *media, gboolean permanent)
{
    if(permanent)
    {
        g_print("Thrashing media\n");
    } else {
        g_print("Media not in dumpster quite yet\n");
    }
}

void print_media_inv_nr(Media *object)
{
    Media *media;
    g_return_if_fail(IS_MEDIA(object));
    media = MEDIA(object);
    g_print("Inventory Number : %d", media->inv_nr);

}

int main()
{
    Media *media;
    guint inv_nr;
    gboolean orig_package;
    g_print("%d %d\n", inv_nr, orig_package);
    // Just the object type 
    media = g_object_new(TYPE_MEDIA, NULL);
    // Object with default arguments 
    media = g_object_new(TYPE_MEDIA, "inventory-id" , 42, "orig-package", TRUE, NULL);    
    g_object_get(media, "inventory-id", &inv_nr, "orig-package", &orig_package, NULL);
    g_print("%d %d\n", inv_nr, orig_package);
    g_print("%d %d\n", inv_nr, orig_package);    
    g_object_set(media, "inventory-id", 83287, "orig-package", TRUE, NULL);
    g_print("%d***%d\n", media->inv_nr, media->orig_package);
}




