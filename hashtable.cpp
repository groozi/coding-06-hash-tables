/******************************************************
 * Name: Graziella Buitron
 * Coding 06
 * Purpose: To create a hash Table class/object with
 * our standard struct.
 *****************************************************/

#include "hashtable.h"

Hashtable::Hashtable(){
    count = 0;

    for (int i = 0; i < HASHTABLESIZE; i++){
        LinkedList newList;
        hashtable[i] = newList;
    }
}

Hashtable::~Hashtable(){
    for (int i = 0; i < HASHTABLESIZE; i++){
            hashtable[i].clearList();
    }
}

bool Hashtable::insertEntry(int id, string *data){
    bool inserted = false;
    
    if (id > 0 && *data != "/0"){
        int position = hash(id);

        if (hashtable[position].addNode(id, data)){
            inserted = true;
            count++;
        }
    }
    return inserted;
}

string Hashtable::getData(int){
    string data;
    return data;
}

bool Hashtable::removeEntry(int id){
    bool removed = false;
    return removed;
}

int Hashtable::getCount(){
    return count;
}

void Hashtable::printTable(){
    for (int i = 0; i < HASHTABLESIZE; i++){
       cout << "List at hashtable index " << i << ": ";
       hashtable[i].printList();
    }
    
}


int Hashtable::hash(int id){
    return id % HASHTABLESIZE;
}
