// AED 2021/2022 - Aula Pratica 09
// Pedro Ribeiro (DCC/FCUP) [03/01/2022]

#include "funWithGraphs.h"
#include "graph.h"

#include <vector>
#include <iostream>


// ----------------------------------------------------------
// Some Example Graphs
// ----------------------------------------------------------

Graph FunWithGraphs::graph1() {
    Graph g(9, false);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.addEdge(5,7);
    g.addEdge(6,9);
    g.addEdge(7,8);
    return g;
}

Graph FunWithGraphs::graph2() {
    Graph g(9, false);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(4,5);
    g.addEdge(6,9);
    g.addEdge(6,7);
    g.addEdge(8,7);
    g.addEdge(8,9);
    return g;
}

Graph FunWithGraphs::graph3() {
    Graph g(12, false);
    g.addEdge(8,1);
    g.addEdge(8,2);
    g.addEdge(8,3);
    g.addEdge(8,7);
    g.addEdge(8,9);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.addEdge(5,11);
    g.addEdge(5,12);
    g.addEdge(6,11);
    g.addEdge(6,12);
    g.addEdge(12,11);
    g.addEdge(11,10);
    return g;
}

Graph FunWithGraphs::graph4() {
    Graph g(9, true);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(5,6);
    g.addEdge(9,6);
    g.addEdge(7,5);
    g.addEdge(8,7);
    return g;
}

Graph FunWithGraphs::graph5() {
    Graph g(4, true);
    g.addEdge(1,2);
    g.addEdge(2,4);
    g.addEdge(4,3);
    g.addEdge(3,1);
    return g;
}

Graph FunWithGraphs::graph6() {
    Graph g(8, true);
    g.addEdge(1,2);
    g.addEdge(2,4);
    g.addEdge(3,1);
    g.addEdge(5,4);
    g.addEdge(5,6);
    g.addEdge(6,7);
    g.addEdge(6,8);
    g.addEdge(8,7);
    return g;
}

Graph FunWithGraphs::graph7() {
    Graph g(3, true);
    g.addEdge(1,2);
    g.addEdge(2,1);
    g.addEdge(1,3);
    g.addEdge(3,1);
    g.addEdge(2,3);
    g.addEdge(3,2);
    return g;
}

Graph FunWithGraphs::graph8() {
    Graph g(49, false);

    // F
    g.addEdge(1,2);
    g.addEdge(1,23);
    g.addEdge(23,24);
    g.addEdge(23,29);
    // E
    g.addEdge(3,4);
    g.addEdge(3,25);
    g.addEdge(25,26);
    g.addEdge(25,30);
    g.addEdge(30,31);
    // L
    g.addEdge(5,32);
    g.addEdge(5,33);
    // I
    g.addEdge(6,34);
    // Z
    g.addEdge(7,8);
    g.addEdge(7,35);
    g.addEdge(35,36);
    g.addEdge(3,25);

    // A
    g.addEdge(9,10);
    g.addEdge(9,27);
    g.addEdge(27,28);
    g.addEdge(10,28);
    g.addEdge(27,37);
    g.addEdge(28,38);
    // N
    g.addEdge(11,39);
    g.addEdge(11,40);
    g.addEdge(12,40);
    // O
    g.addEdge(13,14);
    g.addEdge(13,41);
    g.addEdge(41,42);
    g.addEdge(14,42);

    // N
    g.addEdge(15,43);
    g.addEdge(15,44);
    g.addEdge(16,44);
    // O
    g.addEdge(17,18);
    g.addEdge(17,45);
    g.addEdge(45,46);
    g.addEdge(18,46);
    // V
    g.addEdge(19,47);
    g.addEdge(20,47);
    // O
    g.addEdge(21,22);
    g.addEdge(21,48);
    g.addEdge(48,49);
    g.addEdge(22,49);

    return g;
}


