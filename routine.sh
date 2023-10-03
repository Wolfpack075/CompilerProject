#!/bin/bash

lex 1907016.l
gcc lex.yy.c 
./a.out

lex Counter.l
g++ lex.yy.c
./a.out
