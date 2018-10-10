#include "List.h"

using namespace ini;

template <class T>
List<T>::List() : top{ nullptr }, end{ nullptr }
{
}

template <class T>
List<T>::~List()
{
	while (top)
	{
		ListNode<T> temp = top->next;
		delete temp;
	}
	top = nullptr;
	end = nullptr;
}
