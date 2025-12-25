#include<stdio.h>

void main()
{
    FILE *f,*f1;
    char ch, next;
    f = fopen("output.txt","r");
    f1 = fopen("output1.txt","a");

    while (fscanf(f,"%c", &ch) == 1)
    {
        if (ch == ' ' || ch == '\t' || ch == '\n')
        {
            fprintf(f1, "%c", ch);
            // Skip extra white spaces
            while (ch == ' ' || ch == '\t' || ch == '\n')
            {
                fscanf(f, "%c", &ch);
            }
            // Write a single space to the output file
            //fprintf(f1, " ");
            // Put back the last read character which is not a white space
            ungetc(ch, f);
        }
        else
        {
            fprintf(f1, "%c", ch);
        }
    }
    fclose(f);
    fclose(f1);
}
