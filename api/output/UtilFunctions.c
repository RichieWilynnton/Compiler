#include "UtilFunctions.h"
#include <string.h>
#include <stdlib.h>

char* concatString(const char* s1, const char* s2) {
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);

    char* result = (char*)malloc(len1 + len2 + 1); 
    if (result == NULL) {
        return NULL;
    }

    strcpy(result, s1);
    strcat(result, s2);

    return result;
}
