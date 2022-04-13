// Ludwig von Schoenfeldt
// 04/08/22
// CS 20A Section 4059
// SID: 1871721
// Project 2


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
Specification: Constructs an empty WordList that is allocated enough space to store capacity many words. If capacity is less than 1, set words_list to nullptr. Other member variables should initialized to appropriate values reflecting the WordLis’s state.
Usage: WordList *wordlist = new WordList(5); // new WordList can store 5 words
 
 DONE!!!
*/
WordList::WordList(const int cap):words_list(nullptr), n_words(0),capacity(cap) {
    n_words = 0;
    if (cap < 1) {
        capacity = 0;
        words_list = nullptr;
    }
    else {
        capacity = cap;
        words_list = new char*[capacity];
        for (unsigned int i = 0; i < capacity; i++) {
            words_list[i] = new char[MAX_WORD_SIZE];
        }
    }
}

/* Function: Wordlist Copy Constructor
 Specification: Copy constructor for WordList, constructs a new WordList from an already existing WordList. The newly constructed WordList should have the same attributes as the existing one, but it should own its own dynamically allocated memory.
 Usage: WordList existinglist(5); // WordList can store 5 words //... Some WordList operations
 if (...) {
 WordList newList(existinglist); // Copy Constructor } // Should not results in undefined behavior
 
 DONE!!!
*/
WordList::WordList(const WordList &src) {
    n_words = src.n_words;
    capacity = src.capacity;
    if (capacity < 1) {
        words_list = nullptr;
    }
    else {
        words_list = new char*[capacity];
        for (int i = 0; i < capacity; i++) {
            words_list[i] = new char[MAX_WORD_SIZE];
        }
        for (int i = 0; i < n_words; i++) {
            strcpy(words_list[i], src.words_list[i]);
        }
    }
}

/* Function: Wordlist Destructor
 Specification: Destructor for WordList. Releases any dynamically allocated memory.
 Usage: Called when a WordList leaves scope, like in Function 2 Usage, or when delete is called on a dynamically allocated WordList: delete wordlist; // From Function 1 Spec

*/

WordList::~WordList() {
    
    for (int i = 0; i < n_words; i++) {
        delete [] words_list[i];
        
    }
    delete[] words_list;
    
}

/* Function: printList
 Specification: Prints all the words in WordList in a single line with spaces between each word, then followed by a newline after the last word; there is no space after the last word. Returns the number of words printed. If words_list is nullptr there is nothing to print, return -2.
 Usage: WordList *wordlist = new WordList(5); //... add harry ron hermione into list
 int retval = wordlist->print(); // print “harry ron hermione\n” to console
*/
int    WordList::print() const {

    if (words_list == nullptr) {
        return -1;
    }
    int count = 0;
    for (unsigned int i = 0; i < n_words; i++) {
        cout<<words_list[i];
        count++;
        if (i==(n_words - 1)) {
            break;
        }
        cout<< " ";
        
    }
    cout<< endl;
    return count;
}




/* Function: get
 Specification: Returns the word at the index position in the WordList. If the index is out of bounds return nullptr.
 Usage: //Assuming wordlist is the example in the beginning of the spec char* word = wordlist->get(1);
 if (word != nullptr)
 cout << word << endl; //ron
*/
char* WordList::get(const int index) const {

    if ((index < 0) || (index >=n_words)) {
            return nullptr;
        }
        return words_list[index];
    }


