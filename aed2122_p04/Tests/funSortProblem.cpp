#include "funSortProblem.h"
#include <algorithm>

FunSortProblem::FunSortProblem() {}


//-----------------------------------------------------------------

bool operator<(Product a, Product b){
    if(a.getPrice() == b.getPrice())
        return a.getWeight() < b.getWeight();
    else return a.getPrice() < b.getPrice();
}

// TODO
void FunSortProblem::expressLane(vector<Product> &products, unsigned k) {
    sort(products.begin(), products.end());
    if(k < products.size()) {
        vector<Product> temp = products;
        products.clear();
        for (int i = 0; i < k; i++)
            products.push_back(temp[i]);
    }
}

// TODO
int FunSortProblem::minDifference(const vector<unsigned> &values, unsigned nc) {
    if(values.size() < nc) return -1;
    else
    }
}


// TODO
unsigned FunSortProblem::minPlatforms (const vector<float> &arrival, const vector<float> &departure) {
    return 0;
}


// TODO

void FunSortProblem::nutsBolts(vector<Piece> &nuts, vector<Piece> &bolts) {

}

