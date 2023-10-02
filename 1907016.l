%{
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












