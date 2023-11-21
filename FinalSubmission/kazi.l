/*
    
    Bismillahir Rahmanir Rahim. 
    Every praise goes to ALLAH for our wellbeing.
    Code : Kazi Fahim Tahmid
    Judge: Codeforces
    Date : 2023-10-17 19.02
 
    
*/

/*     -------------- C files include --------------        */

%{
    #include "kazi.tab.h"
    #include <string.h>
    int yyparse();
    int yylex();  
    int yyerror();
    FILE *flexo;
    void count();
    int multicomm=0;
%}

/*     -------------- Keyword Section for Patters --------------        */


char                    [a-zA-Z]
digit                   [0-9]
special                 [$_@]
space                   " "
newline                 "\n"
Datatype                "int"|"double"|"char"|"void"
Operator                "="|"+"|"-"|"/"|"*"|"&"|"|"|"%"
Relational_Operator     "<"|">"|"<="|">="|"&&"|"||"|"=="|"!="
Identifier              ({char}|{digit}|{special})+


/*     -------------- Pattern Matching Rules Section --------------        */
%%
"/*" { 
    comment();
}
[ \t\v\n\f] {
    count();
}
"func" {
    count();
    fprintf(flexo,"LEX 1 : %s\n",yytext);
    return FUNC;
}
"print" {
    count();
    fprintf(flexo,"LEX 2 : %s\n",yytext);
    return PRINT;
}
"switch" {
    count();
    fprintf(flexo,"LEX 2.1 : %s\n",yytext);
    return SWITCH;
}
"case" {
    count();
    fprintf(flexo,"LEX 2.2 : %s\n",yytext);
    return CASE;
}
"default" {
    count();
    fprintf(flexo,"LEX 2.2 : %s\n",yytext);
    return def_ault;
}
"ASIN" {
    count();
    fprintf(flexo,"LEX 3 : %s\n",yytext);
    return ASIN;
}
"ACOS" {
    count();
    fprintf(flexo,"LEX 4 : %s\n",yytext);
    return ACOS;
}
"ATAN" {
    count();
    fprintf(flexo,"LEX 5 : %s\n",yytext);
    return ATAN;
}
"LOG10" {
    count();
    fprintf(flexo,"LEX 6 : %s\n",yytext);
    return LOG10;
}
"LOG" {
    count();
    fprintf(flexo,"LEX 7 : %s\n",yytext);
    return LOG;
}
"SIN" {
    count();
    fprintf(flexo,"LEX 8 : %s\n",yytext);
    return SIN;
}
"COS" {
    count();
    fprintf(flexo,"LEX 9 : %s\n",yytext);
    return COS;
}
"TAN" {
    count();
    fprintf(flexo,"LEX 10 : %s\n",yytext);
    return TAN;
}
"GCD" {
    count();
    fprintf(flexo,"LEX 11 : %s\n",yytext);
    return GCD;
}
"LCM" {
    count();
    fprintf(flexo,"LEX 12 : %s\n",yytext);
    return LCM;
}
"POW" {
    count();
    fprintf(flexo,"LEX 13 : %s\n",yytext);
    return POW;
}
"import" {
    count();
    fprintf(flexo,"LEX 14 : %s\n",yytext);
    return IMPORT;
}
"var" { 
    count();
    fprintf(flexo,"LEX 15 : %s\n",yytext);
    return VAR;
}
"class" {
    count();
    fprintf(flexo,"LEX 16 : %s\n",yytext);
    return CLASS;
}
"init" {
    count();
    fprintf(flexo,"LEX 17 : %s\n",yytext);
    return INIT;
}
"Int" {
    count();
    fprintf(flexo,"LEX 18 : %s\n",yytext);
    return INT;
}
"Double" {
    count();
    fprintf(flexo,"LEX 19 : %s\n",yytext);
    return DOUBLE;
}
"String" {
    count();
    fprintf(flexo,"LEX 20 : %s\n",yytext);
    return STRING;
}
"else if" {
    count();
    fprintf(flexo,"LEX 21 : %s\n",yytext);
    return ELSEIF;
}
"else" {
    count();
    fprintf(flexo,"LEX 22 : %s\n",yytext);
    return ELSE;
}
"if" {
    count();
    fprintf(flexo,"LEX 23 : %s\n",yytext);
    return IF;
}
"for" {
    count();
    fprintf(flexo,"LEX 24 : %s\n",yytext);
    return FOR;
}
"while" {
    count();
    fprintf(flexo,"LEX 25 : %s\n",yytext);
    return WHILE;
}
"const" {
    count();
    fprintf(flexo,"LEX 26 : %s\n",yytext);
    return CONST;
}
"continue" {
    count();
    fprintf(flexo,"LEX 27 : %s\n",yytext);
    return CONTINUE;
}
"return" {
    count();
    fprintf(flexo,"LEX 28 : %s\n",yytext);
    return RETURN;
}
"Void" {
    count();
    fprintf(flexo,"LEX 29 : %s\n",yytext);
    return VOID;
}
"Class" {
    count();
    fprintf(flexo,"LEX 30 : %s\n",yytext);
    return CLASS;
}
"DO" {
    count();
    fprintf(flexo,"LEX 81 : %s\n",yytext);
    return DO;
}
{digit}*"."{digit}+ {
    count();
    fprintf(flexo,"LEX 31 : %s\n",yytext);
    yylval.val.doubleval = atof(yytext);
    yylval.val.type = 3;
    return NUM;
}
{digit}+ {
    count();
    fprintf(flexo,"LEX 32: %s\n",yytext);
    yylval.val.intval = atoi(yytext);
    yylval.val.type = 2;
    return NUM;
}
"$"{Identifier} {
    count();
    fprintf(flexo,"LEX 33 : %s\n",yytext);
    strcpy(yylval.text,yytext+1);
   // printf("Came :: %s\n",yylval.text);
    return VARACCESS;
}
{Identifier} {
    count();
    fprintf(flexo,"LEX 34: %s\n",yytext);
    strcpy(yylval.text,yytext);
    return NAME;
}
">>="			{ count(); 
    fprintf(flexo,"LEX 35 : %s\n",yytext);
    return(RIGHT_ASSIGN); }
