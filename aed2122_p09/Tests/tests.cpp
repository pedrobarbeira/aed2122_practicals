// AED 2021/2022 - Aula Pratica 09
// Pedro Ribeiro (DCC/FCUP) [03/01/2022]

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "graph.h"
#include "funWithGraphs.h"

using testing::Eq;

// ----------------------------------------------------------
// Exercicio 1: Introdução a uma classe simplificada de grafos
// ----------------------------------------------------------

// ..............................
// a) Devolvendo o grau
TEST(test_1, outDegree) {
    cout << "Testando 'outDegree'" << endl;

    cout << "  . graph1 (exemplo do enunciado)" << endl;
    Graph g1 = FunWithGraphs::graph1();
    EXPECT_EQ(2, g1.outDegree(1));
    EXPECT_EQ(3, g1.outDegree(4));
    EXPECT_EQ(1, g1.outDegree(9));
    EXPECT_EQ(-1, g1.outDegree(10));

    cout << "  . graph3" << endl;
    Graph g3 = FunWithGraphs::graph3();
    EXPECT_EQ(5, g3.outDegree(8));
    EXPECT_EQ(4, g3.outDegree(5));
    EXPECT_EQ(3, g3.outDegree(6));
    EXPECT_EQ(2, g3.outDegree(1));
    EXPECT_EQ(1, g3.outDegree(7));
    EXPECT_EQ(-1, g3.outDegree(13));
    EXPECT_EQ(-1, g3.outDegree(0));

    cout << "  . graph4" << endl;
    Graph g4 = FunWithGraphs::graph4();
    EXPECT_EQ(2, g4.outDegree(1));
    EXPECT_EQ(1, g4.outDegree(3));
    EXPECT_EQ(0, g4.outDegree(6));
    EXPECT_EQ(1, g4.outDegree(4));
}

// ----------------------------------------------------------
// Exercicio 2: Componentes conexos
// ----------------------------------------------------------

// ..............................
// a) Contando componentes conexos
TEST(test_2, connectedComponents) {
    cout << "Testando 'connectedComponents'" << endl;

    cout << "  . graph1" << endl;
    Graph g1 = FunWithGraphs::graph1();
    EXPECT_EQ(1, g1.connectedComponents());

    cout << "  . graph2" << endl;
    Graph g2 = FunWithGraphs::graph2();
    EXPECT_EQ(3, g2.connectedComponents());

    cout << "  . graph3" << endl;
    Graph g3 = FunWithGraphs::graph3();
    EXPECT_EQ(1, g3.connectedComponents());

    cout << "  . graph8" << endl;
    Graph g8 = FunWithGraphs::graph8();
    EXPECT_EQ(12, g8.connectedComponents());
}

// ..............................
// b) Component gigante
TEST(test_2, giantComponents) {
    cout << "Testando 'giantComponent'" << endl;

    cout << "  . graph1" << endl;
    Graph g1 = FunWithGraphs::graph1();
    EXPECT_EQ(9, g1.giantComponent());

    cout << "  . graph2" << endl;
    Graph g2 = FunWithGraphs::graph2();
    EXPECT_EQ(4, g2.giantComponent());

    cout << "  . graph3" << endl;
    Graph g3 = FunWithGraphs::graph3();
    EXPECT_EQ(12, g3.giantComponent());

    cout << "  . graph8" << endl;
    Graph g8 = FunWithGraphs::graph8();
    EXPECT_EQ(6, g8.giantComponent());
}

// ----------------------------------------------------------
// Exercicio 3: Ordenacao topologica
// ----------------------------------------------------------
TEST(test_3, topologicalSorting) {
    cout << "Testando 'topologicalSorting'" << endl;

    cout << "  . graph4" << endl;
    Graph g4 = FunWithGraphs::graph4();
    list<int> order = g4.topologicalSorting();
     //Uncomment to print order
     cout << "    Order: ";
     for (auto v : order ) cout << " " << v;
     cout << endl;
    // A naive exhaustive verification
    EXPECT_EQ(9, order.size()); // size of order
    for (int v=1; v<=9; v++) EXPECT_NE(order.end(), find(order.begin(), order.end(), v)); // v exists
    // "Ugly", but to keep the graph class as simple as possible and as it was given so as not to confuse students
    vector<pair<int, int>> edges4 = {{1,2},{1,3}, {2,4}, {3,4}, {4,5}, {5,6}, {9,6},{7,5}, {8,7}};
    for (auto e : edges4) {
        auto u = find(order.begin(), order.end(), e.first);
        auto v = find(order.begin(), order.end(), e.second);
        EXPECT_LT(distance(order.begin(), u), distance(order.begin(), v)); // pos(u) < pos(v)
    }

    cout << "  . graph6" << endl;
    Graph g6 = FunWithGraphs::graph6();
    order = g6.topologicalSorting();
    // Uncomment to print order
    // cout << "    Order: ";
    // for (auto v : order ) cout << " " << v;
    // cout << endl;
    // A naive exhaustive verification
    EXPECT_EQ(8, order.size()); // size of order
    for (int v=1; v<=8; v++) EXPECT_NE(order.end(), find(order.begin(), order.end(), v)); // v exists
    // "Ugly", but to keep the graph class as simple as possible and as it was given so as not to confuse students
    vector<pair<int, int>> edges6 = {{1,2},{3,1}, {2,4}, {5,4}, {5,6}, {6,7},{6,8}, {8,7}};
    for (auto e : edges6) {
        auto u = find(order.begin(), order.end(), e.first);
        auto v = find(order.begin(), order.end(), e.second);
        EXPECT_LT(distance(order.begin(), u), distance(order.begin(), v)); // pos(u) < pos(v)
    }
}

