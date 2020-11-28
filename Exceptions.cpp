#include <iostream>
#include "Source.cpp"
#include "Header.h"
#include <Windows.h>


int main() {

    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251); 

    Queue<char> myQueue(14);

    myQueue.printQueue();

    int ct = 1;
    char ch;

    while (ct++ < 14)
    {
        cin >> ch;
        myQueue.enqueue(ch);
    }

    myQueue.printQueue(); 

    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.dequeue();

    myQueue.printQueue(); 

    cout << "\n\nСработал конструктор копирования:\n";
    Queue<char> newQueue(myQueue);

    newQueue.printQueue();
	return 0; 
}