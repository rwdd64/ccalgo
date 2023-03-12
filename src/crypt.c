#include "headers/crypt.h"

char shift(char c, enum operation op) {
    for (int i=0; i<3; i++) {
        if (op==ENCRYPT) {
            if (c=='Z') {
                c='A';
                continue;
            }
            else if (c=='z') {
                c='a';
                continue;
            }
            c++;
        }
        else if (op==DECRYPT) {
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
    }
    return c;
}

char result[129];
char* crypt(const char text[], enum operation op) {
    if (strlen(text) > 128) {
        return "__ERR__";
    }
    for (int i=0; i < strlen(text); i++){
        const char cur_char = text[i];
    
        if (is_letter(cur_char)){
            result[i] = shift(cur_char, op);
        }
        else {
            result[i] = cur_char;
        }

        result[i+1]='\0';
    }
        return result;
}
