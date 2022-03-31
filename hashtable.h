/******************************************************
 * Name: Graziella Buitron
 * Coding 06
 * Purpose: To create a hash Table class/object with
 * our standard struct.
 *****************************************************/

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include "linkedlist.h"
#define HASHTABLESIZE 15

using std::cout;
using std::endl;

class Hashtable{

    public:
        Hashtable();
        ~Hashtable();
        bool insertEntry(int, string*);
        string getData(int);
        bool removeEntry(int);
        int getCount();
        void printTable();

    private:
        int hash(int);
        int count;
};

#endif //HASHTABLE_H


