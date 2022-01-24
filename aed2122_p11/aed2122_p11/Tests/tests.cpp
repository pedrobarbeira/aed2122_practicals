// AED 2021/2022 - Aula Pratica 11
// Pedro Ribeiro (DCC/FCUP) [17/01/2022]

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "graph.h"
#include "funWithGraphs.h"
#include "minHeap.h"

using testing::Eq;

// ----------------------------------------------------------
// 1) Algoritmo de Dijkstra e caminhos mais curtos
// ----------------------------------------------------------

// ..............................
// a) Distância entre dois nós
TEST(test1, dijkstra_distance) {
    cout << "Testando 'dijkstra_distance'" << endl;

    cout << "  . graph1" << endl;
    Graph g1 = FunWithGraphs::graph1();
    EXPECT_EQ(9,g1.dijkstra_distance(1, 2));
    EXPECT_EQ(9,g1.dijkstra_distance(2, 1));
    EXPECT_EQ(8,g1.dijkstra_distance(1, 5));
    EXPECT_EQ(8,g1.dijkstra_distance(5, 1));
    EXPECT_EQ(11,g1.dijkstra_distance(1, 3));
    EXPECT_EQ(11,g1.dijkstra_distance(3, 1));
    EXPECT_EQ(9,g1.dijkstra_distance(1, 7));
    EXPECT_EQ(9,g1.dijkstra_distance(7, 1));
    EXPECT_EQ(8,g1.dijkstra_distance(4, 3));
    EXPECT_EQ(8,g1.dijkstra_distance(3, 4));
    EXPECT_EQ(6,g1.dijkstra_distance(4, 2));
    EXPECT_EQ(6,g1.dijkstra_distance(2, 4));

    cout << "  . graph2" << endl;
    Graph g2 = FunWithGraphs::graph2();
    EXPECT_EQ(18,g2.dijkstra_distance(1, 9));
    EXPECT_EQ(18,g2.dijkstra_distance(9, 1));
    EXPECT_EQ(24,g2.dijkstra_distance(1, 3));
    EXPECT_EQ(24,g2.dijkstra_distance(3, 1));
    EXPECT_EQ(11,g2.dijkstra_distance(2, 3));
    EXPECT_EQ(11,g2.dijkstra_distance(3, 2));
    EXPECT_EQ(8,g2.dijkstra_distance(6, 8));
    EXPECT_EQ(8,g2.dijkstra_distance(8, 6));

    cout << "  . graph3" << endl;
    Graph g3 = FunWithGraphs::graph3();
    EXPECT_EQ(-1,g3.dijkstra_distance(8, 11));
    EXPECT_EQ(22,g3.dijkstra_distance(11, 8));
    EXPECT_EQ(12,g3.dijkstra_distance(3, 8));
    EXPECT_EQ(6,g3.dijkstra_distance(8, 3));
    EXPECT_EQ(2,g3.dijkstra_distance(10, 5));
    EXPECT_EQ(23,g3.dijkstra_distance(5, 10));
    EXPECT_EQ(4,g3.dijkstra_distance(10, 4));
    EXPECT_EQ(-1,g3.dijkstra_distance(6, 11));
    EXPECT_EQ(-1,g3.dijkstra_distance(1, 11));
}

// ..............................
// b) Caminho mais curto entre dois nós
TEST(test1, dijkstra_path) {
    cout << "Testando 'dijkstra_path'" << endl;

    // For these examples there is only one shortest path, so we can compare
    // directly, but on a general case, for accepting any shortest path,
    // the verification would need to take that into account

    list<int> ans;

    cout << "  . graph1" << endl;
    Graph g1 = FunWithGraphs::graph1();
    ans = {1,4,5,2}; EXPECT_EQ(ans,g1.dijkstra_path(1, 2));
    ans = {2,5,4,1}; EXPECT_EQ(ans,g1.dijkstra_path(2, 1));
    ans = {1,4,5}; EXPECT_EQ(ans,g1.dijkstra_path(1, 5));
    ans = {5,4,1}; EXPECT_EQ(ans,g1.dijkstra_path(5, 1));
    ans = {1,4,6,3}; EXPECT_EQ(ans,g1.dijkstra_path(1, 3));
    ans = {3,6,4,1}; EXPECT_EQ(ans,g1.dijkstra_path(3, 1));
    ans = {1,4,6,7}; EXPECT_EQ(ans,g1.dijkstra_path(1, 7));
    ans = {7,6,4,1}; EXPECT_EQ(ans,g1.dijkstra_path(7, 1));
    ans = {4,6,3}; EXPECT_EQ(ans,g1.dijkstra_path(4, 3));
    ans = {3,6,4}; EXPECT_EQ(ans,g1.dijkstra_path(3, 4));
    ans = {4,5,2}; EXPECT_EQ(ans,g1.dijkstra_path(4, 2));
    ans = {2,5,4}; EXPECT_EQ(ans,g1.dijkstra_path(2, 4));

    cout << "  . graph2" << endl;
    Graph g2 = FunWithGraphs::graph2();
    ans = {1,5,6,9}; EXPECT_EQ(ans,g2.dijkstra_path(1, 9));
    ans = {9,6,5,1}; EXPECT_EQ(ans,g2.dijkstra_path(9, 1));
    ans = {1,5,6,3}; EXPECT_EQ(ans,g2.dijkstra_path(1, 3));
    ans = {3,6,5,1}; EXPECT_EQ(ans,g2.dijkstra_path(3, 1));
    ans = {2,6,3}; EXPECT_EQ(ans,g2.dijkstra_path(2, 3));
    ans = {3,6,2}; EXPECT_EQ(ans,g2.dijkstra_path(3, 2));
    ans = {6,5,8}; EXPECT_EQ(ans,g2.dijkstra_path(6, 8));
    ans = {8,5,6}; EXPECT_EQ(ans,g2.dijkstra_path(8, 6));

    cout << "  . graph3" << endl;
    Graph g3 = FunWithGraphs::graph3();
    ans = {}; EXPECT_EQ(ans,g3.dijkstra_path(8, 11));
    ans = {11,6,4,3,2,1,7,8}; EXPECT_EQ(ans,g3.dijkstra_path(11, 8));
    ans = {3,2,1,7,8}; EXPECT_EQ(ans,g3.dijkstra_path(3, 8));
    ans = {8,4,3}; EXPECT_EQ(ans,g3.dijkstra_path(8, 3));
    ans = {10,5}; EXPECT_EQ(ans,g3.dijkstra_path(10, 5));
    ans = {5,4,3,2,1,7,9,10}; EXPECT_EQ(ans,g3.dijkstra_path(5, 10));
    ans = {10,6,4}; EXPECT_EQ(ans,g3.dijkstra_path(10, 4));
    ans = {}; EXPECT_EQ(ans,g3.dijkstra_path(6, 11));
    ans = {}; EXPECT_EQ(ans,g3.dijkstra_path(1, 11));
}
