g++ -c -g -Wall -O2 -DNDEBUG -std=c++1y strdeque.cc -o strdeque.o
g++ -c -g -Wall -O2 -DNDEBUG -std=c++1y strdequeconst.cc -o strdequeconst.o
g++ -c -g -Wall -O2 -DNDEBUG -std=c++1y strdeque_test2a.cc -o strdeque_test2a.o
g++ -c -g -Wall -O2 -DNDEBUG -std=c++1y strdeque_test2b.cc -o strdeque_test2b.o
g++ strdeque_test2a.o strdeque.o strdequeconst.o -o strdeque_test2a
g++ strdeque_test2b.o strdeque.o strdequeconst.o -o strdeque_test2b
