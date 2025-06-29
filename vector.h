#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<iostream>
namespace yiming
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{

		}
		void reverse(size_t n)
		{
			if (n > _capacity())
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

		size_ t size()const
		{
			return _finsh - _start;
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
			*_finsh = x;
			++_finish;
		}
		
		
	private:
		iterator _start;
		iterator _finsh;
		iterator _endofstorage;

	};
}