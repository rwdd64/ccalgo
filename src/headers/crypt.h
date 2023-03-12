#ifndef __CRYPT_H
#define __CRYPT_H

#include "tools.h"

char shift(char c, enum operation op);
char* crypt(const char text[], enum operation op);

#endif
