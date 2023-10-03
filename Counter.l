%{
	//	Bismillahir Rahmanir Rahim. 
    //	Every praise goes to ALLAH for our wellbeing.
    //	Code : Kazi Fahim Tahmid
	
    
    
    #include <bits/stdc++.h>    // Since g++ compiler also works with lex files so adding all headers like CP
	using namespace std;

	
	
    // creating function to systemOut each tokens
    void tokenPrinting(string type, string lexeme) {
        cout << "input : " << lexeme << "\n";
		cout << "token/type : " << type << "\n\n\n";
	}

    
    
    // ------   init counters   -----
    int total_keywords = 0;
	int total_identifiers = 0;
	int total_statements = 0;
    int total_lineNumber = 0;
	stack<pair<int,char>> valid_bracket;
	int nested_layer = 0;
	int max_nested_layers = 0;


    string fahim; // storing yytext

    
    // -----    Delimiter   -----
    // \n or endl
    // to write multiple statements without invoking \n we use ;


%}

singleline			        ("//")[^\n]*
multiline			        ("/\*").*?("\*/")

identifier   		        [a-zA-Z_][a-zA-Z_0-9]{0,31}
user_datatype   	        ("integer"|"decimal"|"char"|"string"|"binary")
string     			        [\"].*[\"]
integer    			        [\+\-]?[0-9]+
decimal     			    ({integer}([\.][0-9]+)?(e{integer})|{integer}([\.][0-9]+))
binary     			        ("false"|"true")
char  			            ("'\\n'"|[\'][^\n][\'])
returntype			        ({user_datatype}|"void")
back              	        ("return")


assignment_op 				=
assignment_init             (\+=|\-=|\*=|\/=|%=|&=|\|=|\^=|<<=|>>=)
math_op    			        (\+|\-|\*|\/|%)
comparison_op               ("is"|"is not"|<|>|<=|>=)
logical_op			        ("or"|"and"|"xor"|"&&"|"||"|"^")
bitwise_op 			        (&|\|\^|>>|<<)
indec_op 			        ("++"|"--")




iff            		        ("if")[ ]*[\(].*[\)][ ]*[\{].*[\}]
elseif            	        ("else if")[ ]*[\(].*[\)][ ]*[\{].*[\}]
else            	        ("else")[ ]*[\{].*[\}]
if_condition		        {iff}[ ]*{elseif}*?{else}?
iff_condition		        ("if"|"else if"|"else")



for 				        ("for")[ ]{identifier}[ ]("in")[ ]{identifier}
while 				        ("while")
forloop   			        ("for")[ ]{identifier}[ ]("in")[ ]{identifier}[ ]*[\{].*[\}]
whileloop			        ("while")[ ]*[\(].*[\)][ ]*[\{].*[\}]
smash				        ("break")
skip	          	        ("continue")
niyeAshsi	          	    ("import")
header				        ("stdio.h"|"stdlib.h"|"math.h"|"string.h"|"vector.h"|"bits/stdc++.h")

routine				        ("function")[ ]{identifier}[ ]*[\(].*[\)][ ]*:[ ]*{returntype}[ ]*[\{].*[\}]
function 			        ("function")[ ]{identifier}[ ]*[\(].*[\)][ ]*:[ ]*{returntype}


LP 					        [\(]
RP                          [\)]
CURL				        [\{]
CURR				        [\}]
newline        		        [\n]
tab        		            [\t]
comma				        ,
semicolon			        [";"]



%%


{singleline} {
	fahim = yytext; 
	tokenPrinting("singleline comment", fahim);
}

{multiline} {
	fahim = yytext; 
	tokenPrinting("multiline comment", fahim);
}

{header}   {
	fahim = yytext; tokenPrinting("Header File",  fahim);
}

{skip}|{back}|{smash}|{niyeAshsi}|"System.inf"|"System.outf" {
	fahim = yytext; tokenPrinting("keyword", fahim); 
	total_keywords++;
}

{newline} {
	fahim = yytext; 
	tokenPrinting("end of statement", "\\n"); 
	total_statements++;
	total_lineNumber++;
}

{tab} {
	//fahim = yytext; 
	//tokenPrinting("A tab of Space for Indentation", "\\t"); 
}

{semicolon} {
	fahim = yytext;
	tokenPrinting("end of statement", fahim);
	total_statements++;
}

{comma} {
	fahim = yytext; 
	tokenPrinting("comma operator",  fahim);
}

{user_datatype} {
	fahim = yytext; 
	tokenPrinting("datatype",  fahim); 
	total_keywords++;
}

{binary}   {
	fahim = yytext; tokenPrinting("binary",  fahim);
    total_keywords++;
}





{logical_op} {
	fahim = yytext; 
	tokenPrinting("logical_operator",  fahim);
}

{comparison_op} {
	fahim = yytext; 
	tokenPrinting("comparison operator",  fahim);
}



{LP} {
	fahim = yytext;
	tokenPrinting("left paranthesis", fahim);
	valid_bracket.push({total_lineNumber + 1, '('});
}

{RP} {
	fahim = yytext;
	tokenPrinting("right parenthesis", fahim);
	if (valid_bracket.size() && valid_bracket.top().second == '(') {
		valid_bracket.pop();
	}
	else {
		valid_bracket.push({total_lineNumber + 1, ')'});
	}
}

{CURL} {
	fahim = yytext;
	tokenPrinting("left curly bracket", fahim);
	valid_bracket.push({total_lineNumber + 1, '{'});
	nested_layer++;
	max_nested_layers = max(max_nested_layers, nested_layer);
}

{CURR} {
	fahim = yytext;
	tokenPrinting("right curly bracket", fahim);
	if (valid_bracket.size() && valid_bracket.top().second == '{') {
		valid_bracket.pop();
		nested_layer--;
	}
	else {
		valid_bracket.push({total_lineNumber + 1, '}'});
	}
}

{iff_condition}	{
	fahim = yytext; 
	tokenPrinting("if condition", fahim);
}

{for} {
	fahim = yytext; 
	tokenPrinting("for loop", fahim);
}

{while}	{
	fahim = yytext; 
	tokenPrinting("while loop", fahim);
}

{function} {
	fahim = yytext; 
	tokenPrinting("subroutine", fahim);
}

{identifier} {
	fahim = yytext; 
	tokenPrinting("identifier",  fahim); 
	total_identifiers++;
}

{string} {
	fahim = yytext; 
	tokenPrinting("string",  fahim);
}

{integer} {
	fahim = yytext; 
	tokenPrinting("integer",  fahim);
}

{decimal} {
	fahim = yytext;
	tokenPrinting("decimal",  fahim);
}

{char} {
	fahim = yytext; 
	tokenPrinting("char",  fahim);
}

{math_op} {
	fahim = yytext; 
	tokenPrinting("math_op",  fahim);
}

{assignment_op} {
	fahim = yytext; 
	tokenPrinting("assignment operator",  fahim);
}

{assignment_init} {
	fahim = yytext; 
	tokenPrinting("operation with assignment",  fahim);
}

{bitwise_op} {
	fahim = yytext; 
	tokenPrinting("bitwise operator",  fahim);
}

{indec_op} {
	fahim = yytext; 
	tokenPrinting("indec_operator",  fahim);
}





[ ] {

}

. {
	fahim = yytext;
	tokenPrinting("unrecognized", fahim);
}

%%

int yywrap()
{
	return 1;
}



void whiteSpaceRemover(const std::string Kazi) {
    std::ifstream inputFile(Kazi);
    if (!inputFile) {
        std::cerr << "Error: No input file found. Create one First" << std::endl;
        return;
    }
    std::string final_string;
    std::string per_line;
    while (std::getline(inputFile, per_line)) {
        final_string += per_line + " ";
    }
    inputFile.close();
    std::ofstream outputFile("hudai");
    if (!outputFile) {
        std::cerr << "Error: Corrupted Output file System" << std::endl;
        return;
    }
    outputFile << final_string;
    outputFile.close();
}

int main()
{
    whiteSpaceRemover("input2.txt");
	yyin = freopen("input2.txt", "r", stdin);
	yyout = freopen("output2.txt", "w", stdout);
	cout << "Welcome To Kazi's lex tokenization. Also hey The North Remembers! \n---------------------------------------------------------------------- \n\n";
	yylex();

	if (valid_bracket.empty()) {
		cout << "okay! all brackets are balanced\n";
		cout << "okay! all blocks are balanced\n";
		cout << "Maximum Nested Layer Depth of my program is : " << max_nested_layers << "\n";
	}

	while (valid_bracket.size()) {
		cout << "Unexpected " << valid_bracket.top().second << " in line " << valid_bracket.top().first << "\n";
		valid_bracket.pop();
	}

	cout << "Total identifiers found: " << total_identifiers << "\n";
	cout << "Total keywords found   : " << total_keywords << "\n";
	cout << "Total statements found: " << total_statements << "\n";
	cout << "Total Lines found: " << total_lineNumber << "\n";

	return 0;
}