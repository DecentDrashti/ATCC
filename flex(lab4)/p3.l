%option noyywrap
%{
#include<stdio.h>
int count=0;
%}

%%
\/\/.*\n {printf("%s\n",yytext);count++;}
\/\*(.\n)*.*\*\/ {printf("%s\n",yytext);count++;}
.|\n {fprintf(yyout, "%s",yytext);}
%%

void main( )
{
	yyin =fopen("inp.c","r");
	yyout=fopen("temp2.txt","w");
	yylex( );
printf("no of commenet lines are: %d\n",count);
}