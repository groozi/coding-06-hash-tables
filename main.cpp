/******************************************************
 * Name: Graziella Buitron
 * Coding 06
 * Purpose: To create a hash Table class/object with
 * our standard struct.
 *****************************************************/

#include "main.h"

int main() {
    //seed the rand function
    srand(time(NULL));

    /*
     * This code makes test data of 6 - 25 entries
     * Note this guarantees at least one non unique id and one bad id
     * Do not modify this code from here to the next comment telling
     * you to "START HERE"
     */
    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];
    
    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize-2] = ids[testdatasize-3];
    strs[testdatasize-2] = "known duplicate";
    ids[testdatasize-1] = - 1;
    strs[testdatasize-1] = "known bad";
    
    /*
     * Show test data
     */
    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;

    /*
     * Now you have two parallel arrays with ids and strings for test data.
     * START HERE and create your hash table and use the test data to show
     * it works.
     */
    
    // create your hash table object here
    cout << "creating the hashtable.." << endl;
    Hashtable hashtable;
    cout << "hashtable created" << endl << endl;
    
    // show it is empty by calling getCount and printTable
    cout << "checking the current hashtable..." << endl;
    cout << "currently " << hashtable.getCount() << " entries in table" << endl << endl;
    cout << "printing the table... " << endl;
    hashtable.printTable();
    cout << endl;
    
    // try and put ALL the test data into the table and show what happens
    cout << "inserting testdata into the table... " << endl;
     for (int i = 0; i < testdatasize; i++){
        cout << "adding " << ids[i] << ": " << strs[i] << ".. ";
        if (hashtable.insertEntry(ids[i], &strs[i])){
            cout << "added successfully" << endl;
        }else {
            cout << "add failed" << endl;
        }   
    }
    cout << endl;

    cout << "printing the table... " << endl;
    hashtable.printTable();
    cout << endl;
    cout << "currently " << hashtable.getCount() << " entries in hashtable" << endl << endl;

    // continue using and testing your table, add and remove data,
    // do whatever it takes to full test your object and prove it
    // is robust and can handle all use cases.

    //TESTING GETDATA
    cout << "testing getData with random id's from test data..." << endl;
    int randomIndex;  

    for (int i = 0; i < testdatasize; i++){
        randomIndex = rand() % testdatasize;
        cout << "getting " << ids[randomIndex] << "..";

        if (hashtable.getData(ids[randomIndex]) != ""){
            cout << " found: " << hashtable.getData(ids[randomIndex]) << endl;
        }
        else {
            cout << " not found" << endl;
        }
    }
    cout << endl;

    cout << "testing getData with random id's from 0 to MAXID..." << endl;
    int randId;

    for (int i = 0; i < testdatasize; i++){
        randId = rand() % MAXID;
        cout << "getting " << randId << ".. ";

        if(hashtable.getData((randId)) != ""){
            cout << "found: " << hashtable.getData(randId) << endl;
        }
        else{
            cout << "not found" << endl;
        }
    }
    cout << endl;

    cout << "testing removeEntry with random id's from testdata..." << endl; 

    for (int i = 0; i < testdatasize; i++){
        randomIndex = rand() % testdatasize;
        cout << "removing " << ids[randomIndex] << ".. ";

        if (hashtable.removeEntry(ids[randomIndex])){
            cout << "remove successful" << endl;
        }
        else {
            cout << "remove failed" << endl;
        }
    }

        cout << endl;

    cout << "checking the current hashtable..." << endl;
    cout << "currently " << hashtable.getCount() << " entries in table" << endl << endl;
  
    cout << endl;

    cout << "testing removeEntry with random id's from 0 to MAXID..." << endl; 
    //deleting random id's from the table
    for (int i = 0; i < testdatasize; i++){
        randId = rand() % MAXID;

        cout << "removing " << randId << ".. ";
            if (hashtable.removeEntry(randId)){
                cout << " remove successful" << endl;
            }else {
                cout << " remove failed" << endl;
            }
    }
    cout << endl;
    
    cout << "checking the current hashtable..." << endl;
    cout << "currently " << hashtable.getCount() << " entries in table" << endl << endl;
    cout << "printing the table... " << endl;
    hashtable.printTable();
    cout << endl;

    cout << "clearing the hashtable..." << endl;
    for(int i = 0; i < testdatasize; i++){
        cout << "deleting " << ids[i] << ".. ";
        if(hashtable.removeEntry(ids[i])){
            cout << "remove successful" << endl;
        }else{
            cout << "remove failed" << endl;
        }
    }
    cout << endl;

    cout << "checking the current hashtable..." << endl;
    cout << "currently " << hashtable.getCount() << " entries in table" << endl << endl;
    cout << "printing the table... " << endl;
    hashtable.printTable();
    cout << endl;

    cout << "performing randomized testing using id's from 0 to MAXID and data from test data..." << endl << endl;

    int choice = rand() % CHOICES + 1;

    for (int i = 0; i < testdatasize*BASE; i++){
        randId = rand() % MAXID;
        randomIndex = rand() % testdatasize;

        switch(choice){
            case 1: 

            case 2: //testing insert entry with random data from test data
                cout << "inserting " << ids[randomIndex] << ": " << strs[randomIndex] << ".. ";

                if(hashtable.insertEntry(ids[randomIndex], &strs[randomIndex])){
                    cout << "add success" << endl;
                } else{
                    cout << "add failed" << endl;
                }
                cout << endl;
                break;

            case 3: //testing removeEntry with random id's from test data
                cout << "removing " << ids[randomIndex] << ".. ";

                if (hashtable.removeEntry(ids[randomIndex])){
                    cout << "remove successful" << endl;
                }else {
                    cout << "remove failed" << endl;
                }
                cout << endl;
                break;

            case 4: //testing removeEntry with random id's from 0 to MAXID
                cout << "removing " << randId << ".. ";

                if (hashtable.removeEntry(randId)){
                    cout << "remove successful" << endl;
                } else{
                    cout << "remove failed" << endl;
                }
                cout << endl;
                break;

            case 5: //testing getData with random id's from test data
                cout << "getting " << ids[randomIndex] << "..";

                if (hashtable.getData(ids[randomIndex]) != ""){
                    cout << " found: " << hashtable.getData(ids[randomIndex]) << endl;
                }
                else {
                    cout << " not found" << endl;
                }
                cout << endl;
                break;

            case 6: 
                //testing getData with random id's from 0 to MAXID
                cout << "getting " << randId << ".. ";

                if(hashtable.getData((randId)) != ""){
                    cout << "found: " << hashtable.getData(randId) << endl;
                }
                else{
                    cout << "not found" << endl;
                }
                cout << endl;
                break;

            case 7: 
                //testing get count
                cout << "currently " << hashtable.getCount() << " entries in table" << endl << endl;

            case 8:
                //testing printTable
                cout << "printing the table.." << endl;
                hashtable.printTable();
                cout << endl;
                break;

        }
        choice = rand() % CHOICES + 1;
    }
    cout << "testing complete" << endl;

    return 0;
}
