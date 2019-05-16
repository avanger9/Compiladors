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

for g in {0..8}; do
	f=../examples/jp_chkt_1$g.asl
    echo $(basename $f)
    ./asl $f | egrep ^L > tmp.err
    diff tmp.err ${f/asl/err}
    rm -f tmp.err
done
echo "END   examples-full/typecheck"

echo ""
echo "BEGIN examples-initial/codegen"
for f in ../examples/jpbasic_genc_*.asl; do
    echo $(basename $f)
    ./asl $f | egrep -v '^\(' > tmp.t
    diff tmp.t ${f/asl/t}
    rm -f tmp.t
done
echo "END   examples-initial/codegen"

echo ""
echo "BEGIN examples-full/execution"
for g in {1..9}; do
    f=../examples/jp_genc_0$g.asl
    echo $(basename "$f")
    ./asl "$f" > tmp.t
    ../tvm/tvm tmp.t < "${f/asl/in}" > tmp.out
    diff tmp.out "${f/asl/out}"
    rm -f tmp.t tmp.out
done
echo "END   examples-full/execution"
