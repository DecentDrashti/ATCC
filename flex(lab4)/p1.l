//to run flex p1.l --> gcc lex.yy.c--> a.exe
%option noyywrap

%{
int c=0,v=0;
%}

%%

[aeiouAEIOU] v++; //pattern action 
[a-zA-Z] c++;
\n {printf(" No of vowels: %d\nNo of Consonants: %d\n",v,c);v=0;c=0;}
.
%%

void main( )
{
	yylex( );
}