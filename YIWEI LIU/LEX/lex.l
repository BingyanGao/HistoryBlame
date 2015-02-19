%option noyywrap


whitespace    [ \t\n]+


%%
{whitespace}    printf("%s", " ");
.	|
\n ECHO; 
%%   

int main() {
 return yylex();
};
