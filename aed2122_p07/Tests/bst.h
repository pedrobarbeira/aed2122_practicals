// AED 2021/2022 - Aula Pratica 07
// Pedro Ribeiro (DCC/FCUP) [06/12/2021]
// [ficheiro original de Ana Paula Rocha com algumas adicoes]

#ifndef _BST_H_
#define _BST_H_

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

template <class Comparable> class BSTItrIn;
template <class Comparable> class BSTItrPre;
template <class Comparable> class BSTItrPost;
template <class Comparable> class BSTItrLevel;
template <class Comparable> class iteratorBST;
template <class Comparable> class BST;

template <class Comparable>
class BinaryNode {
    Comparable element;
    BinaryNode *left;
    BinaryNode *right;
    BinaryNode(const Comparable& theElement, BinaryNode* lt, BinaryNode* rt): element(theElement), left(lt), right(rt) { }
    friend class BST<Comparable>;
    friend class BSTItrIn<Comparable>;
    friend class BSTItrPre<Comparable>;
    friend class BSTItrPost<Comparable>;
    friend class BSTItrLevel<Comparable>;
    friend class iteratorBST<Comparable>;
};

template <class Comparable>
class BST {
    BinaryNode<Comparable> *root;
    const Comparable ITEM_NOT_FOUND;

    const Comparable& elementAt(BinaryNode<Comparable>* t) const;
    bool insert(const Comparable& x, BinaryNode<Comparable>* & t) const;
    bool remove(const Comparable& x, BinaryNode<Comparable>* & t) const;
    BinaryNode<Comparable>* findMin( BinaryNode<Comparable>* t) const;
    BinaryNode<Comparable>* findMax( BinaryNode<Comparable>* t) const;
    BinaryNode<Comparable>* find(const Comparable& x, BinaryNode<Comparable>* t) const;
    void makeEmpty(BinaryNode<Comparable>* & t) const;
    void printTree(BinaryNode<Comparable>* t) const;
    BinaryNode<Comparable>* clone(BinaryNode<Comparable>* t) const;
    friend class BSTItrIn<Comparable>;
    friend class BSTItrPre<Comparable>;
    friend class BSTItrPost<Comparable>;
    friend class BSTItrLevel<Comparable>;
    friend class iteratorBST<Comparable>;

    // Metodos privados completos adicionados para a aula 07
    bool isEqual(BinaryNode<Comparable>* n1, BinaryNode<Comparable>* n2) const;

public:
    explicit BST(const Comparable& notFound);
    BST(const BST& rhs);
    ~BST( );
    const Comparable& findMin( ) const;
    const Comparable& findMax( ) const;
    const Comparable& find(const Comparable& x) const;
    bool isEmpty( ) const;
    void printTree( ) const;
    void makeEmpty( );
    bool insert(const Comparable& x);
    bool remove(const Comparable& x);
    int height(const Comparable& el) const;
    const BST& operator= (const BST& rhs);
    iteratorBST<Comparable> begin() const;
    iteratorBST<Comparable> end() const;

    // Metodos completos adicionados para a aula 07
    void insert(const vector<Comparable>& v);
    bool operator== (const BST& t) const;

    // Metodos a criar na aula 07
    int balance(const Comparable& x) const;
    bool isAVL() const;
    void rightRotate(const Comparable& x);
};

// Note that all "matching" is based on the < method.

template <class Comparable>
BST<Comparable>::BST(const Comparable& notFound): root(NULL), ITEM_NOT_FOUND(notFound)
{ }

template <class Comparable>
BST<Comparable>::BST(const BST<Comparable>& rhs): root(NULL), ITEM_NOT_FOUND(rhs.ITEM_NOT_FOUND) {
    *this = rhs;
}

template <class Comparable>
BST<Comparable>::~BST( ) {
    makeEmpty( );
}

template <class Comparable>
bool BST<Comparable>::insert(const Comparable& x) {
    return insert(x, root);
}

template <class Comparable>
bool BST<Comparable>::remove(const Comparable& x) {
    return remove(x, root);
}

template <class Comparable>
const Comparable& BST<Comparable>::findMin( ) const {
    return elementAt(findMin(root));
}

template <class Comparable>
const Comparable& BST<Comparable>::findMax( ) const {
    return elementAt(findMax(root));
}

