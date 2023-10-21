#include<stdio.h>
#include<string.h>
int main()
{
    char user_names[11][31];
    int n,i;
    printf("Enter the number of user names you want to input (up to 10 user names) : ");
    scanf("%d",&n);
    if(n>=0 && n<=10)
    {
        for(i=0; i<n; i++)
        {
            printf("Enter user name %d (up to 30 characters) : ",i+1);
            scanf("%30s",user_names[i]);                //user name without spaces
            //scanf(" %30[^\n]s",user_names[i]);            // user name with spaces
        }
        printf("List of user names : \n");
        for(i=0; i<n; i++)
        {
            printf("%s\n",user_names[i]);
        }
    }
    else
    {
        printf("Invalid input!!\n");
    }
    return 0;
}
