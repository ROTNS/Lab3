
#include <iostream>
using namespace std;
{
	class Sort 
	{
	public:
		virtual void sort()
		{};
	}
	class merge : public Sort
	{
	public:
		merge()
		{
		};
		virtual void sort(){};
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
		}
	private:
		int N;
		int K;
		int* arr;
	};
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
		int N;
		int K;
		int* arr;
	};