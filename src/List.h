#pragma once

#include "dllutil.h"

namespace ini
{
	template<class T>
	class ListNode
	{
	public:
		T value;
		ListNode<T> next;
	};

	template <class T>
	class EXPORT_INI List
	{
	public:
		List();
		~List();

		void add(T value);
		T get(int index);
		int size();
		bool remove(T value);
		bool remove(int index);

	private:
		T* top;
		T* end;
	};
}
