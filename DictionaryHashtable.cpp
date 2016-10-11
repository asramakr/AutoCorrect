#include "util.h"
#include "DictionaryHashtable.h"

/* Create a new Dictionary that uses a Hashset back end */
DictionaryHashtable::DictionaryHashtable(){
  dictionaryHashSet = std::unordered_set<std::string> dHashTable;
}

/* Insert a word into the dictionary. */
bool DictionaryHashtable::insert(std::string word)
{
  return std::get<1>(dictionaryHashSet.insert(word));
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryHashtable::find(std::string word) const
{
  return std::get<1>(dictionaryHashSet.find(word));
}

/* Destructor */
DictionaryHashtable::~DictionaryHashtable()
{
  delete dictionaryHashSet;
  delete this;
}
