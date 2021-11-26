#ifndef SRC_FUNSP_H_
#define SRC_FUNSP_H_

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class FunSearchProblem{
public:
    FunSearchProblem();
    static int smallestMissingValue(const vector<int> & values);
    static int facingSun(const vector<int> & values);
    static int squareR(int num);
    static int minPages(const vector<int> & values, int numSt);
};

class NegativeHeight{
private:
    string e;
public:
    NegativeHeight(){
        e = "Buildings can't have negative height!";
    };
    string getError() const{
        return e;
    }
};
#endif