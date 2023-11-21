/*
    
    Bismillahir Rahmanir Rahim. 
    Every praise goes to ALLAH for our wellbeing.
    Code : Kazi Fahim Tahmid
    Judge: Codeforces
    Date : 2023-10-17 23:12
 
    
*/

%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    #include<math.h>
    #include "identifier.c"
    int yyparse();
    int yylex();
    int yyerror();
    int ifdone[1000];
    struct datatype casedata;
    int caseflag;
    int ifptr=0;
    int dimencount = 0;
    struct ll_identifier *root=NULL,*last=NULL;
    int typenow = -1;
    int gcd(int a, int b) 
    { 
        if (b == 0) 
            return a; 
        return gcd(b, a % b);  
    }
    extern FILE *infotext;
%}
%code requires {
    #ifndef __DT__
    #define __DT__
    struct __DT__ datatype {
        int type;
        char *strval;
        int intval;
        double doubleval;
    };
    #endif
}
%union {
    char text[1009];
    struct datatype val;
}

%token<text>NAME
%token<text>VARACCESS
%token<val>NUM
%token<val>STR
%type<val>expression

%token FUNC CLASS INIT INT DOUBLE STRING CONST VOID VAR
%token ELSEIF ELSE IF SWITCH CASE def_ault
%token FOR WHILE DO
%token CONTINUE RETURN
%token RIGHT_ASSIGN LEFT_ASSIGN ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN AND_ASSIGN XOR_ASSIGN OR_ASSIGN RIGHT_OP LEFT_OP INC_OP DEC_OP PTR_OP 
%token AND_OP OR_OP LE_OP GE_OP EQ_OP NE_OP
%token PRINT SIN TAN LOG LOG10 COS ACOS ASIN ATAN GCD LCM POW IMPORT

%%
starthere   : {
                fprintf(infotext,"\nCompiled Successfully\n\n");
                fprint_all(root,infotext);
            }
            | function starthere
            | declaration starthere
            | classgrammer starthere
            | importgrammer starthere
            ;

classgrammer    : CLASS NAME '{' statement '}' ';' {
                    int res = addNewClass(&root,&last,$2,"");
                    if(!res)
                    {
                        printf("Compilation Error ::  this name :: %s is already declared\n",$2);
                        exit(-1);
                    }
                    else{
                        fprintf(infotext,"Class declared :: %s\n",$2);
                    }
                }
                ;

function    : FUNC NAME '(' fparameter ')' PTR_OP TYPE {
                char *val;
                int n = log10(typenow) + 1;
                val = calloc(n + 1, sizeof(char));
                snprintf(val, n, "%ld", typenow);
                int res = addNewFunc(&root,&last,$2,val);
                if(!res)
                {
                    printf("Compilation Error ::  Varribale %s is already declared\n",$2);
                    exit(-1);
                }
                else{
                    fprintf(infotext,"Function declared :: %s\n",$2);
                }
            } '{' statement '}'
            ;
TYPE        : INT { typenow = 1;}
            | DOUBLE { typenow = 2;}
            | STRING { typenow = 3;}
            | VOID { typenow = 4;}
            | NAME {  
                struct ll_identifier* res = getVal(&root,$1);
                if(res==NULL || res->data.type!=6){
                    printf("Error :: Class Name Not defined\n");
                    exit(-1);
                }
                typenow = res->data.intval;
            }
            ;
fparameter : 
            | NAME ':' TYPE fsparameter
            ;
fsparameter :
            | ',' NAME ':' TYPE fsparameter
            | ',' NAME ':' TYPE
            ;
statement   :
            | ifgrammer statement
            | declaration statement
            | forgrammer statement
            | asgngrammer statement
            | whilegrammer statement
            | mathexpr statement
            | dowhilegrameer statement
            | returnstmt statement
            | printgrammer statement
            | switchgrammer statement
            ;

switchgrammer   : SWITCH '(' expression ')' ':'{
                    casedata = $3;
                    fprintf(infotext,"Switch Case declared\n");
                    fprint_datatype(casedata,infotext);
                } '{' casegrammer '}'
                ;

casegrammer     : CASE expression ':' statement  {
                    if(caseflag == 0 && evaluate($2,casedata,"==").intval == 1){
                        caseflag = 1;
                        fprintf(infotext,"Case executed :: ");
                        fprint_datatype($2,infotext);
                    }
                } casegrammer
                | def_ault ':' statement {
                    if(caseflag == 0){
                        fprintf(infotext,"Defualt executed\n");
                    }
                }
                | /* empty */
