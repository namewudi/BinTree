#pragma once
#include "BinNode.h"

template <typename T> 
class RedBlack {
protected:
    void solveDoubleRed(BinNode<T> x); //˫������
    void solveDoubleBlack(BinNode<T> x); //˫������
    int updateHeight(BinNode<T> x); //���½ڵ�x�ĸ߶�
public:
    BinNode<T> insert(const T& e); //����
    bool remove(const T& e); //ɾ��
};

template <typename T>
void RedBlack<T>::solveDoubleRed(BinNode<T> x) {

}
template <typename T>
void RedBlack<T>::solveDoubleBlack(BinNode<T> x) {

}
template <typename T>
int RedBlack<T>::updateHeight(BinNode<T> x) {

}
template <typename T>
