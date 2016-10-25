/*
 * Authors: Alexis Atianzar, Arun Ramakrishnan
 * Date: 10/10/16
 * Description: This class tests the dictionary classes by testing their
 * run time, and seeing how fast they run comparitvely.
 */


#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<set>
#include<cstdlib>
#include <string>
#include "util.h"
#include "DictionaryTrie.h"
#include "DictionaryBST.h"
#include "DictionaryHashtable.h"
#define LETTERS 26
using namespace std;


int main(int argc, char** argv)
{
  unsigned int min_size = (unsigned int)std::atoi(argv[1]);
  unsigned int step_size = (unsigned int)std::atoi(argv[2]);
  unsigned int num_iterations = (unsigned int)std::atoi(argv[3]);
  std::filebuf fb;
  fb.open(argv[4], std::ios::binary);
  std::istream dictfile(&fb);
  Timer time;

  //BST
  DictionaryBST dBST;
  DictionaryHashtable dHash;
  DictionaryTrie dTrie;

  unsigned int dictsize = min_size;
  
 
  Utils::load_dict(dBST, dictfile, dictsize);
  Utils::load_dict(dHash, dictfile, dictsize);
  Utils::load_dict(dTrie, dictfile, dictsize);

  dictfile.seekg(0,ios_base::end);
  unsigned int numFileWords = dictfile.tellg();
  dictfile.seekg(0, ios_base::beg);
  
  // Benchmarking BST
  cout << "DictionaryBST..." << endl;

  for (unsigned int i = 0; i < num_iterations; i++) {    
    dictsize = min_size+i*step_size;
    
    // if fewer than min_size+i*step_size in file, print warning
    if (numFileWords < dictsize) {
      cerr << "WARNING!! Fewer words in file than to be read" << endl;
    }
    
    vector<string> hundredWords;
    std::string line;

    // read 100 words from dictfile and store in vector
    for(int i = 0; i < 100; i++ )
    {
      std::getline( dictfile, line);
      hundredWords.push_back(line);
    }

    long long testTime=0;
    for(int i = 0; i < 10; i++){

      auto BSTBeg = hundredWords.begin();
      time.begin_timer();
      for(int j = 0; j < 100; j++) {
        dBST.find(*BSTBeg);
        BSTBeg++;
      }
      testTime += time.end_timer();
    }

    long long avgtestTime = testTime/10;

    cout << dictsize << "\t" << avgtestTime << endl;
  }

  cout << endl;

  // Benchmarking HashTable
  dictfile.seekg(0, ios_base::beg);  
  cout << "DictionaryHashTable..." << endl;

  for (unsigned int i = 0; i < num_iterations; i++) {    
    dictsize = min_size+i*step_size;
    
    // if fewer than min_size+i*step_size in file, print warning
    if (numFileWords < dictsize) {
      cerr << "WARNING!! Fewer words in file than to be read" << endl;
    }
    
    vector<string> hundredWords;
    std::string line;

    // read 100 words from dictfile and store in vector
    for(int i = 0; i < 100; i++ )
    {
      std::getline( dictfile, line);
      hundredWords.push_back(line);
    }

    long long testTime = 0;
    for(int i = 0; i < 10; i++){

      auto HashBeg = hundredWords.begin();
      time.begin_timer();
      for(int j = 0; j < 100; j++) {
        dHash.find(*HashBeg);
        HashBeg++;
      }
      testTime += time.end_timer();
    }

    long long avgtestTime = testTime/10;

    cout << dictsize << "\t" << avgtestTime << endl;
  } 

  cout << endl;

  // Benchmarking MultiwayTrie
  dictfile.seekg(0, ios_base::beg);  
  cout << "DictionaryTrie..." << endl;

  for (unsigned int i = 0; i < num_iterations; i++) {    
    dictsize = min_size+i*step_size;
    
    // if fewer than min_size+i*step_size in file, print warning
    if (numFileWords < dictsize) {
      cerr << "WARNING!! Fewer words in file than to be read" << endl;
    }
    
    vector<string> hundredWords;
    std::string line;

    // read 100 words from dictfile and store in vector
    for(int i = 0; i < 100; i++ )
    {
      std::getline( dictfile, line);
      hundredWords.push_back(line);
    }

    long long testTime = 0;
    for(int i = 0; i < 10; i++){

      auto TrieBeg = hundredWords.begin();
      time.begin_timer();
      for(int j = 0; j < 100; j++) {
        dTrie.find(*TrieBeg);
        TrieBeg++;
      }
      testTime += time.end_timer();
    }

    long long avgtestTime = testTime/10;

    cout << dictsize << "\t" << avgtestTime << endl;
  }
  fb.close();   
}
