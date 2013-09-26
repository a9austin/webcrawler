#ifndef _DICTIONARY_H_
#define _DICTIONARY_H_

/*
 * Author: George Richards, Eric Saupe, Austin Truong, Alan Mieu
 * Team: Acid Fire
 * Date: 01/26/2012
 *
 * Description: This holds a dictionary to allow you to check spelling of words.
 *
 * Dictionary.h defines the methods and variables used by the Dictionary class
 */

#include <string>
#include <vector>
#include "BST.h"

class Dictionary
{
 public:
  Dictionary(); // Takes no file.  Reads from one bundled with program.
  Dictionary(string file_name); // Reads in a file of dictionary word
  
  /**
   * This function returns true if the provided word is spelled correctly.
   * Otherwise it returns false.
   *
   * Parameters: word - the word to be checked
   *
   * Returns: true if word is spelled correctly, false otherwise
   */
  bool spelled_correctly(string word); // Return true if word is spelled correctly
  /**
   * This function returns true if the provided word is spelled correctly,
   * otherwise it puts up to 5 strings into list which are suggestions for
   * the misspelled words.
   *
   * Parameters: word - the word to be checked, list - the list to be filled with suggestions, count - the number of suggestions to return
   * 
   */
  bool best_matches(string word, vector<string> &list, unsigned int count = 5); // return true if word is spelled correctly or return up to 5 (count) suggested best matches

 private:
  //This is secret private stuff, don't ask about it
  BST *bst;
  void DrawProgressBar (int percent);

};

#endif
