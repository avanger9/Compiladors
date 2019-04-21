#!/bin/bash

echo "jpbasic_chech -> 1"
echo "jpbasic_genc  -> 2"
echo "jp_check      -> 3"
echo "jp_genc       -> 4"

read -p "num per seleccionar fitxer: " num
a=""

if [ $num = 1 ]; then
	a="jpbasic_chkt_0"
	read -p "num del fitxer [1-4]: " nm
	echo ""
	echo "[Writting Asl output]"
	echo ""
	./asl "../examples/"$a$nm".asl"
	echo ""
	echo "[Writting Err output]"
	echo ""
	cat "../examples/"$a$nm".err"

elif [ $num = 2 ]; then
	a="jpbasic_genc_0"
	read -p "num del fitxer [1-4]: " nm
	echo ""
	echo "[Writting Asl output]"
	echo ""
	./asl "../examples/"$a$nm".asl"

elif [ $num = 3 ]; then
	a="jp_chkt_"
	read -p "num del fitxer [01-18]: " nm
	echo "[Writting Asl output]"
	echo "..."
	./asl "../examples/"$a$nm".asl"
	echo "[Writting Err output]"
	echo "..."
	cat "../examples/"$a$nm".err"
else
	a="jp_genc_0"
	read -p "num del fitxer [1-10]: " nm
	echo ""
	echo "[Writting Asl output]"
	echo ""
	./asl "../examples/"$a$nm".asl"	
fi


