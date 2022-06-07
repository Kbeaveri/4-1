#pragma once
#include <iostream>
#include "Node.h"
#include "Iterator.h"
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
		while (last->previous != nullptr)//last->previous = *last.previous, ���� � ��� ������������� != ������
		{
			Node<T>* remove = last->previous;//�������� ������������ ������ ������ �� ���������, remove=������������� ������
			last->previous = remove->previous; //������������� ������ = ����������������� , � ������������� �������
			//������ 1 2 3, � ����� ����� 1 3
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

	void printAll()//�����
	{
		if (last == nullptr)
		{
			std::cout << first->value << " ";
		}
		else {
			Node<T>* node = first;
			while (node->next != nullptr)//������ �� ����� ������
			{
				std::cout << node->value << " ";

				node = node->next;//������� � ���� ����
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
			while (node->next != nullptr)//������ �� ����� ������
			{
				if (i == Iterator<T>(node))
				{

					auto nextNode = node->previous->next;//��������� �����
					auto prevNode = node->next->previous;


					return;
				}
				node = node->next;//������� � ���� ����
			}
		}
		*/
	void edit(Iterator<T> i, const T& value)//++�����
	{
		Node<T>* node = first;
		while (node->next != nullptr)//������ �� ����� ������
		{
			if (i == Iterator<T>(node))
			{
				node->value = value;
				return;
			}
			node = node->next;//������� � ���� ����
		}
	}
	//����� �������� �� ��������





};