// AED 2021/2022 - Aula Pratica 10
// Pedro Ribeiro (DCC/FCUP) [09/01/2022]

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "graph.h"
#include "funWithGraphs.h"
#include "minHeap.h"
#include "disjointSets.h"

using testing::Eq;

// ----------------------------------------------------------
// Exercicio 2: Heaps Binários
// ----------------------------------------------------------

// ..............................
// a) Um pequeno jogo
TEST(test2, game) {
    cout << "Testando 'game'" << endl;

    // Nota: para todos os testes foi verificado que nunca existiam empates nos
    // números a retirar na ronda de um jogo, ou seja, a solução é única

    cout << "  . exemplo do enunciado" << endl;
    EXPECT_EQ(272, FunWithGraphs::game({100, 2, 30, 400}));

    cout << "  . outros exemplos" << endl;
    EXPECT_EQ(51, FunWithGraphs::game({34, 56, 120, 91}));
    EXPECT_EQ(233, FunWithGraphs::game({143, 432, 535, 479}));
    EXPECT_EQ(86, FunWithGraphs::game({317, 243, 460, 174, 12}));
    EXPECT_EQ(734, FunWithGraphs::game({799, 285, 977, 440, 587, 996, 652, 509, 162, 57}));
    EXPECT_EQ(4541040, FunWithGraphs::game({655712, 222346, 79323522, 6425631, 14893716, 42424242, 23456789}));
}

// ----------------------------------------------------------
// Exercicio 3: Algoritmo de Prim
// ----------------------------------------------------------
TEST(test3, prim) {
    cout << "Testando 'prim'" << endl;

    cout << "  . graph1 (exemplo do enunciado)" << endl;
    Graph g1 = FunWithGraphs::graph1();
    EXPECT_EQ(27, g1.prim(1));
    EXPECT_EQ(27, g1.prim(2));
    EXPECT_EQ(27, g1.prim(3));
    EXPECT_EQ(27, g1.prim(4));
    EXPECT_EQ(27, g1.prim(5));
    EXPECT_EQ(27, g1.prim(6));
    EXPECT_EQ(27, g1.prim(7));

    cout << "  . graph2" << endl;
    Graph g2 = FunWithGraphs::graph2();
    EXPECT_EQ(38, g2.prim(1));
    EXPECT_EQ(38, g2.prim(5));
    EXPECT_EQ(38, g2.prim(9));

    cout << "  . graph3" << endl;
    Graph g3 = FunWithGraphs::graph3();
    EXPECT_EQ(22, g3.prim(1));
    EXPECT_EQ(22, g3.prim(2));
    EXPECT_EQ(22, g3.prim(3));
    EXPECT_EQ(22, g3.prim(9));
    EXPECT_EQ(22, g3.prim(10));
    EXPECT_EQ(22, g3.prim(11));

    cout << "  . graph4" << endl;
    Graph g4 = FunWithGraphs::graph4();
    EXPECT_EQ(9, g4.prim(1));
    EXPECT_EQ(9, g4.prim(2));
    EXPECT_EQ(9, g4.prim(3));
    EXPECT_EQ(9, g4.prim(4));
}

