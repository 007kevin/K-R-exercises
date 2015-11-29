#include<stdio.h>

int main(int argc, char *argv[]){
        char c = *(*++argv);
        
        char k = *++*argv;

        //Note: Array names are just pointer values. Since
        //*argv[] is an array of pointers (or  pointer to pointers)
        //which happen to point to characters,
        //
        //(*++argv)[0]   argv is a pointer. *argv points to
        //the pointer it points to. Since *argv is also a pointer
        //array, *argv[0] points to the first character.
        //
        //*(*++argv)     argv is a pointer. *argv is a pointer 
        //pointed by argv. *argv is also a character array. Since
        //arrays are the pointer value to the firect element it 
        //points to , *(*argv) points to the first character.
        //
        //Pointer (argv) to a pointer (*argv) to the value of the
        //pointer *(*argv).

        putchar(c);
        putchar('\n');
        putchar(k);
        putchar('\n');
}
