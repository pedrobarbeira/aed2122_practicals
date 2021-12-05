#include "game.h"
#include <sstream>

Circle::Circle(int p, bool s): points(p), state(s), nVisits(0) {}

int Circle::getPoints() const {
    return points;
}

bool Circle::getState() const {
    return state;
}

void Circle::changeState() {
    if (state == false)
        state = true;
    else
        state = false;
}

int Circle::getNVisits() const {
    return nVisits;
}

void Circle::incNVisits() {
    nVisits++;
}


BinaryTree<Circle>& Game::getGame() {
    return game;
}


//-----------------------------------------------------------------

//TODO
Game::Game(int height, vector<int>& points, vector<bool>& states) {
}

//TODO
int Game::play() {
	return 0;
}

//TODO
int Game::mostVisited() const {
	return 0;
}

