#!/bin/sh
make C0
bin/C0 <test/C0test20.in
mv test/wyc.Pcode test/C0test20.Pcode
./bin/C0interpret test/C0test20.Pcode
make cleanall
