//file text to another file 
#include<stdio.h>
void main()
{
    FILE *f;
    FILE *f1;
    char ch;
    f=fopen("f2.txt","a");
    f1=fopen("f1.txt","r");
    while(fscanf(f1,"%c", &ch)==1)
    {
    fprintf(f,"%c",ch);
    }
    printf("your file is ready");
    fclose(f);
    fclose(f1);
}