#pragma once
#include <iostream>
#include "Node.h"
#include "Iterator.h"

using namespace std;
template<class T>
class List
{
private:
	Node<T>* first;
	Node<T>* last;
public:
	List()
	{
		first = nullptr;
		last = nullptr;
	};
	~List()
	{
		if (first == nullptr)
			return;
		if (last == nullptr)
		{
			delete first;
			return;
		}
		while (last->previous != nullptr)//last->previous = *last.previous, пока у нас предпоследний != ничего
		{
			Node<T>* remove = last->previous;//выдел€ем динамическую €чейку пам€ти на указатель, remove=предпоследн€€ €чейка
			last->previous = remove->previous; //предпоследн€€ €чейка = предпредпоследн€€ , а предпоследнюю удал€ем
			//пример 1 2 3, в итоге будет 1 3
			delete remove;
		}
		delete last;

	};
	void push_back(const T& value)
	{
		if (first == nullptr)
		{
			Node<T>* newNode = new Node<T>(value);
			first = newNode;
		}
		if (last == nullptr)
		{
			Node<T>* newNode = new Node<T>(value);
			last = newNode;
			first->next = last;
			last->previous = first;
			return;
		}
		Node<T>* currentLast = last;
		Node<T>* newNode = new Node<T>(value, nullptr, currentLast);
		currentLast->next = newNode;
		last = newNode;
		return;
	}
	void pop_back()
	{
		if (first == nullptr)
		{
			return;
		}
		if (last == nullptr)
		{
			delete first;
			return;
		}
		Node<T>* newLast = last->previous;
		newLast->next = nullptr;
		delete last;
		last = newLast;
		return;
	}
	Iterator<T> begin() const {
		return Iterator<T>(first);
	}
	Iterator<T> end() const {
		return Iterator<T>(last);
	}
	void insert(Iterator<T> i, const T& value)
	{
		if (first == nullptr)
		{
			push_back(value);
		}
		Node<T>* node = first;
		while (node->next != nullptr)
		{
			if (i == Iterator<T>(node))
			{
				Node<T>* newNode = new Node<T>(value, node, node->previous);
				auto prevNode = node->previous;
				node->previous = newNode;
				if (prevNode != nullptr)
				{
					prevNode->next = newNode;
				}
				else
					first = newNode;

				return;
			}
			node = node->next;
		}
	}

	void push_sort(const T& value)
	{
		if (first == nullptr)
		{
			Node<T>* newNode = new Node<T>(value);
			first = newNode;
		}
		if (last == nullptr)
		{
			Node<T>* newNode = new Node<T>(value);
			last = newNode;
			first->next = last;
			last->previous = first;
			return;
		}
		push_back(value);
		Node<T>* node = last;
		Node<T>* node2 = last->previous;
		while (node2->previous != nullptr) {
			if (node->value > node2->value) {
				insert(Iterator<T>(node2), value);
				pop_back();
				return;
			}
			node2 = node2->previous;
		}
		if (node->value > first->value) {
			insert(Iterator<T>(first->next), value);
			pop_back();
			return;
		}
		else {
			insert(Iterator<T>(first), value);
			pop_back();
			return;
		}
	}


	/*void BubbleSort() {
		Node<T>* tmp;
		auto i = first;
		auto j = first->next;
		for (auto i = first; i != last->previous; i++) {
			for (auto j = first->next; j != last; j++) {
				Node<T>* node = i;
				Node<T>* node2 = j;
				if (node->value > node2->value) {
					tmp = node;
					node = node2;
					node2 = tmp;
				}

			}
		}
	}*/

	void printAll()//робит
	{
		if (last == nullptr)
		{
			std::cout << first->value << " ";
		}
		else {
			Node<T>* node = first;
			while (node->next != nullptr)//проход по всему списку
			{
				std::cout << node->value << " ";

				node = node->next;//переход к след узлу
			}
		}
	}
	void find(Iterator<T> i) {
		Node<T>* node = first;
		bool flag = true;
		while (node->next != nullptr)
		{
			if (i == Iterator<T>(node))
			{
				cout << node->value;
				flag = false;
				break;
			}
			node = node->next;
		}
		if (!flag) {
			cout << "I dont see";
		}
	}
	/*	void delet(Iterator<T> i)
		{
			if (first == nullptr)
			{
				return;
			}
			if (last == nullptr)
			{
				delete first;
				return;
			}
			Node<T>* node = first;
			while (node->next != nullptr)//проход по всему списку
			{
				if (i == Iterator<T>(node))
				{

					auto nextNode = node->previous->next;//запомнили адрес
					auto prevNode = node->next->previous;


					return;
				}
				node = node->next;//переход к след узлу
			}
		}
		*/
	void edit(Iterator<T> i, const T& value)//++робит
	{
		Node<T>* node = first;
		while (node->next != nullptr)//проход по всему списку
		{
			if (i == Iterator<T>(node))
			{
				node->value = value;
				return;
			}
			node = node->next;//переход к след узлу
		}
	}
	//поиск элемента по критерию





};