// ----------------------------------------------------------
// Exercicio 4: Distancias em grafos nao pesados
// ----------------------------------------------------------

// ..............................
// a) Distancia entre dois nos
TEST(test_4, distance) {
    cout << "Testando 'distance'" << endl;

    cout << "  . graph1" << endl;
    Graph g1 = FunWithGraphs::graph1();
    EXPECT_EQ(0, g1.distance(1,1));
    EXPECT_EQ(1, g1.distance(1,2));
    EXPECT_EQ(1, g1.distance(1,3));
    EXPECT_EQ(2, g1.distance(1,4));
    EXPECT_EQ(3, g1.distance(1,5));
    EXPECT_EQ(4, g1.distance(1,6));
    EXPECT_EQ(5, g1.distance(1,9));
    EXPECT_EQ(4, g1.distance(3,9));
    EXPECT_EQ(2, g1.distance(8,5));
    EXPECT_EQ(4, g1.distance(9,8));

    cout << "  . graph2" << endl;
    Graph g2 = FunWithGraphs::graph2();
    EXPECT_EQ(1, g2.distance(1,2));
    EXPECT_EQ(-1, g2.distance(1,4));
    EXPECT_EQ(-1, g2.distance(1,6));
    EXPECT_EQ(2, g2.distance(8,6));
    EXPECT_EQ(1, g2.distance(8,7));
    EXPECT_EQ(1, g2.distance(8,9));
    EXPECT_EQ(-1, g2.distance(8,5));
    EXPECT_EQ(-1, g2.distance(8,3));

    cout << "  . graph3" << endl;
    Graph g3 = FunWithGraphs::graph3();
    EXPECT_EQ(2, g3.distance(2,9));
    EXPECT_EQ(5, g3.distance(10,2));
    EXPECT_EQ(1, g3.distance(5,12));
    EXPECT_EQ(3, g3.distance(7,4));
    EXPECT_EQ(4, g3.distance(1,5));
    EXPECT_EQ(5, g3.distance(12,1));
    EXPECT_EQ(2, g3.distance(9,3));
    EXPECT_EQ(1, g3.distance(8,3));

    cout << "  . graph4" << endl;
    Graph g4 = FunWithGraphs::graph4();
    EXPECT_EQ(1, g4.distance(1,3));
    EXPECT_EQ(-1, g4.distance(3,1));
    EXPECT_EQ(2, g4.distance(8,5));
    EXPECT_EQ(3, g4.distance(1,5));
    EXPECT_EQ(-1, g4.distance(9,5));
}

// ..............................
// b) Diametro
TEST(test_4, diameter) {
    cout << "Testando 'diameter'" << endl;

    cout << "  . graph1" << endl;
    Graph g1 = FunWithGraphs::graph1();
    EXPECT_EQ(5, g1.diameter());

    cout << "  . graph2" << endl;
    Graph g2 = FunWithGraphs::graph2();
    EXPECT_EQ(-1, g2.diameter());

    cout << "  . graph3" << endl;
    Graph g3 = FunWithGraphs::graph3();
    EXPECT_EQ(6, g3.diameter());

    cout << "  . graph4" << endl;
    Graph g4 = FunWithGraphs::graph4();
    EXPECT_EQ(-1, g4.diameter());

    cout << "  . graph5" << endl;
    Graph g5 = FunWithGraphs::graph5();
    EXPECT_EQ(3, g5.diameter());

    cout << "  . graph7" << endl;
    Graph g7 = FunWithGraphs::graph7();
    EXPECT_EQ(1, g7.diameter());
}

// ----------------------------------------------------------
// Exercicio 5: To or not be… a DAG!
// ----------------------------------------------------------
TEST(test_5, hasCycle) {
    cout << "Testando 'hasCycle'" << endl;

    cout << "  . graph4" << endl;
    Graph g4 = FunWithGraphs::graph4();
    EXPECT_FALSE(g4.hasCycle());

    cout << "  . graph5" << endl;
    Graph g5 = FunWithGraphs::graph5();
    EXPECT_TRUE(g5.hasCycle());

    cout << "  . graph6" << endl;
    Graph g6 = FunWithGraphs::graph6();
    EXPECT_FALSE(g6.hasCycle());

    cout << "  . graph7" << endl;
    Graph g7 = FunWithGraphs::graph7();
    EXPECT_TRUE(g7.hasCycle());
}