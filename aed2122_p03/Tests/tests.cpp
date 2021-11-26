#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "funSearchProblem.h"
#include <cmath>

using testing::Eq;

TEST(test, facingsun){
    FunSearchProblem test;

    vector<int> v1 = {5, 3, 2, 6, 5, 8, 1, 2, 3, 4, 5};
    vector<int> v2 = {1, 2, 3, 4, 5, 6, 7, 8};
    vector<int> v3 = {9, 8, 7, 6, 5, 4, 3 ,2, 1};
    vector<int> v4 = {6, 3, 10, 2, 5, 12, 9};
    vector<int> v5 = {3, 5, 4, 6, 5, 7, 6, 8, -1};

    try{
        EXPECT_EQ(3, test.facingSun(v1));
        EXPECT_EQ(8, test.facingSun(v2));
        EXPECT_EQ(1, test.facingSun(v3));
        EXPECT_EQ(3, test.facingSun(v4));
        test.facingSun(v5);
    }
    catch(NegativeHeight e){
        EXPECT_EQ("Buildings can't have negative height!", e.getError());
    }
}

TEST(test, squareR){
    FunSearchProblem test;
    vector<int> v = {2, 8, 15, 16, 123454, 9823489, 1209348};

    EXPECT_EQ(floor(sqrt(v[0])), test.squareR(v[0]));
    EXPECT_EQ(floor(sqrt(v[1])), test.squareR(v[1]));
    EXPECT_EQ(floor(sqrt(v[2])), test.squareR(v[2]));
    EXPECT_EQ(floor(sqrt(v[3])), test.squareR(v[3]));
    EXPECT_EQ(floor(sqrt(v[4])), test.squareR(v[4]));
    EXPECT_EQ(floor(sqrt(v[5])), test.squareR(v[5]));
    EXPECT_EQ(floor(sqrt(v[6])), test.squareR(v[6]));
}

TEST(test, missingvalue){

}

TEST(test, minPages){
    FunSearchProblem test;
    vector<int> v = {10, 20, 30, 40};

    EXPECT_EQ(60, test.minPages(v, 2));
}
