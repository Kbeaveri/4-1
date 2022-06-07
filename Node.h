#pragma once
template<typename T>
class Node
{
public:
	T value;
	Node* next;
	Node* previous;
	Node(const T& value = T(), Node* n = nullptr, Node* p = nullptr) : value(value), next(n), previous(p) {};
	~Node() {};
};



