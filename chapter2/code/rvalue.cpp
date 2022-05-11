#include <iostream>
using namespace std;

int g_conststructCount = 0;
int g_copyConstructCount = 0;
int g_destructCount = 0;

struct A
{
    A()
    {
        cout << "construct: " << ++g_conststructCount << endl;
    }
    A(const A &a)
    {
        cout << "copy construct: " << ++g_copyConstructCount << endl;
    }
    ~A()
    {
        cout << "destruct: " << ++g_destructCount << endl;
    }
};

A GetA()
{
    return A();
}

void PrintValue(int &i)
{
    cout << "lvalue : " << i << endl;
}

void PrintValue(int &&i)
{
    cout << "rvalue : " << i << endl;
}
void Forward(int &&i)
{
    PrintValue(i);
}

int main()
{
    /*part1
    A a = GetA();

    int w1, w2;
    auto &&v1 = w1;
    decltype(w1) &&v2 = move(w2);
    */

    int i = 0; 
    PrintValue(i);
    PrintValue(1);
    Forward(move(2));
    return 0;
}