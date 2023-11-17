#!/bin/bash

lex 1907016.l
gcc lex.yy.c 
a.exe

lex Counter.l
g++ lex.yy.c
a.exe
