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
  return (BSTSet.insert(word)).second;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryBST::find(std::string word) const
{
  if(BSTSet.find(word) == BSTSet.end()){
    return false;   
  }
  return true;
}

/* Destructor */
DictionaryBST::~DictionaryBST(){
  BSTSet.clear();
}
