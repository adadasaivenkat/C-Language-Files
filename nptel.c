#include<stdio.h>
struct sample
{
    int a;
    char b;
};
struct test
{
    int c;
    char d;
};
int main(void)
{
    struct sample s1;
    s1.a=10;
    s1.b=2;
    struct test s2;
    s2.c=10;
    s2.d=2;
    if((s1.a==s2.c)&&(s1.b==s2.d))
    {
        printf("Struct objects are equal\n");
    }
    else
    {
        printf("Struct objects are Not equal\n");
    }
    return 0;
}