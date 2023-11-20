
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* "%code requires" blocks.  */

/* Line 1676 of yacc.c  */
#line 36 "kazi.y"

    #ifndef __DT__
    #define __DT__
    struct __DT__ datatype {
        int type;
        char *strval;
        int intval;
        double doubleval;
    };
    #endif



/* Line 1676 of yacc.c  */
#line 54 "kazi.tab.h"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NAME = 258,
     VARACCESS = 259,
     NUM = 260,
     STR = 261,
     FUNC = 262,
     CLASS = 263,
     INIT = 264,
     INT = 265,
     DOUBLE = 266,
     STRING = 267,
     CONST = 268,
     VOID = 269,
     VAR = 270,
     ELSEIF = 271,
     ELSE = 272,
     IF = 273,
     SWITCH = 274,
     CASE = 275,
     def_ault = 276,
     FOR = 277,
     WHILE = 278,
     DO = 279,
     CONTINUE = 280,
     RETURN = 281,
     RIGHT_ASSIGN = 282,
     LEFT_ASSIGN = 283,
     ADD_ASSIGN = 284,
     SUB_ASSIGN = 285,
     MUL_ASSIGN = 286,
     DIV_ASSIGN = 287,
     MOD_ASSIGN = 288,
     AND_ASSIGN = 289,
     XOR_ASSIGN = 290,
     OR_ASSIGN = 291,
     RIGHT_OP = 292,
     LEFT_OP = 293,
     INC_OP = 294,
     DEC_OP = 295,
     PTR_OP = 296,
     AND_OP = 297,
     OR_OP = 298,
     LE_OP = 299,
     GE_OP = 300,
     EQ_OP = 301,
     NE_OP = 302,
     PRINT = 303,
     SIN = 304,
     TAN = 305,
     LOG = 306,
     LOG10 = 307,
     COS = 308,
     ACOS = 309,
     ASIN = 310,
     ATAN = 311,
     GCD = 312,
     LCM = 313,
     POW = 314,
     IMPORT = 315
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 1676 of yacc.c  */
#line 47 "kazi.y"

    char text[1009];
    struct datatype val;



/* Line 1676 of yacc.c  */
#line 138 "kazi.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


