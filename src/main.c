#include "headers/tools.h"
#include "headers/flags.h"
#include "headers/crypt.h"

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
