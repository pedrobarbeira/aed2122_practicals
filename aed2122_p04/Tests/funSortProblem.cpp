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
    if(nc > values.size()) return -1;
    else {
        nc--;
        vector<unsigned> chocolates = values;
        sort(chocolates.begin(), chocolates.end());
        int min, max, diff = INT_MAX;
        for (int i = 0; i + nc < chocolates.size(); i++) {
            min = chocolates[i];
            max = chocolates[i + nc];
            if (diff > max - min) diff = max - min;
        }
        return diff;
    }
}


// TODO
unsigned FunSortProblem::minPlatforms (const vector<float> &arrival, const vector<float> &departure) {
    vector<float> platformTime;
    for (int i = 0; i < arrival.size(); i++) {
        if (platformTime.empty()) platformTime.push_back(departure[i]);
        else {
            for (vector<float>::iterator it = platformTime.begin(); it < platformTime.end(); it++) {
                if (arrival[i] > (*it)) {
                    (*it) = departure[i];
                    break;
                } else if (it == platformTime.end() - 1) {
                    platformTime.push_back(departure[i]);
                    break;
                }
            }
        }
    }
    return platformTime.size();
}


// TODO

bool operator<(Piece p1, Piece p2){
    return p1.getDiameter() < p2.getDiameter();
}
void FunSortProblem::nutsBolts(vector<Piece> &nuts, vector<Piece> &bolts) {
    sort(nuts.begin(), nuts.end());
    sort(bolts.begin(), bolts.end());
}

