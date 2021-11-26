#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

template <class T>
class MyVector {
    vector<T> values;
public:
    MyVector();
    ~MyVector();
    void push_back(T v1);
    vector<T> getValues() const;
    T max() const;
    bool hasDuplicates() const;
    void removeDuplicates() ;
};


// exception EmptyVector
class EmptyVector
{ };

// methods
template <class T>
MyVector<T>::MyVector() {}

template <class T>
MyVector<T>::~MyVector() {}

template <class T>
void MyVector<T>::push_back(T v1) {
    values.push_back(v1);
}

template <class T>
vector<T> MyVector<T>::getValues() const {
    return values;
}

//---------------------------------

// TODO
template <class T>
//Time Complexity: O(N)
//Space Complexity: O(N)
T MyVector<T>::max() const {
    if(values.empty()) throw EmptyVector();
    T vmax = values[0];
    typename vector<T>::const_iterator it;
    for(it = values.begin(); it !=values.end(); it++) {
        if ((*it) > vmax)
            vmax = (*it);
    }
	return vmax;
}

// TODO
template<class T>
//Time Complexity: O(N^2)
//Space Complexity: O(N)
bool MyVector<T>::hasDuplicates() const {
    typename vector<T>::const_iterator it;
    typename vector<T>::const_iterator et;
    for(it = values.begin(); it != values.end(); it++){
        for(et = it + 1; et != values.end(); et++){
            if((*it) == (*et))
                return true;
        }
    }
	return false;
}

// TODO
template<class T>
//Time Complexity: O(N^2)
//Space Complexity: O(N);
void MyVector<T>::removeDuplicates() {
    typename vector<T>::iterator it;
    typename vector<T>::iterator et;
    for (it = values.begin(); it != values.end(); it++) {
        for (et = it+1; et != values.end(); et++) {
            if ((*it) == (*et)) {
                values.erase(et);
                et--;
            }
        }
    }
}

/**3a)*/
//Time Complexity: O(N^2/(2*1+log(N)));
//Space Complexity: O(1)

/**3b)*/
//Time Complexity: O(N^2)
//Space Complexity: O(1)
