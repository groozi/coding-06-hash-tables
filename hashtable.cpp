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
        hashtable[i] = new LinkedList;
    }
}

Hashtable::~Hashtable(){
    for (int i = 0; i < HASHTABLESIZE; i++){
        if (hashtable[i]){
            delete hashtable[i];
        }
    }
}


bool Hashtable::insertEntry(int id, string *data){
    bool inserted = false;
    int position = hash(id);

    hashtable[position]->addNode(id, data);

    if ( hashtable[position]->addNode(id, data)){
        inserted = true;
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

    /*
    for (int i = 0; i < HASHTABLESIZE; i++){
        if (hashtable[i] != NULL){
            cout << "Hashtable bin " << i+1 << " contents: " << hashtable[i]->printList() << endl;
        }
        else {
            cout << "Hashtable bin " << i+1 << " is empty" << endl;
        }
    }
    */
}


int Hashtable::hash(int id){
    return id % HASHTABLESIZE;
}