template <class Comparable>
const Comparable& BST<Comparable>::find(const Comparable& x) const {
    return elementAt(find(x, root));
}

template <class Comparable>
void BST<Comparable>::makeEmpty( ) {
    makeEmpty(root);
}

template <class Comparable>
bool BST<Comparable>::isEmpty( ) const {
    return root == NULL;
}


template <class Comparable>
void BST<Comparable>::printTree( ) const {
    if(isEmpty())
        cout << "Empty tree" << endl;
    else
        printTree(root);
}

template <class Comparable>
const BST<Comparable>& BST<Comparable>::operator= (const BST<Comparable>& rhs) {
    if(this != &rhs) {
        makeEmpty( );
        root = clone(rhs.root);
    }
    return *this;
}

template <class Comparable>
iteratorBST<Comparable> BST<Comparable>::begin() const {
    iteratorBST<Comparable> it;
    it.setBST(root);
    return it;
}

template <class Comparable>
iteratorBST<Comparable> BST<Comparable>::end() const {
    iteratorBST<Comparable> it;
    it.setBST(NULL);
    return it;
}


// private methods

template <class Comparable>
const Comparable& BST<Comparable>::elementAt(BinaryNode<Comparable>* t) const {
    if(t == NULL)
        return ITEM_NOT_FOUND;
    else
        return t->element;
}

template <class Comparable>
bool BST<Comparable>::insert(const Comparable& x, BinaryNode<Comparable>* & t) const {
    if (t == NULL) {
        t = new BinaryNode<Comparable>(x, NULL, NULL);
        return true;
    }
    else if( x < t->element )
        return insert( x, t->left );
    else if( t->element < x )
        return insert( x, t->right );
    else
        return false;  // Duplicate; do nothing
}

template <class Comparable>
bool BST<Comparable>::remove(const Comparable& x, BinaryNode<Comparable>* & t) const {
    if(t == NULL)
        return false;   // Item not found; do nothing
    if(x < t->element)
        return remove(x, t->left);
    else if(t->element < x)
        return remove(x, t->right);
    else if(t->left != NULL && t->right != NULL) {     // Two children
        t->element = findMin(t->right)->element;
        return remove(t->element, t->right);
    }
    else {
        BinaryNode<Comparable>* oldNode = t;
        t = (t->left != NULL) ? t->left : t->right;
        delete oldNode;
        return true;
    }
}

template <class Comparable>
BinaryNode<Comparable>* BST<Comparable>::findMin(BinaryNode<Comparable>* t) const {
    if(t == NULL)
        return NULL;
    if(t->left == NULL)
        return t;
    return findMin(t->left);
}

template <class Comparable>
BinaryNode<Comparable>* BST<Comparable>::findMax(BinaryNode<Comparable>* t) const {
    if(t != NULL)
        while(t->right != NULL)
            t = t->right;
    return t;
}

template <class Comparable>
BinaryNode<Comparable>* BST<Comparable>::find(const Comparable& x, BinaryNode<Comparable>* t) const
{
    if(t == NULL)
        return NULL;
    else if(x < t->element)
        return find(x, t->left);
    else if(t->element < x)
        return find(x, t->right);
    else
        return t;    // Match
}

template <class Comparable>
void BST<Comparable>::makeEmpty(BinaryNode<Comparable>* & t) const {
    if(t != NULL) {
        makeEmpty(t->left);
        makeEmpty(t->right);
        delete t;
    }
    t = NULL;
}

template <class Comparable>
void BST<Comparable>::printTree(BinaryNode<Comparable>* t) const {
    if(t != NULL) {
        printTree(t->left);
        cout << t->element << endl;
        printTree(t->right);
    }
}

template <class Comparable>
BinaryNode<Comparable>* BST<Comparable>::clone( BinaryNode<Comparable>* t ) const {
    if(t == NULL)
        return NULL;
    else
        return new BinaryNode<Comparable>(t->element, clone(t->left), clone(t->right));
}


//----------- iterators ---------

// Postorder iterator
template <class Comparable>
class BSTItrPost {
    stack<BinaryNode<Comparable> *> itrStack;
    stack<bool> visitStack;
    void slideDown(BinaryNode<Comparable>* n);
public:
    BSTItrPost(const BST<Comparable> &bt);
    void advance();
    const Comparable& retrieve() const { return itrStack.top()->element; }
    bool isAtEnd() const { return itrStack.empty(); }
};

