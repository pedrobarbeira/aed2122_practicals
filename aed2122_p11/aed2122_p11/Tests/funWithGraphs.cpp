// AED 2021/2022 - Aula Pratica 11
// Pedro Ribeiro (DCC/FCUP) [17/01/2022]

#include "funWithGraphs.h"
#include "graph.h"

// ----------------------------------------------------------
// Some Example Graphs
// ----------------------------------------------------------

Graph FunWithGraphs::graph1() {
    Graph g(7, false);
    g.addEdge(1, 2, 12);
    g.addEdge(1, 4, 3);
    g.addEdge(2, 4, 8);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 5, 1);
    g.addEdge(3, 5, 9);
    g.addEdge(3, 6, 3);
    g.addEdge(3, 7, 6);
    g.addEdge(4, 5, 5);
    g.addEdge(4, 6, 5);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7,1);
    return g;
}

Graph FunWithGraphs::graph2() {
    Graph g(9, false);
    g.addEdge(1,2, 16);
    g.addEdge(1,4, 3);
    g.addEdge(1,5, 8);
    g.addEdge(2,3, 12);
    g.addEdge(2,5, 15);
    g.addEdge(2,6, 1);
    g.addEdge(3,6, 10);
    g.addEdge(4,5, 9);
    g.addEdge(4,7, 7);
    g.addEdge(5,6, 6);
    g.addEdge(5,7, 5);
    g.addEdge(5,8, 2);
    g.addEdge(6,8, 14);
    g.addEdge(6,9, 4);
    g.addEdge(7,8, 13);
    g.addEdge(8,9, 11);
    return g;
}

Graph FunWithGraphs::graph3() {
    Graph g(11, true);
    g.addEdge(2, 1, 2);
    g.addEdge(1, 7, 1);
    g.addEdge(3, 2, 4);
    g.addEdge(2, 8, 15);
    g.addEdge(8, 3, 8);
    g.addEdge(4, 3, 4);
    g.addEdge(5, 4, 3);
    g.addEdge(6, 4, 1);
    g.addEdge(8, 4, 2);
    g.addEdge(10, 5, 2);
    g.addEdge(10, 6, 3);
    g.addEdge(11, 6, 5);
    g.addEdge(7, 8, 5);
    g.addEdge(7, 9, 2);
    g.addEdge(8, 9, 1);
    g.addEdge(9, 10, 7);
    g.addEdge(11, 9, 3);
    g.addEdge(11, 10, 5);
    return g;
}

Graph FunWithGraphs::graph4() {
    Graph g(4, false);
    g.addEdge(1, 2, 5);
    g.addEdge(2, 1, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(3, 1, 8);
    g.addEdge(1, 4, 9);
    g.addEdge(3, 2, 42);
    g.addEdge(4, 2, -6);
    g.addEdge(4, 3, -8);
    return g;
}
