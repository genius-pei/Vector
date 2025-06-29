#define _CRT_SECURE_NO_WARNINGS
//#include"vector.h"
#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;
//
//namespace yiming
//{
//	void test01()
//	{
//		vector<int> v;
//		
//	}
//}
int main()
{

	string a = "hello world";

	string b = a;

	if (a.c_str() == b.c_str())

	{

		cout << "true" << endl;

	}

	else cout << "false" << endl;

	string c = b;

	c = "";

	if (a.c_str() == b.c_str())

	{

		cout << "true" << endl;

	}

	else cout << "false" << endl;

	a = "";

	if (a.c_str() == b.c_str())

	{

		cout << "true" << endl;

	}

	else cout << "false" << endl;

	return 0;

}