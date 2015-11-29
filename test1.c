#include<stdio.h>

int main(){
    char *test[] = {"Kevin", "Ian", "Mom", "Dad"};
    
    void *A = test;

    printf("no cast: %x\n", A);
    
    A = (void*) test;
    printf("(void*) cast: %x\n", A);

    A = (void**) test;
    printf("void**) cast: %x\n", A);
    return 0;
}