"<<="			{ count(); 
    fprintf(flexo,"LEX 36 : %s\n",yytext);
    return(LEFT_ASSIGN); }
"+="			{ count(); 
    fprintf(flexo,"LEX 37 : %s\n",yytext);
    return(ADD_ASSIGN); }
"-="			{ count(); 
    fprintf(flexo,"LEX 38 : %s\n",yytext);
    return(SUB_ASSIGN); }
"*="			{ count(); 
    fprintf(flexo,"LEX 39 : %s\n",yytext);
    return(MUL_ASSIGN); }
"/="			{ count(); 
    fprintf(flexo,"LEX 40 : %s\n",yytext);
    return(DIV_ASSIGN); }
"%="			{ count(); 
    fprintf(flexo,"LEX 41 : %s\n",yytext);
    return(MOD_ASSIGN); }
"&="			{ count(); 
    fprintf(flexo,"LEX 42 : %s\n",yytext);
    return(AND_ASSIGN); }
"^="			{ count(); 
    fprintf(flexo,"LEX 43 : %s\n",yytext);
    return(XOR_ASSIGN); }
"|="			{ count(); 
    fprintf(flexo,"LEX 44 : %s\n",yytext);
    return(OR_ASSIGN); }
">>"			{ count(); 
    fprintf(flexo,"LEX 45 : %s\n",yytext);
    return(RIGHT_OP); }
"<<"			{ count(); 
    fprintf(flexo,"LEX 46 : %s\n",yytext);
    return(LEFT_OP); }
"++"			{ count(); 
    fprintf(flexo,"LEX 47 : %s\n",yytext);
    return(INC_OP); }
"--"			{ count(); 
    fprintf(flexo,"LEX 48 : %s\n",yytext);
    return(DEC_OP); }
"->"			{ count(); 
    fprintf(flexo,"LEX 49 : %s\n",yytext);
    return(PTR_OP); }
"&&"			{ count();
    fprintf(flexo,"LEX 50 : %s\n",yytext);
     return(AND_OP); }
"||"			{ count(); 
    fprintf(flexo,"LEX 51 : %s\n",yytext);
    return(OR_OP); }
"<="			{ count(); 
    fprintf(flexo,"LEX 52 : %s\n",yytext);
    return(LE_OP); }
">="			{ count(); 
    fprintf(flexo,"LEX 53 : %s\n",yytext);
    return(GE_OP); }
