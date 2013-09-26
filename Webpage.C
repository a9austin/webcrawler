/*
 *  Author: George Richards, Eric Saupe, Austin Truong, Alan Mieu
 *  Team: Acid Fire
 *  Date: 02/10/2012
 *
 *  Description:
 *
 *  This file is what a webpage contains.
 */

#include "Webpage.h"
#include "Word_Count.h"


using namespace std;

/**
 * Inserts a given item into a specific vector
 *
 * Function: insert
 * Input: item to be inserted string, vector to insert into
 * Output: void
 */
void Webpage::insert(string item, vector<string> vec){
  vec.push_back(item);
}

void Webpage::addword(string item){
  count->add_word(item);
  amountofwords++;
}

/**
 * Goes through the list of users and spell checks their comments. Keeps track of misspelled words.
 *
 * Function: usersUpdateAndMisspelledWords
 * Input: list of users, dictionary file
 * Output: void
 */
void Webpage::usersUpdateAndMisspelledWords(Users *userlist, Dictionary *dict){
  for(unsigned int i = 0; i < users.size(); i++) {
    userSpellCheck(users[i], dict);
    userlist->addUser(users[i]->name, users[i]);
  }  
}
 
/**
 * Helper function for usersUpdateAndMisspelledWords
 *
 * Function: userSpellCheck
 * Input: single user, dictionary file
 * Output: void
 */
 void Webpage::userSpellCheck(UserEntry *user, Dictionary *dict){
   //  vector
  for(unsigned int i = 0; i < user->userreviews.size(); i++){
    string current_word = user->userreviews.at(i);
    if(!dict->spelled_correctly(current_word)){     // If word is misspelled.
      // cout << "Misspelled Word: " << current_word << endl;
      user->typos++;  
      user->misspelledwords->push_back(current_word);
    }
  }
}

/**
 * Spell check for non-Amazon pages
 *
 * Function: normalSpellCheck
 * Input: dictionary file
 * Output: void
 */
void Webpage::normalSpellCheck(Dictionary *dict){
  vector<string> temp;
  for(unsigned int i = 0; i < word_vector.size(); i++){
    if(!dict->spelled_correctly(word_vector[i])){
      misspelled_words.push_back(word_vector[i]);
      amountofmisspell++;
    }
  }
}

/**
 * Helper method to move things from one vector to another
 *
 * Function: addTransferVector
 * Input: source vector, destination vector
 * Output: void
 */
 void Webpage::addTransferVector(vector<string> v1, vector<string> v2){
   for(unsigned int i = 0; i < v1.size(); i++){
     v2.push_back(v1.at(i));
   }
 }

/**
 * Helper method to move things from one vector to another
 *
 * Function: addPointerTransferVector
 * Input: source vector, destination vector address
 * Output: void
 */
void Webpage::addPointerTransferVector(vector<string> v1, vector<string> &v2){
   for(unsigned int i = 0; i < v1.size(); i++){
     v2.push_back(v1.at(i));
   }
 }

/**
 * Helper method to set the size of count.
 *
 * Function: setSize
 * Input: size
 * Output: void
 */
 void Webpage::setSize(int size) {
   count = new Word_Count(size);
 }
 

 
