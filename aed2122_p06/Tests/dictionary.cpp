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

bool WordMean::operator>(const WordMean& rhs) const{
    return this->word > rhs.word;
}

bool WordMean::operator==(const WordMean& rhs) const{
    return this->word == rhs.word;
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
        WordMean findMean(word1, "");
        iteratorBST<WordMean> it = words.begin();
        while(it != words.end()){
            if((*it) == findMean) return (*it).getMeaning();
            else {
                if (it == words.begin()) previous = (*it);
                else previous = next;
                it++;
                next = (*it);
                if(findMean < next) break;
            }
        }
    return "word not found";
}

//TODO
bool Dictionary::update(string word1, string mean1) {
    iteratorBST<WordMean> it = words.begin();
    while(it != words.end()){
        if((*it).getWord() == word1){
            (*it).setMeaning(mean1);
            return true;
        }
        else it++;
    }
    WordMean updateMean(word1, mean1);
    words.insert(updateMean);
    return false;
}

//TODO
void Dictionary::print() const {
    words.printTree();
}

ostream& operator<<(ostream& out, const WordMean& w){
    out << w.word << '\n' << w.meaning << '\n';
    return out;
}

