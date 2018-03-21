#include <iostream>
using namespace std;

namespace BSTree {
	struct Node {
		int var; 
		Node *left,*right; 
	};
	class Tree {
			Node *root;

		public:
			Tree();
			void add_node(int var,Node *&MyTree);
			void insert(int var);
			void del(Node *&MyTree);
			void Show_Tree(Node *MyTree, int x);
			~Tree();
	};

}
