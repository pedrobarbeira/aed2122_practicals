// AED 2021/2022 - Aula Pratica 07
// Pedro Ribeiro (DCC/FCUP) [06/12/2021]

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "funWithBSTs.h"
#include "bst.h"

using testing::Eq;

// ----------------------------------------------------------
// Exercicio 1: Colecao de Cromos
// ----------------------------------------------------------

TEST(test_1, newBag) {
    cout << "Testando 'newBag'" << endl;

    cout << "  . Exemplo do enunciado" << endl;
    EXPECT_EQ(3, FunWithBSTs::newBag({42, 124, 34, 12, 42, 24, 71}, {112, 42, 31, 31, 34, 62}));

    cout << "  . Outros casos" << endl;
    EXPECT_EQ(0, FunWithBSTs::newBag({2,4,6,8,10}, {8,8,4,4,4,6,6,6,6,2,10}));
    EXPECT_EQ(0, FunWithBSTs::newBag({1,2,3}, {}));
    EXPECT_EQ(0, FunWithBSTs::newBag({}, {}));
    EXPECT_EQ(5, FunWithBSTs::newBag({2,4,6,8,10}, {1,2,3,4,5,6,7,8,9,10}));
    EXPECT_EQ(10, FunWithBSTs::newBag({}, {1,2,3,4,5,6,7,8,9,10}));
    EXPECT_EQ(4, FunWithBSTs::newBag({100,200,300,400,400,300,200,100,100,100,100,100},
                                     {100,100,100,100,100,100,150,150,150,250,250,200,350,350,50,50}));
    EXPECT_EQ(3, FunWithBSTs::newBag({12,5,11,9,12,13,8,12,1,8,19,6,20,1,14,19,9,17,13,11},
                                     {6,2,2,9,4,8,17,2,9,17,2,5,8,9,15,19,5,9,14}));
}

// ----------------------------------------------------------
// Exercicio 2: Batalha de Pokemons
// ----------------------------------------------------------

TEST(test_2, battle) {
    cout << "Testando 'battle'" << endl;

    cout << "  . Exemplo do enunciado" << endl;
    EXPECT_EQ(-2, FunWithBSTs::battle({400,300,700}, {700,200,500,200}));

    cout << "  . Outros casos" << endl;
    EXPECT_EQ(0, FunWithBSTs::battle({100,200}, {100,100,100}));
    EXPECT_EQ(0, FunWithBSTs::battle({100,200,300,400}, {500,500}));
    EXPECT_EQ(2, FunWithBSTs::battle({100,100,100,100,100}, {300}));
    EXPECT_EQ(3, FunWithBSTs::battle({300,200,200,300}, {400,200}));
    EXPECT_EQ(-5, FunWithBSTs::battle({500}, {300,300,100,200,200,100}));
    EXPECT_EQ(-3, FunWithBSTs::battle({400,200},{300,200,200,300}));
    EXPECT_EQ(6, FunWithBSTs::battle({6,17,11,14,17,14,16,16,3,13,}, {15,17,19,11,10,18,3,4,8,12}));
    EXPECT_EQ(-12, FunWithBSTs::battle({56,65,13,29,45,99,40,90,59,6,17,70,5,32,99,79,63,47,80,60},
                                     {81,69,94,16,91,37,50,100,49,50,30,39,71,19,51,54,28,73,35,41}));
}

// ----------------------------------------------------------
// Exercicio 3: Reviews Cinematograficas
// ----------------------------------------------------------

