#!/bin/bash


./asl $1 > tmp.t
../tvm/tvm tmp.t
rm tmp.t
