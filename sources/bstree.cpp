#include <iostream>
#include "bstree.hpp"
#include <string>
using namespace std;
using namespace BSTree;


Tree::Tree() {
	root = nullptr;
}
Node* Tree::insert(int var, Node *&node) { //Фукция добавления звена в дерево
	if (nullptr == node) { // Если дерева нет, то ложим семечко
		node = new Node{var,nullptr,nullptr}; // память под звено дерева
	}
    else {
	    if (var < node->var) //Если нововведенный элемент var меньше чем элемент var из семечка дерева, уходим влево
		    node->left=insert(var, node->left);
	    if (var> node->var) //Если нововведенный элемент var больше чем элемент var из семечка дерева, уходим вправо
		    node->right=insert(var, node->right);
	}
	return node;
}
void Tree::remove(Node *&node) {
	if (node != nullptr) {
		remove(node->left);  //Рекурсивная функция прохода по левому поддереву
		remove(node->right); //Рекурсивная функция для прохода по правому поддереву
		delete node; //Удаляем конечный элемент дерева
		node = nullptr;
	}
}

void Tree::insert(int var) {
	insert(var, root);
}
void Tree::show(){
   show(root,1);
}
void Tree::show(char a){
	show1(root);
}
void Tree::show(Node *node, int x) { // ф-я вывода

	if (node != nullptr) {
		if (node->right != nullptr)
			show(node->right, x + 1);
		for (int i = 0; i < x; i++) {
			cout << "   ";
		}
		if ((node->var) != (root->var))
			cout << "--";
		cout << node->var << endl;
		if (node->left != nullptr)
			show(node->left, x + 1 );
	}
	else
		cout << "Tree is empty!" << endl;
}
void Tree::show1(Node *node){
    cout<<node->var<<" ";
    if(node->left!=nullptr)
      show1(node->left);
    if(node->right!=nullptr)
      show1(node->right);
}
void Tree::show2(Node *node){
    if(node!=nullptr){
      show2(node->left);
    cout<<node->var<<" ";
      show2(node->right);
      }
      return;
      }
void Tree::show3(Node *node){
    if(node!=nullptr){
      show3(node->left);
      show3(node->right);
    cout<<node->var<<" ";
      }
      }
Tree::~Tree() {
	remove(root);
}
