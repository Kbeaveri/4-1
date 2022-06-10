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
			return;
		}
		/*if (last == nullptr)
		{
			Node<T>* newNode = new Node<T>(value);
			last = newNode;
			first->next = last;
			last->previous = first;
			return;
		}*/
		push_back(value);
		Node<T>* node = last;
		Node<T>* node2 = first;
		int a = 0;
		while (node2 != nullptr) {
			a++;
			if (node->value < node2->value) {
					insert(Iterator<T>(node2), value);
					pop_back();
					return;
			}
			node2 = node2->next;
		}
		/*if (node->value > first->value) {
			insert(Iterator<T>(first->next), value);
			pop_back();
			return;
		}
		else {
			insert(Iterator<T>(first), value);
			pop_back();
			return;
		}*/
	}
	template <typename b>
	void Cout_find(b a) {
		Node<T>* node = first;
		bool flag = true;
		while (node!= nullptr)
		{
			if (node ->value == a)
			{
				cout << node->value;
				flag = false;
			}
			node = node->next;
		}
		if (!flag) {
			cout << "I dont see";
		}
	}

	void printAll()//робит
	{
		if (last == nullptr)
		{
			std::cout << first->value << " ";
		}
		else {
			Node<T>* node = first;
			while (node != nullptr)//проход по всему списку
			{
				std::cout << node->value << " ";

				node = node->next;//переход к след узлу
			}
		}
	}
	Iterator <T> find_it(int a) {
		Node<T>* node = first;
		bool flag = false;
		for (int i = 0; i < a&&node!=nullptr; i++) {
			node = node->next;
		}
		if (node == nullptr) {
			cout << "I dont see";
		}
		else {
			return Iterator <T>(node);
		}
	}
	void delet(int a)
	{
		Node<T>* node = first;
		auto it = find_it(a);
		while (node->next != nullptr) {
			if (it == Iterator <T>(node)&&a!=0) {
				node->previous->next = node->next;
				node->next->previous = node->previous;
				node->~Node();
				break;
			}
			if (a == 0) {
				first = node->next;
				break;
			}
			node = node->next;
		}
	}
		
	void edit(const T& value,int a)//++робит
	{
		if (a == 0) {
			insert(Iterator<T> (first), value);
			delet(1);
			return;
		}
		delet(a);
		push_sort(value);
	}
	void find(int kol,string  city) {
		Node<T>* node = first;
		while (node != nullptr) {
			if (node->value == city) {
				if (kol_find(city,node->value) >= kol) {
					cout << node->value;
				}
			}
			node = node->next;
		}
	}
	int kol_find(string  city, const T& value) {
		push_back(value);
		int sum = 0;
		Node<T>* node = first;
		Node<T>* node2 = last;
		while (node->next != nullptr) {
			if (node->value == city) {
				if (node2->value==node->value ) {
					sum++;
				}
			}
			node = node->next;
		}
		pop_back();
		return sum;
	}
};