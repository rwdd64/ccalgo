#ifndef __TOOLS_H
#define __TOOLS_H

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

enum operation {
    ENCRYPT, DECRYPT
};

bool is_letter(const char c);

#endif
