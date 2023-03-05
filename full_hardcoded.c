#include "tools.h"

enum operation {
    ENCRYPT, DECRYPT
};

char shift(char c, enum operation op) {
    if (op==ENCRYPT) {
        switch (c) {
            case 'X':
                c='A';
                break;
            case 'Y':
                c='B';
                break;
            case 'Z':
                c='C';
                break;

            case 'x':
                c='a';
                break;
            case 'y':
                c='b';
                break;
            case 'z':
                c='c';
                break;
            default:
                c+=3;
                break;
        }
    }
    else if (op==DECRYPT) {
        switch (c) {
            case 'A':
                c='X';
                break;
            case 'B':
                c='Y';
                break;
            case 'C':
                c='Z';
                break;

            case 'a':
                c='x';
                break;
            case 'b':
                c='y';
                break;
            case 'c':
                c='z';
                break;
            default:
                c-=3;
                break;
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
        if (strcmp(crypt(str, op), "__ERR__") == 0) {
            printf("ERROR > The maximum number of characters in the string is 128.\n");
        }
        else {
            printf("%s\n", crypt(str, op));
        }
    }
}
