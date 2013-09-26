#ifndef _BINARYNODE_H_
#define _BINARYNODE_H_
/**
 * Author: George Richards, Eric Saupe, Austin Truong, Alan Mieu
 * Team: Acid Fire
 * Date: 01/26/2012
 *
 * Description:
 *
 * This is the header file for the BinaryNode class, this class creates a 
 * binary nodes to be stored in our bst.
 *
 * NOTE:
 * 
 * THIS CLASS SHOULD NOT BE USED OUTSIDE OF THE BST CLASS, CONSIDER THIS
 * CLASS PRIVATE!!
 */
#include <string>

using namespace std;

class BinaryNode {
 public:

  /**
   *This constructor creates a node with the specified children 
   *and the data provided.
   */
  BinaryNode(string *_data, BinaryNode *_leftChild, BinaryNode *_rightChild, BinaryNode *_parent);

  /**
   *This constructor creates a node with the provided data.
   */
  BinaryNode(string *_data, BinaryNode *_parent);

  /**
   *This function returns the data in the node
   */
  string *getData();

  /**
   *This function returns the node on this one's right.
   */
  BinaryNode *getRight();

  /**
   *This function returns the node on this one's left.
   */
  BinaryNode *getLeft();

  /**
   *This function returns this node's parent
   */
  BinaryNode *getParent();

  /**
   *This function sets this node's parent
   */
  void setParent(BinaryNode *node);

  /**
   *This function sets the node on this one's right
   */
  void setRight(BinaryNode *node);

  /**
   *This function sets the node on this one's left
   */
  void setLeft(BinaryNode *node);

  /**
   *This function lets us set the data of this node
   */
  void setData(string *_data);

  /**
   *This function checks if our node contains the provided data.
   */
  bool containsData(string *_data);

  //destructor
  ~BinaryNode();

 private:
  //private stuff don't touch
  string *data;
  BinaryNode *right;
  BinaryNode *left;
  BinaryNode *parent;
};
#endif
