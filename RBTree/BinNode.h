#pragma once

using RBcolor=enum{ RED, BLACK };
template<typename T>
struct BinNode {
	T val;
	BinNode<T>* left,*right,*parent;
	RBcolor color;
	BinNode<T>():left(nullptr),right(nullptr),parent(nullptr),color(RED){ }
	BinNode<T>(T data, BinNode<T>* l = nullptr, BinNode<T>* r = nullptr, BinNode<T>* p = nullptr,
		RBcolor c = RED) :val(data), left(l), right(r), parent(p), color(c) { }
};