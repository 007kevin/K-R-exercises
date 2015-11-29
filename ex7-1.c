#include<stdio.h>
#include<ctype.h>
#include<string.h>


int main(int argc, char *argv[]){
    if (strcmp(*argv++, "./lower") == 0){
        while(**argv != '\0')
            putchar(tolower(*(*argv)++));
    }        
    else{
        while(**argv != '\0')
            putchar(toupper(*(*argv)++));
    }
    putchar('\n');
    return 0;
}
