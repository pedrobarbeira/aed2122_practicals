// AED 2021/2022 - Aula Pratica 11
// Pedro Ribeiro (DCC/FCUP) [17/01/2022]

#ifndef _FUNGRAPHS_H_
#define _FUNGRAPHS_H_

#include "graph.h"
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class FunWithGraphs {
    static Graph *g;
    static map<string, int> index;

public:
    // Some example graphs
    static Graph graph1();
    static Graph graph2();
    static Graph graph3();
    static Graph graph4();
};

#endif
