/* Excercise 5-9: Rewrite the routines day_of_year and month_day with pointers instead of indexing */

#include<stdio.h>
#include<ctype.h>
#define LIMIT 1000

void day_of_year(int *,int *,int *);
void month_day(int *,int *,int *,int *);
int get_line(char *, int lim);

int main(){
    char s[LIMIT];
    char option = 1;

    int month, day, year;
    
    printf("Calculate day of year. Enter year, month, then day\n");
    get_line(s, LIMIT);
    year = atoi(s);
    get_line(s, LIMIT);
    month = atoi(s);
    get_line(s, LIMIT);
    day = atoi(s);

    day_of_year(&year, &month, &day);

    printf("%d\n\n", day);

    printf("Calculate month and day. Enter year and day\n");
    get_line(s, LIMIT);
    year = atoi(s);
    get_line(s, LIMIT);
    day = atoi(s);
    month_day(&year, &day, &month, &day);

    printf("%d %d\n", month, day);
    

    return 0;
}

static char daytab[][13] = {
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}
};

/* day_of_year: set day of year from month & day */
void day_of_year(int *year, int *month, int *day){
    int i, leap;

    leap = *year%4 == 0 && *year %100 != 0 || *year %400 == 0;
    for (i = 1; i < *month; i ++)
        *day += *(daytab + leap)[i];
}

/* month_day: set month, day from day of year */
void month_day(int *year, int* yearday, int *pmonth, int *pday)
{
    int i, leap;
    leap = *year % 4 == 0 && *year %100 != 0 || *year %400 == 0;

    for (i = 1; *yearday > daytab[leap][i]; i++)
        *yearday -= *(daytab + leap)[i];
    *pmonth = i;
    *pday = *yearday;
}

int get_line(char *s, int lim){
    int c;
    char *p = s;
    while (lim-- > 0 && (c = getchar()) != EOF && c != '\n')
        *s++ = c;
    if (c == '\n')
        *s++ = c;
    *s = '\0';
    return s - p;
}












