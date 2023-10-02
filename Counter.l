%{
	//	Bismillahir Rahmanir Rahim. 
    //	Every praise goes to ALLAH for our wellbeing.
    //	Code : Kazi Fahim Tahmid
	
    
    
    #include <bits/stdc++.h>    // Since g++ compiler also works with lex files so adding all headers like CP
	using namespace std;

	
	
    // creating function to systemOut each tokens
    void tokenPrinting(string type, string lexeme) {
        cout << "input : " << lexeme << "\n";
		cout << "token : " << type << "\n\n\n";
	}

    
    
    // ------   init counters   -----
    int total_keywords = 0;
	int total_identifiers = 0;
	int total_statements = 0;


    string fahim; // storing yytext

    
    // -----    Delimiter   -----
    // \n or endl
    // to write multiple statements without invoking \n we use ;


%}

single_line_comment			("//")[^\n]*
multiple_line_comment	    ("/\*").*?("\*/")
back              	        ("return")
returntype			        ({datatype}|"void")

identifier   		        [a-zA-Z_][a-zA-Z_0-9]{0,31}
user_datatype   			("integer"|"number"|"character"|"string"|"binary")
string     			        [\"].*[\"]
integer    			        [\+\-]?[0-9]+
decimal     			    ({integer}([\.]{integer})?(e[\+\-]?{integer})|{integer}([\.]{integer}))
binary     			        ("false"|"true")
char  			            ("'\\n'"|[\'][^\n][\'])


assignment_op 				=
assignment_init             (\+=|\-=|\*=|\/=|%=|&=|\|=|\^=|<<=|>>=)
math_op    			        (\+|\-|\*|\/|%)
indec_op 			        ("++"|"--")
logical_op			        ("or"|"and"|"xor")
comparison_op               ("is"|"is not"|<|>|<=|>=)
bitwise_op 			        (&|\|\^|>>|<<)

iff            		        ("if")[ ]*[\(].*[\)][ ]*[\{].*[\}]
elseif            	        ("else if")[ ]*[\(].*[\)][ ]*[\{].*[\}]
else            	        ("else")[ ]*[\{].*[\}]
if_condition		        {iff}[ ]*{elseif}*?{else}?

forloop   			        ("for")[ ]{identifier}[ ]("in")[ ]{identifier}[ ]*[\{].*[\}]
whileloop			        ("while")[ ]*[\(].*[\)][ ]*[\{].*[\}]
stop				        ("break")
skip	          	        ("continue")
func_call				    ("function")[ ]{identifier}[ ]*[\(].*[\)][ ]*:[ ]*{returntype}[ ]*[\{].*[\}]
eof        			        ([\n]|";")
comma				        ,