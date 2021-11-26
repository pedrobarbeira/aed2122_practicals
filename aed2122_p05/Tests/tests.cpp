#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "kid.h"
#include "game.h"
#include "stackExt.h"
#include <string>
#include "performance.h"

using testing::Eq;


TEST(test_1, a_addKid){
    cout<<endl<<"Testing 'addKid'"<<endl;
    Kid c1("Rui",6,'m');
    Kid c2("Ana",4,'f');
    Kid c3("Rita",6,'f');
    Kid c4("Joao",5,'m');
    Kid c5("Marta",4,'f');
    Kid c6("Vasco",5,'m');

    Game game1;
    list<Kid> cc = game1.getKids();
    EXPECT_EQ(0, cc.size());

    game1.addKid(c1);
    game1.addKid(c2);
    game1.addKid(c3);
    game1.addKid(c4);
    game1.addKid(c5);
    game1.addKid(c6);

    cc = game1.getKids();
    EXPECT_EQ(6, cc.size());

    if (cc.size()==6) {
        Kid c = cc.front();
        EXPECT_EQ("Rui", c.getName());
        c = cc.back();
        EXPECT_EQ("Vasco", c.getName());
    }

    Game game2;
    cc.clear();
    cc.push_back(c1); cc.push_back(c2);
    cc.push_back(c3); cc.push_back(c4);
    game2.setKids(cc);

    cc = game2.getKids();
    EXPECT_EQ(4, cc.size());

    if (cc.size()==4) {
        Kid c = cc.front();
        EXPECT_EQ("Rui", c.getName());
        c = cc.back();
        EXPECT_EQ("Joao", c.getName());
    }
}


TEST(test_1, b_loseGame){
    cout<<endl<<"Testing 'loseGame'"<<endl;
    Kid c1("Rui",6,'m');
    Kid c2("Ana",4,'f');
    Kid c3("Rita",6,'f');
    Kid c4("Joao",5,'m');
    Kid c5("Marta",4,'f');
    Kid c6("Vasco",5,'m');

    Game game1;
    game1.addKid(c1);
    game1.addKid(c2);
    game1.addKid(c3);
    game1.addKid(c4);
    game1.addKid(c5);
    game1.addKid(c6);
    string s = "Pim Pam Pum cada bola mata um pra galinha e pro peru quem se livra es mesmo tu";
    Kid cx = game1.loseGame(s);
    EXPECT_EQ("Rui", cx.getName());

    Game game2;
    s = "Pim Pam Pum Pim";
    game2.addKid(c1);
    game2.addKid(c2);
    game2.addKid(c3);
    game2.addKid(c4);
    game2.addKid(c5);
    game2.addKid(c6);
    cx = game2.loseGame(s);
    EXPECT_EQ("Marta", cx.getName());

    Game game3;
    s = "Pim Pam Pum";
    game3.addKid(c1);
    game3.addKid(c2);
    game3.addKid(c3);
    cx = game3.loseGame(s);
    EXPECT_EQ("Ana", cx.getName());
}

TEST(test_1, c_rearrange){
    cout<<endl<<"Testing 'rearrange'"<<endl;
    Kid c1("Rui",6,'m');
    Kid c2("Ana",4,'f');
    Kid c3("Maria",3,'f');
    Kid c4("Joao",5,'m');
    Kid c5("Vasco",7,'m');
    Kid c6("Luis",5,'m');
    Kid c7("Hugo",5,'m');
    Kid c8("Pedro",5,'m');
    Kid c9("Miguel",5,'m');
    Kid c10("Rita",5,'f');
    Game game1;
    game1.addKid(c1);
    game1.addKid(c2);
    game1.addKid(c3);
    game1.addKid(c4);
    game1.addKid(c5);
    game1.addKid(c6);
    game1.addKid(c7);
    game1.addKid(c8);
    game1.addKid(c9);
    game1.addKid(c10);

    queue<Kid> rem = game1.rearrange();
    EXPECT_EQ(1,rem.size());
    if (!rem.empty())
        EXPECT_EQ("Miguel",rem.front().getName());
    list<Kid>res = game1.getKids();
    EXPECT_EQ(9,res.size());
    if (res.size()==9) {
        vector<string> resok = {"Ana", "Rui", "Joao", "Maria", "Vasco", "Luis", "Rita", "Hugo", "Pedro"};;
        for (auto kid1:resok) {
            EXPECT_EQ(kid1,res.front().getName());
            res.pop_front();
        }
    }
}


