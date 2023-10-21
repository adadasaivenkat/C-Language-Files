#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    int n,i,total_bytes=0;
    printf("Enter the number of user names you want to input : ");
    scanf("%d",&n);
    if(n>=0)
    {
        char **user_names;
        user_names=(char **)malloc(n*sizeof(char *));
        total_bytes+=n*sizeof(char *);              //In my complier sizeof(char *) is 8 bytes...
        for(i=0; i<n; i++)
        {
            char input[100];                        //Assuming a maximum user name length of 100 characters
            printf("Enter user name %d : ",i+1);
            scanf("%s",input);                      //Without spaces
            //scanf(" %[^\n]s",input);              //With spaces
            user_names[i]=(char *)malloc((strlen(input)+1)*sizeof(char));   //+1 for null-terminator '\0'
            strcpy(user_names[i],input);
            total_bytes+=(strlen(input)+1)*sizeof(char);
        }
        printf("List of user names : \n");
        for(i=0; i<n; i++)
        {
            printf("%s\n",user_names[i]);
        }
        printf("The total bytes allocated is : %d\n",total_bytes);
        for(i=0; i<n; i++)  //Freeing allocated memory
        {
            free(user_names[i]);                   //Free the memory for each user name
        }
        free(user_names);                          //Free the memory for the array of pointers
    }
    else
    {
        printf("Invalid input!!\n");
    }
    return 0;
}