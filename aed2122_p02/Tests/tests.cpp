#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "cycle.h"
#include "myVector.h"
#include "fibonacci.h"
#include <fstream>
#include <ctime>

using testing::Eq;

TEST(test_1, max){
    MyVector<int> v;

    EXPECT_THROW(v.max(), EmptyVector);

    v.push_back(4); v.push_back(33);
    v.push_back(14); v.push_back(18);
    v.push_back(45); v.push_back(33);
    EXPECT_EQ(45,v.max());

    v.push_back(85);
    EXPECT_EQ(85,v.max());

       /*
    ticks tstart, tend;
    unsigned t;
    tstart = getticks();
    EXPECT_EQ(85,v.max());
    tend = getticks();
    t = ( (int)tend - (int)tstart )/1000;
    cout << "(vmax(size 8)) t = " <<  t <<endl;
     */

}

TEST(test_1, hasDuplicates){
    MyVector<int> v;

    v.push_back(4); v.push_back(33);
    v.push_back(14); v.push_back(18);
    v.push_back(45);
    EXPECT_EQ(false,v.hasDuplicates());

    v.push_back(33);
    EXPECT_EQ(true,v.hasDuplicates());
}

TEST(test_1, removeDuplicates){
    MyVector<int> v;

    v.push_back(4); v.push_back(33);
    v.push_back(14); v.push_back(18);
    v.push_back(45); v.push_back(10);

    v.removeDuplicates();
    vector<int> vx = v.getValues();
    EXPECT_EQ(6, vx.size());
    EXPECT_EQ(4, vx[0]);
    EXPECT_EQ(18, vx[3]);

    v.push_back(33); v.push_back(20);
    v.push_back(18);
    v.removeDuplicates();
    vx = v.getValues();
    EXPECT_EQ(7, vx.size());
    EXPECT_EQ(4, vx[0]);
    EXPECT_EQ(33, vx[1]);
    EXPECT_EQ(18, vx[3]);
    EXPECT_EQ(20, vx[6]);

    v.push_back(20); v.push_back(20);
    v.push_back(20); v.push_back(44);
    v.removeDuplicates();
    vx = v.getValues();
    EXPECT_EQ(8, vx.size());
    EXPECT_EQ(4, vx[0]);
    EXPECT_EQ(18, vx[3]);
    EXPECT_EQ(20, vx[6]);
    EXPECT_EQ(44, vx[7]);
}

void testTime(unsigned (*func)(unsigned), ostream& o, unsigned i, unsigned max){
    clock_t t;
    clock_t out;
    int n = 1;
    do {
        t = clock();
        func(n);
        out = clock() - t;
        o << "n: " << n << " time: " << out << endl;
        n+=i;
    }while(out < max);

}

TEST(test_2, fibonacci_1){
    ofstream outfile("C:\\Users\\35191\\Desktop\\MIEIC\\2ano\\1o Semestre\\AEDA\\Praticas\\aed2122_p02\\aeda2122_p02ex2a.txt");
    EXPECT_EQ(0, fibonacci_1(0));
    EXPECT_EQ(1, fibonacci_1(1));
    EXPECT_EQ(1, fibonacci_1(2));
    EXPECT_EQ(13, fibonacci_1(7));
    EXPECT_EQ(144, fibonacci_1(12));
    EXPECT_EQ(2584, fibonacci_1(18));
    //testTime(fibonacci_1, outfile);
    outfile.close();
}


TEST(test_2, fibonacci_2){
    EXPECT_EQ(0, fibonacci_2(0));
    EXPECT_EQ(1, fibonacci_2(1));
    EXPECT_EQ(1, fibonacci_2(2));
    EXPECT_EQ(13, fibonacci_2(7));
    EXPECT_EQ(144, fibonacci_2(12));
    EXPECT_EQ(2584, fibonacci_2(18));

    ofstream outfile("C:\\Users\\35191\\Desktop\\MIEIC\\2ano\\1o Semestre\\AEDA\\Praticas\\aed2122_p02\\aeda2122_p02ex2b.txt");
    testTime(fibonacci_2, outfile, 1000000, 1000);
    outfile.close();
}
