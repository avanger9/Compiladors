#!/bin/bash

if [ $1 == 1 ]; then
	antlr4 Asl.g4
	javac *.java
else
	rm *.java *.class
fi
