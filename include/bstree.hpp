#include <fstream>
#include <iostream>
using namespace std;

namespace BSTree {
	struct Node {
		int var; // то что записываем в дерево
		Node *left, *right;
	};
	class Tree {
	private:
	    Node* insert(int var, Node *&node);
	    void show(Node *node, int x);
	    void show1(Node *node);
		void show2(Node *node);
		void show3(Node *node);
	public:
		Node *root;
		Tree();
		void show(char choice);
		void remove(Node *&node);
		void insert(int var);
		void show();
		void show23(Node *root,ofstream& fout);
		void save_to_file();
		//void show(Node *node,ostream& os, int x);
		//friend auto operator<<(const Tree& tree,ostream& os) -> ostream&;
		~Tree();
	};
}
