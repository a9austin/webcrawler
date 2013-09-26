/**
 * Authors:  Alan Mieu, George Richards, Eric Saupe, Austin Truong
 * Date:     February 10, 2012
 *
 * UserEntry
 * Function:  This class acts as a container to store user data such as their name, number of reviews, number of typographical errors, and their average rating.
 */

#include "UserEntry.h"

/**
 * UserEntry::UserEntry()
 * Default constructor.
 */
UserEntry::UserEntry()
{
  name = "";
  reviews = 0;
  typos = 0;
  ratings = 0;
  averagerating = 0;
  misspelledwords = new vector<string>();
}

/**
 * UserEntry::UserEntry(string name)
 * Constructor to create a new UserEntry object.
 *
 * Parameter:  name - The name of the new user
 */
UserEntry::UserEntry(string username)
{
  name = username;
  reviews = 0;
  typos = 0;
  ratings = 0;
  averagerating = 0;
  misspelledwords = new vector<string>();
}

/**
 * UserEntry::addRating(int newrating)
 * Function:  Adds a rating and averages it with the other ratings of the user.
 *
 * Parameter:  newrating - The new rating
 */
void UserEntry::addRating(int newrating)
{
  ratings++;
  totalratings = totalratings + newrating;
  averagerating = (double) totalratings / ratings;
}

