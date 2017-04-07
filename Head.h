
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
			double fakt = 1.2473309;
			int step = size - 1;
			int x;
			while (step > 1)
			for (int i = 0; i + step < size; ++i)
			{
				K++;
				if (arr[i]>arr[i + step])
				{
					swap(arr[i], arr[i + step]);
					N++;
				}
				step /= fakt;
			}
			cout << "Отсортированный массив: ";
			for (int k = 0; k < size; ++k)
			{
				cout << arr[k] << " ";
			}
			cout << endl;
			cout << "\tКоличества сравнений: " << K << endl;
			cout << "\tКоличество перестановок: " << N << endl;
			cout << endl;
			delete[] arr;
		}
	private:
		int N; // Количество перестановок
		int K; //Количество сравнений
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
				swap(arr[i], arr[min]);
				N++;
			};

			cout << "Отсортированный массив: ";
			for (int k = 0; k < size; ++k)
			{
				cout << arr[k] << " ";
			}
			cout << endl;
			cout << "\tКоличества сравнений: " << K << endl;
			cout << "\tКоличество перестановок: " << N << endl;
			cout << endl;
			delete[] arr;
		}
	private:
		int N; // Количество перестановок
		int K; //Количество сравнений
		int* arr;
	};
	class Merge : public Sort
	{
	public:
		Merge() : arr(0), N(0), K(0)
		{
		}
		virtual void sort(int arr[], int size)
		{	
			int mid = size / 2;
			if (size % 2 == 1)
				mid++;
			int h = 1;
			int *c = new int[size] ;
			int step;
			while (h < size)
			{
				step = h;
				int i = 0;
				int j = mid;
				int k = 0;
				while (step <= mid)
				{
					while ((i < step) && (j < size) && (j < (mid + step)))
					{
						if (arr[i] < arr[j])
						{
							c[k] = arr[i];
							i++; k++; N++;
						}
						else {
							c[k] = arr[j];
							j++; k++; N++;
						}
					}
					while (i < step)
					{
						c[k] = arr[i];
						i++; k++; N++;
					}
					while ((j < (mid + step)) && (j<size))
					{ 
						c[k] = arr[j];
						j++; k++; N++;
					}
					step = step + h;
					K++;
				}
				h = h * 2;
				for (i = 0; i <size; i++)
					arr[i] = c[i];
			}
			cout << "Отсортированный массив: ";
			for (int k = 0; k < size; k++)
			{
				cout << arr[k] << " ";
			}
			cout << endl;
			cout << "\tКоличества сравнений: " << K << endl;
			cout << "\tКоличество перестановок: " << N << endl;
			cout << endl;
			delete[] arr;
			delete[] c;
		}
	private:
		int N; // Количество перестановок
		int K; //Количество сравнений
		int* arr;
	};
