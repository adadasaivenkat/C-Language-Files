#include<stdio.h>
#include<string.h>
int main(void)
{
    char str1[20],str2[20];
    printf("Enter String-1 : ");
    gets(str1);
    printf("Enter String-2 : ");
    gets(str2);
    int len1=0,len2=0,i,j,k;
    for(i=0; str1[i]!='\0'; i++)
        len1++;
    for(j=0; str2[j]!='\0'; j++)
        len2++;
    for(k=0; k<=len2; k++)
    {
        str1[len1+k]=str2[k];
    }
    printf("The concatenated string is %s\n",str1);
    return 0;
}