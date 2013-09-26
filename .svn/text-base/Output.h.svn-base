#ifndef _OUTPUT_H_
#define _OUTPUT_H_
/**
 * Author: George Richards, Eric Saupe, Austin Truong, Alan Mieu
 * Team: Acid Fire
 * Date: 02/10/2012
 *
 * Description:
 *
 * This is the header file for the output class. This class contains methods
 * to output data to html.
 */
#include <string>
#include <vector>
#include <fstream>
#include "Webpage.h"
#include "Users.h"

using namespace std;

class Output {
 public:
  int wordtopcount;
  int misspelledtopcount;
  
  int maximumreviews;
  int numberoflinks;
  int numberofwords;
  int numberofimages; 
  int numberofvisited;
  int numberofusers;
  double wordsbyimages;
  double averagereviews;
  double averageamountoflinks;
  double averagemisspelling;
  double averagetypos;
  vector<string> totalMisspelledWords;
  vector<string> totalWords;
  vector<string> visitedLinks;
  Output();
  /**
  * This function simply takes the string vector which are html tables built earlier and outputs them into a specified
  * html document.
  * 
  * Parameters: fileName - the filename which should be written to.
  *
  * Returns: true if file was written successfully, otherwise false
  */
  bool writeToHTML(const char *fileName, Users *userlist);

  /**
   *This function creates an html table provided certain inputs.c
   *
   *Parameters: TO BE COMPLETED
   */
  void createTable(Webpage *page, int size, int topwords, Users *userlist, Dictionary *dict);
	
  /**
   * Does calculations on all of the users
   *
   */
  void calculateUserRating(Users *users);

  void update(Webpage *page, bool isAmazon);

 
  //destructor
  ~Output(){ delete tables;};
 private:
  vector<string> *tables;

};


#endif
