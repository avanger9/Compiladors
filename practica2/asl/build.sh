#!/bin/bash

make antlr

sleep 1

make -j

sleep 1

make realclean
