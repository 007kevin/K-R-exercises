/* K&R Exercise 5-15
 * Add the option -f to fold upper and lower case together, so that
 * case distictions are not made during sorting; for example,
 * a and A compare equal
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

#define MAXLINES 5000 /* max #lines to be sorted*/
#define MAXLEN 1000

char *lineptr[MAXLINES]; /* pointers to text lines */

int readline(char *lineptr[], int nlines);
int get_line(char *, int lim);
void writelines(char *lineptr[], int nlines);
void quicksort(void *lineptr[], int left, int right, int (*comp)(void *, void *), int r);
int numcmp(char *, char *);
int fstrcomp(char *, char *);
int strcomp(char *, char *);

/* sort input lines */
main(int argc, char *argv[]){
    int nlines; /* number of input lines read */
    int numeric = 0; /* 1 if numeric sort */
    int reverse = 0;
    int fold = 0;
    char c;

    int (*comp)(void *, void *);

    while(--argc > 0 && (*++argv)[0] == '-')
        while(c = *++argv[0])
            switch(c){
                case 'n':
                    numeric = 1;
                    break;
                case 'r':
                    reverse = 1;
                    break;
                case 'f':
                    fold = 1;
                    break;
                default:
                    printf("find: illegal option %c\n", c);
                    argc = -1;
                    break;
            }
    if (argc != 0){
        printf("Usage: find -x -n pattern\n");
        return 1;
    }
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0){
        if (numeric)
            comp = (int (*)(void *,void *))numcmp;
        else if (fold)
            comp = (int (*)(void *,void *))fstrcomp;
        else
            comp = (int (*)(void *,void *))strcomp;

        quicksort((void**) lineptr, 0, nlines-1, comp, reverse); 
        writelines(lineptr, nlines);
        return 0;
    }
    else{
        printf("input too big to sort\n");
    }
}

/* readlines: read input lines */       //Note, try testing char **lineptr instead of char *lineptr[]
int readlines(char *lineptr[], int maxlines){
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = get_line(line, MAXLEN)) > 0)
            if (nlines >= maxlines || (p = (char *)malloc(len)) == NULL)
                return -1;
            else {
            line[len-1] = '\0'; /* delete newline */
            strcpy(p, line);
            lineptr[nlines++] = p;
            }
    return nlines;
}

int get_line(char *s, int lim){
    int i, c;
    i = 0;
    while (lim-- > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* writelines: write output lines */
void writelines(char *lineptr[], int nlines){
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

/* quicksort: sort v[left]... v[right] into increasing order */
void quicksort(void *v[], int left, int right, int (*comp)(void *, void *), int r){
    int i, last;
    void swap(void *v[], int ,int);

    if (left >= right) /* do nothing if array contains fewer than two elements */
        return;
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if ((r == 0 ? (*comp)(v[i], v[left]) < 0: (*comp)(v[i], v[left]) > 0))
            swap(v, ++last, i);
    swap(v, left, last);
    quicksort(v, left, last - 1, comp, r);
    quicksort(v, last + 1, right, comp, r);
}

/* numcmp: compare s1 and s2 numerically */
int numcmp(char *s1, char *s2){
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}
/* fstrcomp: compare s1 and s2 without case sensitivity */
int fstrcomp(char *s1, char *s2){
    char a, b;
    a = (isupper(*s1) ? tolower(*s1) : *s1);
    b = (isupper(*s2) ? tolower(*s2) : *s2);

    if (a < b)
        return -1;
    else if (a > b)
        return 1;
    else
        return 0;
}

/* strcomp: compare s1 and s2 */
int strcomp(char *s1, char *s2){

    if (*s1 < *s2)
        return -1;
    else if (*s1 > *s2)
        return 1;
    else
        return 0;
}


void swap (void *v[], int i, int j){
    void *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}






















