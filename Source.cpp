#include "Header.h"
#include <Windows.h>

void main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Queue<int> Q1;
    Q1.push(5);
    Q1.push(8);
    Q1.push(11);
    Q1.push(17);
    Q1.push(2);
    Q1.push(33);
    Q1.print("Q1");

    /*int d;
    d = Q1.GetItem();
    cout << "d = " << d << endl;
    */
    
    Queue<string> Q3;
    Q3.push("собака");
    Q3.push("кошка");
    Q3.print("Q3");

    Q3.clear();
    if (Q3.IsEmpty())
        cout << "OK" << endl;
    else
        cout << "NO" << endl;

    cout << "n = " << Q3.GetN() << endl;
}
