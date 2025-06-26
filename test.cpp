#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include<iostream>
using namespace std;
int main()
{
	vector<int>  v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(1);
	v1.push_back(3);
	v1.push_back(1);
	vector<int> v2(10, 1);
	vector<int>v3(v1.begin(), v1.end());
	for (size_t i = 0;i < v1.size();i++)
	{
		cout << v1[i] << " ";
	}
	for (auto e : v2)
	{
		cout << e << " ";
	
	}
	vector<int>::iterator it = v3.begin();
	while (it != v3.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	return 0;
}
