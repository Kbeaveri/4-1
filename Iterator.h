#pragma once
#include "Node.h"

template<typename T>
class Iterator
{
private:
	Node<T>* currentNode;
public:
	Iterator(Node<T>* node = nullptr) :currentNode(node) {};
	~Iterator()
	{
		if (currentNode != nullptr)
		{
			currentNode = nullptr;
		}
	}
	T& operator*() { return currentNode->value; }
	Iterator& operator++() //���������
	{
		if (currentNode != nullptr)
		{
			currentNode = currentNode->next;
		}
		return *this;
	}
	Iterator& operator--()//���������
	{
		if (currentNode != nullptr)
		{
			currentNode = currentNode->previous;
		}
		return *this;
	}
	//���������
	bool operator==(const Iterator& i) //const
	{
		return currentNode == i.currentNode;
	}
	bool operator!=(const Iterator& i) //const
	{
		return !(*this == i);
	}
	bool operator>(const Iterator& i) //const
	{
		return currentNode > i.currentNode;
	}
	bool operator>=(const Iterator& i) //const
	{
		return currentNode >= i.currentNode;
	}
	bool operator<(const Iterator& i) //const
	{
		return !(*this >= i);
	}
	bool operator<=(const Iterator& i) //const
	{
		return !(*this > i);
	}

	Iterator next_it() //const
	{
		if (currentNode != nullptr)
		{
			return Iterator(currentNode->next);
			return *this;// currentNode = current->next;
		}
	}
};

