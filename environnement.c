#include "shell.h"

/**
 * 
*/

void print_env(void){
    
    int i;

    for (i = 0; environ[i] != NULL; i++){

        printf("%s\n", environ[i]);
    }
}