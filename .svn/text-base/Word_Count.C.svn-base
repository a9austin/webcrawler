/**
 * Authors:  Austin Truong, George Richards, Alan Mieu, Eric Saupe
 * Date:     January 27, 2012
 * 
 * Word_Count.h
 * Function:
 * Header file for the Word_Count class file.
 */

#include <string.h>
#include "Word_Count.h"
#include <iostream>


/**
 * Word_Count Constructor
 *
 * Parameter:
 * size:  The size of the hash table to be created.
 */
Word_Count::Word_Count(int size)
{
  tableLength = 0;
  word_table = new WordEntry*[size];
   for (int i = 0; i < size; i++){
     word_table[i] = new WordEntry();
   }
  tableSize = size;
}

/**
 * Word_Count Destructor
 */
Word_Count::~Word_Count()
{
  for (int i = 0; i < tableSize; i++)
  {
    delete word_table[i];
  }
  delete word_table;
}


void Word_Count::readd(WordEntry *word){
int hash = hashCode(word->wordKey); // Create a hash code from the word.
// If the hash position already contains a WordEntry, find the next available position.
 if(strcmp(word_table[hash]->wordKey.c_str(), "") != 0)
   {
     int nextPosition = findNextPosition(hash); // Call the method that finds the next available position.
     word_table[nextPosition] = word;
   }
 else
   {
     word_table[hash] = word;
   }
}

/**
 * add_word
 *
 * Function:
 * Adds a word to the hash table.
 *
 * Parameter:
 * word:  The word to be added to the hash table.
 */
void Word_Count::add_word(string word)
{
  bool exists = findWord(word); // Call the method that checks the hash table to see if the word already exists in the hash table.

  
  if (!exists)
    {
     
      if(tableLength == tableSize) {
	WordEntry **temp = word_table;
	word_table = new WordEntry*[tableSize * 2];
	for (int i = 0; i < tableSize * 2; i++) {
	  word_table[i] = new WordEntry();
	}
	
	tableSize = tableSize * 2;
	for(int i = 0; i < tableLength; i++) {
	  readd(temp[i]);
	}

	delete temp;
	temp = NULL;
      }
      else {
	int hash = hashCode(word); // Create a hash code from the word.
	WordEntry* newWord = new WordEntry(word, 1); // Create a new WordEntry object to hold the word and its count.
	
	// If the hash position already contains a WordEntry, find the next available position.
	if(strcmp(word_table[hash]->wordKey.c_str(), "") != 0)
	  {
	    int nextPosition = findNextPosition(hash); // Call the method that finds the next available position.
	    word_table[nextPosition] = newWord;
	  }
	else
	  {
	    word_table[hash] = newWord;
	  }
      }
       tableLength++;
      
    }
  
}

/**
 * get_word_count
 *
 * Function:
 * Returns the count of a given word.
 *
 * Parameter:
 * word:  The word you wish to get the count for.
 *
 * Return:
 * An integer of the count of the given word.
 */
int Word_Count::get_word_count(string word)
{
  for (int i = 0; i < tableSize; i++)
    {
      if (strcmp(word_table[i]->wordKey.c_str(), word.c_str()) == 0)
	{
	  return word_table[i]->wordCount;
	}
    }
  return 0;
}

/**
 * get_top_words
 *
 * Function:
 * Populates a word and a count vector with the words that have the highest counts in the hash table.  Amount of words determined by the count parameter.
 *
 * Parameters:
 * wordList:  A vector to populate with the top words.
 * counts:  A vector to populate with the top counts.
 * count:  The amount of words you wish to have in the vectors.
 */
void Word_Count::get_top_words(vector<string> &wordList, vector<int> &counts, int count)
{
  WordEntry **topWordsTable; // Create an array to hold words as they are compared.
  topWordsTable = new WordEntry*[count];
  for (int i = 0; i < count; i++){
    topWordsTable[i] = new WordEntry();
  }


  // First, populate the topWordsTable with the first <count> words.
  int counter = 0;
  int earlyend = 0;
  
  for (int i = 0; i < tableSize; i++)
    {
      if(counter < count){
	if (word_table[i]->wordCount != 0){
	  topWordsTable[counter] = word_table[i];
	}
      }
      else
	{
	  earlyend = counter;
	  break;
	}
      counter++;
    }
  // Then take the remaining words in the hash table and compare them with the array, replacing those that have lower counts.
  if (earlyend == 0){
    for (int j = counter; j < tableSize; j++)
      {
	for (int k = 0; k < count; k++)
	  {
	    if (topWordsTable[k]->wordCount < word_table[j]->wordCount)
	      {
		topWordsTable[k] = word_table[j];
		break;
	      }
	  } 
      }
  }
  // Push the words and their counts into the vectors.
  if(earlyend == 0){
    for (int m = 0; m < count; m++)
      {
	wordList.push_back(topWordsTable[m]->wordKey);
	counts.push_back(topWordsTable[m]->wordCount);
      }
  }
  else{
    for (int m = 0; m < earlyend; m++)
      {
	wordList.push_back(topWordsTable[m]->wordKey);
	counts.push_back(topWordsTable[m]->wordCount);
      }
  }
  for (int k = 0; k < count; k++){
    //  delete topWordsTable[k];
  }
  //delete topWordsTable;
  return;
}


/**
 * Word_Count::get_all_words(vector<string> &wordList)
 * Function:
 * Gets all words from the hash table and pushes them onto a vector.
 *
 * Parameter:  wordList - A vector of strings to populate with all words from the table.
 */
void Word_Count::get_all_words(vector<WordEntry> &wordList)
{
  for (int i = 0; i < tableSize; i++)
    {
      wordList.push_back(*word_table[i]);
    }

  return;
}

/**
 * hashCode
 *
 * Function
 * Hashes a given word into some number.
 *
 * Parameter:
 * word:  The word to be hashed.
 *
 * Return:
 * An integer representing the hash code.
 */
int Word_Count::hashCode(string word)
{
  int hashNumber = 0;
  int wordSize = word.size();
  if (wordSize == 0){
    return 0;
  }
  int firstLetter = (int)word.at(0);
  int lastLetter = (int)word.at(wordSize-1);
  hashNumber = word.size()*firstLetter*lastLetter;
  hashNumber = hashNumber % tableSize;
  return hashNumber;
}

/**
 * findWord
 *
 * Function:
 * Searches the hash table to see if the given word exists in the table.
 *
 * Parameter:
 * word:  The word you wish to find in the hash table.
 *
 * Return:
 * A boolean determining whether or not the word exists in the table.
 */
bool Word_Count::findWord(string word)
{
  int hash = hashCode(word);
  
  for (int i = 0; i < tableSize; i++)
    {      
      if (word_table[hash]->wordCount == 0)
	{
	  return false;
	}
      if (strcmp(word_table[hash]->wordKey.c_str(), word.c_str()) == 0)
	{
	  word_table[hash]->wordCount++;
	  return true;
	}
      
      hash = findNextPosition(hash);
    }

  return false;
}

/**
 * findNextPosition
 *
 * Function:
 * Finds the next available position in the hash table if the initial position was filled. Currently uses linear probing.
 *
 * Parameter:
 * The initial hash position.
 *
 * Return:
 * The next available position.
 */
int Word_Count::findNextPosition( int hash )
{
  int nextPosition = ++hash;

  if (nextPosition >= tableSize)
    {
      nextPosition = 0;
    }

  if (word_table[nextPosition]->wordCount != 0)
    {
      findNextPosition(nextPosition);
    }
  else
    {
      return nextPosition;
    }

  return 0;
}

