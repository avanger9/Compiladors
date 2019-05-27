#!/bin/bash


./asl $1".asl" > tmp.t
../tvm/tvm tmp.t < $1".in"
rm tmp.t
