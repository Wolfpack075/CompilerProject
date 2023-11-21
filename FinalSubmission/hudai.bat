bison -d kazi.y
flex kazi.l
gcc kazi.tab.c lex.yy.c -o kazi
kazi