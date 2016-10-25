/*
 * Authors: Alexis Atianzar, Arun Ramakrishnan
 * Date: 10/10/16
 * Description: This class uses a Hashtable to store words from a dictionary
 * in a sorted manner, quickly. 
 */


#include "util.h"
#include "DictionaryHashtable.h"
#include <unordered_set>


/* Create a new Dictionary that uses a Hashset back end */
DictionaryHashtable::DictionaryHashtable(){
  std::unordered_set<std::string> dictionaryHashSet;
}

/* Insert a word into the dictionary. */
bool DictionaryHashtable::insert(std::string word)
{
  return (dictionaryHashSet.insert(word)).second;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryHashtable::find(std::string word) const
{
  if(dictionaryHashSet.find(word) != dictionaryHashSet.end()){
    return true;
  }
  return false;
}

/* Destructor */
DictionaryHashtable::~DictionaryHashtable()
{
  dictionaryHashSet.clear();
}
