//want to remove comments from a file
#include<stdio.h>

void main()
{
    FILE *f,*f1;
    char ch, next;
    f = fopen("file.txt","r");
    f1 = fopen("output.txt","a");

    while (fscanf(f,"%c", &ch) == 1)
    {
        if (ch == '/')
        {
            // Read next char into next (not ch)
            if (fscanf(f,"%c", &next) != 1)
            {
                // nothing after '/', just print '/'
                fprintf(f1, "%c", ch);
                break;
            }

            if (next == '/')   // single-line comment
            {
                while (fscanf(f,"%c", &ch) == 1 && ch != '\n');
            }
            else if (next == '*') // multi-line comment
            {
                char prev;
                fscanf(f,"%c", &ch);
                while (1)
                {
                    prev = ch;
                    if (fscanf(f,"%c", &ch) != 1) break;
                    if (prev == '*' && ch == '/') break;
                }
            }
            else
            {
                // NOT a comment → print both characters
                fprintf(f1, "%c", ch);   // '/'
                fprintf(f1, "%c", next); // second character
            }
        }
        else
        {
            fprintf(f1, "%c", ch);
        }
    }

    fclose(f);
    fclose(f1);
}

// #include<stdio.h>
// void main()
// {
//     FILE *f,*f1;
//     char ch,next;
//     f=fopen("file.txt","r");
//     f1=fopen("output.txt","w");
//      while(fscanf(f,"%c", &ch)==1)
//     {
//      if(ch=='/' )
//      {
//         fscanf(f,"%c", &ch);
//         if(next=='/')
//         {
//             // ch=next;
//             while(ch!='\n')
//             {
//                 fscanf(f,"%c",&ch);
//             }
//         }
//         else if(ch=='*')
//         {
//             char prev;
//             fscanf(f,"%c",&ch);
//             while(1)
//             {
//                 prev=ch;
//                 fscanf(f,"%c",&ch);
//                 if(prev=='*' && ch=='/')
//                 {
//                     break;
//                 }
//             }
//         }
//         else
//         {
//             fprintf(f1,"%c",ch);
//             ungetc(ch,f);

//         }
//      }
//      else
//      {
//         fprintf(f1,"%c",ch);
//      }
//     }
//     fclose(f);
//     fclose(f1);
// }