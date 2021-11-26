#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "funSortProblem.h"
#include "product.h"
#include "piece.h"

using testing::Eq;

TEST(test, expressLane){
    Product p1("pastaX1",3.2,500);
    Product p2("peanutsYY",5.4,700 );
    Product p3("cookieSA2",4.2,600);
    Product p4("milkAS",5.4,600);
    vector<Product> products = {p1,p2,p3,p4};

    FunSortProblem::expressLane(products,3);
    EXPECT_EQ(3,products.size());
    if (products.size() == 3) {
        EXPECT_NE(products.end(), find_if(products.begin(),products.end(), [&](const Product& e) { return e.getId() == "pastaX1"; }));
        EXPECT_EQ(products.end(), find_if(products.begin(),products.end(), [&](const Product& e) { return e.getId() == "peanutsYY"; }));
        EXPECT_NE(products.end(), find_if(products.begin(),products.end(), [&](const Product& e) { return e.getId() == "cookieSA2"; }));
        EXPECT_NE(products.end(), find_if(products.begin(),products.end(), [&](const Product& e) { return e.getId() == "milkAS"; }));
    }

    products = {p1,p2,p3};
    FunSortProblem::expressLane(products,3);
    EXPECT_EQ(3,products.size());
    if (products.size() == 3) {
        EXPECT_NE(products.end(), find_if(products.begin(),products.end(), [&](const Product& e) { return e.getId() == "pastaX1"; }));
        EXPECT_NE(products.end(), find_if(products.begin(),products.end(), [&](const Product& e) { return e.getId() == "peanutsYY"; }));
        EXPECT_NE(products.end(), find_if(products.begin(),products.end(), [&](const Product& e) { return e.getId() == "cookieSA2"; }));
    }

    products = {p1,p2,p3};
    FunSortProblem::expressLane(products,4);
    EXPECT_EQ(3,products.size());
    if (products.size() == 3) {
        EXPECT_NE(products.end(), find_if(products.begin(),products.end(), [&](const Product& e) { return e.getId() == "pastaX1"; }));
        EXPECT_NE(products.end(), find_if(products.begin(),products.end(), [&](const Product& e) { return e.getId() == "peanutsYY"; }));
        EXPECT_NE(products.end(), find_if(products.begin(),products.end(), [&](const Product& e) { return e.getId() == "cookieSA2"; }));
    }

    products = {};
    FunSortProblem::expressLane(products,2);
    EXPECT_EQ(0,products.size());
}

TEST(test, minDifference){
    EXPECT_EQ(6,FunSortProblem::minDifference({3,4,1,9,56,7,9,12}, 5));
    EXPECT_EQ(-1,FunSortProblem::minDifference({3,4,1,9,56,7}, 7));
    EXPECT_EQ(11,FunSortProblem::minDifference({3,4,1,9,12,7}, 6));
    EXPECT_EQ(2,FunSortProblem::minDifference({7, 3, 2, 4, 9, 12, 56}, 3));
}

TEST(test, minPlatforms){
    EXPECT_EQ(3,FunSortProblem::minPlatforms({9.00, 9.40, 9.50, 11.00, 15.00, 18.00}, {9.10, 12.00, 11.20, 11.30, 19.00, 20.00}));
    EXPECT_EQ(1,FunSortProblem::minPlatforms({9.00, 11.00, 12.35}, {10.00, 12.00, 12.40}));
    EXPECT_EQ(3,FunSortProblem::minPlatforms({2.00, 2.10, 3.00, 3.20, 3.50, 5.00 }, { 2.30, 3.40, 3.20, 4.30, 4.00, 5.20 }));
}

TEST(test, nutsBolts){
    vector<Piece> nuts = {Piece("n1",10),Piece("n7",9),Piece("n4",11),Piece("n2",8),Piece("n5",7),Piece("n8",12), Piece("n9",15)};
    vector<Piece> bolts = { Piece("b5",7), Piece("b8",12), Piece("b1",10), Piece("b2",8), Piece("b9",15), Piece("b4",11), Piece("b7",9)};
    FunSortProblem::nutsBolts(nuts, bolts);
    EXPECT_EQ(7, nuts.size());
    EXPECT_EQ(7, bolts.size());
    for (unsigned i=0; i<7; i++) {
        EXPECT_EQ(true,nuts[i].getDiameter() == bolts[i].getDiameter());
    }

}
