#include "util.h"
#include "DictionaryTrie.h"
#include <iostream>
using namespace std;

/* Create a new Dictionary that uses a Trie back end */
DictionaryTrie::DictionaryTrie(){
  root = new Node();
}

Node::Node() {
  for(int i = 0; i < 27; ++i) {
    alphabet[i] = NULL;
  }
  parent = NULL;
  isWord = false;
  freq = 0;
}

/* Insert a word with its frequency into the dictionary.
 * Return true if the word was inserted, and false if it
 * was not (i.e. it was already in the dictionary or it was
 * invalid (empty string) */
bool DictionaryTrie::insert(std::string word, unsigned int freq)
{
  if(word.size() == 0){
    return false; //if the string doesn't exist, return false
  }
  unsigned int counter = 0; //counter to keep track of word array
  Node* currentNode = root;
  while(counter < word.size()-1){ //loop that loops the through the word
    int hashWord = (int)word.at(counter); //the ascii value of char
    //if the char is a space
    if(hashWord == 32 && currentNode->alphabet[26] != NULL){
      currentNode->alphabet[26]->parent = currentNode;
      currentNode = currentNode->alphabet[26];
    }
    //else use the hashWord-97
    else if(currentNode->alphabet[hashWord-97] != NULL){
      currentNode->alphabet[hashWord-97]->parent = currentNode;
      currentNode = currentNode->alphabet[hashWord-97];      
    }
    //if the Node doesn't exist create it
    else{
      if(hashWord == 32){
        currentNode->alphabet[26] = new Node();
        currentNode->alphabet[26]->parent = currentNode;
        currentNode = currentNode->alphabet[26];
      }
      else{
        currentNode->alphabet[hashWord-97] = new Node();
        currentNode->alphabet[hashWord-97]->parent = currentNode;      
        currentNode = currentNode->alphabet[hashWord-97]; 
      }
    }
    counter++; //increment counter
    if(counter == word.size()-1){ //check if last char
      if(currentNode->isWord == true){
        if(currentNode->freq > freq){
          currentNode->freq = freq;
        }
        return false; //return false if the word is already inserted
      }
      currentNode->isWord = true; //make isWord true
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
      if((int)(word[counter]) == 32){
        currentNode = currentNode->alphabet[26]; //the space node
      }
      else{
        //the rest of the alphabet
        currentNode = currentNode->alphabet[(int)(word[counter])-97];
      }      
    }
    else{
      return false; //if a letter doesn't exist return false
    }
    counter++;//counter increments every loop
    if(counter == word.size()-1){ //check if at word end
      if(currentNode->isWord == true){
        return true; //return true if word is found
      }
    }
  }
  return false; //if it isn't found, return false
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
  Node * curr = root; //starts at root
  while(curr){
    //search through the whole alphabet to find a child
    if(curr->alphabet[0]){
      curr = curr->alphabet[0];
    }
    else if(curr->alphabet[1]){
      curr = curr->alphabet[1];
    }
    else if(curr->alphabet[2]){
      curr = curr->alphabet[2];
    }
    else if(curr->alphabet[3]){
      curr = curr->alphabet[3];
    }
    else if(curr->alphabet[4]){
      curr = curr->alphabet[4];
    }
    else if(curr->alphabet[5]){
      curr = curr->alphabet[5];
    }
    else if(curr->alphabet[6]){
      curr = curr->alphabet[6];
    }
    else if(curr->alphabet[7]){
      curr = curr->alphabet[7];
    }
    else if(curr->alphabet[8]){
      curr = curr->alphabet[8];
    }
    else if(curr->alphabet[9]){
      curr = curr->alphabet[9];
    }
    else if(curr->alphabet[10]){
      curr = curr->alphabet[10];
    }
    else if(curr->alphabet[11]){
      curr = curr->alphabet[11];
    }
    else if(curr->alphabet[12]){
      curr = curr->alphabet[12];
    }
    else if(curr->alphabet[13]){
      curr = curr->alphabet[13];
    }
    else if(curr->alphabet[14]){
      curr = curr->alphabet[14];
    }
    else if(curr->alphabet[15]){
      curr = curr->alphabet[15];
    }
    else if(curr->alphabet[16]){
      curr = curr->alphabet[16];
    }
    else if(curr->alphabet[17]){
      curr = curr->alphabet[17];
    }
    else if(curr->alphabet[18]){
      curr = curr->alphabet[18];
    }
    else if(curr->alphabet[19]){
      curr = curr->alphabet[19];
    }
    else if(curr->alphabet[20]){
      curr = curr->alphabet[20];
    }
    else if(curr->alphabet[21]){
      curr = curr->alphabet[21];
    }
    else if(curr->alphabet[22]){
      curr = curr->alphabet[22];
    }
    else if(curr->alphabet[23]){
      curr = curr->alphabet[23];
    }
    else if(curr->alphabet[24]){
      curr = curr->alphabet[24];
    }
    else if(curr->alphabet[25]){
      curr = curr->alphabet[25];
    }
    else if(curr->alphabet[26]){
      curr = curr->alphabet[26];
    }
    //once the all the child nodes are deleted move up to the parent
    else if(curr->parent){      
      curr = curr->parent;

      //delete leaf
      if(curr->alphabet[0]){
        delete curr->alphabet[0];
        curr->alphabet[0] = NULL;
      }
      else if(curr->alphabet[1]){
        delete curr->alphabet[1];
        curr->alphabet[1] = NULL;        
      }
      else if(curr->alphabet[2]){
        delete curr->alphabet[2];
        curr->alphabet[2] = NULL;       
      }
      else if(curr->alphabet[3]){
        delete curr->alphabet[3];
        curr->alphabet[3] = NULL; 
      }
      else if(curr->alphabet[4]){
        delete curr->alphabet[4];
        curr->alphabet[4] = NULL; 
      }
      else if(curr->alphabet[5]){
        delete curr->alphabet[5];
        curr->alphabet[5] = NULL; 
      }
      else if(curr->alphabet[6]){
        delete curr->alphabet[6];
        curr->alphabet[6] = NULL; 
      }
      else if(curr->alphabet[7]){
        delete curr->alphabet[7];
        curr->alphabet[7] = NULL; 
      }
      else if(curr->alphabet[8]){
        delete curr->alphabet[8];
        curr->alphabet[8] = NULL; 
      }
      else if(curr->alphabet[9]){
        delete curr->alphabet[9];
        curr->alphabet[9] = NULL; 
      }
      else if(curr->alphabet[10]){
        delete curr->alphabet[10];
        curr->alphabet[10] = NULL; 
      }
      else if(curr->alphabet[11]){
        delete curr->alphabet[11];
        curr->alphabet[11] = NULL; 
      }
      else if(curr->alphabet[12]){
        delete curr->alphabet[12];
        curr->alphabet[12] = NULL; 
      }
      else if(curr->alphabet[13]){
        delete curr->alphabet[13];
        curr->alphabet[13] = NULL; 
      }
      else if(curr->alphabet[14]){
        delete curr->alphabet[14];
        curr->alphabet[14] = NULL; 
      }
      else if(curr->alphabet[15]){
        delete curr->alphabet[15];
        curr->alphabet[15] = NULL; 
      }
      else if(curr->alphabet[16]){
        delete curr->alphabet[16];
        curr->alphabet[16] = NULL; 
      }
      else if(curr->alphabet[17]){
        delete curr->alphabet[17];
        curr->alphabet[17] = NULL; 
      }
      else if(curr->alphabet[18]){
        delete curr->alphabet[18];
        curr->alphabet[18] = NULL; 
      }
      else if(curr->alphabet[19]){
        delete curr->alphabet[19];
        curr->alphabet[19] = NULL; 
      }
      else if(curr->alphabet[20]){
        delete curr->alphabet[20];
        curr->alphabet[20] = NULL; 
      }
      else if(curr->alphabet[21]){
        delete curr->alphabet[21];
        curr->alphabet[21] = NULL; 
      }
      else if(curr->alphabet[22]){
        delete curr->alphabet[22];
        curr->alphabet[22] = NULL; 
      }
      else if(curr->alphabet[23]){
        delete curr->alphabet[23];
        curr->alphabet[23] = NULL; 
      }
      else if(curr->alphabet[24]){
        delete curr->alphabet[24];
        curr->alphabet[24] = NULL; 
      }
      else if(curr->alphabet[25]){
        delete curr->alphabet[25];
        curr->alphabet[25] = NULL; 
      }
      else if(curr->alphabet[26]){
        delete curr->alphabet[26];
        curr->alphabet[26] = NULL;
      }
    }
    //delete last node
    else{
      delete curr;
      curr = NULL;
      break;
    }    
  }  
}