// a) Contando Filmes
TEST(test_3, numberMovies) {
    cout << "Testando 'numberMovies'" << endl;

    cout << "  . Exemplo do enunciado" << endl;
    EXPECT_EQ(4, FunWithBSTs::numberMovies({
                                                   {"FreeGuy", 8},
                                                   {"Eternals", 6},
                                                   {"Dune", 10},
                                                   {"Eternals", 5},
                                                   {"NoTimeToDie", 7},
                                                   {"Dune", 9}
                                           }));

    cout << "  . Outros casos" << endl;
    EXPECT_EQ(10, FunWithBSTs::numberMovies({
                                                   {"Avatar", 1},
                                                   {"AvengersEndgame", 2},
                                                   {"Titanic", 3},
                                                   {"StarWarsTFA", 4},
                                                   {"JurassicWorld", 5},
                                                   {"Minions", 6},
                                                   {"TheLionKing", 7},
                                                   {"Furious7", 8},
                                                   {"FrozenII", 9},
                                                   {"HarryPotterDH2", 10}
                                           }));
    EXPECT_EQ(3, FunWithBSTs::numberMovies({
                                                    {"Avatar", 1},
                                                    {"Titanic", 1},
                                                    {"Avatar", 1},
                                                    {"Avatar", 1},
                                                    {"Minions", 1},
                                                    {"Avatar", 1},
                                                    {"Minions", 1},
                                                    {"Minions", 1},
                                                    {"Titanic", 1}
                                            }));
    EXPECT_EQ(3, FunWithBSTs::numberMovies({
                                                   {"Avatar", 1},
                                                   {"Titanic", 1},
                                                   {"Avatar", 1},
                                                   {"Avatar", 1},
                                                   {"Minions", 1},
                                                   {"Avatar", 1},
                                                   {"Minions", 1},
                                                   {"Minions", 1},
                                                   {"Titanic", 1}
                                           }));
}

// b) O filme com mais reviews
TEST(test_3, moreReviews) {
    cout << "Testando 'numberMovies'" << endl;

    int m, n;

    cout << "  . Exemplo do enunciado" << endl;
    FunWithBSTs::moreReviews({
                                     {"FreeGuy",     8},
                                     {"Eternals",    6},
                                     {"Dune",        10},
                                     {"Eternals",    5},
                                     {"NoTimeToDie", 7},
                                     {"Dune",        9}
                             }, m, n);
    EXPECT_EQ(2, m);
    EXPECT_EQ(2, n);

    cout << "  . Outros casos" << endl;
    FunWithBSTs::moreReviews({
                                     {"Avatar", 1},
                                     {"AvengersEndgame", 2},
                                     {"Titanic", 3},
                                     {"StarWarsTFA", 4},
                                     {"JurassicWorld", 5},
                                     {"Minions", 6},
                                     {"TheLionKing", 7},
                                     {"Furious7", 8},
                                     {"FrozenII", 9},
                                     {"HarryPotterDH2", 10}
                             }, m, n);
    EXPECT_EQ(1, m);
    EXPECT_EQ(10, n);

    FunWithBSTs::moreReviews({
                                      {"Avatar", 1},
                                      {"Titanic", 1},
                                      {"Avatar", 1},
                                      {"Avatar", 1},
                                      {"Avatar", 1},
                                      {"Minions", 1},
                                      {"Avatar", 1},
                                      {"Minions", 1},
                                      {"Minions", 1},
                                      {"Titanic", 1}
                              },m ,n);
    EXPECT_EQ(5, m);
    EXPECT_EQ(1, n);

    FunWithBSTs::moreReviews({
                                     {"Avatar", 1},
                                     {"Titanic", 1},
                                     {"Avatar", 1},
                                     {"Avatar", 1},
                                     {"Minions", 1},
                                     {"Avatar", 1},
                                     {"Minions", 1},
                                     {"Minions", 1},
                                     {"Minions", 1},
                                     {"Titanic", 1},
                                     {"Titanic", 1},
                                     {"Titanic", 1}
                             },m ,n);
    EXPECT_EQ(4, m);
    EXPECT_EQ(3, n);
}

