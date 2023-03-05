#ifndef __TOOLS_H
#define __TOOLS_H

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool is_letter(const char c) { return (c>='A' && c<='Z') || (c>='a' && c<='z'); }

#endif
