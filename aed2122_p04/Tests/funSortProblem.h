#ifndef SRC_FUNSORTP_H_
#define SRC_FUNSORTP_H_

#include <iostream>
#include <vector>
#include "product.h"
#include "piece.h"

using namespace std;

class FunSortProblem{
public:
    FunSortProblem();
    static void expressLane(vector<Product> &products, unsigned k);
    static int minDifference(const vector<unsigned> &values, unsigned nc);
    static unsigned minPlatforms (const vector<float> &arrival, const vector<float> &departure);
    static void nutsBolts(vector<Piece> &nuts, vector<Piece> &bolds);
};

#endif