// c) Os melhores filmes
TEST(test_3, topMovies) {
    cout << "Testando 'topMovies'" << endl;

    cout << "  . Exemplo do enunciado" << endl;
    vector<pair<string, int>> reviews1 = {
            {"FreeGuy", 8},
            {"Eternals", 6},
            {"Dune", 10},
            {"Eternals", 5},
            {"NoTimeToDie", 7},
            {"Dune", 9}
    };
    vector<string> answer1 = {"Dune", "FreeGuy"};
    EXPECT_EQ(answer1, FunWithBSTs::topMovies(reviews1, 7.5));

    cout << "  . Outros casos" << endl;
    vector<pair<string, int>> reviews2 = {
            {"FreeGuy", 8},
            {"Eternals", 6},
            {"Dune", 10},
            {"Eternals", 5},
            {"NoTimeToDie", 7},
            {"NoTimeToDie", 8},
            {"Eternals", 4},
            {"NoTimeToDie", 9},
            {"Eternals", 8},
            {"NoTimeToDie", 6},
            {"Dune", 9},
            {"Dune", 10},
            {"Dune", 10},
            {"Dune", 10},
            {"FreeGuy", 9},
            {"Dune", 9},
            {"FreeGuy", 6},
            {"Dune", 9},
            {"NoTimeToDie", 3},
            {"SpaceJamNL", 2},
            {"SpaceJamNL", 1},
            {"Cruella", 6}
    };
    vector<string> answer2_1 = {};
    EXPECT_EQ(answer2_1, FunWithBSTs::topMovies(reviews2, 9.9));
    vector<string> answer2_2 = {"Dune"};
    EXPECT_EQ(answer2_2, FunWithBSTs::topMovies(reviews2, 9.55));
    vector<string> answer2_3 = {"Dune", "FreeGuy"};
    EXPECT_EQ(answer2_3, FunWithBSTs::topMovies(reviews2, 7.6));
    vector<string> answer2_4 = {"Dune", "FreeGuy","NoTimeToDie"};
    EXPECT_EQ(answer2_4, FunWithBSTs::topMovies(reviews2, 6.5));
    vector<string> answer2_5 = {"Cruella", "Dune", "FreeGuy","NoTimeToDie"};
    EXPECT_EQ(answer2_5, FunWithBSTs::topMovies(reviews2, 6.0));
    vector<string> answer2_6 = {"Cruella", "Dune", "Eternals", "FreeGuy","NoTimeToDie"};
    EXPECT_EQ(answer2_6, FunWithBSTs::topMovies(reviews2, 3.5));
    vector<string> answer2_7 = {"Cruella", "Dune", "Eternals", "FreeGuy","NoTimeToDie","SpaceJamNL"};
    EXPECT_EQ(answer2_7, FunWithBSTs::topMovies(reviews2, 1.0));
}

// ----------------------------------------------------------
// Exercicio 4: Brincando com arvores
// ----------------------------------------------------------

// a) Desequilibrio de um no
TEST(test_4, balance) {
    cout << "Testando 'balance'" << endl;

    cout << "  . Exemplo do enunciado" << endl;
    BST<int> bt1(-1);
    bt1.insert({42,25, 56,21,45,64,15,61});
    EXPECT_EQ(0, bt1.balance(42));
    EXPECT_EQ(-2, bt1.balance(25));
    EXPECT_EQ(1, bt1.balance(56));

    cout << "  . Outros casos" << endl;
    BST<int> bt2(-1);
    bt2.insert({4,2,6,3,5});
    EXPECT_EQ(0, bt2.balance(4));
    EXPECT_EQ(1, bt2.balance(2));
    EXPECT_EQ(-1, bt2.balance(6));
    EXPECT_EQ(0, bt2.balance(5));
    EXPECT_EQ(0, bt2.balance(3));

    BST<int> bt3(-1);
    bt3.insert({40,30,20,35,10,90,80,87,70,55,75,72,71,73,74});
    EXPECT_EQ(0, bt3.balance(42));
    EXPECT_EQ(4, bt3.balance(40));
    EXPECT_EQ(-6, bt3.balance(90));
    EXPECT_EQ(-4, bt3.balance(80));
    EXPECT_EQ(-1, bt3.balance(30));
    EXPECT_EQ(1, bt3.balance(72));
    EXPECT_EQ(0, bt3.balance(74));
    EXPECT_EQ(3, bt3.balance(70));
}

