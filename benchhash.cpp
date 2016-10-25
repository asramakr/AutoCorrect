/*
 * Authors: Alexis Atianzar, Arun Ramakrishnan
 * Date: 10/10/16
 * Description: This class uses the hash functions to test the amount 
 * of collisions that occur.
 */

#include<iostream>
#include<fstream>
#include <istream>
#include<string>
#include<algorithm>
#include<set>
#include<cstdlib>
#include <string>
#include <array>
#include "util.h"
#include "DictionaryTrie.h"
#include "DictionaryBST.h"
#include "DictionaryHashtable.h"
#define LETTERS 26
using namespace std;
/*
 * This file measures the amount of collisions created by each hash funcs.
 * We then read in a dic, and use the hash functions to check the collision
 * in an array, and then list them out.
 *
 */
unsigned int HashingSimple(std::string word, unsigned int tablesize)
{
//  char charArray[] = word.toCharArray(); // make an char array from string
  unsigned int wordLength = word.length(); //get the length of string
  unsigned int sum = 0; // sum of all chars in string

  // go through array and add each char to total sum of chars
  for (unsigned int i = 0; i < wordLength; i++) {
    sum += word[i];
  }

  // return the index of the word
  return sum % tablesize;
}

unsigned int HashingSDBM(std::string word, unsigned int tablesize) {

	unsigned int hashNum = 0;
	unsigned int wordLength = word.length();

	for (unsigned int i = 0; i < wordLength; i++)
	{
		hashNum = (word[i]) + (hashNum << 6) + (hashNum << 16) - hashNum;
	}

	return hashNum % tablesize;
}

void testHashFunctions() {
  std::string word = "app";
  unsigned int tablesize = 30;
  unsigned int hashRet1 = HashingSimple(word, tablesize);
  unsigned int hashRet2 = HashingSDBM(word, tablesize);

  cout << "Testing Hashing Functions..." << endl;

  cout << "With word: 'app'" << endl;
  cout << "HashingSimple return: " << hashRet1 << endl;
  cout << "HashingSDBM return: " << hashRet2 << endl;
  cout << endl;

  word = "APP";
  hashRet1 = HashingSimple(word, tablesize);
  hashRet2 = HashingSDBM(word, tablesize);

  cout << "Testing Hashing Functions..." << endl;

  cout << "With word: 'APP'" << endl;
  cout << "HashingSimple return: " << hashRet1 << endl;
  cout << "HashingSDBM return: " << hashRet2 << endl;
  cout << endl;

  word = "space here";
  hashRet1 = HashingSimple(word, tablesize);
  hashRet2 = HashingSDBM(word, tablesize);

  cout << "Testing Hashing Functions..." << endl;

  cout << "With word: 'space here'" << endl;
  cout << "HashingSimple return: " << hashRet1 << endl;
  cout << "HashingSDBM return: " << hashRet2 << endl;
  cout << endl;
  
}
  

int main(int argc, char**argv)
{
  testHashFunctions();

  std::ifstream dictfile;
  dictfile.open(argv[1], std::ios::binary);
  unsigned int num_words = (unsigned int)std::atoi(argv[2]);

  unsigned int M = 2*num_words; // tablesize

  
//  dictfile.seekg(0, ios_base::end);
//  unsigned int numFileWords = dictfile.tellg();
  dictfile.seekg(0, ios_base::beg);


  std::string line;
  unsigned int arr[M] = {};

  cout << "Printing the statistics for hashFunction1 with hash table size "
      << M << endl;

  cout << endl;
  
  for (unsigned int i = 0; i < num_words; i++) {
    std::getline(dictfile, line);
    arr[(HashingSimple(line, M))%(M)]+=1;

//    cout << "Simple: " << line << endl;
  }

  unsigned int arrOfCollisions[M] = { };

  for(unsigned int i = 0; i < M; i++){
    if (arr[i] != 0) {
      unsigned int index = arr[i]-1;
      arrOfCollisions[index] += 1;
    }
    else{
      arrOfCollisions[0]+=1;
    }
  }

  unsigned int numOfSteps = 0;
  unsigned int numOfHits = 0;
  unsigned int worstCase = 0;
  cout << "#hits    #slots receiving the #hits" << endl;
  for(unsigned int i = 0; i < M; i++) {
    if (arrOfCollisions[i] != 0) {
      cout << i << "\t" << arrOfCollisions[i] << endl;
      if (i == 0) {
        numOfSteps++;
      }
      numOfSteps += i;
      numOfHits++;
      if (i > worstCase) {
        worstCase = i;
      }
    }
  }

  float avgSteps = numOfSteps/numOfHits;
  cout << "The average number of steps for a successful search for hash" 
      "function 1 would be " << avgSteps << endl;
  cout << endl;

  cout << "The worst case steps that would be needed to find a word is " <<
      worstCase << endl;
  cout << endl;

  cout << "Printing the statistics for hashFunction2 with hash table size "
      << M << endl;

  cout << endl;
  
  dictfile.seekg(0, ios_base::beg);  
  unsigned int arr2[M] = {};
  
  for (unsigned int i = 0; i < num_words; i++) {
    std::getline(dictfile, line);
    arr2[(HashingSDBM(line, M))%(M)]+=1;
    
//    cout << "SDBM: " << line << endl;

  }

  unsigned int arrOfCollisions2[M] = { };

  for(unsigned int i = 0; i < M; i++){
    if (arr2[i] != 0) {
      unsigned int index = arr2[i]-1;
      arrOfCollisions2[index] += 1;
    }
    else{
      arrOfCollisions2[0]+=1;
    }
  }

  unsigned int numOfSteps2 = 0;
  unsigned int numOfHits2 = 0;
  unsigned int worstCase2 = 0;
  cout << "#hits    #slots receiving the #hits" << endl;
  for(unsigned int i = 0; i < M; i++) {
    if (arrOfCollisions2[i] != 0) {
      cout << i << "\t" << arrOfCollisions2[i] << endl;
      if (i == 0) {
        numOfSteps2++;
      }
      numOfSteps2 += i;
      numOfHits2++;
      if (i > worstCase2) {
        worstCase2 = i;
      }
    }
  }

  float avgSteps2 = numOfSteps2/numOfHits2;
  cout << "The average number of steps for a successful search for hash" 
      "function 2 would be " << avgSteps2 << endl;
  cout << endl;

  cout << "The worst case steps that would be needed to find a word is " <<
      worstCase2 << endl;
  cout << endl;

  dictfile.close();
  
  

}
