/* K&R Exercise 5-13 P.98
 *
 * Write the program tail, which prints the last n lines of its input.
 * By default, n is set to 10, let us say, but it can be changed by an 
 * optional argument so that 
 *
 *      tail -n
 *
 * prints the last n lines. The program should behave rationally no matter
 * how unreasonable the input or the value of n. Write the program so it 
 * makes the best use of available storage; lines should be stored as in
 * the sorting program of section 5.6, not in a two dimensional array of
 * fixed size.
 *
 * Note: Make use of a circular array to update pointers with every new line.
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define LIMIT 1000

int get_line(char s[], int lim);

void writeline(char *[], int i, int n);

int main(int argc, char *argv[]){
        int len, i, n = 10;
        char *p, c, buffer[LIMIT];

        
        while(--argc > 0 && (*++argv)[0] == '-'){ //Can be also written as *(*++argv)
            n = 0;
            while(c = *++argv[0])                 //Can be also written as *++*argv
                if(isdigit(c))
                   n = n * 10 + (c - '0');
                else{
                   printf("find: illegal option %c\n", c);
                   argc = -1;
                   break;
                }
        }
        char *tail[n];
        if (n == 0){
            printf("error: invalid input of n\n");
            return 1;
        }
        i = 0;
        if (argc != 0)
            printf("usage: find -n\n");
        else{
            while((len = get_line(buffer, LIMIT)) > 0){
                p = (char *)malloc(len); //Will allocate bytes. Since char is 1 byte, no need to scale 'len' e.g (char *) malloc(len * sizeof(char)
                strcpy(p, buffer);
                tail[i % n] = p;
                i++;
            }
        }
        printf("--------------------------------------\n");

        writeline(tail, i, n);
        return 0;
            
}

void writeline(char *tail[], int i, int n){
        int j, start, end;

        if (i <= n){
            j = 0;
            for (j = 0; j < i; j++)
                printf("%s", tail[j]);
        }
        else{
            start = (i % n);
            end = (i - 1) % n;
            while ((start % n) != end)
                printf("%s", tail[start++ % n]);
            printf("%s", tail[end]);
        }
}

int get_line(char s[], int lim){
        int i, c;
        i = 0;
        while (lim-->0 && (c = getchar()) != EOF && c != '\n')
            s[i++] = c;
        if (c == '\n')
            s[i++] = c;
        s[i] = '\0';
        return i;
}


