
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
		Comb() : arr(0), N(0), K(0), time(0)
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
	};
	class Selection : public Sort
	{
	public:
		Selection()
		{
		};
		virtual void sort()
		{
		}
	};
