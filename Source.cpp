#include "Header.h"
using namespace std; 

template<typename T>
Queue<T>::Queue(int sizeQueue) :
    size(sizeQueue),
    head(0), tail(0), count(0)
{
    queuePtr = new T[size + 1];
}

template<typename T>
Queue<T>::Queue(const Queue& otherQueue) :
    size(otherQueue.size), head(otherQueue.head),
    tail(otherQueue.tail), count(otherQueue.count),
    queuePtr(new T[size + 1])
{
    for (int ix = 0; ix < size; ix++)
        queuePtr[ix] = otherQueue.queuePtr[ix];
// копирование 
}

template<typename T>
Queue<T>::~Queue()
{
    delete[] queuePtr;
}

template<typename T>
void Queue<T>::enqueue(const T& newElem) 
{
    assert(count < size);
    queuePtr[tail++] = newElem;
    count++;
    if (tail > size)
        tail -= size + 1;
}

// функция удаления элемента из очереди
template<typename T>
T Queue<T>::dequeue()
{
   assert(count > 0);
   /* try
    {
        if (size == 0)
        {
            UnderFlowException ex = UnderFlowException("\nОчерель пустая");
            throw ex;
        }
    }
    catch (ex){
        cout << "It is empty!" << endl; 
    }*/
    T returnValue = queuePtr[head++];
    count--;
    if (head > size)
        head -= size + 1; 
    return returnValue;
}

template<typename T>
void Queue<T>::printQueue()
{
    cout << "Очередь: ";

    if (tail == 0 && head == 0)
        cout << " пустая\n";
    else
    {
        for (int ix = tail; ix >= head; ix--)
           cout << queuePtr[ix] << " ";
        cout << endl;
    }
}
