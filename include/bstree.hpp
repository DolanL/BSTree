#include <fstream>
#include <iostream>
using namespace std;

namespace BSTree {
	struct Node {
		int var; // то что записываем в дерево
		Node *left, *right;
		Node *parent;
	};
	class Tree {
	private:
		Node *root;
	    Node* insert(int var, Node *&node);
	    void show(Node *node, int x);
	    void direct_bypass(Node *node);
		void symmetric_bypass(Node *node);
		void back_bypass(Node *node);
	public:
		Tree();
		void show(char choice);
		void remove(Node *&node);
		void insert(int var);
		void show();
		void show23(Node *root,ofstream& fout);
		void save_to_file();
		void show(Node *node,ostream& os, int x)const;
	    friend auto operator<<(ostream& os,const Tree& tree) -> ostream&;
		~Tree();
	};
}
