/**
 * Authors:  Alan Mieu, George Richards, Eric Saupe, Austin Truong
 * Team: Acid Fire
 * Date:     February 10, 2012
 *
 * Users
 * Function:  This class is a vector containing all users encountered during web crawling.
 */

#include <string.h>
#include <vector>
#include <algorithm>
#include "Users.h"

/**
 * Users::Users()
 * Constructor for creating a new Users vector.
 */
Users::Users()
{
}

/**
 * Users::~Users()
 * Destructor for the Users class.
 */
Users::~Users()
{
}

/**
 * Users::addUser(string name)
 * Function: Adds a new user into the vector.
 *
 * Parameter: name - The name of the new user.
 */
void Users::addUser(string name, UserEntry *newuser)
{
  if (!checkForUser(name))
    {
      //UserEntry *pushUser = newuser;
      usertable.push_back(newuser);
    }
}

/**
 * Users::getAverageReviews()
 * Function: This method gets the reviews of each user and returns the average.
 *
 * Return: The average number of reviews in the vector.
 */
double Users::getAverageReviews()
{
  double totalreviews = 0; // Total number of reviews
  for (unsigned int i = 0; i < usertable.size(); i++)
    {
      totalreviews = totalreviews + usertable.at(i)->reviews;
    }
  return ((double) totalreviews / usertable.size());
}

/**
 * Users::getMedianAndMaxReviews()
 * Function: This method gets the median of the reviews in the vector.
 *
 * Return:  The median and maximum number of reviews in the vector, stored in an array.
 * NOTE:
 * The first item in the array is always the median number, and the second item is always the maximum number.
 */
vector<int> Users::getMedianAndMaxReviews()
{
  vector<int> medianmax; // Make an array of size 2.
  vector<int> reviews; // Vector for all reviews.

  for (unsigned int i = 0; i < usertable.size(); i++)
    {
      reviews.push_back(usertable.at(i)->reviews);
    }

  sort(reviews.begin(), reviews.end());
  int middle = reviews.size() / 2;

  medianmax.push_back(reviews.at(middle));
  medianmax.push_back(reviews.at(reviews.size()-1));

  return medianmax;
}

/**
 * Users::getAverageTypos()
 * Function: Returns the average number of typos per person in the vector.
 *
 * Return: The average number of typos per person in the vector.
 */
double Users::getAverageTypos()
{
  double totaltypos = 0;

  for (unsigned int i = 0; i < usertable.size(); i++)
    {
      totaltypos = (double) totaltypos + usertable.at(i)->typos;
    }

  return ((double) totaltypos / usertable.size());
}

/** 
 * Users::getAverageRating(string name)
 * Function: Returns the average rating of a user.
 *
 * Parameter: name - The name of the user you wish to find the average rating for.
 * Return: The average rating of that user.
 */
double Users::getAverageRating(string name)
{
  if (checkForUser(name))
    {
      UserEntry* user = findUser(name);
      return user->averagerating; 
    }

  return 0;
}

/**
 * PRIVATE METHOD
 * Users::findUser(string username)
 * Function: Finds the user in the vector.
 *
 * Parameter: name - The name of the user you're looking for.
 * Return: The UserEntry object containing that name.
 */
 UserEntry* Users::findUser(string username)
 {
   for (unsigned int i = 0; i < usertable.size(); i++)
     {
       if (strcmp(usertable.at(i)->name.c_str(), username.c_str()) == 0)
	 {
	   return usertable.at(i);
	 }
     }

   return NULL;
 }

 /**
  * Users::checkForUser(string username)
  * Function: Checks the vector to see if the given user exists.
  *
  * Parameter: name - The name of the user you wish to find.
  * Return: A boolean stating if the user exists or not.
  */
 bool Users::checkForUser(string username)
 {
   for (unsigned int i = 0; i < usertable.size(); i++)
     {
       if (strcmp(usertable.at(i)->name.c_str(), username.c_str()) == 0)
	 {
	   return true;
	 }
     }

   return false;
 }


      

