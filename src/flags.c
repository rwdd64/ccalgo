#include "headers/flags.h"

void handle_flags(const char* flags, enum operation* op) {
    if (strcmp(flags, "-e") == 0) {
        *op=ENCRYPT;
    }
    else if (strcmp(flags, "-d") == 0) {
        *op=DECRYPT;
    }
}
