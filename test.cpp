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

  wit = words.begin(); // from first word
  wen = words.end(); // after last word

  // insert into the BST, HashTable, and Trie
  for(; wit != wen; ++wit)
    {
      cout << "Inserting: \"" << *wit << "\"... ";
      t_bst = d_bst.insert(*wit);
      t_ht = d_ht.insert(*wit);
      tt = dt.insert(*wit, 1);
      //cout << t_bst << " " << t_ht << " "<< tt << "... ";

  // if insert into BST failed
  if(!t_bst)
	{
	  cout << "failed for DictionaryBST... ";
	}

  // if insert into HashTable failed
  if(!t_ht)
	{
	  cout << "failed for DictionaryHashset... ";
	}

  // if insert into Trie failed
  if(!tt)
	{
	  cout << "failed for DictionaryTrie... ";
	}

  // if all inserted correctly, then all tests passed
  if(t_bst && t_ht && tt)
	{
	  cout << "PASSED! :D ";
	}
      cout << endl;
  }

  // Test re-inserting (should return false)
  cout << endl << "Re-inserting elements that were just inserted into Dictionaries..." << endl;

  wit = words.begin(); // from first word
  wen = words.end(); // after last word

  // insert into each dictionary
  for(; wit != wen; ++wit)
    {
      cout << "Inserting: \"" << *wit << "\"... ";
      t_bst = d_bst.insert(*wit);
      t_ht = d_ht.insert(*wit);
      tt = dt.insert(*wit, 0);

      // if failed for BST
      if(t_bst)
        {
          cout << "failed for DictionaryBST... ";
        }

      // if failed for Hashset
      if(t_ht)
        {
          cout << "failed for DictionaryHashset... ";
        }

      // if failed for Trie
      if(tt)
        {
          cout << "failed for DictionaryTrie... ";
        }

      // if all not inserted, then PASSED
      if(!t_bst && !t_ht && !tt)
        {
          cout << "PASSED! :D ";
        }
      cout << endl;
    }

  cout << endl;

  // Test searching
  cout << "Searching the Dictionaries..." << endl;

  wit = words.begin(); // from first word
  wen = words.end(); // after last word

  // search each dictionary
  for(; wit != wen; ++wit)
    {
      cout << "Finding: \"" << *wit << "\"... ";
      t_bst = d_bst.find(*wit);
      t_ht = d_ht.find(*wit);
      tt = dt.find(*wit);
      //cout << t_bst << " " << t_ht << " "<< tt << "... ";
    
      // if failed for BST
      if(!t_bst)
	{
	  cout << "failed for DictionaryBST... ";
	}

      // if failed for Hashset
      if(!t_ht)
	{
	  cout << "failed for DictionaryHashset... ";
	}

      // if failed for Trie
      if(!tt)
	{
	  cout << "failed for DictionaryTrie... ";
	}

      // if all inserted, then PASSED
      if(t_bst && t_ht && tt)
	{
	  cout << "PASSED! :D ";
	}
      cout << endl;
  }
  cout << endl;

  // Test finding for nonwords
  cout << "Searching for nonwords..." << endl;
  nit = nope.begin(); // from first nonword
  nen = nope.end(); // after last nonword

  // search in each dictionary (should be false)
  for(; nit != nen; ++nit)
    {
      cout << "Finding: \"" << *nit << "\"... ";
      t_bst = d_bst.find(*nit);
      t_ht = d_ht.find(*nit);
      tt = dt.find(*nit);
      //cout << t_bst << " " << t_ht << " "<< tt << "... ";
      
      // if failed for BST
      if(t_bst)
	{
	  cout << "failed for DictionaryBST... ";
	}

      // if failed for Hashset
      if(t_ht)
	{
	  cout << "failed for DictionaryHashset... ";
	}

      // if failed for Trie
      if(tt)
	{
	  cout << "failed for DictionaryTrie... ";
	}

      // if all inserted, then PASSED
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

  wit2 = words2.begin(); // from first word
  wen2 = words2.end(); // after last word

  // insert into each dictionary
  for(; wit2 != wen2; ++wit2)
    {
      cout << "Inserting: \"" << *wit2 << "\"... ";
      t_bst2 = d_bst2.insert(*wit2);
      t_ht2 = d_ht2.insert(*wit2);
      tt2 = dt2.insert(*wit2, 1);
      //cout << t_bst << " " << t_ht << " "<< tt << "... ";
    
      // if failed for BST
      if(!t_bst2)
	{
	  cout << "failed for DictionaryBST... ";
	}

      // if failed for Hashset
      if(!t_ht2)
	{
	  cout << "failed for DictionaryHashset... ";
	}

      // if failed for Trie
      if(!tt2)
	{
	  cout << "failed for DictionaryTrie... ";
	}

      // if all inserted, then PASSED
      if(t_bst2 && t_ht2 && tt2)
	{
	  cout << "PASSED! :D ";
	}
      cout << endl;
  }

  // Test re-inserting (should return false)
  cout << endl << "Re-inserting elements that were just inserted into Dictionaries..." << endl;

  wit2 = words2.begin(); // from first word
  wen2 = words2.end(); // after last word

  // insert into each dictionary
  for(; wit2 != wen2; ++wit2)
    {
      cout << "Inserting: \"" << *wit2 << "\"... ";
      t_bst2 = d_bst2.insert(*wit2);
      t_ht2 = d_ht2.insert(*wit2);
      tt2 = dt2.insert(*wit2, 0);

      // if failed for BST
      if(t_bst2)
        {
          cout << "failed for DictionaryBST... ";
        }

      // if failed for Hashset
      if(t_ht2)
        {
          cout << "failed for DictionaryHashset... ";
        }

      // if failed for Trie
      if(tt2)
        {
          cout << "failed for DictionaryTrie... ";
        }

      // if not inserted in any, then PASSED
      if(!t_bst2 && !t_ht2 && !tt2)
        {
          cout << "PASSED! :D ";
        }
      cout << endl;
    }

  cout << endl;

  // Test searching
  cout << "Searching the Dictionaries..." << endl;

  wit2 = words2.begin(); // from first word
  wen2 = words2.end(); // after last word

  // search each dictionary
  for(; wit2 != wen2; ++wit2)
    {
      cout << "Finding: \"" << *wit2 << "\"... ";
      t_bst2 = d_bst2.find(*wit2);
      t_ht2 = d_ht2.find(*wit2);
      tt2 = dt2.find(*wit2);
      //cout << t_bst << " " << t_ht << " "<< tt << "... ";
     
      // if failed for BST
      if(!t_bst2)
	{
	  cout << "failed for DictionaryBST... ";
	}

      // if failed for Hashset
      if(!t_ht2)
	{
	  cout << "failed for DictionaryHashset... ";
	}

      // if failed for Trie
      if(!tt2)
	{
	  cout << "failed for DictionaryTrie... ";
	}

      // if found in all, then PASSED
      if(t_bst2 && t_ht2 && tt2)
	{
	  cout << "PASSED! :D ";
	}
      cout << endl;
  }
  cout << endl;

  // Test finding for nonwords (should return false)
  cout << "Searching for nonwords..." << endl;
  nit2 = nope2.begin(); // from first nonword
  nen2 = nope2.end(); // after last nonword

  // search each dictionary
  for(; nit2 != nen2; ++nit2)
    {
      cout << "Finding: \"" << *nit2 << "\"... ";
      t_bst2 = d_bst2.find(*nit2);
      t_ht2 = d_ht2.find(*nit2);
      tt2 = dt2.find(*nit2);
      //cout << t_bst << " " << t_ht << " "<< tt << "... ";
      
      // if failed for BST
      if(t_bst2)
	{
	  cout << "failed for DictionaryBST... ";
	}

      // if failed for Hashset
      if(t_ht2)
	{
	  cout << "failed for DictionaryHashset... ";
	}

      // if failed for Trie
      if(tt2)
	{
	  cout << "failed for DictionaryTrie... ";
	}

      // if not found in any, then PASSED
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

  wit3 = words3.begin(); // from first word
  wen3 = words3.end(); // after last word

  // insert into each dictionary
  for(; wit3 != wen3; ++wit3)
    {
      cout << "Inserting: \"" << *wit3 << "\"... ";
      t_bst3 = d_bst3.insert(*wit3);
      t_ht3 = d_ht3.insert(*wit3);
      tt3 = dt3.insert(*wit3, 1);
      //cout << t_bst << " " << t_ht << " "<< tt << "... ";
     
      // if failed for BST
      if(!t_bst3)
	{
	  cout << "failed for DictionaryBST... ";
	}

      // if failed for Hashset
      if(!t_ht3)
	{
	  cout << "failed for DictionaryHashset... ";
	}

      // if failed for Trie
      if(!tt3)
	{
	  cout << "failed for DictionaryTrie... ";
	}

      // if inserted in all, then PASSED
      if(t_bst3 && t_ht3 && tt3)
	{
	  cout << "PASSED! :D ";
	}
      cout << endl;
  }

  // Test re-inserting (should return false)
  cout << endl << "Re-inserting elements that were just inserted into Dictionaries..." << endl;

  wit3 = words3.begin(); // from first word
  wen3 = words3.end(); // after last word

  // insert into each dictionary
  for(; wit3 != wen3; ++wit3)
    {
      cout << "Inserting: \"" << *wit3 << "\"... ";
      t_bst3 = d_bst3.insert(*wit3);
      t_ht3 = d_ht3.insert(*wit3);
      tt3 = dt3.insert(*wit3, 0);

      // if failed for BST
      if(t_bst3)
        {
          cout << "failed for DictionaryBST... ";
        }

      // if failed for Hashset
      if(t_ht3)
        {
          cout << "failed for DictionaryHashset... ";
        }

      // if failed for Trie
      if(tt3)
        {
          cout << "failed for DictionaryTrie... ";
        }

      // if not inserted in any, then PASSED
      if(!t_bst3 && !t_ht3 && !tt3)
        {
          cout << "PASSED! :D ";
        }
      cout << endl;
    }

  cout << endl;

  // Test searching
  cout << "Searching the Dictionaries..." << endl;

  wit3 = words3.begin(); // from first word
  wen3 = words3.end(); // after last word

  // search each dictionary
  for(; wit3 != wen3; ++wit3)
    {
      cout << "Finding: \"" << *wit3 << "\"... ";
      t_bst3 = d_bst3.find(*wit3);
      t_ht3 = d_ht3.find(*wit3);
      tt3 = dt3.find(*wit3);
      //cout << t_bst << " " << t_ht << " "<< tt << "... ";
     
      // if failed for BST
      if(!t_bst3)
	{
	  cout << "failed for DictionaryBST... ";
	}

      // if failed for Hashset
      if(!t_ht3)
	{
	  cout << "failed for DictionaryHashset... ";
	}

      // if failed for Trie
      if(!tt3)
	{
	  cout << "failed for DictionaryTrie... ";
	}

      // if found in all, then PASSED
      if(t_bst3 && t_ht3 && tt3)
	{
	  cout << "PASSED! :D ";
	}
      cout << endl;
  }
  cout << endl;

  // Test finding for nonwords (should return false
  cout << "Searching for nonwords..." << endl;
  nit3 = nope3.begin(); // from first nonword
  nen3 = nope3.end(); // after last nonword

  // search each dictionary
  for(; nit3 != nen3; ++nit3)
    {
      cout << "Finding: \"" << *nit3 << "\"... ";
      t_bst3 = d_bst3.find(*nit3);
      t_ht3 = d_ht3.find(*nit3);
      tt3 = dt3.find(*nit3);
      //cout << t_bst << " " << t_ht << " "<< tt << "... ";
      
      // if failed for BST
      if(t_bst3)
	{
	  cout << "failed for DictionaryBST... ";
	}

      // if failed for Hashset
      if(t_ht3)
	{
	  cout << "failed for DictionaryHashset... ";
	}

      // if failed for Trie
      if(tt3)
	{
	  cout << "failed for DictionaryTrie... ";
	}

      // if not found in any, then PASSED
      if(!t_bst3 && !t_ht3 && !tt3)
	{
	  cout << "PASSED! :D ";
	}
      cout << endl;
  }
  cout << endl;


  // TEST 4

  //Initialize words
  vector<std::string> words4;
  vector<string>::iterator wit4;
  vector<string>::iterator wen4;

  //initialize nonwords
  set<string> nope4;
  set<string>::iterator nit4;
  set<string>::iterator nen4;

  //Initialize data structures
  DictionaryBST d_bst4;
  DictionaryHashtable d_ht4;
  DictionaryTrie dt4;
  int t_bst4, t_ht4, tt4;

  words4.push_back("at");
  words4.push_back("ate");
  words4.push_back("attach");
  words4.push_back("catch");
  words4.push_back("atom");

  nope4.insert("horse");
  nope4.insert("watermelon");
  nope4.insert("world");
  nope4.insert("attract");
  nope4.insert("attachment");
  nope4.insert("catcher");
  
  
  // Test inserting
  cout << "Inserting into Dictionaries..." << endl;

  wit4 = words4.begin(); // from first word
  wen4 = words4.end(); // after last word

  // insert into each dictionary
  for(; wit4 != wen4; ++wit4)
    {
      cout << "Inserting: \"" << *wit4 << "\"... ";
      t_bst4 = d_bst4.insert(*wit4);
      t_ht4 = d_ht4.insert(*wit4);
      tt4 = dt4.insert(*wit4, 1);
      //cout << t_bst << " " << t_ht << " "<< tt << "... ";
     
      // if failed for BST
      if(!t_bst4)
	{
	  cout << "failed for DictionaryBST... ";
	}

      // if failed for Hashset
      if(!t_ht4)
	{
	  cout << "failed for DictionaryHashset... ";
	}

      // if failed for Trie
      if(!tt4)
	{
	  cout << "failed for DictionaryTrie... ";
	}

      // if inserted in all, then PASSED
      if(t_bst4 && t_ht4 && tt4)
	{
	  cout << "PASSED! :D ";
	}
      cout << endl;
  }

  cout << endl;
 
  // Test inserting an empty string (should return false)
  cout << "Inserting an empty string into DictionaryTrie...";
  tt4 = dt4.insert(*wit4, 1);
  if (tt4) {
    cout << "failed" << endl;
  }
  else {
    cout << "PASSED" << endl;
  }

  // Test re-inserting (should return false)
  cout << endl << "Re-inserting elements that were just inserted into Dictionaries..." << endl;

  wit4 = words4.begin(); // from first word
  wen4 = words4.end(); // after last word

  // insert into each dictionary
  for(; wit4 != wen4; ++wit4)
    {
      cout << "Inserting: \"" << *wit4 << "\"... ";
      t_bst4 = d_bst4.insert(*wit4);
      t_ht4 = d_ht4.insert(*wit4);
      tt4 = dt4.insert(*wit4, 0);

      // if failed for BST
      if(t_bst4)
        {
          cout << "failed for DictionaryBST... ";
        }

      // if failed for Hashset
      if(t_ht4)
        {
          cout << "failed for DictionaryHashset... ";
        }

      // if failed for Trie
      if(tt4)
        {
          cout << "failed for DictionaryTrie... ";
        }

      // if not inserted in any, then PASSED
      if(!t_bst4 && !t_ht4 && !tt4)
        {
          cout << "PASSED! :D ";
        }
      cout << endl;
    }

  cout << endl;

  // Test searching
  cout << "Searching the Dictionaries..." << endl;

  wit4 = words4.begin(); // from first word
  wen4 = words4.end(); // after last word

  // search each dictionary
  for(; wit4 != wen4; ++wit4)
    {
      cout << "Finding: \"" << *wit4 << "\"... ";
      t_bst4 = d_bst4.find(*wit4);
      t_ht4 = d_ht4.find(*wit4);
      tt4 = dt4.find(*wit4);
      //cout << t_bst << " " << t_ht << " "<< tt << "... ";
    
      // if failed for BST
      if(!t_bst4)
	{
	  cout << "failed for DictionaryBST... ";
	}

      // if failed for Hashset
      if(!t_ht4)
	{
	  cout << "failed for DictionaryHashset... ";
	}

      // if failed for Trie
      if(!tt4)
	{
	  cout << "failed for DictionaryTrie... ";
	}

      // if found in all, then PASSED
      if(t_bst4 && t_ht4 && tt4)
	{
	  cout << "PASSED! :D ";
	}
      cout << endl;
  }
  cout << endl;

  // Test finding for nonwords (should return false)
  cout << "Searching for nonwords..." << endl;
  nit4 = nope4.begin(); // from first nonword
  nen4 = nope4.end(); // after last nonword

  // search each dictionary
  for(; nit4 != nen4; ++nit4)
    {
      cout << "Finding: \"" << *nit4 << "\"... ";
      t_bst4 = d_bst4.find(*nit4);
      t_ht4 = d_ht4.find(*nit4);
      tt4 = dt4.find(*nit4);
      //cout << t_bst << " " << t_ht << " "<< tt << "... ";
     
      // if failed for BST
      if(t_bst4)
	{
	  cout << "failed for DictionaryBST... ";
	}

      // if failed for Hashset
      if(t_ht4)
	{
	  cout << "failed for DictionaryHashset... ";
	}

      // if failed for Trie
      if(tt4)
	{
	  cout << "failed for DictionaryTrie... ";
	}

      // if not found in any, then PASSED
      if(!t_bst4 && !t_ht4 && !tt4)
	{
	  cout << "PASSED! :D ";
	}
      cout << endl;
  }
  cout << endl;

  // TEST 5

  //Initialize words
  vector<std::string> words5;
  vector<string>::iterator wit5;
  vector<string>::iterator wen5;

  //initialize nonwords
  set<string> nope5;
  set<string>::iterator nit5;
  set<string>::iterator nen5;

  //Initialize data structures
  DictionaryBST d_bst5;
  DictionaryHashtable d_ht5;
  DictionaryTrie dt5;
  int t_bst5, t_ht5, tt5;

  nope5.insert("notHere");
  nope5.insert("nonexistent");
  nope5.insert("itsAnEmptyWorld");
  nope5.insert("imFeelingEmpty");
  nope5.insert("emptyStomach");

  // Test finding for nonwords (should return false)
  cout << "Searching for nonwords..." << endl;
  nit5 = nope5.begin(); // from first nonword
  nen5 = nope5.end(); // after last nonword

  // search each dictionary
  for(; nit5 != nen5; ++nit5)
    {
      cout << "Finding: \"" << *nit5 << "\"... ";
      t_bst5 = d_bst5.find(*nit5);
      t_ht5 = d_ht5.find(*nit5);
      tt5 = dt5.find(*nit5);
      //cout << t_bst << " " << t_ht << " "<< tt << "... ";
      
      // if failed for BST
      if(t_bst5)
	{
	  cout << "failed for DictionaryBST... ";
	}

      // if failed for Hashset
      if(t_ht5)
	{
	  cout << "failed for DictionaryHashset... ";
	}

      // if failed for Trie
      if(tt5)
	{
	  cout << "failed for DictionaryTrie... ";
	}

      // if not found in any, then PASSED
      if(!t_bst5 && !t_ht5 && !tt5)
	{
	  cout << "PASSED! :D ";
	}
      cout << endl;
  }
  cout << endl;

  
  // TEST 6

  //Initialize words
  vector<std::string> words6;
  vector<string>::iterator wit6;
  vector<string>::iterator wen6;

  //initialize nonwords
  set<string> nope6;
  set<string>::iterator nit6;
  set<string>::iterator nen6;

  //Initialize data structures
  DictionaryBST d_bst6;
  DictionaryHashtable d_ht6;
  DictionaryTrie dt6;
  int t_bst6, t_ht6, tt6;

  words6.push_back("this better work");
  words6.push_back("we can only be hopeful");
  words6.push_back("come on now");

  nope6.insert("oh no it didnt work");
  nope6.insert("such a great phrase");
  nope6.insert("yay spaces are good");
  
  
  // Test inserting
  cout << "Inserting into Dictionaries..." << endl;

  wit6 = words6.begin(); // from first word
  wen6 = words6.end(); // after last word

  // insert into each dictionary
  for(; wit6 != wen6; ++wit6)
    {
      cout << "Inserting: \"" << *wit6 << "\"... ";
      t_bst6 = d_bst6.insert(*wit6);
      t_ht6 = d_ht6.insert(*wit6);
      tt6 = dt6.insert(*wit6, 1);
      //cout << t_bst << " " << t_ht << " "<< tt << "... ";
     
      // if failed for BST
      if(!t_bst6)
	{
	  cout << "failed for DictionaryBST... ";
	}

      // if failed for Hashset
      if(!t_ht6)
	{
	  cout << "failed for DictionaryHashset... ";
	}

      // if failed for Trie
      if(!tt6)
	{
	  cout << "failed for DictionaryTrie... ";
	}

      // if inserted in all, then PASSED
      if(t_bst6 && t_ht6 && tt6)
	{
	  cout << "PASSED! :D ";
	}
      cout << endl;
  }

  cout << endl;
 

  // Test re-inserting (should return false)
  cout << endl << "Re-inserting elements that were just inserted into Dictionaries..." << endl;

  wit6 = words6.begin(); // from first word
  wen6 = words6.end(); // after last word

  // insert into each dictionary
  for(; wit6 != wen6; ++wit6)
    {
      cout << "Inserting: \"" << *wit6 << "\"... ";
      t_bst6 = d_bst6.insert(*wit6);
      t_ht6 = d_ht6.insert(*wit6);
      tt6 = dt6.insert(*wit6, 0);

      // if failed for BST
      if(t_bst6)
        {
          cout << "failed for DictionaryBST... ";
        }

      // if failed for Hashset
      if(t_ht6)
        {
          cout << "failed for DictionaryHashset... ";
        }

      // if failed for Trie
      if(tt6)
        {
          cout << "failed for DictionaryTrie... ";
        }

      // if not inserted in any, then PASSED
      if(!t_bst6 && !t_ht6 && !tt6)
        {
          cout << "PASSED! :D ";
        }
      cout << endl;
    }

  cout << endl;

  // Test searching
  cout << "Searching the Dictionaries..." << endl;

  wit6 = words6.begin(); // from first word
  wen6 = words6.end(); // after last word

  // search each dictionary
  for(; wit6 != wen6; ++wit6)
    {
      cout << "Finding: \"" << *wit6 << "\"... ";
      t_bst6 = d_bst6.find(*wit6);
      t_ht6 = d_ht6.find(*wit6);
      tt6 = dt6.find(*wit6);
      //cout << t_bst << " " << t_ht << " "<< tt << "... ";
    
      // if failed for BST
      if(!t_bst6)
	{
	  cout << "failed for DictionaryBST... ";
	}

      // if failed for Hashset
      if(!t_ht6)
	{
	  cout << "failed for DictionaryHashset... ";
	}

      // if failed for Trie
      if(!tt6)
	{
	  cout << "failed for DictionaryTrie... ";
	}

      // if found in all, then PASSED
      if(t_bst6 && t_ht6 && tt6)
	{
	  cout << "PASSED! :D ";
	}
      cout << endl;
  }
  cout << endl;

  // Test finding for nonwords (should return false)
  cout << "Searching for nonwords..." << endl;
  nit6 = nope6.begin(); // from first nonword
  nen6 = nope6.end(); // after last nonword

  // search each dictionary
  for(; nit6 != nen6; ++nit6)
    {
      cout << "Finding: \"" << *nit6 << "\"... ";
      t_bst6 = d_bst6.find(*nit6);
      t_ht6 = d_ht6.find(*nit6);
      tt6 = dt6.find(*nit6);
      //cout << t_bst << " " << t_ht << " "<< tt << "... ";
     
      // if failed for BST
      if(t_bst6)
	{
	  cout << "failed for DictionaryBST... ";
	}

      // if failed for Hashset
      if(t_ht6)
	{
	  cout << "failed for DictionaryHashset... ";
	}

      // if failed for Trie
      if(tt6)
	{
	  cout << "failed for DictionaryTrie... ";
	}

      // if not found in any, then PASSED
      if(!t_bst6 && !t_ht6 && !tt6)
	{
	  cout << "PASSED! :D ";
	}
      cout << endl;
  }
  cout << endl;

  // Test 1: predictCompletions

  cout << "Testing autocomplete..." << endl;
  DictionaryTrie sameWordsTrie;
  std::vector<std::string> topCompletes;
  std::string incompletePrefix = "he";
  unsigned int numTopCompletes = 4;

  sameWordsTrie.insert("he", 1);
  sameWordsTrie.insert("height", 4);
  sameWordsTrie.insert("her", 3);
  sameWordsTrie.insert("hemming", 5);
  sameWordsTrie.insert("headline", 6);
  sameWordsTrie.insert("cat", 1);

  topCompletes = sameWordsTrie.predictCompletions(incompletePrefix, 
      numTopCompletes);
  cout << "Top " << numTopCompletes << " Completions for '" << 
      incompletePrefix << "':" << endl;

  vector<string>::iterator sameWordsBeg;
  vector<string>::iterator sameWordsEnd;

  sameWordsBeg = topCompletes.begin();
  sameWordsEnd = topCompletes.end();


  for (; sameWordsBeg != sameWordsEnd; ++sameWordsBeg) {
    cout << *sameWordsBeg << endl;
  }

  cout << endl;

  // Test 2: predictCompletions
  cout << "Testing autocomplete..." << endl;
  DictionaryTrie sameWordsTrie2;
  std::vector<std::string> topCompletes2;
  std::string incompletePrefix2 = "ca";
  unsigned int numTopCompletes2 = 3;

  sameWordsTrie2.insert("catch", 4);
  sameWordsTrie2.insert("car", 8);
  sameWordsTrie2.insert("cat", 9);
  sameWordsTrie2.insert("california", 6);
  sameWordsTrie2.insert("can", 3);
  sameWordsTrie2.insert("calico", 2);


  topCompletes2 = sameWordsTrie2.predictCompletions(incompletePrefix2, 
      numTopCompletes2);
  cout << "Top " << numTopCompletes2 << " Completions for '" << 
      incompletePrefix2 << "':" << endl;


  vector<string>::iterator sameWordsBeg2;
  vector<string>::iterator sameWordsEnd2;

  sameWordsBeg2 = topCompletes2.begin();
  sameWordsEnd2 = topCompletes2.end();


  for (; sameWordsBeg2 != sameWordsEnd2; ++sameWordsBeg2) {
    cout << *sameWordsBeg2 << endl;
  }

  cout << endl;
  
  // Test 3: predictCompletions
  cout << "Testing autocomplete..." << endl;
  DictionaryTrie sameWordsTrie3;
  std::vector<std::string> topCompletes3;
  std::string incompletePrefix3 = "orang";
  unsigned int numTopCompletes3 = 3;

  sameWordsTrie3.insert("orange", 11);
  sameWordsTrie3.insert("orangutan", 8);
  sameWordsTrie3.insert("apple", 5);


  topCompletes3 = sameWordsTrie3.predictCompletions(incompletePrefix3, 
      numTopCompletes3);
  cout << "Top " << numTopCompletes3 << " Completions for '" << 
      incompletePrefix3 << "':" << endl;


  vector<string>::iterator sameWordsBeg3;
  vector<string>::iterator sameWordsEnd3;

  sameWordsBeg3 = topCompletes3.begin();
  sameWordsEnd3 = topCompletes3.end();


  for (; sameWordsBeg3 != sameWordsEnd3; ++sameWordsBeg3) {
    cout << *sameWordsBeg3 << endl;
  }

  // Test 4: predictCompletions
  cout << "Testing autocomplete..." << endl;
  DictionaryTrie sameWordsTrie4;
  std::vector<std::string> topCompletes4;
  std::string incompletePrefix4 = "xylo";
  unsigned int numTopCompletes4 = 2;

  sameWordsTrie4.insert("dog", 11);
  sameWordsTrie4.insert("relaxation", 8);
  sameWordsTrie4.insert("baseball", 5);
  sameWordsTrie4.insert("handle", 3);
  sameWordsTrie4.insert("computer", 14);


  topCompletes4 = sameWordsTrie4.predictCompletions(incompletePrefix4, 
      numTopCompletes4);
  cout << "Top " << numTopCompletes4 << " Completions for '" << 
      incompletePrefix4 << "':" << endl;


  vector<string>::iterator sameWordsBeg4;
  vector<string>::iterator sameWordsEnd4;

  sameWordsBeg4 = topCompletes4.begin();
  sameWordsEnd4 = topCompletes4.end();

  if (topCompletes4.empty()) {
    cout << "None found :( " << endl;
  }
  for (; sameWordsBeg4 != sameWordsEnd4; ++sameWordsBeg4) {
    cout << *sameWordsBeg4 << endl;
  }
  
  cout << endl;

  // Test 5: predictCompletions
  cout << "Testing autocomplete..." << endl;
  DictionaryTrie sameWordsTrie5;
  std::vector<std::string> topCompletes5;
  std::string incompletePrefix5 = "i ";
  unsigned int numTopCompletes5 = 3;

  sameWordsTrie5.insert("i love", 11);
  sameWordsTrie5.insert("i am", 9);
  sameWordsTrie5.insert("i hate", 4);
  sameWordsTrie5.insert("i went", 3);
  sameWordsTrie5.insert("i like", 10);


  topCompletes5 = sameWordsTrie5.predictCompletions(incompletePrefix5, 
      numTopCompletes5);
  cout << "Top " << numTopCompletes5 << " Completions for '" << 
      incompletePrefix5 << "':" << endl;


  vector<string>::iterator sameWordsBeg5;
  vector<string>::iterator sameWordsEnd5;

  sameWordsBeg5 = topCompletes5.begin();
  sameWordsEnd5 = topCompletes5.end();

  if (topCompletes5.empty()) {
    cout << "None found :( " << endl;
  }
  for (; sameWordsBeg5 != sameWordsEnd5; ++sameWordsBeg5) {
    cout << *sameWordsBeg5 << endl;
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
