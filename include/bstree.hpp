#include <iostream>
using namespace std;

namespace BSTree {
	struct Node {
		int var;
		Node *left, *right;
	};
	class Tree {

	public:
	    Node *root;
		Tree();
		Node* add_node(int var, Node *&MyTree);
		void del(Node *&MyTree);
		void Insert(Tree *&tree,int var);
		void Show_Tree(Node *MyTree, int x);
		~Tree();
	};

}
