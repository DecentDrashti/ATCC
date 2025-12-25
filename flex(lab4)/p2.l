%option noyywrap
%{
int c=0,l=0,w=0;
%}
%%
[a-zA-Z0-9]* {w++,c+=yyleng;}
.  {c++;}
\n {c++;l++;}
%%

void main( )
{
	yyin =fopen("input6.txt","r");
	yylex( );
printf("no of character: %d\nno of words: %d\nno of lines: %d\n",c,w,l);
}