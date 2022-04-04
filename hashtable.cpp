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


//delete the if statement with the exists method call, getNode returns bool. use that
string Hashtable::getData(int id){
    string dataReturn;
    Data tempData;

    if (id > 0){
        int position = hash(id); 

        //gets data from node in linkedlist if list is not empty and getNode returns true(found the node)
        if(hashtable[position].getCount() != 0 && hashtable[position].getNode(id, &tempData)){
            dataReturn = tempData.data; 
        }else{
            dataReturn = "";
        }
    }else{
        dataReturn = "";
    }
    
    return dataReturn;
}

bool Hashtable::removeEntry(int id){
    bool removed = false;
    int position = hash(id);

    if (hashtable[position].deleteNode(id)){
        removed = true;
        count--;
    }
    return removed;
}

int Hashtable::getCount(){
    return count;
}

void Hashtable::printTable(){
    for (int i = 0; i < HASHTABLESIZE; i++){
       cout << "list at hashtable index " << i << ": ";
       hashtable[i].printList();
    }
}

int Hashtable::hash(int id){
    return id % HASHTABLESIZE;
}
