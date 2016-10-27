//
// Created by bl on 22.10.16.
//

#include "strdequeconst.h"
#include "strdeque.h"
#include <iostream>

using namespace std;
#ifndef NDEBUG
    const bool debug = true;
#else
    const bool debug = false;
#endif

unsigned long emptystrdeque() {
    if (debug)
        cerr << "emptystrdeque\n";
    static const unsigned long empty_deque = strdeque_new();
    return empty_deque;
}
