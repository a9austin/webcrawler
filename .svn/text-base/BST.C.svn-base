/**
 * Author: George Richards, Eric Saupe, Austin Truong, Alan Mieu
 * Team: Acid Fire
 * Date: 01/26/2012
 *
 * Description:
 *
 * This is the implementation file for the BST class, this class creates a 
 * binary search tree.
 */

#include <string>
#include <vector>
#include <cstdlib>
#include "BST.h"


using namespace std;

BST::BST() {
  this->root = NULL;
}

bool BST::add(string *newElement) {
  if (this->root == NULL) {
    this->root = new BinaryNode(newElement, NULL);
    return true;
  }
  if (newElement == NULL) {
    return false;
  }
  return addRecursive(root, newElement);
}

bool BST::contains(string *searchElement) {
  if(this->root->containsData(searchElement)) {
    return true;
  }
  return containsRecursive(this->root, searchElement);
}

string *BST::nearby(string *searchElement) {
  if (this->root->containsData(searchElement)) {
    return NULL;
  }
  return nearbyRecursive(this->root, searchElement);
}

bool BST::addRecursive(BinaryNode *current, string *item) {
  if (item->compare(*current->getData()) < 0) {
    if(current->getLeft() == NULL) {
      current->setLeft(new BinaryNode(item, current));
      return true;
    }
    else {
      return addRecursive(current->getLeft(), item);
    }
  }
  else {
    if (current->getRight() == NULL) {
      current->setRight(new BinaryNode(item, current));
      return true;
    }
    else {
      return addRecursive(current->getRight(), item);
    }
  }
}

bool BST::containsRecursive(BinaryNode *current, string *item) {
  if (item->compare(*current->getData()) < 0) {
    if (current->getLeft() == NULL) {
      return false;
    }
    if (current->getLeft()->getData()->compare(*item) == 0) {
      return true;
    }
    else {
      return containsRecursive(current->getLeft(), item);
    }
  }
  else {
    if (current->getRight() == NULL) {
      return false;
    }
    if (current->getRight()->getData()->compare(*item) == 0) {
      return true;
    }
    else {
      return containsRecursive(current->getRight(), item);
    }
  }
}
string *BST::nearbyRecursive(BinaryNode *current, string *item) {
  if (item->compare(*current->getData()) < 0) {
    if (current->getLeft() == NULL) {
      return current->getParent()->getData();
    }
    if (current->getLeft()->getData()->compare(*item) == 0) {
      return current->getData();
    }
    else {
      return nearbyRecursive(current->getLeft(), item);
    }
  }
  else {
    if (current->getRight() == NULL) {
      return current->getParent()->getData();
    }
    if (current->getRight()->getData()->compare(*item) == 0) {
      return current->getData();
    }
    else {
      return nearbyRecursive(current->getRight(), item);
    }
  }
}
BST::~BST() {
  delete this->root;		
}
