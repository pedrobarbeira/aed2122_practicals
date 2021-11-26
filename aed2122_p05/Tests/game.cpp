#include "game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;


unsigned int Game::numberOfWords(string phrase) {
  if ( phrase.length() == 0 ) return 0;

  unsigned n=1;
  size_t pos = phrase.find(' ');
  while (pos != string::npos) {
    phrase = phrase.substr(pos+1);
    pos = phrase.find(' ');
    n++;
  }
  return n;
}

Game::Game() {
	this->kids.clear();
}

Game::Game(list<Kid>& l2) {
    this->kids = l2;
}

//-----------------------------------------------------------------

// TODO
void Game::addKid(const Kid k1) {
    this->kids.push_back(k1);
}

// TODO
list<Kid> Game::getKids() const {
    return this->kids;
}

// TODO
void Game::setKids(const list<Kid>& l1) {
    this->kids = l1;
}

// TODO
Kid Game::loseGame(string phrase) {
    while(kids.size() > 1) {
        int n = numberOfWords(phrase);
        while (n > 1){
            Kid k = kids.front();
            kids.pop_front();
            kids.push_back(k);
            n--;
        }
        kids.pop_front();
    }
    return kids.front();
}

// TODO
list<Kid> Game::removeOlder(unsigned id) {
    list<Kid> ofAge;
    for(list<Kid>::iterator it = kids.begin(); it != kids.end(); it++){
        if(it->getAge() > id) {
            ofAge.push_back((*it));
            kids.erase(it);
            it--;
        }
    }
    return ofAge;
}

// TODO
queue<Kid> Game::rearrange() {
    queue<Kid> boys;
    queue<Kid> girls;

    for(auto it:kids){
        if (it.getSex() == 'm')
            boys.push(it);
        else girls.push(it);
    }

    int n = girls.size(),
        m = boys.size();

    kids.clear();
    kids.push_back(girls.front());
    girls.pop();

    if(n < m){
        int i = girls.size() +1;
        while(i > 0){
            int k = m/n;
            while(k > 0 && !boys.empty()) {
                kids.push_back(boys.front());
                boys.pop();
                k--;
            }
            if(!girls.empty()) {
                kids.push_back(girls.front());
                girls.pop();
            }
            i--;
        }
    }
    else{
        int i = boys.size();
        while(i > 0){
            int k = m/n;
            while( k > 0 && ! girls.empty()){
                kids.push_back(girls.front());
                girls.pop();
                k--;
            }
            if(!boys.empty()){
                kids.push_back(boys.front());
                boys.pop();
            }
            i--;
        }
    }


    if(boys.empty()){
        return girls;
    }
    else if (girls.empty()){
        return boys;
    }
    else{
        queue<Kid> leftovers;
        while(!boys.empty()){
            leftovers.push(boys.front());
            boys.pop();
        }
        while(!girls.empty()){
            leftovers.push(girls.front());
            girls.pop();
        }
        return leftovers;
    }
}

// TODO
bool Game::operator==(Game& g2) {
	bool same = true;

	if(kids.size() != g2.getKids().size()) return false;
    {
        list<Kid>::iterator it = kids.begin();
        list<Kid>::iterator et = g2.getKids().begin();

        while (it != kids.end()) {
            if (it->getName() != et->getName() ||
                it->getAge() != et->getAge() ||
                it->getSex() != et->getSex()) same = false;
            it++;
            et++;
        }
    }

	return same;
}

// TODO
list<Kid> Game::shuffle() const {
	list<Kid> randKids(kids.size());
    list<Kid>::iterator et;
	int i;

	for(list<Kid>::const_iterator it = kids.begin(); it != kids.end(); it++){
	    do {
            et = randKids.begin();
            i = rand() % kids.size();
            while (i > 0) {
                et++;
                i--;
            }
        }while(et->getName() != "");
        (*et) = (*it);
	}

	return randKids;
}
