#ifndef _WORD_COUNT_H_
#define _WORD_COUNT_H_

/**
 * This is the header file for the Word_Count class.
 */

#include <string>
#include <vector>
#include "WordEntry.h"

using namespace std;

class Word_Count
{
 public:
  Word_Count(int size); // Constructor for WordCount
  ~Word_Count(); // Destructor
  void        readd(WordEntry *word);
  void        add_word( string word ); // Add a word to the WordCount table
  int         get_word_count( string word ); // Method for finding the number of occurences of a word
  void        get_top_words( vector<string> &word_list, vector<int> &counts, int count=50); // Finds the most frequent words
  void        get_all_words(vector<WordEntry> &word_list); 
  WordEntry   **word_table;
  int         tableSize;

 private:
  
  int        tableLength;
  int        hashCode( string word ); // Hash a word into an int
  int        findNextPosition( int hash ); // Find the next hashcode
  bool       findWord( string word ); // Search WordCount table to see if a given word exists
};

#endif
