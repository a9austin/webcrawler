/**
 * Author: George Richards, Eric Saupe, Austin Truong, Alan Mieu
 * Team: Acid Fire
 * Date: 01/26/2012
 *
 * Description:
 *
 * This is the implementation file for the BinaryNode class, this class creates a 
 * binary nodes to be stored in our bst.
 */

#include <string>
#include <cstdlib>
#include "BinaryNode.h"

using namespace std;


BinaryNode::BinaryNode(string *_data, BinaryNode *_leftChild, BinaryNode *_rightChild, BinaryNode *_parent) {
  this->data = _data;
  this->left = _leftChild;
  this->right = _rightChild;
  this->parent = _parent;
}

BinaryNode::BinaryNode(string *_data, BinaryNode *_parent) {
  this->data = _data;
  this->parent = _parent;
  this->left = NULL;
  this->right = NULL;
}

string *BinaryNode::getData() {
  return this->data;
}

BinaryNode *BinaryNode::getRight() {
  return this->right;
}

BinaryNode *BinaryNode:: getLeft() {
  return this->left;
}

BinaryNode *BinaryNode:: getParent() {
  return this->parent;
}

void BinaryNode::setParent(BinaryNode *node) {
  this->parent = node;
}

void BinaryNode::setRight(BinaryNode *node) {
  this->right = node;
}

void BinaryNode::setLeft(BinaryNode *node) {
  this->left = node;
}

void BinaryNode::setData(string *_data) {
  this->data = _data;
}

bool BinaryNode::containsData(string *_data){
  return (this->data->compare(*_data) == 0);
}

BinaryNode::~BinaryNode() {
	delete this->data;
	delete this->left;
	delete this->right;
}