mathexpr    : expression ';' {
                    printf("Value of the expression :: ");
                    print_datatype($1);
            }
            ;
ifgrammer   : IF '(' expression ')' '{' statement '}' {
                ifptr++;
                if(boolvalue($3)){
                    fprintf(infotext,"IF executed \n");
                    ifdone[ifptr] = 1;
                }
            } elsifgrmr {
                ifptr--;
            }
            ;
expression  : NUM { $$ = $1;
                     //print_datatype($1);
            }
            | STR {
                $$ = $1; 
                //print_datatype($1);
            }
            | VARACCESS {
                struct ll_identifier* res = isDeclared(&root,$1);
                if(res==NULL)
                {
                    printf("Compilation Error ::  Varribale %s is not declared\n",$1);
                    exit(-1);
                }
                else if(res->data.type == 1 || res->data.type == 6)
                {
                    printf("Error :: You can't set a value to class/function");
                    exit(-1);
                }
                else 
                {
                    if(res->data.type==2)
                        $$ = make_datatype_int(res->data.intval);
                    else if(res->data.type==3)
                        $$ = make_datatype_double(res->data.doubleval);
                    else if(res->data.type==4){
                        $$ = make_datatype_char(res->data.strval);
                    }
                }
            }
            | SIN '(' expression ')'  {
                    if($3.type==4){
                        printf("Compilation Error :: Cannot convert a String to Double\n");
                        exit(-1);
                    }
                    double val = $3.type==2?$3.intval:$3.doubleval;
                    fprintf(infotext,"Value of the expression :: %f\n",sin(val));
            }
            | ASIN '(' expression ')'  {
                    if($3.type==4){
                        printf("Compilation Error :: Cannot convert a String to Double\n");
                        exit(-1);
                    }
                    double val = $3.type==2?$3.intval:$3.doubleval;
                    fprintf(infotext,"Value of the expression :: %f\n",asin(val));
            }
            | ACOS '(' expression ')' {
                    if($3.type==4){
                        printf("Compilation Error :: Cannot convert a String to Double\n");
                        exit(-1);
                    }
                    double val = $3.type==2?$3.intval:$3.doubleval;
                    fprintf(infotext,"Value of the expression :: %f\n",acos(val));
            }
            | COS '(' expression ')'  {
                    if($3.type==4){
                        printf("Compilation Error :: Cannot convert a String to Double\n");
                        exit(-1);
                    }
                    double val = $3.type==2?$3.intval:$3.doubleval;
                    fprintf(infotext,"Value of the expression :: %f\n",cos(val));
            }
            | LOG '(' expression ')' {
                    if($3.type==4){
                        printf("Compilation Error :: Cannot convert a String to Double\n");
                        exit(-1);
                    }
                    double val = $3.type==2?$3.intval:$3.doubleval;
                    fprintf(infotext,"Value of the expression :: %f\n",log(val));
            }
            | LOG10 '(' expression ')' {
                    if($3.type==4){
                        printf("Compilation Error :: Cannot convert a String to Double\n");
                        exit(-1);
                    }
                    double val = $3.type==2?$3.intval:$3.doubleval;
                    fprintf(infotext,"Value of the expression :: %f\n",log10(val));
            }
            | POW '(' expression ',' expression ')'  {
                    if($3.type==4){
                        printf("Compilation Error :: Cannot convert a String to Double\n");
                        exit(-1);
                    }
                    if($5.type==4){
                        printf("Compilation Error :: Cannot convert a String to Double\n");
                        exit(-1);
                    }
                    double val = $3.type==2?$3.intval:$3.doubleval;
                    double p = $5.type==2?$5.intval:$5.doubleval;
                    fprintf(infotext,"Value of the expression :: %f\n",pow(val,p));
            }
            | TAN '(' expression ')'  {
                    if($3.type==4){
                        printf("Compilation Error :: Cannot convert a String to Double\n");
                        exit(-1);
                    }
                    double val = $3.type==2?$3.intval:$3.doubleval;
                    fprintf(infotext,"Value of the expression :: %f\n",tan(val));
            }
            | ATAN '(' expression ')' {
                    if($3.type==4){
                        printf("Compilation Error :: Cannot convert a String to Double\n");
                        exit(-1);
                    }
                    double val = $3.type==2?$3.intval:$3.doubleval;
                    fprintf(infotext,"Value of the expression :: %f\n",atan(val));
            }
            | LCM '(' expression ',' expression ')' {
                    if($3.type!=2){
                        printf("Compilation Error :: Cannot override for other than Int\n");
                        exit(-1);
                    }
                    if($5.type!=2){
                        printf("Compilation Error :: Cannot override for other than Int\n");
                        exit(-1);
                    }
                    int val1 = $3.intval; 
                    int val2 = $5.intval; 
                    fprintf(infotext,"Value of the expression :: %d\n",val1*val2/gcd(val1,val2));
            }
            | GCD '(' expression ',' expression ')' {
                    if($3.type!=2){
                        printf("Compilation Error :: Cannot override for other than Int\n");
                        exit(-1);
                    }
                    if($5.type!=2){
                        printf("Compilation Error :: Cannot override for other than Int\n");
                        exit(-1);
                    }
                    int val1 = $3.intval; 
                    int val2 = $5.intval; 
                    fprintf(infotext,"Value of the expression :: %d\n",gcd(val1,val2));
            }
            | expression '+' expression { 
                $$ = evaluate($1,$3,"+");
            }
            | expression '-' expression { 
                $$ = evaluate($1,$3,"-");
            }
            | expression '/' expression { 
                $$ = evaluate($1,$3,"/");
            }
            | expression '*' expression { 
                $$ = evaluate($1,$3,"*");
            }
            | expression LE_OP expression { 
                $$ = evaluate($1,$3,"<=");
            }
            | expression GE_OP expression { 
                $$ = evaluate($1,$3,">=");
            }
            | expression '<' expression { 
                $$ = evaluate($1,$3,"<");
            }
            | expression '>' expression { 
                $$ = evaluate($1,$3,">");
            }
            | expression EQ_OP expression { 
                $$ = evaluate($1,$3,"==");
            }
            | expression NE_OP expression { 
                $$ = evaluate($1,$3,"!=");
            }
            | '(' expression ')' { 
                $$ = $2;
            }
            | expression AND_OP expression {
                $$ = make_datatype_int(boolvalue($1) && boolvalue($3));
            }
            | expression OR_OP expression {
                $$ = make_datatype_int(boolvalue($1) || boolvalue($3));
            }
            | expression "&" expression {
                $$ = make_datatype_int(_intvalue($1) & _intvalue($3));
            }
            | '!' expression {
                $$ = make_datatype_int(!_intvalue($2));
            }
            | '~' expression {
                $$ = make_datatype_int(~_intvalue($2));
            }
            | expression '^' expression {
                $$ = make_datatype_int(_intvalue($1) ^ _intvalue($3));
            }
            | expression '|' expression {
                $$ = make_datatype_int(_intvalue($1) | _intvalue($3));
            }
            
            ;

