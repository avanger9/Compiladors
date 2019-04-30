#!/bin/bash

f="../examples/jp_chkt_18.asl"
cat -n $f
echo ""
echo "execute asl"
./asl $f

echo ""
echo "show err"
echo ""
f="../examples/jp_chkt_18.err"
cat -n $f

