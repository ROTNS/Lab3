#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>
using namespace std;
	class Sort
	{
	public:
		virtual void sort(int arr[], int size) = 0;
	};
	class Comb : public Sort
	{
	public:
		Comb() : arr(0), N(0), K(0)
		{
		}
		virtual void sort(int arr[], int size)
		{
			int k;
			int step = size;
			int siz = size;
			while (step > 1)
			{
				step /= 1.247f;
				if (step < 1)
					step = 1;
				k = 0;
				for (int i = 0; i + step < siz; ++i)
				{
					if (arr[i]>arr[i + step])
					{
						swap(arr[i], arr[i + step]);
						k = i;
						N++;
					}
					K++;
				}
				if (step == 1)
					siz = k + 1;
			}
			cout << "Готовый массив: ";
			for (int k = 0; k < size; ++k)
			{
				cout << arr[k] << " ";
			}
			cout << endl;
			cout << "Количество сравнений: " << K << endl;
			cout << "Количество перестановок: " << N << endl;
			cout << endl;
			delete[] arr;
		}
	private:
		int N;
		int K;
		int* arr;
	};
	class Selection : public Sort
	{
	public:
		Selection() : arr(0), N(0), K(0)
		{
		}
		virtual void sort(int arr[], int size)
		{
			for (int i = 0; i < size - 1; i++)
			{
				int min = i;
				for (int j = i + 1; j < size; j++)
				{
					K++;
					if (arr[j] < arr[min])
					{
						min = j;
					}
				}
				if (arr[i] != arr[min])
				{
					swap(arr[i], arr[min]);
					N++;
				}
			};

			cout << "Готовый массив: ";
			for (int k = 0; k < size; ++k)
			{
				cout << arr[k] << " ";
			}
			cout << endl;
			cout << "Количество сравнений: " << K << endl;
			cout << "Количество перестановок: " << N << endl;
			cout << endl;
			delete[] arr;
		}
	private:
		int N;
		int K;
		int* arr;
	};
	class Merge : public Sort
	{
	public:
		Merge() : arr(0), N(0), K(0), score()
		{
		}
		virtual void sort(int arr[], int size)
		{
			size_t BlockSizeIterator;
			size_t BlockIterator;
			size_t LeftBlockIterator;
			size_t RightBlockIterator;
			size_t MergeIterator;
			size_t LeftBorder;
			size_t MidBorder;
			size_t RightBorder;
			for (BlockSizeIterator = 1; BlockSizeIterator < size; BlockSizeIterator *= 2)
			{
				K++;
				for (BlockIterator = 0; BlockIterator < size - BlockSizeIterator; BlockIterator += 2 * BlockSizeIterator)
				{
					K++;
					LeftBlockIterator = 0;
					RightBlockIterator = 0;
					LeftBorder = BlockIterator;
					MidBorder = BlockIterator + BlockSizeIterator;
					RightBorder = BlockIterator + 2 * BlockSizeIterator;
					RightBorder = (RightBorder < size) ? RightBorder : size;
					int* SortedBlock = new int[RightBorder - LeftBorder];
					while (LeftBorder + LeftBlockIterator < MidBorder && MidBorder + RightBlockIterator < RightBorder)
					{
						K++;
						if (arr[LeftBorder + LeftBlockIterator] < arr[MidBorder + RightBlockIterator])
						{
							K++;
							N++;
							SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[LeftBorder + LeftBlockIterator];
							LeftBlockIterator++;
						}
						else
						{	
							K++;
							N++;
							SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[MidBorder + RightBlockIterator];
							RightBlockIterator++;
						}
					}
					while (LeftBorder + LeftBlockIterator < MidBorder)
					{
						N++;
						K++;
						SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[LeftBorder + LeftBlockIterator];
						LeftBlockIterator++;
					}
					while (MidBorder + RightBlockIterator < RightBorder)
					{
						N++;
						K++;
						SortedBlock[LeftBlockIterator + RightBlockIterator] = arr[MidBorder + RightBlockIterator];
						RightBlockIterator++;
					}
					for (MergeIterator = 0; MergeIterator < LeftBlockIterator + RightBlockIterator; MergeIterator++)
					{
						arr[LeftBorder + MergeIterator] = SortedBlock[MergeIterator];
					}
					delete SortedBlock;
				}
			}
			cout << "Готовый массив: ";
			for (int k = 0; k < size; k++)
			{
				cout << arr[k] << " ";
			}
			cout << endl;
			cout << "Количествo сравнений: " << K << endl;
			cout << "Количество перестановок: " << N << endl;
			cout << endl;

		}
	private:
		int N;
		int K;
		int* arr;
		int score;
	};