TEST(test_1, d_removeOlder){
    cout<<endl<<"Testing 'removeOlder'"<<endl;
    Kid c1("Rui",6,'m');
    Kid c2("Ana",4,'f');
    Kid c3("Rita",3,'f');
    Kid c4("Joao",5,'m');
    Kid c5("Marta",7,'f');
    Kid c6("Vasco",5,'m');
    Game game1;
    game1.addKid(c1);
    game1.addKid(c2);
    game1.addKid(c3);
    game1.addKid(c4);
    game1.addKid(c5);
    game1.addKid(c6);

    list<Kid> kidsOlder = game1.removeOlder(5);
    EXPECT_EQ(2,kidsOlder.size());
    list<Kid>::iterator it= find(kidsOlder.begin(), kidsOlder.end(),Kid("Rui",6,'m'));
    EXPECT_EQ("Rui", it->getName());
    it= find(kidsOlder.begin(), kidsOlder.end(),Kid("Marta",7,'f'));
    EXPECT_EQ("Marta", it->getName());
    EXPECT_EQ(4,game1.getKids().size());
    if (game1.getKids().size() == 4) {
        EXPECT_EQ("Ana",game1.getKids().front().getName());
        EXPECT_EQ("Vasco",game1.getKids().back().getName());
    }

}


TEST(test_1, e_GameEqual){
    cout<<endl<<"Testing 'gameEqual'"<<endl;
    list<Kid> kids1;
    kids1.push_back( Kid("Rui",6,'m') );
    kids1.push_back( Kid("Ana",4,'f') );
    kids1.push_back( Kid("Rita",3,'f') );
    kids1.push_back( Kid("Joao",5,'m') );
    kids1.push_back( Kid("Marta",7,'f') );
    kids1.push_back( Kid("Vasco",5,'m') );
    kids1.push_back( Kid("Ines",5,'f') );

    Game game1(kids1);
    Game game2(kids1);
    EXPECT_EQ(true, game1 == game2);

    list<Kid> kids2;
    kids2.push_back( Kid("Rui",6,'m') );
    kids2.push_back( Kid("Ana",4,'f') );
    kids2.push_back( Kid("Rita",3,'f') );
    kids2.push_back( Kid("Maria",5,'f') );
    kids2.push_back( Kid("Marta",7,'f') );
    kids2.push_back( Kid("Vasco",5,'m') );
    kids2.push_back( Kid("Ines",5,'f') );

    game2.setKids(kids2);
    EXPECT_EQ(false, game1 == game2);
}

TEST(test_1, f_Shuffle){
    cout<<endl<<"Testing 'shuffle'"<<endl;
    list<Kid> kids;
    kids.push_back( Kid("Rui",6,'m') );
    kids.push_back( Kid("Ana",4,'f') );
    kids.push_back( Kid("Rita",3,'f') );
    kids.push_back( Kid("Joao",5,'m') );
    kids.push_back( Kid("Marta",7,'f') );
    kids.push_back( Kid("Vasco",5,'m') );
    kids.push_back( Kid("Ines",5,'f') );

    Game game1;
    game1.setKids(kids);

    list<Kid> kids2 = game1.shuffle();
    EXPECT_EQ(7, kids2.size());

    list<Kid>::iterator it;
    it= find(kids2.begin(), kids2.end(),Kid("Rui",6,'m'));
    EXPECT_EQ("Rui", it->getName());

    it= find(kids2.begin(), kids2.end(),Kid("Ines",5,'m'));
    EXPECT_EQ("Ines", it->getName());

    Game game2(kids2);
    EXPECT_EQ(false, game1 == game2);
}

TEST(test_2, FindMin){
    StackExt<int> s1;
    // Testing empty()
    EXPECT_EQ(true, s1.empty());
    // Testing push() e top()
    s1.push(6);
    s1.push(4);
    s1.push(7);
    s1.push(2);
    s1.push(5);
    EXPECT_EQ(5, s1.top());
    // Testing pop() e top()
    s1.pop();
    s1.pop();
    EXPECT_EQ(7, s1.top());

    // Testing findMin()
    EXPECT_EQ(4, s1.findMin());
    s1.push(3);
    s1.push(2);
    EXPECT_EQ(2, s1.findMin());

    // Now testing findMin() to verify constant time
    // clearing Stack
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    s1.pop();
    EXPECT_EQ(true, s1.empty());

    // preparing data to test execution test
    int size = 9;
    unsigned int elapsedTime[size];
    int x_el[] = {5000000,6000000,7000000,8000000,9000000,10000000,11000000,12000000,13000000};
    int random_int;
    ticks tstart;
    ticks tend;

    for (int i = 0; i < size; i++) {
        // fill stack with number of elements specified in x_el
        for (int z = 1; z <= x_el[i]; z++) {
            random_int = rand() % 1000 + 1;
            s1.push(random_int);
        }
        // counting time
        tstart = getticks(); // initiate ticks counting
        s1.findMin(); // this is constant
        tend = getticks(); // end ticks counting
        elapsedTime[i] = getElapsed(tend,tstart);
        // clearing stack
        for (int z = 1; z <= x_el[i]; z++) {
            s1.pop();
        }
    }
    // Verify if constant time
    // NOTE: parameter 10 means that values in the range [-10, 10] are considered constant
    EXPECT_EQ(true, isConstant(elapsedTime, size, 10));
}