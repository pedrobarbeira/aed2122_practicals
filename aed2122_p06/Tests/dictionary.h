#ifndef _DIC
#define _DIC
#include <string>
#include <fstream>
#include "bst.h"

class WordMean {
    string word;
    string meaning;
public:
    WordMean(string w, string m);
    string getWord() const;
    string getMeaning() const;
    void setMeaning(string m);
    void setWord(string w);
    bool operator<(const WordMean& rhs) const;
    void operator<<(const WordMean& out) const;
};

class Dictionary
{
      BST<WordMean> words;
public:
      Dictionary(): words(WordMean("","")) {};
      BST<WordMean> getWords() const;
      void readFile(ifstream& f);
      string consult(string word1, WordMean& previous, WordMean& next) const;
      bool update(string word1, string mean1);
      void print() const;
};

#endif