template <class Comparable>
BSTItrPost<Comparable>::BSTItrPost (const BST<Comparable>& bt) {
    if (!bt.isEmpty())
        slideDown(bt.root);
}

template <class Comparable>
void BSTItrPost<Comparable>::advance () {
    itrStack.pop();
    visitStack.pop();
    if ((!itrStack.empty()) && (visitStack.top() == false)) {
        visitStack.pop();
        visitStack.push(true);
        slideDown(itrStack.top()->right);
    }
}

template <class Comparable>
void BSTItrPost<Comparable>::slideDown(BinaryNode<Comparable>* n) {
    while (n) {
        itrStack.push(n);
        if (n->left) {
            visitStack.push(false);
            n = n->left;
        } else if (n->right) {
            visitStack.push(true);
            n = n->right;
        } else {
            visitStack.push(true);
            break;
        }
    }
}


// Preorder iterator
template <class Comparable>
class BSTItrPre {
    stack<BinaryNode<Comparable> *> itrStack;
public:
    BSTItrPre(const BST<Comparable>& bt);
    void advance();
    const Comparable& retrieve() const { return itrStack.top()->element; }
    bool isAtEnd() const { return itrStack.empty(); }
};

template <class Comparable>
BSTItrPre<Comparable>::BSTItrPre (const BST<Comparable>& bt)
{
    if (!bt.isEmpty())
        itrStack.push(bt.root);
}

