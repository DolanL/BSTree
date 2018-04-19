#include <iostream>
using namespace std;

namespace BSTree {
	struct Node {
		int var; // то что записываем в дерево
		Node *left, *right;
	};
	class Tree {
	private:
    Node *root;
    Node* insert(int var, Node *&node);
    void show(Node *node, int x);
    void show1(Node *node);
	void show2(Node *node);
	void show3(Node *node);
	public:
		Tree();
		void show(char a);
		void remove(Node *&node);
		void insert(int var);
		void show();
		~Tree();
	};

}
