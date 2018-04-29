#include <random>
#include <iostream>
#include <fstream>

#include "Dictionary.h"


using namespace std;



/**
   author: Kathryn Rodgers
   date: May 2016
 */


// Constructor
// Takes the names of the files to get the words from
Dictionary::Dictionary(std::string nounfile, std::string verbfile, std::string adverbfile, std::string adjfile, std::string prepfile, std::string articlefile){
  if (!(readNouns(nounfile) && readVerbs(verbfile) && readAdverbs(adverbfile) && readAdjectives(adjfile) && readPrepositions(prepfile) && readVerbs(verbfile) && readArticles(articlefile))){
    cout << "Dictionary failed to find the word list files" << endl;
  }

}

///////////////////////////////////////
// Utility Functions
///////////////////////////////////

// Returns a random noun
string Dictionary::getNoun(){
  int randIndx = getRandomNumber(0, nouns.size()-1);
  return nouns[randIndx];
}

// Returns a random article
string Dictionary::getArticle(){
  int randIndx = getRandomNumber(0, articles.size()-1);
  return articles[randIndx];
}

// Returns a random adjective
string  Dictionary::getAdjective(){
  int randIndx = getRandomNumber(0, adjectives.size()-1);
  return adjectives[randIndx];
}

// Returns a random preposition
string  Dictionary::getPreposition(){
  int randIndx = getRandomNumber(0, prepositions.size()-1);
  return prepositions[randIndx];
}

// Returns a random adverb
string  Dictionary::getAdverb(){
  int randIndx = getRandomNumber(0, adverbs.size()-1);
  return adverbs[randIndx];
}

// Returns a random verb
string  Dictionary::getVerb(){
  int randIndx = getRandomNumber(0, verbs.size()-1);
  return verbs[randIndx];
}

///////////////////////////
// Read in files functions
//////////////////////////
bool Dictionary::readNouns(string file){
  ifstream input(file);
  // Failed to open
  if(!input){
    cout << "Failed to open noun file" << endl;
    return false;
  }
  string word;
  while(input >> word){
    if(word != ""){
      nouns.push_back(word);
    }
  }
  
  input.close();
  return true;
}
bool Dictionary::readAdverbs(string file){
  ifstream input(file);
  // Failed to open
  if(!input){
    cout << "Failed to open adverb file" << endl;
    return false;
  }
  string word;
  while(input >> word){
    if(word != ""){
      adverbs.push_back(word);
    }
  }
  
  input.close();
  return true;
}

bool Dictionary::readAdjectives(string file){
  ifstream input(file);
  // Failed to open
  if(!input){
    cout << "Failed to open adjective file" << endl;
    return false;
  }
  string word;
  while(input >> word){
    if(word != ""){
      adjectives.push_back(word);
    }
  }
  
  input.close();
  return true;
}
bool Dictionary::readPrepositions(string file){
  ifstream input(file);
  // Failed to open
  if(!input){
    cout << "Failed to open preposition file" << endl;
    return false;
  }
  string word;
  while(input >> word){
    if(word != ""){
      prepositions.push_back(word);
    }
  }
  
  input.close();
  return true;
}

bool Dictionary::readVerbs(string file){
  ifstream input(file);
  // Failed to open
  if(!input){
    cout << "Failed to open verb file" << endl;
    return false;
  }
  string word;
  while(input >> word){
    if(word != ""){
      verbs.push_back(word);
    }
  }
  
  input.close();
  return true;
}

bool Dictionary::readArticles(string file){
  ifstream input(file);
  // Failed to open
  if(!input){
    cout << "Failed to open article file" << endl;
    return false;
  }
  string word;
  while(input >> word){
    if(word != ""){
      articles.push_back(word);
    }
  }
  
  input.close();
  return true;
}



  /////////////////
  // Random number generation
  /////////////////////////
int Dictionary::getRandomNumber(int minVal, int maxVal){
  random_device r;
  default_random_engine eng(r());
  uniform_int_distribution<int> dist(minVal, maxVal);
  return dist(eng);
  }
