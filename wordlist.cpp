/* WordList source file
*
*
*    This file will contain the function definitions you will implement.
*    The function signitures may NOT be changed.  You may create your own
*    helper functions and include them in this file.
*
*    In addition to the specific instructions for each function, no function
*    should cause any memory leaks or alias words_list in any way that would result
*    in undefined behavior.
*
*    Topics: Multilevel Pointers, Dynamic Allocation, Classes
*
*/
// MS VS does not like cstring functions, this is to tell it to chill out.
#ifdef _MSC_VER  //  Microsoft Visual C++

#define _CRT_SECURE_NO_DEPRECATE

#else  // not Microsoft Visual C++, so assume UNIX interface

#endif

// Do not include any other libraries
#include"wordlist.h"
#include<iostream>
#include<cstring>

using std::cout;
using std::endl;

using std::strcat;
using std::strcmp;
using std::strcpy;
using std::strlen;

/* Function: Wordlist Constructor
*/
WordList::WordList(const int cap):words_list(nullptr), n_words(0),capacity(cap){

    // TODO:

}

/* Function: Wordlist Copy Constructor
*/
WordList::WordList(const WordList &src) {

    // TODO:

}


/* Function: Wordlist Destructor
*/
WordList::~WordList() {

    // TODO:

}

/* Function: printList
*/
int    WordList::print() const {

    // TODO:
    int dummyreturnval = -9000;
    return dummyreturnval;

}



/* Function: get
*/
char* WordList::get(const int index) const {

    // TODO:
    char* dummyreturnval = nullptr;
    return dummyreturnval;

}


/* Function: count
*/
int    WordList::count() const {

    // TODO:
    int dummyreturnval = -9000;
    return dummyreturnval;
}


/* Function: insert
*/
int    WordList::insert(const char word[]) {

    // TODO:
    int dummyreturnval = -9000;
    return dummyreturnval;

}


/* Funtion: erase
*/
int    WordList::erase(const char word[]) {

    // TODO:
    int dummyreturnval = -9000;
    return dummyreturnval;

}


/* Funtion: prepend
*/
int    WordList::prepend(const WordList* src) {

    // TODO:
    int dummyreturnval = -9000;
    return dummyreturnval;

}


/* Funtion: search
*/
int WordList::search(const char word[]) const {

    // TODO:
    int dummyreturnval = -9000;
    return dummyreturnval;

}


/* Funtion: sort
*/
int    WordList::sort(bool asc) {

    // TODO:
    int dummyreturnval = -9000;
    return dummyreturnval;

}


/* Funtion: Assignment Operator
*/
WordList& WordList::operator=(const WordList &src) {

    // TODO:
    return *this;

}

















