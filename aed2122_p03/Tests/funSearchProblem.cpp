#include "funSearchProblem.h"

FunSearchProblem::FunSearchProblem() {}

//-----------------------------------------------------------------

/**
 * Calculates the number of buildings which will see the sun rice
 * @param values the vector with buildings' heights
 * @return the result
 */
int FunSearchProblem::facingSun(const vector<int> & values){
    int res = 1;
    int lastTaller = values[0];
    for(auto it = values.begin(); it != values.end(); it++){
        if((*it) < 0) throw NegativeHeight();
        else {
            if ((*it) > lastTaller) {
                lastTaller = (*it);
                res++;
            }
        }
    }
    return res;
}

// TODO
int FunSearchProblem::squareR(int num) {
    int p, x = 1, y=1;
    while(pow(x*2, 2) < num){
        x = y;
        y *= 2;
    }
    if(pow(x, 2) == num) return x;
    else {
        int mid = (x+y/2);
        while (pow(mid, 2) > num || pow(mid + 1, 2) < num) {
            mid = (x + y) / 2;
            p = pow(mid, 2);
            if (p > num) y = mid;
            else x = mid;
        }
        return mid;
    }
}

// TODO
int FunSearchProblem::smallestMissingValue(const vector<int> & values) {
    vector<bool> numbers(INT_MAX, false);
    for(int i = 0; i < values.size(); i++)
        if(values[i] > 0)
            numbers[values[i]] = true;
    for(int i = 0; i < numbers.size(); i++)
        if(i == false) return i;
    return 0;
}

// TODO
int FunSearchProblem::minPages(const vector<int> & values, int numSt) {
    int lo = 0, hi = 0;
    for(auto it: values){
        lo = max(lo, it);
        hi += it;
    }
    while(lo < hi){
        int mid = (lo + hi)/2;
        int students = 1, sum = 0;
        for(auto it: values){
            sum += it;
            if (sum > mid){
                sum = it;
                students++;
            }
        }
        if(students > numSt) lo = mid + 1;
        else hi = mid;
    }

    return lo;
}

