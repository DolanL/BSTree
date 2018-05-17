#include <fstream>
#include "bstree.hpp"
#include <string>
#include <iostream>
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
void Tree::show(char choice){
	switch(choice)
	{
		case 'a':direct_bypass(root);
		cout<<endl;
		break;
		case 'b':symmetric_bypass(root);
		cout<<endl;
		break;
		case 'c':back_bypass(root);
		cout<<endl;
		break;
	}
}
void Tree::show(Node *node, int x) {

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
void Tree::show(Node *node,ostream& os, int x) const{
		if (node->right != nullptr)
			show(node->right,os, x + 1);
		for (int i = 0; i < x; i++) {
			os << "   ";
		}
		if ((node->var) != (root->var))
			os << "--";
		os << node->var << endl;
		if (node->left != nullptr)
			show(node->left,os , x + 1 );
}
void Tree::direct_bypass(Node *node){
    cout<<node->var<<" ";
    if(node->left!=nullptr)
      direct_bypass(node->left);
    if(node->right!=nullptr)
      direct_bypass(node->right);
}
void Tree::symmetric_bypass(Node *node){
    if(node!=nullptr){
      symmetric_bypass(node->left);
    cout<<node->var<<" ";
      symmetric_bypass(node->right);
      }
      return;
      }
void Tree::back_bypass(Node *node){
    if(node!=nullptr){
      back_bypass(node->left);
      back_bypass(node->right);
    cout<<node->var<<" ";
      }
 }
void Tree::show23(Node* root, ofstream &fout) {
	if (root != nullptr) {
		fout << root->var << " ";
		show23(root->right,fout);
		show23(root->left,fout);
	}
}
void Tree::save_to_file()
{
    string filename;
    cout << "enter name of file" << endl;
    cin >> filename;
    ofstream fout(filename.c_str());
    show23(root, fout);
}
namespace BSTree{
	auto operator<<(ostream& os,const Tree& tree) -> ostream&{
		tree.show(tree.root,os,1);
		return os;
	}
}
Tree::~Tree() {
	remove(root);
}
