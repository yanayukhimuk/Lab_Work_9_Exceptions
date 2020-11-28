#pragma once
#include <cassert>
#include <iostream>
using namespace std; 

template <class T>
class Queue {
	T* queuePtr;
	const int size;
	int head;
	int tail; 
	int count;
public:
	Queue(int = 10); // ����������� �� ��������� 
	Queue(const Queue<T>&); // ����������� �����������
	~Queue(); // ���������� 

	void enqueue(const T&); // �������� ������� � �������
	T dequeue(); // ������� ������� �� �������
	void printQueue(); // ����� 
};