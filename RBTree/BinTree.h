#pragma once
#include "BinNode.h"
#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include <queue>

using std::string;

template<typename T>
class BinTree {
public:
	BinNode<T>* root;
	BinTree() :root(nullptr){ }
	~BinTree() { remove(&root); }
	bool empty() { return root == nullptr; }
	void insertAsRoot(T val);
	void insertAsLC(BinNode<T>*, BinNode<T>*);
	void insertAsRC(BinNode<T>*, BinNode<T>*);
	void remove(BinNode<T>**);//删除某一结点
	template<typename VST>
	void inorderTraversal(BinNode<T>* p, VST);//中序遍历
	template<typename VST>
	void levelOrderTraversal(BinNode<T>* p, VST);//层序遍历
	BinNode<T>* search(const T& e);//查找
	//字符串转二叉树
	void sToBinTree(string& s) { std::cout << "只支持int和char格式结点"; }
private:
	void build_tree(std::vector<string>& v);
};

template<typename T>
void BinTree<T>::remove(BinNode<T>** p) {
	if (*p == nullptr) return;
	remove(&((*p)->left));
	remove(&((*p)->right));
	delete *p; 
	*p = nullptr;
}
template<typename T>
BinNode<T>* BinTree<T>::search(const T& e) {
	if (this->empty()) return nullptr;
	std::stack<BinNode<T>*> s;
	BinNode<T>* cur=root;
	while (true) {
		while (cur != nullptr) {
			s.push(cur);
			cur = cur->left;
		}
		if (s.empty()) break;
		cur = s.top();
		if (e == cur->val) return cur;
		s.pop();
		cur = cur->right;
	}
	return nullptr;
}
template<typename T>
void BinTree<T>::insertAsRoot(T val) {
	if (root != nullptr) {
		std::cout << "已有根节点" << std::endl;
		return;
	}
	root = new BinNode<T>(val, nullptr, nullptr, nullptr, BLACK);
}
template<typename T>
void BinTree<T>::insertAsLC(BinNode<T>* p, BinNode<T>* q) {
	if (p == nullptr) {
		std::cout << "父节点为空" << std::endl;
		return;
	}
	if (p->left != nullptr) {
		std::cout << "该位置已被占用" << std::endl;
		return;
	}
	p->left = q;
	q->parent = p;
}
template<typename T>
void BinTree<T>::insertAsRC(BinNode<T>* p, BinNode<T>* q) {
	if (p == nullptr) {
		std::cout << "父节点为空"<<std::endl;
		return;
	}
	if (p->right != nullptr) {
		std::cout << "该位置已被占用" << std::endl;
		return;
	}
	p->right = q;
	q->parent = p;
}
template<typename T> template<typename VST>
void BinTree<T>::inorderTraversal(BinNode<T>* p, VST fo) {
	if (p==nullptr) return;
	std::stack<BinNode<T>*> s;
	BinNode<T>* cur = p;
	while (true) {
		while (cur != nullptr) {
			s.push(cur);
			cur = cur->left;
		}
		if (s.empty()) break;
		cur = s.top();
		fo(cur->val);
		std::cout << ' ';
		s.pop();
		cur = cur->right;
	}
}
template<typename T> template<typename VST>
void BinTree<T>::levelOrderTraversal(BinNode<T>* p,VST fo) {
	if (p == nullptr) return;
	std::queue<BinNode<T>*> q;
	BinNode<T>* cur = p;
	q.push(cur);
	int elemSize = 0, validSize = 1;
	std::cout << '[';
	while (true) {
		for (elemSize = q.size(); elemSize > 0; elemSize--) {
			cur = q.front(); q.pop();
			if(cur==nullptr) std::cout << "null";
			else {
				fo(cur->val);
				validSize--;
				if (cur->left != nullptr) validSize++;
				q.push(cur->left);
				if (cur->right != nullptr) validSize++;
				q.push(cur->right);
			}
			if (validSize == 0) {
				std::cout << "]";
				return;
			}
			else std::cout << ",";
		}
	}
}
void BinTree<int>::build_tree(std::vector<std::string>& v) {
    if (v.empty() || v[0] == "null") return;
	BinNode<int>* _root = new BinNode<int>(stoi(v[0])), * cur;
	root = _root;
    std::queue<BinNode<int>*> q;
    q.push(_root);
    int node_num = 0, idx = 0, N = v.size();
    while (!q.empty() && idx < N - 1) {
        node_num = q.size();
        while ((node_num-- > 0) && (idx < N - 1)) {
            cur = q.front(); q.pop();
            if ((++idx < N) && (v[idx] != "null")) {
                cur->left = new BinNode<int>(stoi(v[idx]));
                q.push(cur->left);
            }
            if ((++idx < N) && (v[idx] != "null")) {
                cur->right = new BinNode<int>(stoi(v[idx]));
                q.push(cur->right);
            }
        }
    }
}

void BinTree<char>::build_tree(std::vector<std::string>& v) {
	if (v.empty() || v[0] == "null") return;
	if (v[0].size() > 1) {
		std::cout << "只支持int和char格式结点";
		return;
	}
	BinNode<char>* cur;
	root = new BinNode<char>(v[0][0]);
	std::queue<BinNode<char>*> q;
	q.push(root);
	int node_num = 0, idx = 0, N = v.size();
	while (!q.empty() && idx < N - 1) {
		node_num = q.size();
		while ((node_num-- > 0) && (idx < N - 1)) {
			cur = q.front(); q.pop();
			if ((++idx < N) && (v[idx] != "null")) {
				if (v[idx].size() > 1) {
					std::cout << "只支持int和char格式结点";
					remove(&root);
					return;
				}
				cur->left = new BinNode<char>(v[idx][0]);
				q.push(cur->left);
			}
			if ((++idx < N) && (v[idx] != "null")) {
				if (v[idx].size() > 1) {
					std::cout << "只支持int和char格式结点";
					remove(&root);
					return;
				}
				cur->right = new BinNode<char>(v[idx][0]);
				q.push(cur->right);
			}
		}
	}
}
//字符串转二叉树 int特化
void BinTree<int>::sToBinTree(string& s) {
	s.assign(s.begin() + 1, s.end() - 1); //去括号
	int cont = 0;
	std::vector<std::string> node_infor;
	for (auto ch = s.begin(); ch != s.end(); ch++) {
		if (*ch != ',') cont++;
		else {
			node_infor.push_back(s.substr(ch - s.begin() - cont, cont));
			cont = 0;
		}
	}//逗号分隔字符串
	if (!s.empty()) {
		node_infor.push_back(s.substr(s.size() - cont, cont));
	}
	root = nullptr;
	build_tree(node_infor);
}
//字符串转二叉树 char特化
void BinTree<char>::sToBinTree(string& s) {
	s.assign(s.begin() + 1, s.end() - 1); //去括号
	int cont = 0;
	std::vector<std::string> node_infor;
	for (auto ch = s.begin(); ch != s.end(); ch++) {
		if (*ch != ',') cont++;
		else {
			node_infor.push_back(s.substr(ch - s.begin() - cont, cont));
			cont = 0;
		}
	}//逗号分隔字符串
	if (!s.empty()) {
		node_infor.push_back(s.substr(s.size() - cont, cont));
	}
	root = nullptr;
	build_tree(node_infor);
}