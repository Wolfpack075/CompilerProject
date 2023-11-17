%{
	    
		//	Bismillahir Rahmanir Rahim. 
    	//	Every praise goes to ALLAH for our wellbeing.
		//	Code : Kazi Fahim Tahmid
		
		#include<stdio.h>
	    #include <string.h>
        #include<math.h>
	    #include<stdlib.h>
%}

single_line_comment     "//".*
multiple_line_comment   [/][*][A-Za-z0-9. \n]*[*][/]
User_Datatype           "integerf"|"floatf"|"characterf"|"doublef"
variable                "f#"[a-zA-Z]([a-zA-Z0-9])*[?]
logical_operator        "&&"|"||"|"!!!"




%%

{single_line_comment} {
	printf("Single line comment\n");
}

{multiple_line_comment} {
	printf("Multiple line comment\n");
}

"=f"						{printf("="); }

"integerf"					{printf("int"); }

"floatf"					{printf("float"); }

"characterf"				{printf("char"); }

"doublef"					{printf("double"); }

"plusequal"					{printf("+="); }

"minusequal"					{printf("-=");}

"mulequal"					{printf("Assignment operator *= in c\n");}

"divequal"					{printf("Assignment operator /= in c\n");}

"inc"  						{printf("++"); }

"dec"  						{printf("--"); }

"GT" 						{printf(">") ; }

"ls" 						{printf("<") ; }

"feq" 						{printf("==") ; }

"neq" 						{printf("!="); }

"GTeq" 						{printf(">=");}

"lseq" 						{printf("<="); }

{logical_operator} 			{printf("%s", yytext); }

"f(" 						{printf("(") ; }

"f)" 						{printf(")") ; }

"START" 					{printf("{"); }

"END"						{printf("}"); }

"f[" 						{printf("["); }

"f]" 						{printf("]"); }

"jog" 						{printf("+");}

"biyog" 					{printf("-");}

"gun" 						{printf("*");}

"vag"  						{printf("/");}

"power"  					{printf("pow");}

"modulo" 					{printf("modulus");}

"factorial"  				{printf("!");}

"jonno"  					{printf("for");}

"during"  					{printf("while");}

"switchf"  					{printf("switch");}

"case_f" 					{printf("case");}

"timeless" 					{printf("default");}

"smash" 					{printf("break");}

"iff" 						{printf("if"); }

"elif" 						{printf("else if"); }

"otherwise" 				{printf("else"); }

"sinf" 						{printf("sin");}

"cosf" 						{printf("cos");}

"tanf" 						{printf("tan");}

"logf" 						{printf("log");}

"function()"  				{printf("main()\n");}

"rtn" 						{printf("return");}

"porerta"					{printf("continue\n");}

"System.out"				{printf("printf");}

"System.in"					{printf("scanf");}

"1907016"					{printf("#include");}

"stdio" 					{printf("stdio.h");}

"string" 					{printf("string.h");}

"math" 						{printf("math.h");}

"stdlib" 					{printf("stdlib.h");}

[0-9]+ 						{ 
								int n = atoi(yytext);
								printf("%d", n);
							}

"comma" 					{ printf(",");}

"colon" 					{printf(":");}

"sm" 						{printf(";");}

{variable} 					{
								char* a=strdup(yytext);
    							char s[50];
    							int j = 0;
    							for(int i = 2 ; a[i] != '?' ; i++){
    					    		s[j++] = a[i];
    							}
    							s[j] = '\0';
								printf("%s", s);
							}

[a-zA-Z] 						{printf("%s", yytext);}	




%%



int yywrap(){}
int main(){
  yyin =freopen("input.txt","r",stdin);
  yyout =freopen("output.txt","w",stdout); 
  yylex();
}