"=="			{ count(); 
    fprintf(flexo,"LEX 54 : %s\n",yytext);
    return(EQ_OP); }
"!="			{ count(); 
    fprintf(flexo,"LEX 55 : %s\n",yytext);
    return(NE_OP); }

";"			{ count(); 
    fprintf(flexo,"LEX 56 : %s\n",yytext);
    return(';'); }
("{"|"<%")		{ count(); 
    fprintf(flexo,"LEX 57 : %s\n",yytext);
    return('{'); }
("}"|"%>")		{ count(); 
    fprintf(flexo,"LEX 58 : %s\n",yytext);
    return('}'); }
","			{ count(); 
    fprintf(flexo,"LEX 59 : %s\n",yytext);
    return(','); }
":"			{ count(); 
    fprintf(flexo,"LEX 60 : %s\n",yytext);
    return(':'); }
"="			{ count(); 
    fprintf(flexo,"LEX 61 : %s\n",yytext);
    return('='); }
"("			{ count();
    fprintf(flexo,"LEX 62 : %s\n",yytext);
     return('('); }
")"			{ count();
    fprintf(flexo,"LEX 63 : %s\n",yytext);
     return(')'); }
("["|"<:")		{ count();
    fprintf(flexo,"LEX 64 : %s\n",yytext);
     return('['); }
("]"|":>")		{ count();
    fprintf(flexo,"LEX 65 : %s\n",yytext);
     return(']'); }
"."			{ count();
    fprintf(flexo,"LEX 66 : %s\n",yytext);
     return('.'); }
"&"			{ count(); 
    fprintf(flexo,"LEX 67 : %s\n",yytext);
    return('&'); }
"!"			{ count();
    fprintf(flexo,"LEX 68 : %s\n",yytext);
     return('!'); }
"~"			{ count();
    fprintf(flexo,"LEX 69 : %s\n",yytext);
     return('~'); }
"-"			{ count(); 
    fprintf(flexo,"LEX 70 : %s\n",yytext);
    return('-'); }
"+"			{ count(); 
    fprintf(flexo,"LEX 71 : %s\n",yytext);
    return('+'); }
"*"			{ count(); 
    fprintf(flexo,"LEX 72 : %s\n",yytext);
    return('*'); }
"/"			{ count(); 
    fprintf(flexo,"LEX 73 : %s\n",yytext);
    return('/'); }
"%"			{ count();
    fprintf(flexo,"LEX 74 : %s\n",yytext);
     return('%'); }
"<"			{ count(); 
    fprintf(flexo,"LEX 75 : %s\n",yytext);
    return('<'); }
">"			{ count(); 
    fprintf(flexo,"LEX 76 : %s\n",yytext);
    return('>'); }
"^"			{ count();
    fprintf(flexo,"LEX 77 : %s\n",yytext);
     return('^'); }
"|"			{ count();
    fprintf(flexo,"LEX 78 : %s\n",yytext);
     return('|'); }
"?"			{ count();
    fprintf(flexo,"LEX 79 : %s\n",yytext);
     return('?'); }

"\""(.)*"\"" {
    count();
    fprintf(flexo,"LEX 80 : %s\n",yytext);
    yylval.val.type = 4;
    yylval.val.strval = calloc(strlen(yytext),sizeof(char));
    strcpy(yylval.val.strval,yytext+1);
    yylval.val.strval[strlen(yylval.val.strval)-1]=0;
    return STR;
}
. {
    printf("Error :: Unknown character\n");
    exit(-1);
}
%%
int yywrap () {
	return 1;
}
void comment() {
	char c, c1;
loop:
	while ((c = input()) != '*' && c != 0)
		putchar(c);

	if ((c1 = input()) != '/' && c != 0)
	{
		unput(c1);
		goto loop;
	}

	if (c != 0)
		putchar(c1);
}
int column = 0;
FILE *infotext;
void count () {
    int i;
    for(int i=0;yytext[i]!='\0';i++)
    {
        if(yytext[i]=='\n')
            column=0;
        else if(yytext[i]=='\t')
            column+=(8-(column%8));
        else column++;
    }
    ECHO;
}
int main () {
    freopen("input.txt","r",stdin);
	flexo = fopen("lex_out.txt","w");
    infotext = fopen("info.txt","w");
    yyparse();
    fclose(flexo);
}