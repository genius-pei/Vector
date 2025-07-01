#define _CRT_SECURE_NO_WARNINGS
#include"vector.h"
template<class Container>
void Print(const Container& con)
{
	for (auto e : con)
	{
		cout << e << " ";

	}
	cout << endl;
}

	void test01()
	{
		yiming::vector<int> a;
		a.insert(a.begin(), 0);
		a.push_back(1);
		a.push_back(2);
		a.push_back(3);
		Print(a);
		a.pop_back();
		Print(a);
		//int x;
		//cin >> x;
		//auto it = find(a.begin(), a.end(),x);
		//if (it != a.end())
		//{
		//	a.insert(it, 10);
		//	//如果扩容会导致it失效，失效后不要使用it
		//}
		//Print(a);
		a.push_back(4);
		a.push_back(5);
		a.push_back(6);
		int x;
		cin >> x;
		auto it = find(a.begin(), a.end(),x);
		if (it != a.end())
		{
			a.erase(it);//it因为不涉及扩容，后面可以修改it
		}
		Print(a);

	}
	int main()
	{
		test01();
		return 0;
	}