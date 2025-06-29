#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
#include<assert.h>
using namespace std;
namespace yiming
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{

		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t oldsize = size();
				T* tmp = new T[n];
			//当start不为空时，拷贝旧数据到新空间
				if (_start)
				{
					memcpy(tmp, _start, sizeof(T) * _size());
					delete[]_start;
				}
				_start = tmp;
				_finish = _start + oldsize;
				_endofstorage = _start + n;
			}
		}
		T& operator[](size_t i)
		{
			assert(i < size());
			return  _start[i];
		}
		const T& operator[](size_t i)const
		{
			assert(i < size());
			return _start[i];

		}
		iterator begin()
		{
			return _start;
		}
		const iterator begin()const
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const iterator end()const
		{
			return _finish;
		}

		size_ t size()const
		{
			return _finish - _start;
		}
		size_t capacity()const
		{
			return  _endofstorage - _start;
		}
		void push_back(const T& x)
		{
			if (_finish == _endofstorage)
			{
				reserve(capacity() == 0 ? 4;capacity() * 2);
			}
			*_finish = x;
			++_finish;
		}
		void Print(vector<int>& v);
		
		
		
	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;

	};
}