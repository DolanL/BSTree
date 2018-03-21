#include <iostream>
#include "BSTree.hpp"
using namespace std;
using namespace BSTree;
Tree::Tree() {
	root = nullptr;
}
void Tree::add_node(int var,Node *&MyTree) { //Фукция добавления звена в дерево
	if (nullptr==MyTree) {
		MyTree=new Node;
		MyTree->var=var;
		MyTree->left=MyTree->right=nullptr;
	}
	if (var<MyTree->var) {
		if (MyTree->left!=nullptr) add_node(var,MyTree->left);
		else {
			MyTree->left=new Node;
			MyTree->left->left=MyTree->left->right=nullptr;
			MyTree->left->var=var;
		}
	}
	if (var>MyTree->var) {
		if (MyTree->right!=nullptr) add_node(var,MyTree->right);
		else {
			MyTree->right=new Node;  //Выделяем память правому подзвену
			MyTree->right->left=MyTree->right->right=nullptr;
			MyTree->right->var=var;
		}
	}
}
void Tree::del(Node *&MyTree) {
	if (MyTree!=nullptr) {
		del(MyTree->left);  //Рекурсивная функция прохода по левому поддереву
		del(MyTree->right); //Рекурсивная функция для прохода по правому поддереву
		delete MyTree; //Удаляем конечный элемент дерева
		MyTree = nullptr;
	}
}

void Tree::Insert (int var) {
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
	} else
		cout << "Tree is empty!" << endl;
}
Tree::~Tree() {
	del(root);
}

