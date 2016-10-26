//
// Created by bl on 22.10.16.
//

#include "strdeque.h"
#include "strdequeconst.h"
#include <deque>
#include <map>
#include <assert.h>
#include <iostream>


#ifndef DNDEBUG
const bool debug = true;
#else
const bool debug = false;
#endif

using namespace std;

namespace {
    map<unsigned long, deque<const char *>> &get_dequeues_map() {
        static map<unsigned long, deque<const char *> > dequeues_map;
        return dequeues_map;
    }


    unsigned long get_a_new_key() {
        static unsigned long last_key = 1;
        while (get_dequeues_map().count(last_key) == 1)
            last_key++;
        assert(last_key == 0);
        return last_key++;
    }


    deque<const char *> &get_strdeque(unsigned long id) {
        map<unsigned long, deque<const char *> >::iterator it;
        it = get_dequeues_map().find(id);
        if (it != get_dequeues_map().end()) {
            return get<1>(*it);
        }
        deque<const char *> *ret = NULL;
        return *ret;
    }
}

extern "C" {
unsigned long strdeque_new() {
    if (debug)
        cerr << "strdeque_new()\n";
    unsigned long key = get_a_new_key();
    get_dequeues_map()[key] = deque<const char *>();
    if (debug)
        cerr << "strdeque_new: deque " << key << " created\n";
    return key;
}


void strdeque_delete(unsigned long id) {
    if (id == emptystrdeque()) {
        if (debug) {
            cerr << "strdeque_delete: attempt to delete the Empty Deque)\n";
        }
    }
    else {
        map<unsigned long, deque<const char *> >::iterator it;
        it = get_dequeues_map().find(id);
        if (it != get_dequeues_map().end()) {
            get_dequeues_map().erase(it);
            if (debug) {
                cerr << "strdeque_delete: deque " << id << " deleted\n";
            }
        }
        else if (debug) {
            cerr << "strdeque_delete: deque " << id << " dose not exist\n";
        }
    }
}


size_t strdeque_size(unsigned long id) {
    deque<const char *> *dq = &get_strdeque(id);
    if (dq != NULL) {
        if (debug) {
            if (id == emptystrdeque()) {
                cerr << "strdeque_size: the Empty Deque contain " << dq->size() << "elements\n";
            }
            else {
                cerr << "strdeque_size: deque " << id << " consist " << dq->size() << " elements\n";
            }
        }
        return dq->size();
    }
    if (debug) {
        cerr << "strdeque_size: deque " << id << " dose not exist\n";
    }
    return 0;
}


void strdeque_insert_at(unsigned long id, size_t pos, const char *value) {
    if (id == emptystrdeque()) {
        if (debug) {
            cerr << "strdeque_insert_at: attempt to insert into the Empty Deque\n";
        }
    }
    else if (value != NULL) {
        deque<const char *> *dq = &get_strdeque(id);
        if (dq != NULL) {
            if (pos >= dq->size()) {
                dq->push_back(value);
                if (debug) {
                    cerr << "strdeque_insert_at: deque " << id << ", element " << value <<
                    " inserted at the end of deque\n";
                }
            }
            else {
                deque<const char *>::iterator deq_it = dq->begin();
                deq_it += pos;
                dq->insert(deq_it, value);
                if (debug) {
                    cerr << "strdeque_insert_at: deque " << id << ", element " << value << " inserted at " << pos <<
                    "\n";
                }
            }
        }
        else if (debug) {
            cerr << "strdeque_insert_at: deque " << id << " does not exist\n";
        }
    }
    else if (debug) {
        cerr << "strdeque_insert_at: attempt to insert value = NULL\n";
    }
}


void strdeque_remove_at(unsigned long id, size_t pos) {
    if (id == emptystrdeque()) {
        if (debug) {
            cerr << "strdeque_remove_at: attept to remove from the Empty deque\n";
        }
    }
    else {
        deque<const char *> *dq = &get_strdeque(id);
        if (dq != NULL) {
            if (pos < dq->size()) {
                deque<const char *>::iterator deq_it;
                deq_it += pos;
                dq->erase(deq_it);
                if (debug) {
                    cerr << "strdeque_remove_at: deque " << id << ", element at " << pos << " removed\n";
                }
            }
            else if (debug) {
                cerr << "strdeque_remove_at: deque " << id << "does not contain element at " << pos << "\n";
            }
        }
        else if (debug) {
            cerr << "strdeque_remove_at: deque " << id << "does not exist\n";
        }
    }
}

const char *strdeque_get_at(unsigned long id, size_t pos) {
    if (id == emptystrdeque()) {
        if (debug) {
            cerr << "strdeque_get_at: the Empty Deque does not contain any elements\n";
        }
    }
    else {
        deque<const char *> *dq = &get_strdeque(id);
        if (dq != NULL) {
            if (pos < dq->size()) {
                if (debug) {
                    cerr << "strdeque_get_at: deque " << id << ", element at " << pos << " is " << dq->at(pos) << "\n";
                }
                return dq->at(pos);
            }
            else if (debug) {
                cerr << "strdeque_get_at: deque " << id << "does not contain an element at " << pos << "\n";
            }
        }
        else if (debug) {
            cerr << "strdeque_get_at: deque " << id << " does not exist\n";
        }
    }
    return NULL;
}

void strdeque_clear(unsigned long id) {
    if (id == emptystrdeque()) {
        if (debug) {
            cerr << "strdeque_clear: attempt to clear the Empty Deque\n";
        }
    }
    else {
        deque<const char *> *dq = &get_strdeque(id);
        if (dq != NULL) {
            dq->clear();
            if (debug) {
                cerr << "strdeque_clear: deque " << id << " was cleared\n";
            }
        }
        else if (debug) {
            cerr << "strdeque_clear: deque " << id << " do not exist\n";
        }
    }
}


int strdeque_comp(unsigned long id1, unsigned long id2) {
    deque<const char *> *dq1 = &get_strdeque(id1);
    if (dq1 == NULL) {
        if (debug) {
            cerr << "strdeque_comp: deque " << id1 << " does not exist\n";
        }
    }
    deque<const char *> *dq2 = &get_strdeque(id2);
    if (dq2 == NULL) {
        if (debug) {
            cerr << "strdeque_comp: deque " << id2 << " does not exist\n";
        }
    }
    if (debug) {
        cerr << "strdeque_comp: result of comparing deque " << id1 << " and deque " << id2 << " is ";
    }
    if (dq1 == dq2) {
        if (debug) {
            cerr << "0\n";
        }
        return 0;
    }
    if (dq1 < dq2) {
        if (debug) {
            cerr << "-1\n";
        }
        return -1;
    }
    // dq1 > dq2
    if (debug) {
        cerr << "1\n";
    }
    return 1;
}
};