/* Function: count
 Specification: Returns the number of words currently stored in the WordList.
 Usage: //Assuming wordlist is setup to the example in the beginning of the spec for (int i = 0; i < wordlist->count(); i++) {
                      cout << wordlist->get(i) << " ";
               } //pritns “harry ron Hermione”

*/
int    WordList::count() const {

    return n_words;

}
/* Function: insert
Specification: Inserts the word to the front the word into WordList. If WordList does not have enough capacity to insert word, insert will resize with just enough space to allow for the addition of word. If insert needed to resize then return 1, otherwise if there already enough space to insert word without resizing, return 0. If word is empty do nothing return -1. If words_list was nullptr, everything above still applies except return -2.

*/
int    WordList::insert(const char word[]) {
    int result = 0;
        if (word[0] == '\0') {
            return -1;
        }
    
    
        if (n_words == capacity) {
            
            if (words_list == nullptr) {
                result = -2;
            }
            else {
                result = 1;
            }
            int temp_max_words = capacity + 1;
            char** temp = new char*[temp_max_words];
            for (unsigned int i = 0; i < temp_max_words; i++) {
                temp[i] = new char[20];
            }
            for (unsigned int i = 0; i < n_words; i++) {
                // Assumes words will be no more than 19 characters in length (+1 for the null character)
                strcpy(temp[i], words_list[i]);
            }
            for (unsigned int i = 0; i < capacity; i++) {
                delete [] words_list[i];
            }
            delete [] words_list;
            words_list = temp;
            capacity = temp_max_words;
            
        }
        
        strcpy(words_list[n_words], word );
        n_words++;
        
        return result;
}


/* Funtion: erase
 Specification: If words_list is nullptr, returns -2. Otherwise, searches for every occurrence of word, and erases that word from the list, returns the number of words erased. Make sure the resulting WordList follows the rules for a valid WordList outlined in the spec.
 Usage: WordList serenity(10);
               serenity.insert("Wash");
               serenity.insert("Book");
               serenity.insert("River");
               serenity.insert("Simon");
               serenity.insert("Kaylee");
               serenity.insert("Jayne");
               serenity.insert("Wash");
               serenity.insert("Inara");
               serenity.insert("Mal");
               serenity.print();
 // prints "Mal Inara Wash Jayne Kaylee Simon River Book Wash\n"
 serenity.erase("Wash"); // :(
 serenity.print();
 // prints "Mal Inara Jayne Kaylee Simon River Book\n"
 
 
 WEIRD PROBLEM - mine is printing the reverse order but still erasing the right one
*/
int    WordList::erase(const char word[]) {

    int result = -1;
    if (words_list == nullptr) {
        return result;
    }
    else {
        result = 0;
    }
    while (search(word) != -1) {
        int index = search(word);
        for (int i = index; i < n_words -1; i++) {
            strcpy(words_list[i],words_list[i+1]);
        }
        n_words--;
        result++;
        
    }
    return result;
}


/* Funtion: prepend
 Specification: Prepends the contents of *src to the WordList. If WordList does not have enough space prepend should dynamically allocate enough space to prepend the contents of *src to WordList, returns number of words prepended. If *src is nullptr or empty prepend does nothing and returns 0. If this WordList::words_list is nullptr everything above still applies except returns -2.
 Usage: WordList wordlist1(0); wordlist1.insert("mia");
               wordlist1.insert("susannah"); // num 2, max 2
               WordList wordlist2(4);
               wordlist2.insert("dean");
               wordlist2.insert("holmes");
               wordlist2.insert("odetta"); // num 3, max 4
 int retval = wordlist2.prepend(&wordlist1);
 wordlist2.print(); // print “susannah mia odetta holmes dean\n”
 // Assuming member variables are public
 cout << retval<< " "<< wordlist2.n_words << " " << wordlist2.capacity;
 //prints 2 5 5
*/
int    WordList::prepend(const WordList* src) {

    int result = -1;
    if ((src == nullptr) || (src->count() == 0)) {
        return result;
    }
    if ((n_words + src->count()) > capacity) {
        if (words_list == nullptr) {
            result = -2;
            
        } else {
            result = src->count();
        }
        int temp_max_words = n_words + src->count();
        char** temp = new char*[temp_max_words];
        for (int i = 0; i < temp_max_words; i++) {
            temp[i] = new char[20];
        }
        for (int i = 0; i < n_words; i++) {
            strcpy(temp[i], words_list[i]);
        }
        for (int i = 0; i < capacity; i++) {
            delete [] words_list[i];
        }
        delete [] words_list;
        words_list = temp;
        capacity = temp_max_words;
        
    }
    for (int i = 0; i < src->count(); i++) {
        strcpy(words_list[n_words], src->get(i));
        n_words++;
    }
    return result;
}


