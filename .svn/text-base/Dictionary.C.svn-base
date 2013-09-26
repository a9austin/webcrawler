/*
 *  Author: George Richards, Eric Saupe, Austin Truong, Alan Mieu
 *  Team: Acid Fire
 *  Date: 01/26/2012
 *
 *  Description:
 *
 *  Dictionary.C contains methods for reading and storing
 *  a dictionary of words.
 */

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <algorithm>
#include "Dictionary.h"


using namespace std;

/*
 *  Constructor if no dictionary file is given.  Reads from a file included with program.
 */
Dictionary::Dictionary(){
  
  string file_name = "words";
  cout << "Reading dictionary file: " << file_name << endl;
  ifstream inputFile(file_name.c_str());
  if(!inputFile.is_open()) {
    cout << "Failed to open " << file_name << " terminating..." << endl;
    exit(1);
  }
  string line;
  vector<string> words;
  while(getline(inputFile, line)) {
    words.push_back(line);
  } 
  inputFile.close();
  random_shuffle ( words.begin(), words.end() );

  bst = new BST();
  
  srand ( time(NULL) );
  int len = words.size();
  int percentage = 0;
  while(!words.empty()){
    bst->add(new string(words[words.size()-1]));
    words.pop_back();
    if((((double)(len - words.size()) /(double)len)*100) > percentage){
      DrawProgressBar((((double)(len - words.size()) /(double)len)*100));
      percentage = (((double)(len - words.size()) /(double)len)*100);
    } 
  }
  
}


/**
 * Standard Dictionary constructor that takes a file of words as the argument.
 * It runs through the file and puts all the words into a BST and Hash Table.
 */
Dictionary::Dictionary(string file_name){
  cout << "Reading dictionary file: " << file_name << endl;
  ifstream inputFile(file_name.c_str());
  if(!inputFile.is_open()) {
    cout << "Failed to open " << file_name << " terminating..." << endl;
    exit(1);
  }
  string line;
  vector<string> words;
  while(getline(inputFile, line)) {
    words.push_back(line);
  }
  inputFile.close();
  random_shuffle ( words.begin(), words.end() );
  bst = new BST();
  
  srand ( time(NULL) );
  int len = words.size();
  int percentage = 0;
  while(!words.empty()){
    bst->add(new string(words[words.size()-1]));
    words.pop_back();
    if((((double)(len - words.size()) /(double)len)*100) > percentage){
      DrawProgressBar((((double)(len - words.size()) /(double)len)*100));
      percentage = (((double)(len - words.size()) /(double)len)*100);
    }
   
  }
  cout << endl; //used to move from percentage line
}

/**
 * Checks the given word to see if it is spelled correctly by searching the BST or Hash table for the word.
 */
bool Dictionary::spelled_correctly(string word) {
  bool found = false;
  found = bst->contains(&word);
  return found;
}

/**
 * Returns true if the word is spelled correctly.  If it isn't it will give a number of 
 * suggested words that are close.
 */
bool Dictionary::best_matches(string word, vector<string> &list, unsigned int count) {
  if(bst->contains(&word))
    return true;
  else {
    list.push_back(*bst->nearby(&word));
    while(list.size() != count + 1){
      string *s = bst->nearby(&list.back());
      if(s == NULL){
	break;
      }
      list.push_back(*s);
    }
    return false; 
  }
  return true;
}

/**
 * Outputs the progress to the screen.
 */
void Dictionary::DrawProgressBar(int percent) {
  cout <<  "\rLoading Dictionary : " << percent << '%';
}
