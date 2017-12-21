
/*
�������� ����, ������ ��17-16�
������� 6
������������ ������ 4

���� ������������� �������. ���������� �������� �� �������� ������� ������������
������������ ������� ���������.
*/

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <clocale>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
using namespace std;

void menu()
{
	system("cls");
	cout << "1. ���� ��������� �������" << endl << "2. ��������� ������" << endl << "3. ����� ������� � ����������� �� �����" << endl << "4. �����" << endl;
}

int ** enterArray(int *n, int *m, int *b, int *c2, int *y) {
	*b = 0;
	*c2 = 0;
	*y = 1;
	int a;

	system("cls");
	cout << "������� ���������� ����� � �������" << endl;
	cin >> *n;

	while (*n <= 0 || cin.fail())
	{
		system("cls");
		cout << "������ �����. ������� ���������� ���������� �����" << endl;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cin >> *n;
	}

	system("cls");
	cout << "������� ���������� �������� � �������" << endl;
	cin >> *m;

	while (*m <= 0 || cin.fail())
	{
		system("cls");
		cout << "������ �����. ������� ���������� ���������� ��������" << endl;
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cin >> *m;
	}
	if (*n < *m)
		*b = *n;
	else
		*b = *m;

	int ** M = new int*[*n];
	for (int i = 0; i < *n; i++)
	{
		M[i] = new int[*m];
	}

	system("cls");
	cout << "1. ������ �������� ��������� � ����������" << endl << "2. ��������� ������� ���������� ����������" << endl;

	int t = 0;

	while (t == 0)
	{
		cin >> a;

		switch (a)
		{
		case 1:
			t = 1;

			for (int i = 0; i < *n; i++)
				for (int j = 0; j < *m; j++)
				{
					cout << "������� ������� (" << i << "," << j << ")" << endl;
					cin >> M[i][j];

					while (cin.fail())
					{
						system("cls");
						cout << "������ �����. ������� ���������� ��������" << endl;
						cin.clear();
						cin.ignore(cin.rdbuf()->in_avail());
						cin >> M[i][j];
					}
				}
			break;

		case 2:
			t = 1;
			srand(time(NULL));
			for (int i = 0; i < *n; i++)
				for (int j = 0; j < *m; j++)
				{
					M[i][j] = rand();
				}
			break;

		default:
			system("cls");
			cout << "�������� ����� ����" << endl << "1. ������ �������� ��������� � ����������" << endl << "2. ��������� ������� ���������� ����������" << endl;
			break;
		}
	}
	return M;
}

int obrData(int *y, int b, int ** M) {
	system("cls");
	{
		for (int i = 0; i < b; i++)
			for (int j = 0; j < b; j++)
			{
				if (M[i][j] != M[j][i])
					*y = 0;
			}
		cout << "������ ����������" << endl;
		system("pause");
	}
	return 1;

}

void showArray(int y, int n, int m, int ** M) {
	system("cls");
	for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cout << M[i][j] << "      ";
			}
			cout << endl;
		}
		cout << endl << endl << "������� ";
		if (y == 0)
			cout << "�� ";
		cout << "����������� ������������ ������� ���������." << endl;
		system("pause");
	}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int i, j, n, m, p, t, y, e, a, C, c2, b;
	int **M = NULL;

	y = 1;
	C = 0;
	i = 0;
	j = 0;
	c2 = 0;

	do
	{
		menu();
		cin >> p;

		switch (p)
		{
		case 1:
			M = enterArray(&n, &m, &b, &c2, &y);
			break;
		case 2:
			if (M == NULL)
			{
				cout << "�� �� ����� �������� ��������� �������" << endl;
				system("pause");
			}
			else {
				c2 = obrData(&y, b, M);
			}
			break;
		case 3:
			if (M == NULL || c2 == 0)
			{
				cout << "������ �� ����������" << endl;
				system("pause");
			}
			else {
				showArray(y, n, m, M);
			}
			break;

		case 4:
			C = 1;
			break;

		default:
			cout << "�������� ����� ����" << endl;
			system("pause");
			break;
		}
	} while (C == 0);

	if (M != NULL)
	{
		for (i = 0; i < n; i++)
			delete[] M[i];
		delete[] M;
	}

	return 0;
}