/* Funtion: search
 Specification: Searches for the first occurrence of the word in the WordList returns the indexing position of that word in the list. Otherwise, if the word is not in the WordList return -1 or if words_list is nullptr return -2.
 Usage: WordList wordlist(4); wordlist.insert("Waldo");
               wordlist.insert("Is");
               wordlist.insert("Where");
               int retval = wordlist.search("waldo");
               if (retval < 0)
                      cout << "Not found" << endl;
*/
int WordList::search(const char word[]) const {

    if (words_list == nullptr) {
        return -1;
    }
    for (int i = 0; i < n_words; i++) {
        if (strcmp(words_list[i], word) == 0) {
            return i;
        }
        
    }
    return -1;
}


/* Funtion: sort
 Specification: If WordList is nullptr return -2. If there is only one word in the words_list return 1. Otherwise, sort sorts the words in WordList in ascending order if asc is true and descending order if asc is false, returns 0. You may not use any built-in sorting function provided by your environment, Implement your own sorting algorithm.
 Usage: WordList neverwhere(5);
 neverwhere.insert("Richard");
 neverwhere.insert("Door");
 neverwhere.insert("Carabas");
 neverwhere.insert("Islington");
 neverwhere.insert("Abbot");
 neverwhere.sort(true);
 neverwhere.print(); // prints "Abbot Carabas Door Islington Richard\n"

*/
int    WordList::sort(bool asc) {

    if (words_list == nullptr) {
            return -2;
        }

        if (n_words == 1) {
            return 1;
        }

        for (int i = 0; i < n_words - 1; i++) {
            for (int j = 0; j < n_words - i - 1; j++) {
                if ((asc && strcmp(words_list[j], words_list[j + 1]) > 0) || (!asc && strcmp(words_list[j], words_list[j + 1]) < 0)) {
                    char* temp = new char[strlen(words_list[j]) + 1];
                    strcpy(temp, words_list[j]);

                    delete[] words_list[j];

                    words_list[j] = new char[strlen(words_list[j + 1]) + 1];

                    strcpy(words_list[j], words_list[j + 1]);

                    delete[] words_list[j + 1];

                    words_list[j + 1] = new char [strlen(temp) + 1];

                    strcpy(words_list[j + 1], temp);

                    delete[] temp;
                }
            }
        }

        return 0;
    }

/* Funtion: Assignment Operator
 Specification: Copies from an existing WordList to another exiting WordList. Should not result in any
 memory leaks or aliasing of dynamically allocated memory.
 Usage: WordList ben(5); // WordList can store 5 words //... Some WordList operations
 if (...) {
                      WordList ann(4);
                      ann = ben;
               } // Should not results in undefined behavior
               ben = ben; // should not result in undefined behavior
*/
WordList& WordList::operator=(const WordList &src) {
    if (this == &src) {
            return *this;
        }
        for (unsigned int i = 0; i < capacity; i++) {
            delete [] words_list[i];
        }
        delete [] words_list;
        n_words = src.n_words;
        capacity = src.capacity;
        
        if (src.words_list == nullptr) {
            words_list = nullptr;
        }
        else {
            words_list = new char*[capacity];
            for (unsigned int i = 0; i < capacity; i++) {
                words_list[i] = new char[MAX_WORD_SIZE];
            }
            for (unsigned int i = 0; i < n_words; i++) {
                // Assumes words will be no more than 19 characters in length (+1 for the null character)
                strcpy(words_list[i], src.words_list[i]);
            }
        }
        return *this;
    }
















