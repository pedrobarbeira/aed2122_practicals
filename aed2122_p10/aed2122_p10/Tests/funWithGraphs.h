// AED 2021/2022 - Aula Pratica 10
// Pedro Ribeiro (DCC/FCUP) [09/01/2022]

#ifndef _FUNGRAPHS_H_
#define _FUNGRAPHS_H_

#include "graph.h"
#include <vector>
#include <iostream>

using namespace std;

class FunWithGraphs {

public:
    // Some example graphs
    static Graph graph1();
    static Graph graph2();
    static Graph graph3();
    static Graph graph4();

    // ----- Functions to implement in this class -----
    static int game(const vector<int>& v);
    static int gridCity(const vector<pair<int, int>>& plants, const vector<pair<int, int>>& houses);
};

#endif
