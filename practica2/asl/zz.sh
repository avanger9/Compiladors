#!/bin/bash

echo ""
echo "BEGIN examples-full/typecheck"
f="../examples/jp_chkt_05.asl"
er="../examples/jp_chkt_05.err"

echo "[step 1] execute... "
echo ""
./asl $f
echo ""
echo "[step 2] show .err"
echo ""
cat $er
echo ""

cat -n $f
