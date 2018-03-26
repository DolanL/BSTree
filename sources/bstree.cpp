#include <iostream>
#include "BSTree.hpp"
#include <string>
using namespace std;
using namespace BSTree;


Tree::Tree() {
	root = nullptr;
}
Node* Tree::add_node(int var, Node *&MyTree) { //Фукция добавления звена в дерево
	if (nullptr == MyTree) {
		MyTree = new Node{var,nullptr,nullptr};
	}
	else{
	if (var < MyTree->var)
		MyTree->left=add_node(var, MyTree->left);
	if (var>MyTree->var)
		MyTree->right=add_node(var, MyTree->right);
	}
	return MyTree;
}
void Tree::del(Node *&MyTree) {
	if (MyTree != nullptr) {
		del(MyTree->left);  //Рекурсивная функция прохода по левому поддереву
		del(MyTree->right); //Рекурсивная функция для прохода по правому поддереву
		delete MyTree; //Удаляем конечный элемент дерева
		MyTree = nullptr;
	}
}

void Tree::Insert(Tree *&tree,int var) {
	add_node(var, root);
}
void Tree::Show_Tree(Node *MyTree, int x) {

	if (MyTree != nullptr) {
		if (MyTree->right != nullptr)
			Show_Tree(MyTree->right, x + 1);
		for (int i = 0; i < x; i++) {
			cout << "   ";
		}
		if ((MyTree->var) != (root->var))
			cout << "--";
		cout << MyTree->var << endl;
		if (MyTree->left != nullptr)
			Show_Tree(MyTree->left, x + 1);
	}
	else
		cout << "Tree is empty!" << endl;
}
Tree::~Tree() {
	del(root);
}

