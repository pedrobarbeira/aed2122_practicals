#ifndef GAME_H_
#define GAME_H_

#include "kid.h"
#include <list>
#include <queue>
#include <string>
using namespace std;

class Game
{
    list<Kid> kids;
public:
    Game();
    Game(list<Kid>& l2);
    static unsigned numberOfWords(string phrase);
    void addKid(const Kid k1);
    list<Kid> getKids() const;
    void setKids(const list<Kid>& l1);
    Kid loseGame(string phrase);
    list<Kid> removeOlder(unsigned id);
    queue<Kid> rearrange();
    bool operator==(Game& g2);
    list<Kid> shuffle() const;
};

#endif /* GAME_H_ */
