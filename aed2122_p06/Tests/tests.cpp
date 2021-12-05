#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "game.h"
#include "dictionary.h"
#include <fstream>

using testing::Eq;

TEST(test_1, a_createDictionary) {
    cout<<endl<<"Testing 'createDictionary'"<<endl;
    ifstream f;
    f.open("dic.txt");
    if (!f.is_open()) {
        cout<< "File not found";
        return;
    }
    Dictionary d1;
    d1.readFile(f);
    f.close();
    BST<WordMean> dicT = d1.getWords();
    bool isEmp = dicT.isEmpty();
    EXPECT_EQ(false, isEmp);
    if (isEmp == false) {
        BSTItrIn<WordMean> it(dicT);
        it.advance();
        it.advance();
        EXPECT_EQ("gato", it.retrieve().getWord());
    }
}

TEST(test_1, b_printDictionary) {
    cout<<endl<<"Testing 'printDictionary'"<<endl;
    ifstream f;
    f.open("dic.txt");
    if (!f.is_open()) {
        cout<< "File not found";
        return;
    }
    cout << "This test never fails. Check the information on the monitor" << endl;
    Dictionary d1;
    d1.readFile(f);
    f.close();
    d1.print();
}
/*
TEST(test_1, c_consultDictionary) {
    cout<<endl<<"Testing 'consultDictionary'"<<endl;
    ifstream fich;
    fich.open("dic.txt");
    ifstream f;
    f.open("dic.txt");
    if (!f.is_open()) {
        cout<< "File not found";
        return;
    }
    Dictionary d1;
    d1.readFile(f);
    f.close();
    WordMean prev("",""), next("","");
    EXPECT_EQ("mamifero felino", d1.consult("gato", prev, next));
    string mean1=d1.consult("janela", prev, next);
    EXPECT_EQ("word not found",mean1);
    EXPECT_EQ("ilha", prev.getWord());
    EXPECT_EQ("porto de terra emersa rodeada de agua", prev.getMeaning());
    EXPECT_EQ("macaco", next.getWord());
    EXPECT_EQ("mamifero da ordem dos primatas", next.getMeaning());
}

TEST(test_1, d_updateDictionary) {
    cout<<endl<<"Testing 'updateDictionary'"<<endl;
    ifstream f;
    f.open("dic.txt");
    if (!f.is_open()) {
        cout<< "File not found";
        return;
    }
    Dictionary d1;
    d1.readFile(f);
    f.close();
    WordMean prev("",""), next("","");
    EXPECT_EQ(true,d1.update("morango","fruto vermelho"));
    EXPECT_EQ("fruto vermelho", d1.consult("morango", prev, next));
    EXPECT_EQ(false,d1.update("esquilo","pequeno mamifero roedor de cauda longa"));
    BST<WordMean> dicT = d1.getWords();
    bool isEmp = dicT.isEmpty();
    EXPECT_EQ(false, isEmp);
    if (isEmp == false) {
        BSTItrIn<WordMean> it(dicT);
        it.advance();
        it.advance();
        EXPECT_EQ("esquilo", it.retrieve().getWord());
        EXPECT_EQ("pequeno mamifero roedor de cauda longa", d1.consult("esquilo", prev, next));
    }
}

TEST(test_1, e_nodeSize) {
    cout<<endl<<"Testing 'nodeSize'"<<endl;
    BST<int>  bt1(-1);
    EXPECT_EQ(-1,bt1.size(4));
    bt1.insert(12);
    bt1.insert(10);
    bt1.insert(2);
    bt1.insert(22);
    bt1.insert(31);
    bt1.insert(4);
    bt1.insert(40);
    bt1.insert(15);
    bt1.insert(7);
    EXPECT_EQ(3,bt1.size(10));
    EXPECT_EQ(-1,bt1.size(18));
    EXPECT_EQ(0,bt1.size(15));
    EXPECT_EQ(8,bt1.size(12));
}


TEST(test_2, a_InitGame) {
    cout<<endl<<"Testing 'initGame'"<<endl;
    vector<int> points;
    vector<bool> states;
    points.push_back(1); points.push_back(2); points.push_back(3);
    points.push_back(4); points.push_back(5); points.push_back(6); points.push_back(7);
    states.push_back(true); states.push_back(false); states.push_back(false);
    states.push_back(false); states.push_back(false); states.push_back(true); states.push_back(false);
    Game game1(2, points, states);
    EXPECT_EQ(false, game1.getGame().isEmpty());
    if (game1.getGame().isEmpty() == false)
        EXPECT_EQ(1, game1.getGame().getRoot().getPoints());
}

TEST(test_2, b_Play) {
    cout<<endl<<"Testing 'playGame'"<<endl;
    vector<int> points;
    vector<bool> states;
    points.push_back(1); points.push_back(2); points.push_back(3);
    points.push_back(4); points.push_back(5); points.push_back(6);
    points.push_back(7); points.push_back(8); points.push_back(9);
    points.push_back(10); points.push_back(11); points.push_back(12);
    points.push_back(13); points.push_back(14); points.push_back(15);
    states.push_back(true); states.push_back(false); states.push_back(false);
    states.push_back(false); states.push_back(false); states.push_back(true);
    states.push_back(false); states.push_back(true); states.push_back(true);
    states.push_back(true); states.push_back(true); states.push_back(true);
    states.push_back(true); states.push_back(true); states.push_back(true);
    Game game1(3, points, states);
    EXPECT_EQ(13, game1.play());
    EXPECT_EQ(8,game1.play());
}

TEST(test_2, c_MostVisited) {
    cout<<endl<<"Testing 'mostVisited_game'"<<endl;
    vector<int> points;
    vector<bool> states;
    points.push_back(1); points.push_back(2); points.push_back(3);
    points.push_back(4); points.push_back(5); points.push_back(6);
    points.push_back(7); points.push_back(8); points.push_back(9);
    points.push_back(10); points.push_back(11); points.push_back(12);
    points.push_back(13); points.push_back(14); points.push_back(15);
    states.push_back(true); states.push_back(false); states.push_back(false);
    states.push_back(false); states.push_back(false); states.push_back(true);
    states.push_back(false); states.push_back(true); states.push_back(true);
    states.push_back(true); states.push_back(true); states.push_back(true);
    states.push_back(true); states.push_back(true); states.push_back(true);
    Game game1(3, points, states);

    game1.play(); game1.play(); game1.play();
    EXPECT_EQ(2, game1.mostVisited());

    game1.play(); game1.play(); game1.play();game1.play();
    EXPECT_EQ(4, game1.mostVisited());
}
*/