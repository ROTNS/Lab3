
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
		Comb()
		{};
		virtual void sort(){};
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
}