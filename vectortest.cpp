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
	void test02()
	{
		yiming::vector<char> a;
		a.resize(10,'x');
		Print(a);
		a.resize(5,10);
		Print(a);
	}
	void test03()
	{
		yiming::vector<int> a1;
		a1.resize(5, 1);
		Print(a1);
		yiming::vector<int> a2(a1);
	
		Print(a2);

	}
	void test04()
	{
		yiming::vector<int> a = { 1,2,3 };
		Print(a);
		yiming::vector<int> b(a.begin(), a.end());
		string s1("hello world");
		yiming::vector<char> c(s1.begin(), s1.end());
		Print(b);
		Print(c);
		yiming::vector<int> d(10, 1);
		Print(d);


	}
	
	int main()
	{
		//test01();
		//test02();
		//test03();
		test04();
		return 0;
	}