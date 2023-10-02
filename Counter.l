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