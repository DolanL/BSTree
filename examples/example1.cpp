#include <iostream>
#include "BSTree.hpp"
#include <string>
using namespace std;
using namespace BSTree;


int showmenu(Tree *&tree)
{
	cout << "Выберите одну из операций:" << endl
		<< "1. Вывести дерево на экран" << endl
		<< "2. Вывести список узлов дерева" << endl
		<< "3. Добавить узел в дерево" << endl
		<< "4. Удалить узел из дерева" << endl
		<< "5. Сохранить дерево в файл" << endl
		<< "6. Загрузить дерево из файла" << endl
		<< "7. Проверить наличие узла" << endl
		<< "8. Завершить работу программы" << endl;
	int choise;
	string answer;
	while (answer != "y" && answer != "Y" )
	{
		cin >> choise;
		switch (choise)
		{
		case 1:
			tree->Show_Tree(tree->root,1);
			break;

		case 8:
			cout << "Вы уверены?(yes/no)" << endl;
			cin >> answer;
			if ((answer == "y") && (answer == "yes") && (answer == "Y") && (answer == "Yes") &&
				(answer == "YES"))
				cout << "До свидания!" << endl;
			return 0;
		default:
			cerr << "Ошибка!" << endl;
		}
	}
}
int main(int argc, char *argv[]) {
	Tree *tree = new Tree;
	for (int i = 1; i < argc; i++)
		tree->Insert(tree,atoi(argv[i]));
	showmenu(tree);
	delete tree;
	return 0;
}

