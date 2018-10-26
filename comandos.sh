#!/bin/bash

gcc -g -c CaixeiroTeste.c -o CaixeiroTeste.o
gcc -g -c caixeiro.c -o caixeiro.o
gcc -g -c combinatoria.c -o combinatoria.o
gcc CaixeiroTeste.o caixeiro.o combinatoria.o -o CaixeiroTeste
