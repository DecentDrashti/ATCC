//file every first letter of a word should be capital 
#include<stdio.h>
#include<ctype.h>
void main()
{
    FILE *f;
    char ch, prev = ' ';
    f=fopen("f1.txt","r");
    if (!f) {
        printf("File not found");
        return ;
    }
    while(fscanf(f,"%c",&ch)==1)
    {
        if (prev == ' ' || prev == '\n') 
            printf("%c", toupper(ch));

        prev = ch;
        
    }
    fclose(f);
}