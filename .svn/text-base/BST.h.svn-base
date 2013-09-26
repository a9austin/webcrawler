#ifndef _BST_H_
#define _BST_H_
/**
 * Author: George Richards, Eric Saupe, Austin Truong, Alan Mieu
 * Team: Acid Fire
 * Date: 01/26/2012
 *
 * Description:
 *
 * This is the header file for the BST class, this class creates a 
 * binary search tree.
 */
#include <string>
#include <vector>
#include "BinaryNode.h"

using namespace std;

class BST {
 public:

  BST(); //default constructor
  
  /**
   *This is the function which we use to add an element to our bst.
   *
   *Parameters: newElement - the element to insert
   */
  bool add(string *newElement);

  /**
   *This function tells us whether a particular string exists in the bst.
   *
   *Parameters: searchElement - the element to search for
   *
   *Return: true if bst contains searchElement and false otherwise
   */
  bool contains(string *searchElement);

  /**
   *This function SHOULDN'T be called unless we determine that  a string
   *doesn't exist in our bst by using the contains method.
   *
   *Parameters: searchElement - the element to get suggestions for.
   *
   *Return: A suggested alternate word to searchElement
   */
  string *nearby(string *searchElement);
	
  //destructor
  ~BST();
 private:
  //These are private helper functions that will be used to help the above functions recursively. Don't touch them.
  bool addRecursive(BinaryNode *current, string *item);

  bool containsRecursive(BinaryNode *current, string *item);

  string *nearbyRecursive(BinaryNode *current, string *item);

  BinaryNode *root;

};

#endif
