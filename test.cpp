#include<iostream>
#include <fstream>
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

  // TEST 1
 
  //Initialize words
  vector<std::string> words;
  vector<string>::iterator wit;
  vector<string>::iterator wen;
  //initialize nonwords
  set<string> nope;
  set<string>::iterator nit;
  set<string>::iterator nen;

  //Initialize data structures
  DictionaryBST d_bst;
  DictionaryHashtable d_ht;
  DictionaryTrie dt;
  int t_bst, t_ht, tt;

  words.push_back("harry");
  words.push_back("sriram");
  words.push_back("cse");
  words.push_back("crucio");
  words.push_back("autocomplete");

  nope.insert("voldemort");
  nope.insert("bellatrix");
  nope.insert("malfoy");
  nope.insert("avadaKedavra");
  
  
  // Test inserting
  cout << "Inserting into Dictionaries..." << endl;

  wit = words.begin();
  wen = words.end();
  for(; wit != wen; ++wit)
    {
      cout << "Inserting: \"" << *wit << "\"... ";
      t_bst = d_bst.insert(*wit);
      t_ht = d_ht.insert(*wit);
      tt = dt.insert(*wit, 1);
      //cout << t_bst << " " << t_ht << " "<< tt << "... ";
      if(!t_bst)
	{
	  cout << "failed for DictionaryBST... ";
	}
      if(!t_ht)
	{
	  cout << "failed for DictionaryHashset... ";
	}
      if(!tt)
	{
	  cout << "failed for DictionaryTrie... ";
	}
      if(t_bst && t_ht && tt)
	{
	  cout << "PASSED! :D ";
	}
      cout << endl;
  }

  // Test re-inserting
  cout << endl << "Re-inserting elements that were just inserted into Dictionaries..." << endl;

  wit = words.begin();
  wen = words.end();
  for(; wit != wen; ++wit)
    {
      cout << "Inserting: \"" << *wit << "\"... ";
      t_bst = d_bst.insert(*wit);
      t_ht = d_ht.insert(*wit);
      tt = dt.insert(*wit, 0);
      if(t_bst)
        {
          cout << "failed for DictionaryBST... ";
        }
      if(t_ht)
        {
          cout << "failed for DictionaryHashset... ";
        }
      if(tt)
        {
          cout << "failed for DictionaryTrie... ";
        }
      if(!t_bst && !t_ht && !tt)
        {
          cout << "PASSED! :D ";
        }
      cout << endl;
    }

  cout << endl;

  // Test searching
  cout << "Searching the Dictionaries..." << endl;

  wit = words.begin();
  wen = words.end();
  for(; wit != wen; ++wit)
    {
      cout << "Finding: \"" << *wit << "\"... ";
      t_bst = d_bst.find(*wit);
      t_ht = d_ht.find(*wit);
      tt = dt.find(*wit);
      //cout << t_bst << " " << t_ht << " "<< tt << "... ";
      if(!t_bst)
	{
	  cout << "failed for DictionaryBST... ";
	}
      if(!t_ht)
	{
	  cout << "failed for DictionaryHashset... ";
	}
      if(!tt)
	{
	  cout << "failed for DictionaryTrie... ";
	}
      if(t_bst && t_ht && tt)
	{
	  cout << "PASSED! :D ";
	}
      cout << endl;
  }
  cout << endl;

  // Test finding for nonwords
  cout << "Searching for nonwords..." << endl;
  nit = nope.begin();
  nen = nope.end();
  for(; nit != nen; ++nit)
    {
      cout << "Finding: \"" << *nit << "\"... ";
      t_bst = d_bst.find(*nit);
      t_ht = d_ht.find(*nit);
      tt = dt.find(*nit);
      //cout << t_bst << " " << t_ht << " "<< tt << "... ";
      if(t_bst)
	{
	  cout << "failed for DictionaryBST... ";
	}
      if(t_ht)
	{
	  cout << "failed for DictionaryHashset... ";
	}
      if(tt)
	{
	  cout << "failed for DictionaryTrie... ";
	}
      if(!t_bst && !t_ht && !tt)
	{
	  cout << "PASSED! :D ";
	}
      cout << endl;
  }
  cout << endl;

  // TEST 2

  //Initialize words
  vector<std::string> words2;
  vector<string>::iterator wit2;
  vector<string>::iterator wen2;

  //initialize nonwords
  set<string> nope2;
  set<string>::iterator nit2;
  set<string>::iterator nen2;

  //Initialize data structures
  DictionaryBST d_bst2;
  DictionaryHashtable d_ht2;
  DictionaryTrie dt2;
  int t_bst2, t_ht2, tt2;

  words2.push_back("apple");
  words2.push_back("banana");
  words2.push_back("carrots");
  words2.push_back("dragonfruit");
  words2.push_back("eggplant");
  words2.push_back("fennel");
  words2.push_back("grapefuit");

  nope2.insert("asparagus");
  nope2.insert("broccoli");
  nope2.insert("cabbage");
  nope2.insert("daikon");
  nope2.insert("edamame");
  nope2.insert("favaBeans");
  nope2.insert("ginger");
  
  
  // Test inserting
  cout << "Inserting into Dictionaries..." << endl;

  wit2 = words2.begin();
  wen2 = words2.end();
  for(; wit2 != wen2; ++wit2)
    {
      cout << "Inserting: \"" << *wit2 << "\"... ";
      t_bst2 = d_bst2.insert(*wit2);
      t_ht2 = d_ht2.insert(*wit2);
      tt2 = dt2.insert(*wit2, 1);
      //cout << t_bst << " " << t_ht << " "<< tt << "... ";
      if(!t_bst2)
	{
	  cout << "failed for DictionaryBST... ";
	}
      if(!t_ht2)
	{
	  cout << "failed for DictionaryHashset... ";
	}
      if(!tt2)
	{
	  cout << "failed for DictionaryTrie... ";
	}
      if(t_bst2 && t_ht2 && tt2)
	{
	  cout << "PASSED! :D ";
	}
      cout << endl;
  }

  // Test re-inserting
  cout << endl << "Re-inserting elements that were just inserted into Dictionaries..." << endl;

  wit2 = words2.begin();
  wen2 = words2.end();
  for(; wit2 != wen2; ++wit2)
    {
      cout << "Inserting: \"" << *wit2 << "\"... ";
      t_bst2 = d_bst2.insert(*wit2);
      t_ht2 = d_ht2.insert(*wit2);
      tt2 = dt2.insert(*wit2, 0);
      if(t_bst2)
        {
          cout << "failed for DictionaryBST... ";
        }
      if(t_ht2)
        {
          cout << "failed for DictionaryHashset... ";
        }
      if(tt2)
        {
          cout << "failed for DictionaryTrie... ";
        }
      if(!t_bst2 && !t_ht2 && !tt2)
        {
          cout << "PASSED! :D ";
        }
      cout << endl;
    }

  cout << endl;

  // Test searching
  cout << "Searching the Dictionaries..." << endl;

  wit2 = words2.begin();
  wen2 = words2.end();
  for(; wit2 != wen2; ++wit2)
    {
      cout << "Finding: \"" << *wit2 << "\"... ";
      t_bst2 = d_bst2.find(*wit2);
      t_ht2 = d_ht2.find(*wit2);
      tt2 = dt2.find(*wit2);
      //cout << t_bst << " " << t_ht << " "<< tt << "... ";
      if(!t_bst2)
	{
	  cout << "failed for DictionaryBST... ";
	}
      if(!t_ht2)
	{
	  cout << "failed for DictionaryHashset... ";
	}
      if(!tt2)
	{
	  cout << "failed for DictionaryTrie... ";
	}
      if(t_bst2 && t_ht2 && tt2)
	{
	  cout << "PASSED! :D ";
	}
      cout << endl;
  }
  cout << endl;

  // Test finding for nonwords
  cout << "Searching for nonwords..." << endl;
  nit2 = nope2.begin();
  nen2 = nope2.end();
  for(; nit2 != nen2; ++nit2)
    {
      cout << "Finding: \"" << *nit2 << "\"... ";
      t_bst2 = d_bst2.find(*nit2);
      t_ht2 = d_ht2.find(*nit2);
      tt2 = dt2.find(*nit2);
      //cout << t_bst << " " << t_ht << " "<< tt << "... ";
      if(t_bst2)
	{
	  cout << "failed for DictionaryBST... ";
	}
      if(t_ht2)
	{
	  cout << "failed for DictionaryHashset... ";
	}
      if(tt2)
	{
	  cout << "failed for DictionaryTrie... ";
	}
      if(!t_bst2 && !t_ht2 && !tt2)
	{
	  cout << "PASSED! :D ";
	}
      cout << endl;
  }
  cout << endl;

  
    // TEST 3

  //Initialize words
  vector<std::string> words3;
  vector<string>::iterator wit3;
  vector<string>::iterator wen3;

  //initialize nonwords
  set<string> nope3;
  set<string>::iterator nit3;
  set<string>::iterator nen3;

  //Initialize data structures
  DictionaryBST d_bst3;
  DictionaryHashtable d_ht3;
  DictionaryTrie dt3;
  int t_bst3, t_ht3, tt3;

  words3.push_back("listen");
  words3.push_back("silent");
  words3.push_back("rescue");
  words3.push_back("secure");
  words3.push_back("arcs");
  words3.push_back("scar");
  words3.push_back("cars");

  nope3.insert("ball");
  nope3.insert("tail");
  nope3.insert("smell");
  nope3.insert("bottle");
  nope3.insert("chair");
  nope3.insert("orange");
  nope3.insert("saturday");
  
  
  // Test inserting
  cout << "Inserting into Dictionaries..." << endl;

  wit3 = words3.begin();
  wen3 = words3.end();
  for(; wit3 != wen3; ++wit3)
    {
      cout << "Inserting: \"" << *wit3 << "\"... ";
      t_bst3 = d_bst3.insert(*wit3);
      t_ht3 = d_ht3.insert(*wit3);
      tt3 = dt3.insert(*wit3, 1);
      //cout << t_bst << " " << t_ht << " "<< tt << "... ";
      if(!t_bst3)
	{
	  cout << "failed for DictionaryBST... ";
	}
      if(!t_ht3)
	{
	  cout << "failed for DictionaryHashset... ";
	}
      if(!tt3)
	{
	  cout << "failed for DictionaryTrie... ";
	}
      if(t_bst3 && t_ht3 && tt3)
	{
	  cout << "PASSED! :D ";
	}
      cout << endl;
  }

  // Test re-inserting
  cout << endl << "Re-inserting elements that were just inserted into Dictionaries..." << endl;

  wit3 = words3.begin();
  wen3 = words3.end();
  for(; wit3 != wen3; ++wit3)
    {
      cout << "Inserting: \"" << *wit3 << "\"... ";
      t_bst3 = d_bst3.insert(*wit3);
      t_ht3 = d_ht3.insert(*wit3);
      tt3 = dt3.insert(*wit3, 0);
      if(t_bst3)
        {
          cout << "failed for DictionaryBST... ";
        }
      if(t_ht3)
        {
          cout << "failed for DictionaryHashset... ";
        }
      if(tt3)
        {
          cout << "failed for DictionaryTrie... ";
        }
      if(!t_bst3 && !t_ht3 && !tt3)
        {
          cout << "PASSED! :D ";
        }
      cout << endl;
    }

  cout << endl;

  // Test searching
  cout << "Searching the Dictionaries..." << endl;

  wit3 = words3.begin();
  wen3 = words3.end();
  for(; wit3 != wen3; ++wit3)
    {
      cout << "Finding: \"" << *wit3 << "\"... ";
      t_bst3 = d_bst3.find(*wit3);
      t_ht3 = d_ht3.find(*wit3);
      tt3 = dt3.find(*wit3);
      //cout << t_bst << " " << t_ht << " "<< tt << "... ";
      if(!t_bst3)
	{
	  cout << "failed for DictionaryBST... ";
	}
      if(!t_ht3)
	{
	  cout << "failed for DictionaryHashset... ";
	}
      if(!tt3)
	{
	  cout << "failed for DictionaryTrie... ";
	}
      if(t_bst3 && t_ht3 && tt3)
	{
	  cout << "PASSED! :D ";
	}
      cout << endl;
  }
  cout << endl;

  // Test finding for nonwords
  cout << "Searching for nonwords..." << endl;
  nit3 = nope3.begin();
  nen3 = nope3.end();
  for(; nit3 != nen3; ++nit3)
    {
      cout << "Finding: \"" << *nit3 << "\"... ";
      t_bst3 = d_bst3.find(*nit3);
      t_ht3 = d_ht3.find(*nit3);
      tt3 = dt3.find(*nit3);
      //cout << t_bst << " " << t_ht << " "<< tt << "... ";
      if(t_bst3)
	{
	  cout << "failed for DictionaryBST... ";
	}
      if(t_ht3)
	{
	  cout << "failed for DictionaryHashset... ";
	}
      if(tt3)
	{
	  cout << "failed for DictionaryTrie... ";
	}
      if(!t_bst3 && !t_ht3 && !tt3)
	{
	  cout << "PASSED! :D ";
	}
      cout << endl;
  }
  cout << endl;

  
/*You are supposed to add more test cases in this file */
   DictionaryBST dBST1;
   std::ifstream in;

   in.open("freq_dict.txt", std::ifstream::in);
   Utils::load_dict(dBST1,in);
   in.close();
   
  return 0;
}