returnstmt  : RETURN mathexpr {
    fprintf(infotext,"return occured\n");
}
            | RETURN ';' {
                fprintf(infotext,"return occured\n");
            }

declaration :VAR varriables ';'
            ;
varriables  : varriable ',' varriables
            | varriable
            ;
varriable   : NAME ':' TYPE {
                int res = addNewVal(&root,&last,$1,"");
                if(!res)
                {
                    printf("Compilation Error ::  Varribale %s is already declared\n",$1);
                    exit(-1);
                }
                fprintf(infotext,"varriable declared : %s\n",$1);
            }
            | NAME '=' expression {
                char *val;
                if ($3.type == 2) {
                    $3.type = 4;
                    int n = log10($3.intval) + 1;
                    val = calloc(n + 1, sizeof(char));
                    snprintf(val, n + 1, "%ld", $3.intval);
                }
                else if ($3.type == 3) {
                    $3.type = 4;
                    val = calloc(51, sizeof(char));
                    snprintf(val, 50, "%lf", $3.doubleval);
                }
                else{
                    val = $3.strval;
                }
                int res = addNewVal(&root,&last,$1,val);
                if(!res)
                {
                    printf("Compilation Error ::  Varribale %s is already declared\n",$1);
                    exit(-1);
                }
                else{
                    fprintf(infotext,"varriable declared : %s\n",$1);
                }
            }
            | NAME ':' arraydim '*' '(' expression ')' {
                char *val;
                //printf("dimencount :: %d\n",dimencount);
                int n = log10(dimencount) + 2;
                val = calloc(n + 1, sizeof(char));
                char *temp = calloc(n,sizeof(char));
                snprintf(temp, n, "%ld", dimencount);
                val[0]='`';
                strcat(val,temp);
                int res = addNewVal(&root,&last,$1,val);
                if(!res)
                {
                    printf("Compilation Error ::  Varribale %s is already declared\n",$1);
                    exit(-1);
                }
                else{
                    fprintf(infotext,"Array declared : %s Dimension : %d\n",$1,dimencount);
                }
            }
            | NAME ':' arraydim {
                char *val;
                //printf("dimencount :: %d\n",dimencount);
                int n = log10(dimencount) + 2;
                val = calloc(n + 1, sizeof(char));
                char *temp = calloc(n,sizeof(char));
                snprintf(temp, n, "%ld", dimencount);
                val[0]='`';
                strcat(val,temp);
                int res = addNewVal(&root,&last,$1,val);
                if(!res)
                {
                    printf("Compilation Error ::  Varribale %s is already declared\n",$1);
                    exit(-1);
                }
                else{
                    fprintf(infotext,"Array declared : %s Dimension : %d\n",$1,dimencount);
                }
            }
            ;
