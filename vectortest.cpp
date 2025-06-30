#define _CRT_SECURE_NO_WARNINGS
#include"vector.h"

	void test01()
	{
		yiming::vector<int> a;
		a.push_back(1);
		a.push_back(2);
		a.push_back(3);
		Print(a);
	}
	int main()
	{
		test01();
		return 0;
	}