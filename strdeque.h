//
// Created by bl on 22.10.16.
//


#ifndef INC_2_STRDEQUE_H
#define INC_2_STRDEQUE_H
#ifndef STDLIB_H
#define STDLIB_H
#include <stdlib.h>
#endif

extern "C" {

unsigned long strdeque_new();
void strdeque_delete(unsigned long id);
size_t strdeque_size(unsigned long id);
void strdeque_insert_at(unsigned long id, size_t pos, const char *value);
void strdeque_remove_at(unsigned long id, size_t pos);
const char *strdeque_get_at(unsigned long id, size_t pos);
void strdeque_clear(unsigned long id);
int strdeque_comp(unsigned long id1, unsigned long id2);

};

#endif //INC_2_STRDEQUE_H
