echo "=======Start======="
date
echo My machine has this many processors
sysctl -n hw.ncpu # this is for Mac machines
echo Generating 1000000 random numbers
sleep 1
./generate 1000000 100000 999999 # you have to write generate.cpp
sleep 1
echo Starting system sort
sleep 1
{ time sort numbers.dat > systemsort.out; } 2>> sortrace.log
sleep 1
echo Starting my sort
sleep 1
{ time ./mysort numbers.dat > mysort.out; } 2>> sortrace.log
sleep 1
ls -l systemsort.out
ls -l mysort.out
echo Comparing systemsort.out to mysort.out
diff systemsort.out mysort.out 2>> sortrace.log
echo All done
echo "=======End======="
date