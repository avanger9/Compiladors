#!/bin/bash

antlr4 Asl.g4
javac *.java

prog="../examples/jpbasic_chkt_01.asl"
while true; do
	read -p "write 1 for -tree or 2 for -gui or 3 for exit: " i
	if [ $i == 1 ]; then
		grun Asl program -tree $prog
	elif [ $i == 2 ]; then
		grun Asl program -gui $prog
	else
		rm *.java *.interp *.tokens *.class
		exit
	fi		
done