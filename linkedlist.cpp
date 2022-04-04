/**********************************************************
 * Name: Graziella Buitron
 * Coding 06
 * Purpose: To create a hash Table class/object with
 * our standard struct.
 *********************************************************/

#include "linkedlist.h"

LinkedList::LinkedList(){
    head = NULL;
}

LinkedList::~LinkedList(){
    clearList();
}

bool LinkedList::addNode(int id , string *data){
    bool added;

    if (id > 0 && *data != "/0"){
        Node* position = head;
        Node **nodeHolder;

        //if list is empty or if id of new node is less than position's id add a new head
        if (position == NULL || id < position->data.id){
            addHead(id, data, position, *nodeHolder);
            added = true;
        }else{
            //search for place to add node
            while (id > position->data.id && position->next != NULL){
                position = position->next;
            }
            if (id == position->data.id){
                added = false;
            //if id is greater than position's id and we ARE at the end of the list, add a new tail
            }else if(id > position->data.id && position->next == NULL){
                addTail(id, data, position, *nodeHolder);
                added = true;
            }else{
                //in any other case we add to middle of the list
                addMiddle(id, data, position, *nodeHolder);
                added = true;
            }
        }
    }else{
        added = false;
    } 
    return added;
}

bool LinkedList::deleteNode(int id){
    Node* position = head;
    bool deleted; 

    if (position == NULL){
        deleted = false;
    }else{
        while (id != position->data.id && position->next != NULL){
            position = position->next;
        }
        if(id != position->data.id){
            deleted = false;

        //if deleting the head and it's the only node in the list
        }else if(id == position->data.id && position->prev == NULL && position->next == NULL){
            delete(position);
            head = NULL;
            deleted = true;
        }else if (position->prev == NULL){
            head = position->next;
            position->next->prev = NULL;
            delete(position);
            deleted = true;
        //deleting the tail    
        }else if(position->next == NULL){
            position->prev->next = NULL;
            delete(position);
            deleted = true;
        }else if (position->next != NULL){
            position->prev->next = position->next;
            position->next->prev = position->prev;
            delete(position);
            deleted = true;
        }
    }
    return deleted;
}

bool LinkedList::getNode(int id, Data* dataStruct){
    Node* position = head;
    bool gotNode;

    if (id == position->data.id){
        dataStruct->id = position->data.id;
        dataStruct->data = position->data.data;
        gotNode = true;
    } else {
        while(id != position->data.id && position->next!= NULL){
            position = position->next;
        }
        if (id == position->data.id){
            dataStruct->id = position->data.id;
            dataStruct->data = position->data.data;
            gotNode = true;
        } 
        else{
            dataStruct->id = -1;
            dataStruct->data = "";
            gotNode = false;
        }
    }
    return gotNode;
}

void LinkedList::printList(bool backward){
    Node* position = head;

    if(position == NULL){
        std::cout << "list is empty" << std::endl;
    }else if (backward == true){
        while(position->next != NULL){
            position = position->next;
        }
        while (position){
            std::cout << position->data.id;

            if(position->next != NULL){
                std::cout << " -> ";
            }
            position = position->prev;
        }
        std::cout << std::endl;
    }else {
        while (position){
            std::cout << position->data.id;
            if(position->next != NULL){
                std::cout << " -> ";
            } 
            position = position->next;
        }
        std::cout << std::endl;
    }
}

int LinkedList::getCount(){
    Node* position = head;
    int count = 0;

    if (position != NULL){
       while(position){
        count++;
        position = position->next;
        } 
    }
    return count;
}

bool LinkedList::exists(int id){
    bool nodeFound; 
    Node* position = head;

    if (id == position->data.id){
        nodeFound = true;
    }else{
        while(id != position->data.id && position->next!= NULL){
            position = position->next;
        }
        if (id == position->data.id){
            nodeFound = true;
        }else{
            nodeFound = false;
        }
    }
    return nodeFound;
}

bool LinkedList::clearList(){
    bool listCleared = false;

    if (head != NULL){
        Node *position = head;

        while(position != NULL){
            head = position->next;
            delete position;
            position = head;
        }
        head = NULL;
        listCleared = true;
    }
   
    return listCleared;
}

void LinkedList::prepNode(int id, string *data, Node** nodeHolder){
    Node *newNode = new Node;
    newNode->data.id = id;
    newNode->data.data = *data;
    *nodeHolder = newNode;
}

void LinkedList::addHead(int id, string *data, Node* position, Node* nodeHolder){
    prepNode(id, data, &nodeHolder);

    if (position == NULL){
        nodeHolder->prev = NULL;
        nodeHolder->next = NULL;
    } else{
        nodeHolder->prev = NULL;
        nodeHolder->next = position;
        position->prev = nodeHolder;
    }
    head = nodeHolder;
}

void LinkedList::addTail(int id, string *data, Node* position, Node* nodeHolder){
    prepNode(id, data, &nodeHolder);
    nodeHolder->next = NULL;
    nodeHolder->prev = position;
    position->next = nodeHolder;
}

void LinkedList::addMiddle(int id, string* data, Node* position, Node* nodeHolder){
    prepNode(id, data, &nodeHolder);
    nodeHolder->next = position;
    nodeHolder->prev = position->prev;
    position->prev->next = nodeHolder;
    position->prev = nodeHolder;
}