#pragma once
#include "BinNode.h"

template <typename T> 
class RedBlack {
protected:
    void solveDoubleRed(BinNode<T> x); //双红修正
    void solveDoubleBlack(BinNode<T> x); //双黑修正
    int updateHeight(BinNode<T> x); //更新节点x的高度
public:
    BinNode<T> insert(const T& e); //插入
    bool remove(const T& e); //删除
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
