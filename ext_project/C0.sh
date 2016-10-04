#!/bin/sh
make C0
echo "which kind of operation do you want to do?"
echo "1 for compiler .in file and run it."
echo "2 for run .Pcode file."
echo "3 for compiler .in file and run it"
read choose
if [ "$choose" -eq "1" ]; then
read filename
bin/C0 <test/$filename.in
mv test/wyc.Pcode test/$filename.Pcode
exit 0
elif [ "$choose" -eq "2" ]; then
read filename
./bin/C0interpret test/$filename.Pcode
exit 0
elif [ "$choose" -eq "3" ]; then
read filename
bin/C0 <test/$filename.in
mv test/wyc.Pcode test/$filename.Pcode
./bin/C0interpret test/$filename.Pcode
exit 0
else
echo "Wrong input, please input 1 or 2!"
cd ..
cd bin
./sh
fi
exit 0
