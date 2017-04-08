#include <iostream>
#include <string>
#include <time.h>
#include "Head.h"
#include <fstream>
#include <conio.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Rus");
		Comb el1;
		Selection el2;
		Merge el3;
		Sort *pr1 = &el1;
		Sort *pr2 = &el2;
		Sort *pr3 = &el3;
		Comb bestComb;
		Selection bestSel;
		Merge bestMerge;
		Comb worstComb;
		Selection worstSel;
		Merge worstMerge;
		Sort* bComb = &bestComb;
		Sort* bSel = &bestSel;
		Sort* bMerge = &bestMerge;
		Sort* wComb = &worstComb;
		Sort* wSel = &worstSel;
		Sort* wMerge = &worstMerge;
		srand((unsigned)time(NULL));
		int size, n;
		cout << "������� ������ �������: ";
		if (!(cin >> size) || size == 0)
		{
			throw string("������������ ������!");
		}
		cout << "������� �������� ��������: ";
		if (!(cin >> n) || n == 0)
		{
			throw string("������������ ��������!");
		}
		int *arr1 = new int[size];
		int *arr2 = new int[size];
		int *arr3 = new int[size];
		int* best1 = new int[size];
		int* best2 = new int[size];
		int* best3 = new int[size];
		int* worst1 = new int[size];
		int* worst2 = new int[size];
		int* worst3 = new int[size];
		cout << "�������� ������: ";
		for (int i = 0; i < size; ++i)
		{
			arr1[i] = 1 + rand() % n;
			arr2[i] = arr1[i];
			arr3[i] = arr1[i];
			cout << arr1[i] << " ";
		}
		cout << endl;
		cout << endl;
		cout << "���������� ���������:" << endl;
		pr1->sort(arr1, size);
		cout << endl;
		cout << "���������� �������:" << endl;
		pr2->sort(arr2, size);
		cout << "���������� ��������: " << endl;
		pr3->sort(arr3, size);
		cout << "�������� " << endl;
		cout << endl;
		cout << "������ �������: ";
		for (int i = 0; i < size; i++)
		{
			best1[i] = i;
			best2[i] = best1[i];
			best3[i] = best1[i];
			cout << best1[i] << " ";
		}
		cout << endl;
		cout << "������ �������: ";
		for (int i = 0; i < size; i++)
		{
			worst1[i] = (size - 1) - i;
			worst2[i] = worst1[i];
			worst3[i] = worst1[i];
			cout << worst1[i] << " ";
		}
		cout << endl;
		cout << endl;
		cout << "���������� ���������: " << endl;
		cout << "(������ �������) " << endl;
		bComb->sort(best1, size);
		cout << "(������ �������) " << endl;
		wComb->sort(worst1, size);
		cout << "���������� �������: " << endl;
		cout << "(������ �������) " << endl;
		bSel->sort(best2, size);
		cout << "(������ �������) " << endl;
		wSel->sort(worst2, size);
		cout << "���������� ��������: " << endl;
		cout << "(������ �������) " << endl;
		bMerge->sort(best3, size);
		cout << "(������ �������) " << endl;
		wMerge->sort(worst3, size);
	return 0;
}