template <class Comparable>
void BSTItrPre<Comparable>::advance()
{
    BinaryNode<Comparable>* actual = itrStack.top();
    BinaryNode<Comparable>* next = actual->left;
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


//Inorder iterator
template <class Comparable>
class BSTItrIn {
    stack<BinaryNode<Comparable> *> itrStack;
    void slideLeft(BinaryNode<Comparable> *n);
public:
    BSTItrIn(const BST<Comparable>& bt);
    void advance();
    const Comparable& retrieve() const { return itrStack.top()->element; }
    bool isAtEnd() const { return itrStack.empty(); }
};

template <class Comparable>
BSTItrIn<Comparable>::BSTItrIn (const BST<Comparable>& bt) {
    if (!bt.isEmpty())
        slideLeft(bt.root);
}

template <class Comparable>
void BSTItrIn<Comparable>::slideLeft(BinaryNode<Comparable>* n) {
    while (n) {
        itrStack.push(n);
        n = n->left;
    }
}

template <class Comparable>
void BSTItrIn<Comparable>::advance() {
    BinaryNode<Comparable> * actual = itrStack.top();
    itrStack.pop();
    BinaryNode<Comparable> * next = actual->right;
    if (next)
        slideLeft(next);
}


//Bylevel iterator
template <class Comparable>
class BSTItrLevel {
    queue<BinaryNode<Comparable> *> itrQueue;
public:
    BSTItrLevel(const BST<Comparable> &bt);
    void advance();
    const Comparable& retrieve() const { return itrQueue.front()->element; }
    bool isAtEnd() const { return itrQueue.empty(); }
};

template <class Comparable>
BSTItrLevel<Comparable>::BSTItrLevel (const BST<Comparable>& bt) {
    if (!bt.isEmpty())
        itrQueue.push(bt.root);
}

template <class Comparable>
void BSTItrLevel<Comparable>::advance() {
    BinaryNode<Comparable>* actual = itrQueue.front();
    itrQueue.pop();
    BinaryNode<Comparable>* next = actual->left;
    if (next)
        itrQueue.push(next);
    next = actual->right;
    if (next)
        itrQueue.push(next);
}


// another inorder iterator
template <class Comparable>
class iteratorBST {
    stack<BinaryNode<Comparable> *> itrStack;
    void slideLeft(BinaryNode<Comparable>* n);
    void setBST(BinaryNode<Comparable>* root);
    friend class BST<Comparable>;
public:
    iteratorBST<Comparable>& operator ++(int);
    Comparable operator*() const;
    bool operator==(const iteratorBST<Comparable>& it2) const;
    bool operator!=(const iteratorBST<Comparable>& it2) const;
};

template <class Comparable>
void iteratorBST<Comparable>::slideLeft(BinaryNode<Comparable>* n) {
    while (n) {
        itrStack.push(n);
        n = n->left;
    }
}

template <class Comparable>
void iteratorBST<Comparable>::setBST(BinaryNode<Comparable>* root) {
    if (root!=NULL)
        slideLeft(root);
}

template <class Comparable>
iteratorBST<Comparable>& iteratorBST<Comparable>::operator++ (int) {
    BinaryNode<Comparable>* actual = itrStack.top();
    itrStack.pop();
    BinaryNode<Comparable>* next = actual->right;
    if (next)
        slideLeft(next);
    return *this;
}

template <class Comparable>
Comparable iteratorBST<Comparable>::operator*() const {
    return itrStack.top()->element;
}

template <class Comparable>
bool iteratorBST<Comparable>::operator== (const iteratorBST<Comparable>& it2) const {
    return itrStack == it2.itrStack;
}

template <class Comparable>
bool iteratorBST<Comparable>::operator!= (const iteratorBST<Comparable>& it2) const {
    return itrStack != it2.itrStack;
}

//--------------------------------------------------------
// Metodos adicionados para a aula 07
//--------------------------------------------------------

// Inserir todos os elementos de um vector
template <class Comparable>
void BST<Comparable>::insert(const vector<Comparable>& v)  {
    for (auto x : v) insert(x);
}

// Comparar topologia e valores de duas arvores
template <class Comparable>
bool BST<Comparable>::operator== (const BST& t) const {
    return isEqual(root, t.root);
}

// Metodo usado pelo operador == para comparar arvores com raizes em n1 e n2
template <class Comparable>
bool BST<Comparable>::isEqual(BinaryNode<Comparable>* n1, BinaryNode<Comparable> *n2) const {
    if (n1 == NULL && n2 == NULL) return true;
    if (n1 == NULL || n2 == NULL) return false;
    return (n1->element == n2->element) &&
           isEqual(n1->left, n2->left) &&
           isEqual(n1->right, n2->right);
}

// ----------------------------------------------------------
// Exercicio 4: Brincando com arvores
// ----------------------------------------------------------

// ..............................
// a) Desequilibrio de um no
// TODO
template <class Comparable>
int BST<Comparable>::balance(const Comparable& x) const {
    BinaryNode<Comparable> *c;
    c = find(x, root);
    if (c == NULL) return 0;
    int sizeRight;
    int sizeLeft;
    if(c->left == NULL && c->right == NULL) return 0;
    else {
        if(c->left != NULL) {
            sizeLeft = height(c->left->element) + 1;
            if (c->right != NULL){
                sizeRight = height(c->right->element) + 1;
                return sizeRight - sizeLeft;
            }
            else
                return -sizeLeft;
        }
        else
            return height(c->right->element) + 1;
    }
}

template <class Comparable>
int BST<Comparable>::height(const Comparable& el) const {
    BinaryNode<Comparable> *c;
    c = find(el, root);
    if (c == NULL)
        return -1;
    else{
        int count = 0;
        if(c->left == NULL && c->right == NULL) return count;
        else{
            count++;
            if(c->left != NULL) {
                if(c->right != NULL) {
                    count += max(height(c->left->element), height(c->right->element));
                    return count;
                }
                else return count + height(c->left->element);
            }
            else return count + height(c->right->element);
        }
    }
}

// ..............................
// b) E uma arvore AVL?
// TODO
template <class Comparable>
bool BST<Comparable>::isAVL() const {
  iteratorBST<Comparable> it = this->begin();
  int unbalance;
  while(it != this->end()){
      unbalance = balance((*it));
      if(abs(unbalance) > 1) return false;
      it++;
  }
  return true;
}

// ..............................
// c) Rotação a direita
// TODO
template <class Comparable>
void BST<Comparable>::rightRotate(const Comparable& x) {
    BinaryNode<Comparable> *f = find(x, root);
    if(f == NULL || f->left == NULL) return;
    BinaryNode<Comparable> *Y = f->left,
                    *T2 = Y->right;
    Y->right = f;
    f->left = T2;
    BinaryNode<Comparable> *r = root;
    while(true) {
        if (r->left->element == f->element) {
            r->left = Y;
            break;
        }
        else if (r->right->element == f->element) {
            r->right = Y;
            break;
        }
        else {
            if (f->element < r->element)
                r = r->left;
            else r = r->right;
        }
    }
}

#endif
