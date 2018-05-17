#include <iostream>
#include "bstree.hpp"
#include <string>
#include <fstream>

using namespace std;
using namespace BSTree;


int showmenu(Tree &tree)
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
	char a;
	char b;
	char c;
	int value;
	while (answer != "y" && answer != "Y" )
	{
		cin >> choise;
		switch (choise)
		{
		case 1:
			cout<<tree<<endl;
			break;
        case 2:
            cin>>a;
            tree.show(a);
            cin>>b;
            tree.show(b);
            cin>>c;
            tree.show(c);
            break;
            case 3:
            cin>>value;
            tree.insert(value);
            break;
            case 4:
            break;
            case 5:
            	tree.save_to_file();
            break;
            case 6:
            break;
            case 7:
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
	Tree tree;
	for (int i = 1; i < argc; i++)
		tree.insert(atoi(argv[i]));
	showmenu(tree);
	return 0;
}
