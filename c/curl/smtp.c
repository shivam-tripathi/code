#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#define SENDER "shivam.flash@gmail.com"
#define RECEIVER "shivam.flash@gmail.com"
#define CC "shivam.flash@gmail.com"

struct status{
    int lines;
};

static size_t payload()
