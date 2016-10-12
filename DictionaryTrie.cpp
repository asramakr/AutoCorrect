#include "util.h"
#include "DictionaryTrie.h"
#include <iostream>
using namespace std;

/* Create a new Dictionary that uses a Trie back end */
DictionaryTrie::DictionaryTrie(){
  root = new Node();
}

Node::Node() {
  for(int i = 0; i < 26; ++i) {
    alphabet[i] = NULL;
  }
  isWord = false;
  freq = 0;
}

Node::~Node(){
  delete alphabet;
  delete &isWord;
  delete &freq;
}

/* Insert a word with its frequency into the dictionary.
 * Return true if the word was inserted, and false if it
 * was not (i.e. it was already in the dictionary or it was
 * invalid (empty string) */
bool DictionaryTrie::insert(std::string word, unsigned int freq)
{
  if(word.size() == 0){
    return false;
  }
  unsigned int counter = 0;
  Node* currentNode = root;
  while(counter < word.size()-1){
    int hashWord = (int)word.at(counter);
    int total = hashWord - 97;
    cout << total << endl;
    cout << currentNode->alphabet[total] << endl;
    if(currentNode != NULL){
      currentNode = currentNode->alphabet[hashWord-97];      
    }
    else{
      currentNode->alphabet[hashWord-97] = new Node();
      currentNode = currentNode->alphabet[hashWord-97]; 
    }
    counter++;
    if(counter == word.size()-1){
      if(currentNode->isWord == true){
        if(currentNode->freq > freq){
          currentNode->freq = freq;
        }
        return false;
      }
      currentNode->isWord = true;
    }
  }
  return true;
}

/* Return true if word is in the dictionary, and false otherwise */
bool DictionaryTrie::find(std::string word) const
{
  unsigned int counter = 0;
  Node* currentNode = root;
  while(counter < word.size()-1){
    if(currentNode != NULL){
      currentNode = currentNode->alphabet[(int)(word[counter])-97];      
    }
    else{
      return false;
    }
    counter++;
    if(counter == word.size()-1){
      if(currentNode->isWord == true){
        return true;
      }
    }
  }
  return false;
}

/* Return up to num_completions of the most frequent completions
 * of the prefix, such that the completions are words in the dictionary.
 * These completions should be listed from most frequent to least.
 * If there are fewer than num_completions legal completions, this
 * function returns a vector with as many completions as possible.
 * If no completions exist, then the function returns a vector of size 0.
 * The prefix itself might be included in the returned words if the prefix
 * is a word (and is among the num_completions most frequent completions
 * of the prefix)
 */
std::vector<std::string> DictionaryTrie::predictCompletions(std::string prefix, unsigned int num_completions)
{
  std::vector<std::string> words;
  return words;
}

/* Destructor */
DictionaryTrie::~DictionaryTrie(){
  delete root;
}
