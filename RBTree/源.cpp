#include<iostream>
#include"BinTree.h"
using namespace std;

int main() {
	string s = "[7,6,8,null,null,9,null,0]";
	BinTree<int>* tree=new BinTree<int>;
	tree->sToBinTree(s);
	BinNode<int>* p = new BinNode<int>(5);
	tree->insertAsLC(tree->root->left,p);
	tree->inorderTraversal(tree->root);

	return 0;
}