#ifndef _USERENTRY_H_
#define _USERENTRY_H_
/**
 * Author: George Richards, Eric Saupe, Austin Truong, Alan Mieu
 * Team: Acid Fire
 * Date: 02/10/2012
 *
 * Description:
 *
 * This is the header file for the UserEntry class. See UserEntry.C for more detailed documentation.
 */

#include <string>
#include <vector>

using namespace std;

class UserEntry
{
 public:
  UserEntry(); // Default constructor
  UserEntry(string name); // Constructor for the UserEntry class
  string name; // Name of the user
  int reviews; // Number of reviews by this user
  int typos; // Number of typos by this user
  double averagetypos;
  double ratings; // Number of ratings by this user
  double totalratings; // The sum of all ratings by this user
  double averagerating; // The average rating by this user
  vector<string> userreviews; // The reviews by this user
  vector<string> *misspelledwords; // The misspelled words by this user
  void addRating(int rating); // Method for adding a rating to the average rating of this user
};
#endif