// b) E uma arvore AVL?
TEST(test_4, isAVL) {
    cout << "Testando 'isAVL'" << endl;

    cout << "  . Exemplo do enunciado" << endl;
    BST<int> bt1(-1), bt3(-1);
    bt1.insert({42,25,56,21,45,64,15,61});
    bt3.insert({42,21,25,15,56,64,61,45});
    EXPECT_FALSE(bt1.isAVL());
    EXPECT_TRUE(bt3.isAVL());

    cout << "  . Outros casos" << endl;
    BST<int> bt4(-1);
    bt4.insert({4,2,3,1,6,5,7});
    EXPECT_TRUE(bt4.isAVL());
    BST<int> bt5(-1);
    bt5.insert({8,4,12,2,6,10,13,1,5,9});
    EXPECT_TRUE(bt5.isAVL());
    BST<int> bt6(-1);
    bt6.insert({1,2,3});
    EXPECT_FALSE(bt6.isAVL());
    BST<int> bt7(-1);
    bt7.insert({5,4,1,2,7,6});
    EXPECT_FALSE(bt7.isAVL());
    BST<int> bt8(-1);
    bt8.insert({5,4,3,2,1,6,7,8,9});
    EXPECT_FALSE(bt8.isAVL());
}

// c) Rotação à direita
TEST(test_4, rightRotate) {
    cout << "Testando 'rightRotate'" << endl;

    cout << "  . Exemplo do enunciado" << endl;
    BST<int> bt1(-1), bt2(-1), bt3(-1);
    bt1.insert({42,25,56,21,45,64,15,61});
    bt2.insert({42,25,21,15,56,64,61,45});
    bt3.insert({42,21,25,15,56,64,61,45});
    EXPECT_TRUE(bt1 == bt2);
    EXPECT_FALSE(bt1 == bt3);
    bt1.rightRotate(25);
    EXPECT_FALSE(bt1 == bt2);
    EXPECT_TRUE(bt1 == bt3);

    cout << "  . Outros casos" << endl;
    BST<int> bt2_1(-1), bt3_1(-1);
    bt2.rightRotate(42);
    bt2_1.insert({25,42,21,15,56,64,61,45});
    EXPECT_TRUE(bt2 == bt2_1);
    bt3.rightRotate(42);
    bt3_1.insert({21,42,25,15,56,45,64,61});
    EXPECT_TRUE(bt3 == bt3_1);

    BST<int> bt4(-1), bt4_1(-1), bt4_2(-1), bt4_3(-1),
            bt4_4(-1), bt4_5(-1), bt4_6(-1), bt4_7(-1);
    bt4.insert({40,30,20,35,10,90,80,87,70,55,75,72,71,73,74});
    bt4_1.insert({40,30,20,90,80,70,55,75,72,71,73,74,10,87,35});
    bt4.rightRotate(42);
    EXPECT_TRUE(bt4 == bt4_1);
    bt4.rightRotate(73);
    EXPECT_TRUE(bt4 == bt4_1);
    bt4.rightRotate(72);
    bt4_2.insert({40,30,20,35,10,90,80,87,70,55,75,71,72,73,74});
    EXPECT_TRUE(bt4 == bt4_2);
    bt4.rightRotate(75);
    bt4_3.insert({40,30,20,35,10,90,80,87,70,55,71,75,72,73,74});
    bt4.rightRotate(80);
    bt4_4.insert({40,30,20,35,10,90,70,55,80,87,71,75,72,73,74});
    bt4.rightRotate(90);
    bt4_5.insert({40,30,20,35,10,70,90,55,80,87,71,75,72,73,74});
    EXPECT_TRUE(bt4 == bt4_5);
    bt4.rightRotate(40);
    bt4_6.insert({30,40,20,35,10,70,90,55,80,87,71,75,72,73,74});
    EXPECT_TRUE(bt4 == bt4_6);
    bt4.rightRotate(75);
    bt4_7.insert({30,40,20,35,10,70,90,55,80,87,71,72,75,73,74});
    EXPECT_TRUE(bt4 == bt4_7);


}