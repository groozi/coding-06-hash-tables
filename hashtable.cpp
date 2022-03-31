/******************************************************
 * Name: Graziella Buitron
 * Coding 06
 * Purpose: To create a hash Table class/object with
 * our standard struct.
 *****************************************************/


#include "hashtable.h"

Hashtable::Hashtable(){
    count = 0;
    LinkedList hashtable[HASHTABLESIZE];
}

Hashtable::~Hashtable(){

}


bool Hashtable::insertEntry(int id, string *data){
    bool inserted = false;
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

}


int Hashtable::hash(int id){
    return id % HASHTABLESIZE;
}
