#!/bin/bash

echo "BEGIN examples-initial/typecheck"
for f in ../examples/jpbasic_chkt_*.asl; do
    echo $(basename "$f")
    ./asl "$f" | egrep ^L > tmp.err
    diff tmp.err "${f/asl/err}"
    rm -f tmp.err
done
echo "END   examples-initial/typecheck"

echo ""
echo "BEGIN examples-full/typecheck"
for g in {1..9}; do
	f=../examples/jp_chkt_0$g.asl
    echo $(basename $f)
    ./asl $f | egrep ^L > tmp.err
    diff tmp.err ${f/asl/err}
    rm -f tmp.err
done

for g in {0..7}; do
	f=../examples/jp_chkt_1$g.asl
    echo $(basename $f)
    ./asl $f | egrep ^L > tmp.err
    diff tmp.err ${f/asl/err}
    rm -f tmp.err
done
echo "END   examples-full/typecheck"
