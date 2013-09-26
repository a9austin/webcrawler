#ifndef _USERS_H_
#define _USERS_H_
/**
 * Author: George Richards, Eric Saupe, Austin Truong, Alan Mieu
 * Team: Acid Fire
 * Date: 02/10/2012
 *
 * Description:
 * 
 * This is the header class for the Users class. See Users.C for a detailed documentation.
 */

#include <string>
#include <vector>
#include "UserEntry.h"

using namespace std;

class Users
{
 public:
  Users(); // Constructor for the Users class
  ~Users(); // Destructor for the Users class
  void addUser(string name, UserEntry *newuser); // Method for adding a new user into the vector.
  double getAverageReviews(); // Method for retrieving the average number of reviews per user.
  vector<int> getMedianAndMaxReviews(); // Method for retrieving the median number of reviews per user.
  double getAverageTypos(); // Method for finding the average number of spelling mistakes per user.
  double getAverageRating(string name); // Method for finding the average rating by a user.
  vector<UserEntry*> usertable; // Vector for storing all users.
   bool checkForUser(string username); // Method for checking the vector to see if a user exists.
 private:
  UserEntry* findUser(string username); // Method for finding a user in the vector.
};

#endif
