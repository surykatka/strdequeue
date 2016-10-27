g++ -c -Wall -O2 -std=c++1y strdeque.cc -o strdeque.o
g++ -c -Wall -O2 -std=c++1y strdequeconst.cc -o strdequeconst.o
gcc -c -Wall -O2 strdeque_test1.c -o strdeque_test1.o
g++ strdeque_test1.o strdeque.o strdequeconst.o -o strdeque_test1