arraydim    : '[' arrayx ']' {dimencount++;}
            ;
arrayx      : TYPE {dimencount = 0;}
            | '[' arrayx ']' {dimencount++;}
            ;
elsifgrmr   :
            | ELSEIF '(' expression ')' '{' statement '}' {
                if(ifdone[ifptr]==0 && boolvalue($3)){
                    ifdone[ifptr]=1;
                    fprintf(infotext,"ELSE IF executed\n");
                }
            } elsifgrmr
            | ELSE '{' statement '}' {
                if(ifdone[ifptr]==0){
                    fprintf(infotext,"ELSE executed\n");
                }
            }
            ;
asgngrammer : ASGNVAR ',' asgngrammer
            | ASGNVAR ';'
            ;

forgrammer  : FOR '(' forassign ';' expression ';' forassign ')' '{' statement '}' {
                fprintf(infotext,"for loop executed with expression : ");
                fprint_datatype($5,infotext);
            }
            ;

forassign   : ASGNVAR ',' forassign
            | ASGNVAR
ASGNVAR     : VARACCESS '=' expression {
                struct ll_identifier* res = isDeclared(&root,$1);
                if(res==NULL)
                {
                    printf("Compilation Error ::  Varribale %s is not declared\n",$1);
                    exit(-1);
                }
                else if(res->data.type == 1 || res->data.type == 6)
                {
                    printf("Error :: You can't set a value to class/function");
                    exit(-1);
                }
                else 
                {
                    if($3.type == 2){
                        int n = log10($3.intval) + 1;
                        char *numberArray = calloc(n, sizeof(char));
                        sprintf(numberArray,"%ld",$3.intval);
                        setVal(&root,&last,$1,numberArray);
                        fprintf(infotext,"Value assigned :: %s = %d\n",$1,$3.intval);
                    }
                    else if($3.type == 3){
                        char *numberArray = calloc(51,sizeof(char));
                        snprintf(numberArray,50,"%lf",$3.doubleval);
                        setVal(&root,&last,$1,numberArray);
                        fprintf(infotext,"Value assigned :: %s = %f\n",$1,$3.doubleval);
                    }
                    else{
                        setVal(&root,&last,$1,$3.strval);
                        fprintf(infotext,"Value assigned :: %s = %s\n",$1,$3.strval);
                    }
                }
            }
            | VARACCESS INC_OP {
                struct ll_identifier* res = isDeclared(&root,$1);
                if(res==NULL)
                {
                    printf("Compilation Error ::  Varribale %s is not declared\n",$1);
                    exit(-1);
                }
                else if(res->data.type == 1 || res->data.type == 6)
                {
                    printf("Error :: You can't set a value to class/function");
                    exit(-1);
                }
                struct datatype tmp,tmp1,tmp2;
                if(res->data.valtype == 2) tmp = make_datatype_int(res->data.intval);
                else if(res->data.valtype == 3) tmp = make_datatype_double(res->data.doubleval);
                else if(res->data.valtype == 4) tmp = make_datatype_char(res->data.strval);
                else tmp = make_datatype_int(0);
                tmp1 = make_datatype_int(1);
                tmp2 = evaluate(tmp,tmp1,"+");
                if(tmp2.type == 2){
                        int n = log10(tmp2.intval) + 1;
                        char *numberArray = calloc(n, sizeof(char));
                        sprintf(numberArray,"%ld",tmp2.intval);
                        setVal(&root,&last,$1,numberArray);
                        fprintf(infotext,"Value assigned :: %s = %d\n",$1,tmp2.intval);
                }
                else if(tmp2.type == 3){
                        char *numberArray = calloc(51,sizeof(char));
                        snprintf(numberArray,50,"%lf",tmp2.doubleval);
                        setVal(&root,&last,$1,numberArray);
                        fprintf(infotext,"Value assigned :: %s = %f\n",$1,tmp2.doubleval);
                }
                else{
                        setVal(&root,&last,$1,tmp2.strval);
                        fprintf(infotext,"Value assigned :: %s = %s\n",$1,tmp2.strval);
                }
            }
            | VARACCESS DEC_OP {
                struct ll_identifier* res = isDeclared(&root,$1);
                if(res==NULL)
                {
                    printf("Compilation Error ::  Varribale %s is not declared\n",$1);
                    exit(-1);
                }
                else if(res->data.type == 1 || res->data.type == 6)
                {
                    printf("Error :: You can't set a value to class/function");
                    exit(-1);
                }
                struct datatype tmp,tmp1,tmp2;
                if(res->data.valtype == 2) tmp = make_datatype_int(res->data.intval);
                else if(res->data.valtype == 3) tmp = make_datatype_double(res->data.doubleval);
                else if(res->data.valtype == 4) tmp = make_datatype_char(res->data.strval);
                else tmp = make_datatype_int(0);
                tmp1 = make_datatype_int(1);
                tmp2 = evaluate(tmp,tmp1,"-");
                if(tmp2.type == 2){
                        int n = log10(tmp2.intval) + 1;
                        char *numberArray = calloc(n, sizeof(char));
                        sprintf(numberArray,"%ld",tmp2.intval);
                        setVal(&root,&last,$1,numberArray);
                        fprintf(infotext,"Value assigned :: %s = %d\n",$1,tmp2.intval);
                }
                else if(tmp2.type == 3){
                        char *numberArray = calloc(51,sizeof(char));
                        snprintf(numberArray,50,"%lf",tmp2.doubleval);
                        setVal(&root,&last,$1,numberArray);
                        fprintf(infotext,"Value assigned :: %s = %f\n",$1,tmp2.doubleval);
                }
                else{
                        setVal(&root,&last,$1,tmp2.strval);
                        fprintf(infotext,"Value assigned :: %s = %s\n",$1,tmp2.strval);
                }
            }
            | VARACCESS ADD_ASSIGN expression {
                struct ll_identifier* res = isDeclared(&root,$1);
                if(res==NULL)
                {
                    printf("Compilation Error ::  Varribale %s is not declared\n",$1);
                    exit(-1);
                }
                else if(res->data.type == 1 || res->data.type == 6)
                {
                    printf("Error :: You can't set a value to class/function");
                    exit(-1);
                }
                struct datatype tmp,tmp2;
                if(res->data.valtype == 2) tmp = make_datatype_int(res->data.intval);
                else if(res->data.valtype == 3) tmp = make_datatype_double(res->data.doubleval);
                else if(res->data.valtype == 4) tmp = make_datatype_char(res->data.strval);
                else tmp = make_datatype_int(0);
                tmp2 = evaluate(tmp,$3,"+");
                if(tmp2.type == 2){
                        int n = log10(tmp2.intval) + 1;
                        char *numberArray = calloc(n, sizeof(char));
                        sprintf(numberArray,"%ld",tmp2.intval);
                        setVal(&root,&last,$1,numberArray);
                        fprintf(infotext,"Value assigned :: %s = %d\n",$1,tmp2.intval);
                }
                else if(tmp2.type == 3){
                        char *numberArray = calloc(51,sizeof(char));
                        snprintf(numberArray,50,"%lf",tmp2.doubleval);
                        setVal(&root,&last,$1,numberArray);
                        fprintf(infotext,"Value assigned :: %s = %f\n",$1,tmp2.doubleval);
                }
                else{
                        setVal(&root,&last,$1,tmp2.strval);
                        fprintf(infotext,"Value assigned :: %s = %s\n",$1,tmp2.strval);
                }
            }
            | VARACCESS SUB_ASSIGN expression {
                struct ll_identifier* res = isDeclared(&root,$1);
                if(res==NULL)
                {
                    printf("Compilation Error ::  Varribale %s is not declared\n",$1);
                    exit(-1);
                }
                else if(res->data.type == 1 || res->data.type == 6)
                {
                    printf("Error :: You can't set a value to class/function");
                    exit(-1);
                }
                struct datatype tmp,tmp2;
                if(res->data.valtype == 2) tmp = make_datatype_int(res->data.intval);
                else if(res->data.valtype == 3) tmp = make_datatype_double(res->data.doubleval);
                else if(res->data.valtype == 4) tmp = make_datatype_char(res->data.strval);
                else tmp = make_datatype_int(0);
                tmp2 = evaluate(tmp,$3,"-");
                if(tmp2.type == 2){
                        int n = log10(tmp2.intval) + 1;
                        char *numberArray = calloc(n, sizeof(char));
                        sprintf(numberArray,"%ld",tmp2.intval);
                        setVal(&root,&last,$1,numberArray);
                        fprintf(infotext,"Value assigned :: %s = %d\n",$1,tmp2.intval);
                }
                else if(tmp2.type == 3){
                        char *numberArray = calloc(51,sizeof(char));
                        snprintf(numberArray,50,"%lf",tmp2.doubleval);
                        setVal(&root,&last,$1,numberArray);
                        fprintf(infotext,"Value assigned :: %s = %f\n",$1,tmp2.doubleval);
                }
                else{
                        setVal(&root,&last,$1,tmp2.strval);
                        fprintf(infotext,"Value assigned :: %s = %s\n",$1,tmp2.strval);
                }
            }
            | VARACCESS MUL_ASSIGN expression {
                struct ll_identifier* res = isDeclared(&root,$1);
                if(res==NULL)
                {
                    printf("Compilation Error ::  Varribale %s is not declared\n",$1);
                    exit(-1);
                }
                else if(res->data.type == 1 || res->data.type == 6)
                {
                    printf("Error :: You can't set a value to class/function");
                    exit(-1);
                }
                struct datatype tmp,tmp2;
                if(res->data.valtype == 2) tmp = make_datatype_int(res->data.intval);
                else if(res->data.valtype == 3) tmp = make_datatype_double(res->data.doubleval);
                else if(res->data.valtype == 4) tmp = make_datatype_char(res->data.strval);
                else tmp = make_datatype_int(0);
                tmp2 = evaluate(tmp,$3,"*");
                if(tmp2.type == 2){
                        int n = log10(tmp2.intval) + 1;
                        char *numberArray = calloc(n, sizeof(char));
                        sprintf(numberArray,"%ld",tmp2.intval);
                        setVal(&root,&last,$1,numberArray);
                        fprintf(infotext,"Value assigned :: %s = %d\n",$1,tmp2.intval);
                }
                else if(tmp2.type == 3){
                        char *numberArray = calloc(51,sizeof(char));
                        snprintf(numberArray,50,"%lf",tmp2.doubleval);
                        setVal(&root,&last,$1,numberArray);
                        fprintf(infotext,"Value assigned :: %s = %f\n",$1,tmp2.doubleval);
                }
                else{
                        setVal(&root,&last,$1,tmp2.strval);
                        fprintf(infotext,"Value assigned :: %s = %s\n",$1,tmp2.strval);
                }
            }
            | VARACCESS DIV_ASSIGN expression {
                struct ll_identifier* res = isDeclared(&root,$1);
                if(res==NULL)
                {
                    printf("Compilation Error ::  Varribale %s is not declared\n",$1);
                    exit(-1);
                }
                else if(res->data.type == 1 || res->data.type == 6)
                {
                    printf("Error :: You can't set a value to class/function");
                    exit(-1);
                }
                struct datatype tmp,tmp2;
                if(res->data.valtype == 2) tmp = make_datatype_int(res->data.intval);
                else if(res->data.valtype == 3) tmp = make_datatype_double(res->data.doubleval);
                else if(res->data.valtype == 4) tmp = make_datatype_char(res->data.strval);
                else tmp = make_datatype_int(0);
                tmp2 = evaluate(tmp,$3,"/");
                if(tmp2.type == 2){
                        int n = log10(tmp2.intval) + 1;
                        char *numberArray = calloc(n, sizeof(char));
                        sprintf(numberArray,"%ld",tmp2.intval);
                        setVal(&root,&last,$1,numberArray);
                        fprintf(infotext,"Value assigned :: %s = %d\n",$1,tmp2.intval);
                }
                else if(tmp2.type == 3){
                        char *numberArray = calloc(51,sizeof(char));
                        snprintf(numberArray,50,"%lf",tmp2.doubleval);
                        setVal(&root,&last,$1,numberArray);
                        fprintf(infotext,"Value assigned :: %s = %f\n",$1,tmp2.doubleval);
                }
                else{
                        setVal(&root,&last,$1,tmp2.strval);
                        fprintf(infotext,"Value assigned :: %s = %s\n",$1,tmp2.strval);
                }
            }
            | VARACCESS MOD_ASSIGN expression {
                struct ll_identifier* res = isDeclared(&root,$1);
                if(res==NULL)
                {
                    printf("Compilation Error ::  Varribale %s is not declared\n",$1);
                    exit(-1);
                }
                else if(res->data.type == 1 || res->data.type == 6)
                {
                    printf("Error :: You can't set a value to class/function");
                    exit(-1);
                }
                struct datatype tmp,tmp2;
                if(res->data.valtype == 2) tmp = make_datatype_int(res->data.intval);
                else if(res->data.valtype == 3) tmp = make_datatype_double(res->data.doubleval);
                else if(res->data.valtype == 4) tmp = make_datatype_char(res->data.strval);
                else tmp = make_datatype_int(0);
                tmp2 = evaluate(tmp,$3,"%");
                if(tmp2.type == 2){
                        int n = log10(tmp2.intval) + 1;
                        char *numberArray = calloc(n, sizeof(char));
                        sprintf(numberArray,"%ld",tmp2.intval);
                        setVal(&root,&last,$1,numberArray);
                        fprintf(infotext,"Value assigned :: %s = %d\n",$1,tmp2.intval);
                }
                else if(tmp2.type == 3){
                        char *numberArray = calloc(51,sizeof(char));
                        snprintf(numberArray,50,"%lf",tmp2.doubleval);
                        setVal(&root,&last,$1,numberArray);
                        fprintf(infotext,"Value assigned :: %s = %f\n",$1,tmp2.doubleval);
                }
                else{
                        setVal(&root,&last,$1,tmp2.strval);
                        fprintf(infotext,"Value assigned :: %s = %s\n",$1,tmp2.strval);
                }
            }
            | VARACCESS AND_ASSIGN expression {
                struct ll_identifier* res = isDeclared(&root,$1);
                if(res==NULL)
                {
                    printf("Compilation Error ::  Varribale %s is not declared\n",$1);
                    exit(-1);
                }
                else if(res->data.type == 1 || res->data.type == 6)
                {
                    printf("Error :: You can't set a value to class/function");
                    exit(-1);
                }
                struct datatype tmp,tmp2;
                if(res->data.valtype == 2) tmp = make_datatype_int(res->data.intval);
                else if(res->data.valtype == 3) tmp = make_datatype_double(res->data.doubleval);
                else if(res->data.valtype == 4) tmp = make_datatype_char(res->data.strval);
                else tmp = make_datatype_int(0);
                tmp2 = evaluate(tmp,$3,"&");
                if(tmp2.type == 2){
                        int n = log10(tmp2.intval) + 1;
                        char *numberArray = calloc(n, sizeof(char));
                        sprintf(numberArray,"%ld",tmp2.intval);
                        setVal(&root,&last,$1,numberArray);
                        fprintf(infotext,"Value assigned :: %s = %d\n",$1,tmp2.intval);
                }
                else if(tmp2.type == 3){
                        char *numberArray = calloc(51,sizeof(char));
                        snprintf(numberArray,50,"%lf",tmp2.doubleval);
                        setVal(&root,&last,$1,numberArray);
                        fprintf(infotext,"Value assigned :: %s = %f\n",$1,tmp2.doubleval);
                }
                else{
                        setVal(&root,&last,$1,tmp2.strval);
                        fprintf(infotext,"Value assigned :: %s = %s\n",$1,tmp2.strval);
                }
            }
            | VARACCESS XOR_ASSIGN expression {
                struct ll_identifier* res = isDeclared(&root,$1);
                if(res==NULL)
                {
                    printf("Compilation Error ::  Varribale %s is not declared\n",$1);
                    exit(-1);
                }
                else if(res->data.type == 1 || res->data.type == 6)
                {
                    printf("Error :: You can't set a value to class/function");
                    exit(-1);
                }
                struct datatype tmp,tmp2;
                if(res->data.valtype == 2) tmp = make_datatype_int(res->data.intval);
                else if(res->data.valtype == 3) tmp = make_datatype_double(res->data.doubleval);
                else if(res->data.valtype == 4) tmp = make_datatype_char(res->data.strval);
                else tmp = make_datatype_int(0);
                tmp2 = evaluate(tmp,$3,"^");
                if(tmp2.type == 2){
                        int n = log10(tmp2.intval) + 1;
                        char *numberArray = calloc(n, sizeof(char));
                        sprintf(numberArray,"%ld",tmp2.intval);
                        setVal(&root,&last,$1,numberArray);
                        fprintf(infotext,"Value assigned :: %s = %d\n",$1,tmp2.intval);
                }
                else if(tmp2.type == 3){
                        char *numberArray = calloc(51,sizeof(char));
                        snprintf(numberArray,50,"%lf",tmp2.doubleval);
                        setVal(&root,&last,$1,numberArray);
                        fprintf(infotext,"Value assigned :: %s = %f\n",$1,tmp2.doubleval);
                }
                else{
                        setVal(&root,&last,$1,tmp2.strval);
                        fprintf(infotext,"Value assigned :: %s = %s\n",$1,tmp2.strval);
                }
            }
            | VARACCESS OR_ASSIGN expression {
                struct ll_identifier* res = isDeclared(&root,$1);
                if(res==NULL)
                {
                    printf("Compilation Error ::  Varribale %s is not declared\n",$1);
                    exit(-1);
                }
                else if(res->data.type == 1 || res->data.type == 6)
                {
                    printf("Error :: You can't set a value to class/function");
                    exit(-1);
                }
                struct datatype tmp,tmp2;
                if(res->data.valtype == 2) tmp = make_datatype_int(res->data.intval);
                else if(res->data.valtype == 3) tmp = make_datatype_double(res->data.doubleval);
                else if(res->data.valtype == 4) tmp = make_datatype_char(res->data.strval);
                else tmp = make_datatype_int(0);
                tmp2 = evaluate(tmp,$3,"|");
                if(tmp2.type == 2){
                        int n = log10(tmp2.intval) + 1;
                        char *numberArray = calloc(n, sizeof(char));
                        sprintf(numberArray,"%ld",tmp2.intval);
                        setVal(&root,&last,$1,numberArray);
                        fprintf(infotext,"Value assigned :: %s = %d\n",$1,tmp2.intval);
                }
                else if(tmp2.type == 3){
                        char *numberArray = calloc(51,sizeof(char));
                        snprintf(numberArray,50,"%lf",tmp2.doubleval);
                        setVal(&root,&last,$1,numberArray);
                        fprintf(infotext,"Value assigned :: %s = %f\n",$1,tmp2.doubleval);
                }
                else{
                        setVal(&root,&last,$1,tmp2.strval);
                        fprintf(infotext,"Value assigned :: %s = %s\n",$1,tmp2.strval);
                }
            }
            ;
        
whilegrammer    : WHILE '(' expression ')' '{' statement '}' {
                    fprintf(infotext,"While loop executed with expression : ");
                    fprint_datatype($3,infotext);
                }
                ;
dowhilegrameer  : DO '{' statement '}' WHILE '(' expression ')' ';' {
                    fprintf(infotext,"Do While loop executed with expression : ");
                    fprint_datatype($7,infotext);
                }
printgrammer    : PRINT '(' {
                    fprintf(infotext,"PRINT :: ")
                } manyexprgm ')' ';'
                ;
manyexprgm      : expression {
                    fprint_datatype($1,infotext);
                } ',' manyexprgm
                | expression {
                    fprint_datatype($1,infotext);
                }
                ;
importgrammer   : IMPORT {
                    fprintf(infotext,"imported module :: ");
                } manyname ';'
                ;
manyname        : NAME ',' {
                    fprintf(infotext,"%s , ",$1);
                } manyname
                | NAME {
                    fprintf(infotext,"%s\n",$1);
                }
%%
extern char yytext[];
extern int column;
int yyerror(char *s){
    fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}