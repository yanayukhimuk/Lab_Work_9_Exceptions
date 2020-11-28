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
	Queue(int = 10); // конструктор по умолчанию 
	Queue(const Queue<T>&); // конструктор копирования
	~Queue(); // деструктор 

	void enqueue(const T&); // добавить элемент в очередь
	T dequeue(); // удалить элемент из очереди
	void printQueue(); // вывод 
};