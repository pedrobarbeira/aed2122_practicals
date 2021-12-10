#include "game.h"
#include <cmath>
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
    vector<BinaryTree<Circle>*> leaves(points.size(), nullptr);
    for(int i = points.size()-1; i >= 0; i--){
        if(i*2+1 > points.size()-1){
            leaves[i] = new BinaryTree<Circle>(Circle(points[i], states[i]));
        }
        else{
            leaves[i] = new BinaryTree<Circle>(Circle(points[i], states[i]), (*leaves[2*i+1]), (*leaves[2*i+2]));
        }
    }
    game = (*leaves[0]);
    for(auto it: leaves)
        delete it;
}

//TODO
int Game::play() {
    BTItrLevel<Circle> it(game);
    Circle c = it.retrieve();
    bool over = false;
    while(!it.isAtEnd()){
        Circle& current = it.retrieve();
        c.incNVisits();
        bool state = c.getState();
        c.changeState();
        if(state){
            for(int p = c.getPoints(); p >= 0; p--) {
                it.advance();
                if (it.isAtEnd()) {
                    over = true;
                    break;
                }
            }
        }
        else{
            for(int p = c.getPoints(); p > 0; p--){
                it.advance();
                if (it.isAtEnd()) {
                    over = true;
                    break;
                }
            }
        }
        if(over) break;
        else {
            current = c;
            c = it.retrieve();
        }
    }
	return c.getPoints();
}

//TODO
int Game::mostVisited() const {
	BTItrLevel<Circle> it(game);
	it.advance();
	int max = 0;
	while(!it.isAtEnd()){
        Circle c = it.retrieve();
        if(c.getNVisits() > max) max = c.getNVisits();
        it.advance();
	}
	return max;
}

