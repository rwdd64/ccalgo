#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#include "tools.h"

char sub_three(char c) {
    for (int i=0; i<3; i++) {
        if (c=='A') {
            c='Z';
            continue;
        }
        else if (c=='a') {
            c='z';
            continue;
        }
        c--;
    }
    return c;
}

char result[128];
char* decrypt(const char text[]) {
    for (int i=0; i < strlen(text); i++){
        const char cur_char = text[i];
    
        if (is_letter(cur_char)){
            result[i] = sub_three(cur_char);
        }
        else {
            result[i] = cur_char;
        }

        result[i+1]='\0';
    }
        return result;
}

int main(int argc, char *argv[]) {
    if (argc<2) {
        printf("Please input a text to decrypt when calling the command.\n");
    }
    else {
        printf("%s\n", decrypt(argv[1]));
    }
}
