#pragma once
#include "BinNode.h"
#include "BinTree.h"

template <typename T> 
class RedBlack : public BinTree<T> {
protected:
    BinNode<T>* pre;//search�����н��ĸ����
    //˫������
    void solveDoubleRed(BinNode<T>* x); 
    //˫������
    void solveDoubleBlack(BinNode<T>* x); 
    BinNode<T>* rotateAt(BinNode<T>*);
    BinNode<T>* connect34(BinNode<T>*, BinNode<T>*, BinNode<T>*, BinNode<T>*, BinNode<T>*, BinNode<T>*, BinNode<T>*);
public:
    BinNode<T>* uncle(BinNode<T>*);
    //����
    BinNode<T>* search(const T& val); 
    //����
    BinNode<T>* insert(const T& val); 
    //ɾ��
    bool remove(const T& val); 
    //��ת
    
};

template <typename T>
void RedBlack<T>::solveDoubleRed(BinNode<T>* x) {
    if (x == nullptr || x == this->root) return;
    BinNode<T>* p = x->parent;
    if (p->color == BLACK) return;
    BinNode<T>* g = p->parent; //pΪ��,g�ش���
    BinNode<T>* u = uncle(x);
    if (u == nullptr || u->color == BLACK) {//�常���Ϊ�ڻ��
        if ((p->left == x) == (g->left == p)) //ͬ��
            p->color = BLACK;
        else x->color = BLACK;
        g->color = RED;
        BinNode<T>* gg = g->parent;
        BinNode<T>* r = rotateAt(x);//��ת��ĸ��ڵ�
        if (gg == nullptr) this->root = r;
        else gg->left == g ? gg->left = r : gg->right = r;
    }
    else {//�常���Ϊ��
        if (g != this->root)g->color = RED;
        u->color = BLACK;
        p->color = BLACK;
        solveDoubleRed(g);
    }
}
template <typename T>
void RedBlack<T>::solveDoubleBlack(BinNode<T>* x) {

}
template <typename T>
BinNode<T>* RedBlack<T>::uncle(BinNode<T>* x) {
    BinNode<T>* p = x->parent;
    return p->parent->left == p ? p->parent->right : p->parent->left;
}

template <typename T>
BinNode<T>* RedBlack<T>::search(const T& val) {
    pre = nullptr;
    BinNode<T>* cur = this->root;
    while (cur != nullptr) {
        if (cur->val == val) return cur;
        pre = cur;
        if (cur->val < val) cur = cur->right;
        else cur = cur->left;
    }
    return nullptr;
}
template <typename T>
BinNode<T>* RedBlack<T>::insert(const T& val) {
    if (search(val) != nullptr) return nullptr;//�ҵõ��򷵻ؿ�ָ��
    BinNode<T>* x = new BinNode<T>(val, nullptr, nullptr, pre);
    if (pre != nullptr) val < pre->val ? pre->left = x : pre->right = x;
    solveDoubleRed(x);
    
    return x;

}
template <typename T>
bool RedBlack<T>::remove(const T& val) {

}
template <typename T>
BinNode<T>* RedBlack<T>::rotateAt(BinNode<T>* x) {
    BinNode<T>* p = x->parent;
    BinNode<T>* g = p->parent; 
    if (p == g->left) {
        if (x == p->left) {
            p->parent = g->parent;
            return connect34(x, p, g, x->left, x->right, p->right, g->right);
        }
        else {
            x->parent = g->parent;
            return connect34(p, x, g, p->left, x->left, x->right, g->right);
        }
    }
    else {
        if (x == p->left) {
            x->parent = g->parent;
            return connect34(g, x, p, g->left, x->left, x->right, p->right);
        }
        else {
            p->parent = g->parent;
            return connect34(g, p, x, g->left, p->left, x->left, x->right);
        }
    }
}
template <typename T>
BinNode<T>* RedBlack<T>::connect34(BinNode<T>* x, BinNode<T>* p, BinNode<T>* g, BinNode<T>* t1, BinNode<T>* t2, BinNode<T>* t3, BinNode<T>* t4) {
    p->left = x; x->parent = p;
    p->right = g; g->parent = p;
    x->left = t1; if (t1 != nullptr) t1->parent = x;
    x->right = t2; if (t2 != nullptr) t2->parent = x;
    g->left = t3; if (t3 != nullptr) t3->parent = g;
    g->right = t4; if (t4 != nullptr) t4->parent = g;
    return p;
}
