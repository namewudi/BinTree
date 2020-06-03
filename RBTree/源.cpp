#include<iostream>
#include"BinTree.h"
#include"RedBlack.h"
using namespace std;

template <typename T>
struct print {
	void operator()(T& e) {
		cout << e;
	}
};
int main() {
	/*string s = "[7,6,8,null,null,9,null,0]";
	BinTree<int>* tree=new BinTree<int>;
	tree->sToBinTree(s);
	tree->inorderTraversal(tree->root);*/
	RedBlack<int>* Tree = new RedBlack<int>;
	Tree->insert(2);
	Tree->insert(6);
	Tree->insert(3);
	Tree->insert(4);
	Tree->insert(8);
	Tree->insert(1);
	Tree->insert(18);
	Tree->insert(14);
	Tree->insert(16);
	cout << "Level order: ";
	Tree->levelOrderTraversal(Tree->root,print<int>());
	cout << endl << "Inorder: ";
	Tree->inorderTraversal(Tree->root, print<int>());
	return 0;
}