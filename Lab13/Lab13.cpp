#include <iostream>
#include <math.h>
#include <locale.h>
#include <iomanip>
#include <windows.h>
#include <fstream>
#include <string>
#include <conio.h>
#include <vector>
#define s_z 30

using namespace std;

class graph_1
{
public:
	vector<int> list;
	int num;

	graph_1()
	{
		num = 0;
	}
	graph_1(graph_1& w)
	{
		num = w.num;
		for (int i = 0; i < list.size(); i++)
		{
			list[i] = w.list[i];
		}
	}
	graph_1(int n)
	{
		num = n;
	}
protected:
};

class graph : public graph_1
{
public:
	int size;
	void showlist()
	{
		for (int i = 0; i < list.size(); i++)
		{
			cout << list[i];
		}
	}
	void addinlist(graph_1& w)
	{
		w.list.push_back(num);
		list.push_back(w.num);
	}
protected:
};

void create_gragh(graph* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i].num = i + 1;
	}
}

int deletelement(graph* w, int n)
{
	int m = 0;

	cout << "Введіть елемент, який хочете видалити: ";

	cin >> m;

	for (int i = m - 1; i < n; ++i)
	{
		w[i] = w[i + 1];
	}
	return n - 1;
}

int addelement(graph* w, int n) 
{
	cout << "Укажіть, який елемент необхідно додати: ";
	int t = 0;
	cin >> t;
	w[n].num = t;

	int a;

note_1:cout << "Укажіть, до яких елементів потрібно додати новий: ";

	cin >> a;
	if (a == 0)
	{
		goto note_2;
	}
	w[n].addinlist(w[a - 1]);
	cout << endl;
	goto note_1;

note_2:return n ;
}

void show(graph* w, int n)
{
	if (w[0].num == 0)
	{
		cout << "Спочатку створіть граф!" << endl;
		goto note;
	}
	for (int i = 0; i < n; i++)
	{
		cout << w[i].num << " ";
		w[i].showlist();
		cout << endl;
	}
note:;
}

void menu()
{
	cout << "1. Створити граф." << endl;
	cout << "2. Вивести граф." << endl;
	cout << "3. Видалення із графу елемента." << endl;
	cout << "4. Включення до графу елемента." << endl;
	cout << "5. Очистити граф." << endl;
	cout << "6. Вийти з програми." << endl;
	cout << "Оберіть бажану функцію: ";
}

void main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	graph elem[s_z];
	int n = 0, x = 0;

menu:menu();

	cin >> x;
	cout << endl;
	switch (x)
	{
	default:
		cout << "Помилка! Укажіть існуючий пункт!" << endl;
		goto menu;
	case 1:
		system("cls");
		cout << "Введіть розмір графа: ";
		cin >> n;
		create_gragh(elem, n);
		cout << endl;
		goto menu;
	case 2:
		system("cls");
		show(elem, n);
		cout << endl;
		goto menu;
	case 3:
		system("cls");
		n = deletelement(elem, n);
		cout << endl;
		goto menu;
	case 4:
		system("cls");
		n = addelement(elem, n);
		cout << endl;
		goto menu;
	case 5:
		elem[0].num = 0;
		goto menu;
	case 6:
		cout << "Ви вийшли з програми. " << endl;
		break;
	}
}