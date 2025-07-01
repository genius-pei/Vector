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
		//Print(a);(a);
		//int x;
		//cin >> x;
		//auto it = find(a.begin(), a.end(),x);
		//if (it != a.end())
		//{
		a.push_back(4);
		a.push_back(5);
		a.push_back(6);
		int x;
		cin >> x;
		auto it = find(a.begin(), a.end(),x);
		if (it != a.end())
		{
			a.erase(it);//it失效，是否报错取决于不同平台对迭代器失效的检查
			++it;
		}
		Print(a);

	}
	int main()
	{
		test01();
		return 0;
	}