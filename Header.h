#pragma once; 
#include <Windows.h>
#include <iostream>
#include <new>

using namespace std; 

template <typename T> 
class Queue {
	T* p;
	int count; 
public:
	Queue() {
		count = 0;
	}
	Queue(Queue const& obj) {
		count = obj.count;
		try {
			p = new T[count];
			for (int i = 0; i < count; i++)
				p[i] = obj.p[i];
		}
		catch (bad_alloc e)
		{
			cout << e.what() << endl; //если не была выведена память 
			count = 0; // создаём пустую очередь 
		}
	}

	void push(T item)
	{
		T* p2;
		p2 = p;

		try { // пытаемся выделить память доя p, но на 1 больше 
			p = new T[count + 1]; // копировать данные из участка на кот указывает р2 в р
			for (int i = 0; i < count; i++)
				p[i] = p2[i];

			p[count] = item; // копируем последний элемент
			count++;
			if (count > 1) // освободить память
				delete[] p2;
		}
		catch (bad_alloc e)
		{
			cout << e.what() << endl; // если память не выделится 
			p = p2; // вернуть старый указатель на р 
		}
	}
	T pop()
	{
		if (count == 0)
			return 0;
		T item;
		item = p[0];
		try {
			T* p2;
			p2 = new T[count - 1];
			count--;
			for (int i = 0; i < count; i++)
				p2[i] = p[i + 1];
			if (count > 0)
				delete[] p;
			p = p2;
			return item;
		}
		catch (bad_alloc e) {
			cout << e.what() << endl;
			return 0;
		}
	}

	Queue& operator = (const Queue& obj)
	{
		T* p2;
		try {
			p2 = new T[obj.count];
			if (count > 0)
				delete[]p;

			p = p2;
			count = obj.count;
			for (int i = 0; i < count; i++)
				p[i] = obj.p[i];
		}
		catch (bad_alloc e)
		{
			cout << e.what() << endl;
		}
		return *this;
	}
	~Queue() {
		if (count > 0)
			delete[]p;
	}
	T GetItem()
	{
		if (count > 0)
			return p[0];
		else
			return 0;
	}

	void clear()
	{
		if (count > 0)
		{
			delete[] p; 
			count = 0; 
		}
	}

	bool IsEmpty() {
		return count == 0;
	}
	int GetN()
	{
		return count; 
	}
	void print(const char* objName)
	{
		cout << "Object: " << objName << endl; 
		for (int i = 0; i < count; i++)
			cout << p[i] << "\t";
		cout << endl; 
		cout << "---------------------------" << endl; 
	}
};