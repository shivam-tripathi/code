#include <glib-object.h>
#include <stdio.h>

#define _template(name, type) \
GValue *name; \
name = g_new0(GValue, 1);\
g_value_init(name, type);


char checker(GValue *gvalue){
    if(G_VALUE_HOLDS_INT(gvalue))
        g_print("%d\n",g_value_get_int(gvalue));
    else
        g_print("%s\n",g_value_dup_string(gvalue));
}

int main(){
	_template(gvalueint, G_TYPE_INT)
	_template(gvaluestring, G_TYPE_STRING)
	g_value_set_static_string(gvaluestring, "hello");
    g_value_set_int(gvalueint, 45);
    checker(gvalueint);
    checker(gvaluestring);
}
