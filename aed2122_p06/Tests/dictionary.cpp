#include <iostream>
#include <string>
#include <fstream>
#include "dictionary.h"

using namespace std;

WordMean::WordMean(string w, string m): word(w), meaning(m) {}

string WordMean::getWord() const {
    return word;
}

string WordMean::getMeaning() const {
    return meaning;
}

void WordMean::setMeaning(string m) {
    meaning = m;
}

void WordMean::setWord(string w) {
    word = w;
}

bool WordMean::operator<(const WordMean& rhs) const{
    return this->word < rhs.word;
}

BST<WordMean> Dictionary::getWords() const {
	return words;
}

// ---------------------------------------------

//TODO
void Dictionary::readFile(ifstream &f) {
    std::string word, meaning;
    while(getline(f, word)){
        getline(f, meaning);
        WordMean w(word, meaning);
        words.insert(w);
    }
}

//TODO
string Dictionary::consult(string word1, WordMean& previous, WordMean& next) const {


}

//TODO
bool Dictionary::update(string word1, string mean1) {
    return true;
}

//TODO
void Dictionary::print() const {
    words.printTree();
}

ostream& operator<<(ostream& out, const WordMean& w){
    out << w.meaning << '\n' << w.word << '\n';
    return out;
}

