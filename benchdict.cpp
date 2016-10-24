#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<set>
#include<cstdlib>
#include "util.h"
#include "DictionaryTrie.h"
#include "DictionaryBST.h"
#include "DictionaryHashtable.h"
#define LETTERS 26
using namespace std;


int main(int argc, char** argv)
{
  unsigned int min_size = (unsigned int)argv[1];
  unsigned int step_size = (unsigned int)argv[2];
  unsigned int num_iterations = (unsigned int)argv[3];
  ifstream dictfile = (ifstream)argv[4];

  // Benchmarking BST
  cout << "Benchmarking DictionaryBST..." << endl;

  for (unsigned int i = 0; i < num_iterations; i++) {
    DictionaryBST dBST;
    Utils::load_dict(&dBST, dictfile, (min_size+i*step_size));
    unsigned int numFileWords = (dictfile.seekg(0, ios_base::beg), 
        dictfile.seekg(0,ios_base::end));
    
    // if fewer than min_size+i*step_size in file, print warning
    if (numFileWords < (min_size+i*step_size)) {
      cerr << "WARNING!! Fewer words in file than to be read" << endl;
    }
    
    vector<string> hundredWords;
    std::string line;

    // read 100 words from dictfile and store in vector
    for(int i = 0; i < 100; i++ )
    {
      getline( &dictfile, &line);
      hundredWords.push_back(line);
    }

    long long testTime;
    for(int i = 0; i < 10; i++){

      auto BSTBeg = hundredWords.begin();
      util::Timer::begin_timer();
      for(int j = 0; j < 100; j++) {
        dBST.find(*BSTBeg);
        BSTBeg++;
      }
      testTime += util::Timer::end_timer();
    }


  }

