/*
 * Authors: Alexis Atianzar, Arun Ramakrishnan
 * Date: 10/10/16
 * Description: This class uses a BST to store words from a dictionary
 * in a sorted manner, quickly. 
 */

#include "util.h"
#include "DictionaryBST.h"

/* Create a new Dictionary that uses a BST back end */
DictionaryBST::DictionaryBST(){
  std::set<std::string> BSTSet;
}

/* Insert a word into the dictionary. */
bool DictionaryBST::insert(std::string word)
{
  return std::get<1>(BSTSet.insert(word));
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryBST::find(std::string word) const
{
  return std::get<1>(BSTSet.find(word));
}

/* Destructor */
DictionaryBST::~DictionaryBST(){
  delete BSTSet;
  delete this;
}
