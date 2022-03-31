/**********************************************************
 * Name: Graziella Buitron
 * Coding 05
 * Purpose: To create a fully functional doubly linked list
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