// ----------------------------------------------------------
// Exercicio 4: Conjuntos Disjuntos (disjoint-sets)
// ----------------------------------------------------------
TEST(test4, disjointSets) {
    cout << "Testando 'DisjointSets'" << endl;

    cout << "  . casos pequenos" << endl;

    DisjointSets<int> s1;
    for (int i=1; i<=3; i++) s1.makeSet(i);
    EXPECT_NE(s1.find(1), s1.find(2));
    EXPECT_NE(s1.find(1), s1.find(3));
    s1.unite(1, 2);
    EXPECT_EQ(s1.find(1), s1.find(2));
    EXPECT_NE(s1.find(1), s1.find(3));
    s1.unite(2, 3);
    EXPECT_EQ(s1.find(1), s1.find(3));
    EXPECT_EQ(s1.find(2), s1.find(3));

    DisjointSets<char> s2;
    for (char c='a'; c<='z'; c++) s2.makeSet(c);
    EXPECT_NE(s2.find('a'), s2.find('b'));
    EXPECT_NE(s2.find('b'), s2.find('c'));
    EXPECT_NE(s2.find('a'), s2.find('d'));
    s2.unite('a', 'b');
    EXPECT_EQ(s2.find('a'), s2.find('b'));
    s2.unite('a', 'c');
    EXPECT_EQ(s2.find('b'), s2.find('c'));
    s2.unite('b', 'd');
    EXPECT_EQ(s2.find('a'), s2.find('d'));

    DisjointSets<int> s3;
    for (int i=0; i<10; i++) s3.makeSet(i);
    s3.unite(0,2); s3.unite(2,4); s3.unite(4,6); s3.unite(6,8);
    s3.unite(9,7); s3.unite(1,3); s3.unite(7,5); s3.unite(3,5);
    EXPECT_NE(s3.find(0), s3.find(1));
    EXPECT_NE(s3.find(3), s3.find(2));
    EXPECT_EQ(s3.find(0), s3.find(8));
    EXPECT_EQ(s3.find(6), s3.find(2));
    EXPECT_EQ(s3.find(1), s3.find(9));
    EXPECT_EQ(s3.find(7), s3.find(3));
    s3.unite(0,9);
    EXPECT_EQ(s3.find(0), s3.find(1));
    EXPECT_EQ(s3.find(3), s3.find(2));
    s3.unite(6,5);
    EXPECT_EQ(s3.find(1), s3.find(0));
    EXPECT_EQ(s3.find(2), s3.find(3));

    cout << "  . caso grande" << endl;

    DisjointSets<int> s4;

    int limit = 150000; // Amount of numbers to store
    int ops = 150;      // Amount of finds in the end

    for (int i=0; i<limit; i++) s4.makeSet(i);
    for (int i=1; i<limit/2; i++) s4.unite(i-1,i);
    for (int i=limit-1; i>limit/2; i--) s4.unite(i-1,i);

    for (int i=0; i<ops; i++) {
        EXPECT_EQ(s4.find(i), s4.find(limit/2-1-i));
        EXPECT_EQ(s4.find(i), s4.find(i+1));
        EXPECT_EQ(s4.find(limit/2-1-i), s4.find(limit/2-2-i));
        EXPECT_EQ(s4.find(limit/2+i), s4.find(limit-1-i));
        EXPECT_EQ(s4.find(limit/2+i), s4.find(limit/2+i+1));
        EXPECT_EQ(s4.find(limit-1-i), s4.find(limit-2-i));
        EXPECT_NE(s4.find(i), s4.find(limit/2+i));
    }

}


// ----------------------------------------------------------
// Exercicio 5: Algoritmo de Kruskal
// ----------------------------------------------------------
TEST(test5, kruskal) {
    cout << "Testando 'kruskal'" << endl;

    cout << "  . graph1 (exemplo do enunciado)" << endl;
    Graph g1 = FunWithGraphs::graph1();
    EXPECT_EQ(27, g1.kruskal());

    cout << "  . graph2" << endl;
    Graph g2 = FunWithGraphs::graph2();
    EXPECT_EQ(38, g2.kruskal());

    cout << "  . graph3" << endl;
    Graph g3 = FunWithGraphs::graph3();
    EXPECT_EQ(22, g3.kruskal());

    cout << "  . graph4" << endl;
    Graph g4 = FunWithGraphs::graph4();
    EXPECT_EQ(9, g4.kruskal());
}

// ----------------------------------------------------------
// Exercicio 6: Uma cidade "quadriculada"
// ----------------------------------------------------------
TEST(test6, gridCity) {
    cout << "Testando 'gridCity'" << endl;

    cout << "  . exemplo" << endl;
    vector<pair<int, int>> plants1 = {{1,5}, {4,1}};
    vector<pair<int, int>> houses1 = {{1,1},{3,4}, {3,6}, {5,5}, {6, 3}, {6,6}};
    EXPECT_EQ(16, FunWithGraphs::gridCity(plants1, houses1));


    cout << "  . outros casos" << endl;

    vector<pair<int, int>> plants2 = {{3,3}};
    vector<pair<int, int>> houses2 = {{1,1},{2,2}, {2,1}, {2,4}, {1,5}, {3,3}, {4,4}, {5, 5}};
    EXPECT_EQ(12, FunWithGraphs::gridCity(plants2, houses2));

    vector<pair<int, int>> plants3 = {{18,50}, {81,38}, {8,8}, {66,33}};
    vector<pair<int, int>> houses3 = {{81,3}, {17,62}, {79,57}, {10,56}, {48,80}, {86, 90},
                                      {30,73},{9,7}, {6,96}, {66,24}, {34,18}, {96,12}};
    EXPECT_EQ(286, FunWithGraphs::gridCity(plants3, houses3));
}