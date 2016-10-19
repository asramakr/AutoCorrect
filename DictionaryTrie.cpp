#include "util.h"
#include "DictionaryTrie.h"
#include <iostream>
#include <set>
#include <string>
#include <stack>
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

  while(counter < word.size()){ //loop that loops the through the word
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
    if(counter == word.size()){ //check if last char
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
  while(counter < word.size()){
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
    if(counter == word.size()){ //check if at word end
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
  std::pair <unsigned int, std::string> wordPairs;
  std::set< pair<unsigned int, std::string> > totalWords;

  unsigned int counter = 0;
  Node * currentNode = root;
  while(counter < prefix.size()){
    if(currentNode != NULL){
      if((int)(prefix[counter]) == 32){
        currentNode = currentNode->alphabet[26]; //the space node
      }
      else{
        //the rest of the alphabet
        currentNode = currentNode->alphabet[(int)(prefix[counter])-97];
      }
    }
    else{
      return words;
    }
    counter++;
  }
  
  if (currentNode->isWord == true) {
    wordPairs.first = currentNode->freq;
    wordPairs.second = wordFinder(currentNode);
    totalWords.insert(wordPairs);
  }
  while(currentNode){
    //search through the whole alphabet to find a child
    if(currentNode->alphabet[0]){
      currentNode = currentNode->alphabet[0];
    }
    else if(currentNode->alphabet[1]){
      currentNode = currentNode->alphabet[1];
    }
    else if(currentNode->alphabet[2]){
      currentNode = currentNode->alphabet[2];
    }
    else if(currentNode->alphabet[3]){
      currentNode = currentNode->alphabet[3];
    }
    else if(currentNode->alphabet[4]){
      currentNode = currentNode->alphabet[4];
    }
    else if(currentNode->alphabet[5]){
      currentNode = currentNode->alphabet[5];
    }
    else if(currentNode->alphabet[6]){
      currentNode = currentNode->alphabet[6];
    }
    else if(currentNode->alphabet[7]){
      currentNode = currentNode->alphabet[7];
    }
    else if(currentNode->alphabet[8]){
      currentNode = currentNode->alphabet[8];
    }
    else if(currentNode->alphabet[9]){
      currentNode = currentNode->alphabet[9];
    }
    else if(currentNode->alphabet[10]){
      currentNode = currentNode->alphabet[10];
    }
    else if(currentNode->alphabet[11]){
      currentNode = currentNode->alphabet[11];
    }
    else if(currentNode->alphabet[12]){
      currentNode = currentNode->alphabet[12];
    }
    else if(currentNode->alphabet[13]){
      currentNode = currentNode->alphabet[13];
    }
    else if(currentNode->alphabet[14]){
      currentNode = currentNode->alphabet[14];
    }
    else if(currentNode->alphabet[15]){
      currentNode = currentNode->alphabet[15];
    }
    else if(currentNode->alphabet[16]){
      currentNode = currentNode->alphabet[16];
    }
    else if(currentNode->alphabet[17]){
      currentNode = currentNode->alphabet[17];
    }
    else if(currentNode->alphabet[18]){
      currentNode = currentNode->alphabet[18];
    }
    else if(currentNode->alphabet[19]){
      currentNode = currentNode->alphabet[19];
    }
    else if(currentNode->alphabet[20]){
      currentNode = currentNode->alphabet[20];
    }
    else if(currentNode->alphabet[21]){
      currentNode = currentNode->alphabet[21];
    }
    else if(currentNode->alphabet[22]){
      currentNode = currentNode->alphabet[22];
    }
    else if(currentNode->alphabet[23]){
      currentNode = currentNode->alphabet[23];
    }
    else if(currentNode->alphabet[24]){
      currentNode = currentNode->alphabet[24];
    }
    else if(currentNode->alphabet[25]){
      currentNode = currentNode->alphabet[25];
    }
    else if(currentNode->alphabet[26]){
      currentNode = currentNode->alphabet[26];
    }
    //once the all the child nodes are deleted move up to the parent
    else if(currentNode->parent){      
      currentNode = currentNode->parent;

      //delete leaf
      if(currentNode->alphabet[0]){
        if (currentNode->alphabet[0]->isWord == true) {
          wordPairs.first = currentNode->alphabet[0]->freq;
          wordPairs.second = wordFinder(currentNode->alphabet[0]);
          totalWords.insert(wordPairs);
        }
      }
      else if(currentNode->alphabet[1]){
        if (currentNode->alphabet[1]->isWord == true) {
          wordPairs.first = currentNode->alphabet[1]->freq;
          wordPairs.second = wordFinder(currentNode->alphabet[1]);
          totalWords.insert(wordPairs);
        }
      }
      else if(currentNode->alphabet[2]){
        if (currentNode->alphabet[2]->isWord == true) {
          wordPairs.first = currentNode->alphabet[2]->freq;
          wordPairs.second = wordFinder(currentNode->alphabet[2]);
          totalWords.insert(wordPairs);
        }
      }
      else if(currentNode->alphabet[3]){
        if (currentNode->alphabet[3]->isWord == true) {
          wordPairs.first = currentNode->alphabet[3]->freq;
          wordPairs.second = wordFinder(currentNode->alphabet[3]);
          totalWords.insert(wordPairs);        
        }
      }
      else if(currentNode->alphabet[4]){
        if (currentNode->alphabet[4]->isWord == true) {
          wordPairs.first = currentNode->alphabet[4]->freq;
          wordPairs.second = wordFinder(currentNode->alphabet[4]);
          totalWords.insert(wordPairs);        
        }
      }
      else if(currentNode->alphabet[5]){
        if (currentNode->alphabet[5]->isWord == true) {
          wordPairs.first = currentNode->alphabet[5]->freq;
          wordPairs.second = wordFinder(currentNode->alphabet[5]);
          totalWords.insert(wordPairs);        
        }
      }
      else if(currentNode->alphabet[6]){
        if (currentNode->alphabet[6]->isWord == true) {
          wordPairs.first = currentNode->alphabet[6]->freq;
          wordPairs.second = wordFinder(currentNode->alphabet[6]);
          totalWords.insert(wordPairs);        
        }
      }
      else if(currentNode->alphabet[7]){
        if (currentNode->alphabet[7]->isWord == true) {
          wordPairs.first = currentNode->alphabet[7]->freq;
          wordPairs.second = wordFinder(currentNode->alphabet[7]);
          totalWords.insert(wordPairs);        
        }
      }
      else if(currentNode->alphabet[8]){
        if (currentNode->alphabet[8]->isWord == true) {
          wordPairs.first = currentNode->alphabet[8]->freq;
          wordPairs.second = wordFinder(currentNode->alphabet[8]);
          totalWords.insert(wordPairs);        
        }
      }
      else if(currentNode->alphabet[9]){
         if (currentNode->alphabet[9]->isWord == true) {
          wordPairs.first = currentNode->alphabet[9]->freq;
          wordPairs.second = wordFinder(currentNode->alphabet[9]);
          totalWords.insert(wordPairs);        
         }
      }
      else if(currentNode->alphabet[10]){
        if (currentNode->alphabet[10]->isWord == true) {
          wordPairs.first = currentNode->alphabet[10]->freq;
          wordPairs.second = wordFinder(currentNode->alphabet[10]);
          totalWords.insert(wordPairs);        
        }
      }
      else if(currentNode->alphabet[11]){
        if (currentNode->alphabet[11]->isWord == true) {
          wordPairs.first = currentNode->alphabet[1]->freq;
          wordPairs.second = wordFinder(currentNode->alphabet[1]);
          totalWords.insert(wordPairs);        
        }
      }
      else if(currentNode->alphabet[12]){
        if (currentNode->alphabet[12]->isWord == true) {
          wordPairs.first = currentNode->alphabet[12]->freq;
          wordPairs.second = wordFinder(currentNode->alphabet[12]);
          totalWords.insert(wordPairs);
        }
      }
      else if(currentNode->alphabet[13]){
        if (currentNode->alphabet[13]->isWord == true) {
          wordPairs.first = currentNode->alphabet[13]->freq;
          wordPairs.second = wordFinder(currentNode->alphabet[13]);
          totalWords.insert(wordPairs);        
        }
      }
      else if(currentNode->alphabet[14]){
       if (currentNode->alphabet[14]->isWord == true) {
          wordPairs.first = currentNode->alphabet[14]->freq;
          wordPairs.second = wordFinder(currentNode->alphabet[14]);
          totalWords.insert(wordPairs);
        }
      }
      else if(currentNode->alphabet[15]){
        if (currentNode->alphabet[15]->isWord == true) {
          wordPairs.first = currentNode->alphabet[15]->freq;
          wordPairs.second = wordFinder(currentNode->alphabet[15]);
          totalWords.insert(wordPairs);        
        }
      }
      else if(currentNode->alphabet[16]){
        if (currentNode->alphabet[16]->isWord == true) {
          wordPairs.first = currentNode->alphabet[16]->freq;
          wordPairs.second = wordFinder(currentNode->alphabet[16]);
          totalWords.insert(wordPairs);        
        }
      }
      else if(currentNode->alphabet[17]){
        if (currentNode->alphabet[17]->isWord == true) {
          wordPairs.first = currentNode->alphabet[17]->freq;
          wordPairs.second = wordFinder(currentNode->alphabet[17]);
          totalWords.insert(wordPairs);        
        }
      }
      else if(currentNode->alphabet[18]){
        if (currentNode->alphabet[18]->isWord == true) {
          wordPairs.first = currentNode->alphabet[18]->freq;
          wordPairs.second = wordFinder(currentNode->alphabet[18]);
          totalWords.insert(wordPairs);       
        }
      }
      else if(currentNode->alphabet[19]){
        if (currentNode->alphabet[19]->isWord == true) {
          wordPairs.first = currentNode->alphabet[19]->freq;
          wordPairs.second = wordFinder(currentNode->alphabet[19]);
          totalWords.insert(wordPairs);        
        }
      }
      else if(currentNode->alphabet[20]){
        if (currentNode->alphabet[20]->isWord == true) {
          wordPairs.first = currentNode->alphabet[20]->freq;
          wordPairs.second = wordFinder(currentNode->alphabet[20]);
          totalWords.insert(wordPairs);
        }
      }
      else if(currentNode->alphabet[21]){
        if (currentNode->alphabet[21]->isWord == true) {
          wordPairs.first = currentNode->alphabet[21]->freq;
          wordPairs.second = wordFinder(currentNode->alphabet[21]);
          totalWords.insert(wordPairs);        
        }
      }
      else if(currentNode->alphabet[22]){
        if (currentNode->alphabet[22]->isWord == true) {
          wordPairs.first = currentNode->alphabet[22]->freq;
          wordPairs.second = wordFinder(currentNode->alphabet[22]);
          totalWords.insert(wordPairs);        
        }
      }
      else if(currentNode->alphabet[23]){
        if (currentNode->alphabet[23]->isWord == true) {
          wordPairs.first = currentNode->alphabet[23]->freq;
          wordPairs.second = wordFinder(currentNode->alphabet[23]);
          totalWords.insert(wordPairs);        
        } 
      }
      else if(currentNode->alphabet[24]){
        if (currentNode->alphabet[24]->isWord == true) {
          wordPairs.first = currentNode->alphabet[24]->freq;
          wordPairs.second = wordFinder(currentNode->alphabet[24]);
          totalWords.insert(wordPairs);        
        }
      }
      else if(currentNode->alphabet[25]){
        if (currentNode->alphabet[25]->isWord == true) {
          wordPairs.first = currentNode->alphabet[25]->freq;
          wordPairs.second = wordFinder(currentNode->alphabet[25]);
          totalWords.insert(wordPairs);        
        }
      }
      else if(currentNode->alphabet[26]){
        if (currentNode->alphabet[26]->isWord == true) {
          wordPairs.first = currentNode->alphabet[26]->freq;
          wordPairs.second = wordFinder(currentNode->alphabet[26]);
          totalWords.insert(wordPairs);        
        } 
      }     
    }
  }

  if (totalWords.empty() == true) {
    return words;
  }
  else {
    auto totalWordsList = totalWords.end();
    totalWordsList--;
    for (int i = 0; i < 4; i++) {
      words.push_back((*totalWordsList).second);
      totalWordsList--;
    }
  }

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

std::string DictionaryTrie::wordFinder(Node * currentNode){
  std::stack<char> myQueue;
  std::string word;
  Node * parentNode;

  while(currentNode->parent){
    parentNode = currentNode->parent;
    for(unsigned int i=0; i<27; i++){
      if(currentNode == parentNode->alphabet[i]){
        switch(i){
          case 0: 
            myQueue.push('a');
            break;
          case 1: 
            myQueue.push('b');
            break;
          case 2: 
            myQueue.push('c');
            break;
          case 3: 
            myQueue.push('d');
            break;
          case 4: 
            myQueue.push('e');
            break;
          case 5: 
            myQueue.push('f');
            break;
          case 6: 
            myQueue.push('g');
            break;
          case 7: 
            myQueue.push('h');
            break;
          case 8: 
            myQueue.push('i');
            break;
          case 9: 
            myQueue.push('j');
            break;
          case 10: 
            myQueue.push('k');
            break;
          case 11: 
            myQueue.push('l');
            break;
          case 12: 
            myQueue.push('m');
            break;
          case 13: 
            myQueue.push('n');
            break;
          case 14: 
            myQueue.push('o');
            break;
          case 15: 
            myQueue.push('p');
            break;
          case 16: 
            myQueue.push('q');
            break;
          case 17: 
            myQueue.push('r');
            break;
          case 18: 
            myQueue.push('s');
            break;
          case 19: 
            myQueue.push('t');
            break;
          case 20: 
            myQueue.push('u');
            break;
          case 21: 
            myQueue.push('v');
            break;
          case 22: 
            myQueue.push('w');
            break;
          case 23: 
            myQueue.push('x');
            break;
          case 24: 
            myQueue.push('y');
            break;
          case 25: 
            myQueue.push('z');
            break;
          case 26: 
            myQueue.push(' ');
            break;            
        }
      }
    }
    currentNode = currentNode->parent;
  }

  for(unsigned int i=0; i<myQueue.size(); i++){
    word.append(&myQueue.top());
    myQueue.pop();
  }
  return word;
}
