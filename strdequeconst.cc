//
// Created by bl on 22.10.16.
//

#include "strdequeconst.h"
#include "strdeque.h"


unsigned long emptystrdeque() {
    static const unsigned long empty_deque = strdeque_new();
    return empty_deque;
}