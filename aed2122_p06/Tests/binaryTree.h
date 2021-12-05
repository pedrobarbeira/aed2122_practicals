    #ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

template <class T> class BTItrIn;
template <class T> class BTItrPre;
template <class T> class BTItrPost;
template <class T> class BTItrLevel;
template <class T> class BinaryTree;
class Underflow { };

template <class T>
class BTNode {
    T element;
    BTNode<T>* left, * right;
    friend class BinaryTree<T>;
    friend class BTItrIn<T>;
    friend class BTItrPre<T>;
    friend class BTItrPost<T>;
    friend class BTItrLevel<T>;
public:
    BTNode(const T& el, BTNode<T>* l = 0, BTNode<T>* r = 0): element(el), left(l), right(r) { }
};

template <class T>
class BinaryTree {
    BTNode<T> *root;
    void makeEmpty (BTNode<T> *n);
    BTNode<T>* copySubtree(const BTNode<T>* n) const;
    void outputPreorder(ostream& out, const BTNode<T>* n) const;
    friend class BTItrIn<T>;
    friend class BTItrPre<T>;
    friend class BTItrPost<T>;
    friend class BTItrLevel<T>;
 public:
    BinaryTree() { root = 0; }
    BinaryTree(const BinaryTree<T>& t);
    BinaryTree(const T& el);
    BinaryTree(const T& el, const BinaryTree<T>& l, const BinaryTree<T>& r);
    ~BinaryTree() { makeEmpty(); }
    const BinaryTree<T>& operator= (const BinaryTree<T>& rhs);
    bool isEmpty () const;
    T& getRoot () const;
    void makeEmpty();
    void outputPreorder(ostream &out) const;
};


template <class T>
BinaryTree<T>::BinaryTree(const T& el) {
    root = new BTNode<T>(el);
}

template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& t) {
    root = copySubtree(t.root);
}

template <class T>
BTNode<T>* BinaryTree<T>::copySubtree(const BTNode<T>* n) const {
    if (n) {
        BTNode<T>* node = new BTNode<T>(n->element, copySubtree(n->left), copySubtree(n->right));
        return node;
    }
    return 0;
}

template <class T>
BinaryTree<T>::BinaryTree(const T& el, const BinaryTree<T>& l, const BinaryTree<T>& r) {
    root = new BTNode<T>(el, copySubtree(l.root), copySubtree(r.root));
}

template <class T>
const BinaryTree<T>& BinaryTree<T>::operator= (const BinaryTree<T>& rhs) {
    if (this != & rhs) {
        makeEmpty();
        root = copySubtree(rhs.root);
    }
    return *this;
}

template <class T>
bool BinaryTree<T>::isEmpty() const {
    return (root == 0) ? true : false;
}

template <class T>
T& BinaryTree<T>::getRoot () const {
    if (root)
        return root->element;
    throw Underflow();
}

template <class T>
void BinaryTree<T>::makeEmpty() {
    makeEmpty(root);
}


template <class T>
void BinaryTree<T>::makeEmpty(BTNode<T>* n) {
    if (n) {
        makeEmpty(n->left);
        makeEmpty(n->right);
        delete n;
    }
}

template <class T>
void BinaryTree<T>::outputPreorder(ostream& out) const {
    outputPreorder(out, root);
}

template <class T>
void BinaryTree<T>::outputPreorder(ostream& out, const BTNode<T>* n) const {
    out << '(';
    if (n) {
        out <<  n->element << ' ';
        outputPreorder(out, n->left);
        out << ' ';
        outputPreorder(out, n->right);
    }
    out << ')';
}

template <class T>
ostream& operator<<(ostream& out, const BinaryTree<T>& t) {
    t.outputPreorder(out);
    return out;
}


// ---------- Iterators  ------------

// Postorder iterator
template <class T>
class BTItrPost {
    stack<BTNode<T> *> itrStack;
    stack<bool> visitStack;
    void slideDown(BTNode<T>* n);
public:
    BTItrPost(const BinaryTree<T>& t);
    void advance();
    T& retrieve() const { return itrStack.top()->element; }
    bool isAtEnd() const { return itrStack.empty(); }
};

template <class T>
BTItrPost<T>::BTItrPost (const BinaryTree<T>& t) {
    if (!t.isEmpty())
        slideDown(t.root);
}

template <class T>
void BTItrPost<T>::advance () {
    itrStack.pop();
    visitStack.pop();
    if (!itrStack.empty() && (visitStack.top() == false)) {
        visitStack.pop();
        visitStack.push(true);
        slideDown(itrStack.top()->right);
    }
}

template <class T>
void BTItrPost<T>::slideDown(BTNode<T>* n) {
    while (n) {
        itrStack.push(n);
        if (n->left) {
            visitStack.push(false);
            n = n->left;
        }
        else if (n->right) {
            visitStack.push(true);
            n = n->right;
        }
        else {
            visitStack.push(true);
            break;
        }
    }
}


// Preorder iterator
template <class T>
class BTItrPre {
    stack<BTNode<T> *> itrStack;
public:
    BTItrPre(const BinaryTree<T>& t);
    void advance();
    T& retrieve() const { return itrStack.top()->element; }
    bool isAtEnd() const { return itrStack.empty(); }
};

template <class T>
BTItrPre<T>::BTItrPre (const BinaryTree<T>& t) {
    if (!t.isEmpty())
        itrStack.push(t.root);
}

template <class T>
void BTItrPre<T>::advance() {
    BTNode<T>* actual = itrStack.top();
    BTNode<T>* next = actual->left;
    if (next)
        itrStack.push(next);
    else {
        while (!itrStack.empty()) {
            actual = itrStack.top();
            itrStack.pop();
            next = actual -> right;
            if (next) {
                itrStack.push(next);
                break;
            }
        }
    }
}


// Inorder iterator
template <class T>
class BTItrIn {
    stack<BTNode<T> *> itrStack;
    void slideLeft(BTNode<T>* n);
public:
    BTItrIn(const BinaryTree<T>& t);
    void advance();
    T& retrieve() const { return itrStack.top()->element; }
    bool isAtEnd() const { return itrStack.empty(); }
};

template <class T>
BTItrIn<T>::BTItrIn (const BinaryTree<T>& t) {
    if (!t.isEmpty())
        slideLeft(t.root);
}

template <class T>
void BTItrIn<T>::slideLeft(BTNode<T>* n) {
    while (n) {
        itrStack.push(n);
        n = n->left;
    }
}

template <class T>
void BTItrIn<T>::advance() {
    BTNode<T>* actual = itrStack.top();
    itrStack.pop();
    BTNode<T>* next = actual->right;
    if (next)
        slideLeft(next);
}


// Bylevel iterator
template <class T>
class BTItrLevel {
    queue<BTNode<T> *> itrQueue;
public:
    BTItrLevel(const BinaryTree<T>& t);
    void advance();
    T& retrieve() const { return itrQueue.front()->element; }
    bool isAtEnd() const { return itrQueue.empty(); }
};

template <class T>
BTItrLevel<T>::BTItrLevel (const BinaryTree<T>& t) {
    if (!t.isEmpty())
        itrQueue.push(t.root);
}

template <class T>
void BTItrLevel<T>::advance() {
    BTNode<T>* actual = itrQueue.front();
    itrQueue.pop();
    BTNode<T>* next = actual->left;
    if (next)
        itrQueue.push(next);
    next = actual->right;
    if (next)
        itrQueue.push(next);
}

#endif

