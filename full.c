#include "tools.h"

enum operation {
    ENCRYPT, DECRYPT
};

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

char result[128];
char* crypt(const char text[], enum operation op) {
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

void handle_flags(const char* flags, enum operation* op) {
    if (strcmp(flags, "-e") == 0) {
        *op=ENCRYPT;
    }
    else if (strcmp(flags, "-d") == 0) {
        *op=DECRYPT;
    }
}


int main(int argc, char *argv[]) {
    if (argc<3) {
        printf("When calling the command, please input a action to perform (-e => encrypt | -d => decrypt) followed by the text you want to perform the action on.\n");
    }
    else {
        const char* flags=argv[1];
        const char* str=argv[2];
        enum operation op; 

        handle_flags(flags, &op);

        printf("%s\n", crypt(str, op));
    }
}
