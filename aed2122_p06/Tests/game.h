#ifndef GAME_H_
#define GAME_H_

#include "binaryTree.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

class Circle {
 int points;
 bool state;
 int nVisits;
public:
 Circle(int p=0, bool s=false);
 int getPoints() const;
 bool getState() const;
 void changeState();
 int getNVisits() const;
 void incNVisits();
};


class Game {
	BinaryTree<Circle> game;
public:
    BinaryTree<Circle>& getGame();
	Game(int height, vector<int>& points, vector<bool>& states);
	int play();
	int mostVisited() const;
};

#endif
