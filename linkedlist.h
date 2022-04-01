/**********************************************************
 * Name: Graziella Buitron
 * Coding 06
 * Purpose: To create a hash Table class/object with
 * our standard struct.
 *********************************************************/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "data.h"
#include <iostream>

class LinkedList {

public:

    LinkedList();
    ~LinkedList();
    bool addNode(int, string*);
    bool deleteNode(int); 
    bool getNode(int, Data*); 
    void printList(bool = false);
    int getCount();
    bool clearList();
    bool exists(int);

private:
    Node *head;

    void prepNode(int, string*, Node**);
    void addHead(int, string*, Node*, Node*);
    void addTail(int, string*, Node*, Node*);
    void addMiddle(int, string*, Node*, Node*);
};

#endif //LINKEDLIST_H