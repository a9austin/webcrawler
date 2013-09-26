/*
 *  Author: George Richards, Eric Saupe, Austin Truong, Alan Mieu
 *  Team: Acid Fire
 *  Date: 02/10/2012
 *
 *  Description:
 *
 * This file contains all the method implementations for the Output Class.
 */

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Output.h"
#include "Word_Count.h"
#include "Dictionary.h"

using namespace std;

/**
 * This is the default constructor for the Output class
 *
 * Function: Output
 * Input: none
 * Output: none
 */
Output::Output(){
 wordtopcount = 100;
 misspelledtopcount = 100;
  
 numberoflinks = 0; 
 numberofwords = 0;
 numberofimages= 0; 
 numberofvisited = 0;
 numberofusers = 0;
 wordsbyimages = 0;
 averagereviews = 0;
 averageamountoflinks = 0;
 averagemisspelling = 0;
 averagetypos = 0;
 maximumreviews = 0;
 tables = new vector<string>();
}

/**
 * Updates the count of the combined data from webpages crawled.
 *
 * Function: update
 * Input: Webpage that was crawled, bool whether the site is an Amazon page\
 * Output: void
 */
void Output::update(Webpage *page, bool isAmazon){
  
  numberofwords += page->amountofwords;
  numberoflinks += page->amountoflinks;
  numberofimages += page->amountofimages;
  numberofvisited++;
  if(isAmazon){
    numberofusers += page->users.size();
   
  }
  
  for(unsigned int i = 0; i < page->misspelled_words.size(); i++){
    totalMisspelledWords.push_back(page->misspelled_words[i]);
  }
  
  for(unsigned int i = 0; i < page->word_vector.size(); i++){
    totalWords.push_back(page->word_vector[i]);
  }
  
}
								    
/**
 * This function simply takes a string of html tables and outputs them into a specified
 * html document.
 *
 * Function: writeToHTML
 * Input: file name, user list of users crawled
 * Output: true if file was created succesfully
 */
