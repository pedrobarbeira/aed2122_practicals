// AED 2021/2022 - Aula Pratica 10
// Pedro Ribeiro (DCC/FCUP) [09/01/2022]

#ifndef _DISJOINTSETS_H_
#define _DISJOINTSETS_H_

#include <unordered_map>

template <class T>
class DisjointSets {
    struct Node {
        T parent;
        int myrank; // to use on union by rank
    };

    unordered_map<T, Node> a;

public:
    void makeSet(const T& x);            // Create a set with a single element x
    T find(const T& x);                  // Find the representative of the set of element x
    void unite(const T& x, const T& y);  // Merge the sets of elements x and y

};

// Create a set with a single element x
template <class T>
void DisjointSets<T>::makeSet(const T& x) {
    a[x].parent = x;
    a[x].myrank = 0;
}

// Find the representative of the set of element x
template <class T>
T DisjointSets<T>::find(const T& x) {
    if(a[x].parent != x)
        a[x].parent = find(a[x].parent);
    return a[x].parent;
}

// Merge the sets of elements x and y
template <class T>
void DisjointSets<T>::unite(const T& x, const T& y) {
    T xRoot = find(x);
    T yRoot = find(y);
    if(xRoot == yRoot) return;
    if(a[xRoot].myrank < a[yRoot].myrank)
        a[xRoot].parent = yRoot;
    else if (a[xRoot].myrank > a[yRoot].myrank)
        a[yRoot].parent = xRoot;
    else{
        a[yRoot].parent = xRoot;
        a[xRoot].myrank++;
    }
}

#endif
