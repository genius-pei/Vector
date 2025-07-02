#define _CRT_SECURE_NO_WARNINGS

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
		vector(const vector<T>& x)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			reserve(x.capacity());
			for (auto& e : x)
			{
				push_back(e);
			}
		}
		~vector() {
			if (_start) {
				delete[] _start;
				_start = _finish = _endofstorage = nullptr;
			}
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
					memcpy(tmp, _start, sizeof(T) * size());
					delete[]_start;
				}
				_start = tmp;
				_finish = _start + oldsize;
				_endofstorage = _start + n;
			}
		}
		void resize(size_t n,T val=T())//模版如何给缺省值？使用匿名对象，其缺省值就是T类型的默认构造的值
		{
			if (n > size())//插入
			{
				reserve(n);
				while (_finish != _start + n)
				{
					*_finish = val;
					_finish++;
				}
			}
			else//删除数据
			{
				_finish = _start + n;
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
		void clear()
		{
			_finish = _start;
		}
		iterator begin()
		{
			return _start;
		}
		const_iterator begin()const
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator end()const
		{
			return _finish;
		}

		size_t size()const
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
				reserve(capacity() == 0 ? 4:capacity() * 2);
			}
			*_finish = x;
			++_finish;
		}
		void pop_back()
		{
			assert(_finish > _start);
			_finish--;
		}
		void insert(iterator pos, const T& x) 
		{
			assert(pos >= _start && pos <= _finish);

			size_t offset = pos - _start; // 1.保存偏移量，防止异地扩容导致问题

			if (_finish == _endofstorage) {
				size_t new_cap = capacity() ? capacity() * 2 : 4;
				reserve(new_cap);
				pos = _start + offset; // 2.重新计算pos
			}

			iterator new_pos = _start + offset;
			iterator end = _finish;

			// 3.正确移动元素（后->前）
			for (; end > new_pos; --end) {
				*end = *(end - 1); // 移动语义提升性能
			}

			*new_pos = x; // 4.插入元素
			++_finish;
		}
		void erase(iterator pos)
		{
			assert(pos >= _start && pos <= _finish);
			iterator it = pos + 1;
			while (it != _finish)
			{
				*(it - 1) = *it;
				it++;
			}
			_finish--;
		}

		
		
		
	private:
		iterator _start=nullptr;
		iterator _finish=nullptr;
		iterator _endofstorage=nullptr;

	};
	void Print(vector<int>& x);
}