bool Output::writeToHTML(const char *fileName, Users *userlist) {
  Word_Count *misspelledCount = new Word_Count(1000);
  Word_Count *totalCount = new Word_Count(1000);

  vector<string> misspelledWordVector;
  vector<int> misspelledCountVector;
  
  vector<string> totalWordVector;
  vector<int> totalCountVector;

  for(unsigned int i = 0; i < totalMisspelledWords.size(); i++){
    misspelledCount->add_word(totalMisspelledWords[i]);
  }
  for(unsigned int i = 0; i < totalWords.size(); i++){
    totalCount->add_word(totalWords[i]);
  }

  misspelledCount->get_top_words(misspelledWordVector, misspelledCountVector, misspelledtopcount);
  totalCount->get_top_words(totalWordVector, totalCountVector, wordtopcount);
  
  if(numberofimages > 0){
    wordsbyimages = numberofwords / numberofimages;
  }
        ofstream outFile(fileName); // Open for writing
	if (outFile.is_open()) { // check if our file is open
		outFile << "<!DOCTYPE html>\
		<html>\
		<head>\
		<meta http-equiv='Content-Type' content='text/html; charset=UTF-8' />\
		<title>The Ultimate Crawler</title>\
        <style type='text/css'>\
	body {\
        background:rgb(178,34,34);\
		}\
		h1 {\
        color:#FFF;\
		font-size:3em;\
		margin:0;\
		padding:0;\
		text-align:center;\
		text-shadow: 0 1px 0 #ccc,\
		0 2px 0 #c9c9c9,\
		0 3px 0 #bbb,\
		0 4px 0 #b9b9b9,\
		0 5px 0 #aaa,\
		0 6px 1px rgba(0,0,0,.1),\
		0 0 5px rgba(0,0,0,.1),\
		0 1px 3px rgba(0,0,0,.3),\
		0 3px 5px rgba(0,0,0,.2),\
		0 5px 10px rgba(0,0,0,.25),\
		0 10px 10px rgba(0,0,0,.2),\
		0 20px 20px rgba(0,0,0,.15);\
		}\
		::-moz-selection { background: #5af; color: #fff; text-shadow: none; }\
		::selection { background: #5af; color: #fff; text-shadow: none; }\
		table {\
		margin:auto;\
		text-align:center;\
		border-collapse: collapse;\
		}\
		table tr td {\
		padding:10px;\
		border:1px solid #000;\
		}\
		table tr th {\
		padding:10px;\
		}\
		table caption {\
		padding-top:5px;\
		text-decoration:underline;\
		font-size:2em;\
		}\
		</style>\
		</head>\
		<body>\
		<div id='outerwrapper'>\
		<h1 class='appear'>WEB CRAWLER STATISTICS</h1>\
		<div id='MainTable' class='appear'>\
		<table>\
                <tr><td>External Resources/Links from Domain</td><td>" << numberoflinks  << "</td></tr> \
                <tr><td>Web Pages Visited</td><td>" << numberofvisited  << "</td></tr> \
                <tr><td>Number of Words (Total for All pages Visited)</td><td>" << numberofwords  << "</td></tr> \
                <tr><td>Number of Images (Total for All Pages Visited)</td><td>" << numberofimages  << "</td></tr> \
                <tr><td>Words/Images (Total for All Pages Visited)</td><td>" << wordsbyimages  << "</td></tr> \
                </table>\
                <table>\
                <tr><th>Top Misspelled Words</th><th>Number of Misspellings</th></tr> ";
		  for (unsigned int i = 0; i < misspelledWordVector.size(); i++){
		    if (misspelledWordVector[i] != ""){
		      outFile << "<tr><td>" << misspelledWordVector[i] << "</td>\
		      <td>" << misspelledCountVector[i] << "</td></tr>";
		    }
		  }
               
		  outFile << "</table>";
		  
		  outFile << "<table><tr><th>Top Words</th><th>Count</th></tr>"; 				                 
		  for (unsigned int i = 0; i < totalWordVector.size(); i++){
		    if (totalWordVector[i] != ""){
		      outFile << "<tr><td>" << totalWordVector[i] << "</td>\
		      <td>" << totalCountVector[i] << "</td></tr>";
		    }
		  }
               
		  outFile << "</table>";
		  
		  if(userlist->usertable.size() != 0){
		    
		    averagereviews = userlist->getAverageReviews();
		    averagetypos = userlist->getAverageTypos();
		    vector<int> maxmed = userlist->getMedianAndMaxReviews();
		    
		    outFile << "<table> \
                   <tr><th>Total Users</th><th>Average Number of Reviews per User</th><th>Maximum Number of Reviews per Person</th></tr>	\
                   <tr><td>" << userlist->usertable.size() << "</td><td>"<< averagereviews << "</td><td>" << maxmed[1] << "</td></tr>";

		    outFile << "<table> \
                   <tr><th>Name of User</th><th>Number of reviews</th></tr>";	
		    for(unsigned int i = 0; i < userlist->usertable.size(); i++){
		      outFile << "<tr><td>" << userlist->usertable[i]->name <<"</td><td>" << userlist->usertable[i]->reviews << "</td></tr>"; 
		    }
		  }
	      

		  
		outFile << "</div>\
		</div>\
		</body>\
		</html>" << endl;
		outFile.close();
		delete misspelledCount;
		delete totalCount;
		misspelledCount = NULL;
		totalCount = NULL;
		return true; //writting succeeded
	} else {
	        delete misspelledCount;
	        delete totalCount;
	        misspelledCount = NULL;
	        totalCount = NULL;
	        return false;//writting failed
	}
}

/**
 * Calculates the average review rating given per user.
 *
 * Function: calculateUserRating
 * Input: list of users
 * Output: void
 */
void Output::calculateUserRating(Users *users) {
  
  for(unsigned int i = 0; i < users->usertable.size(); i++){
    // If the user exists
    if (users->checkForUser(users->usertable[i]->name)){
      double averageRating = users->getAverageRating(users->usertable[i]->name);
     
      users->usertable[i]->averagerating = averageRating;
    }
  }
 
}

