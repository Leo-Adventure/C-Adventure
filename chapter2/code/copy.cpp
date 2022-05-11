#include <iostream>
using namespace std;
class A
{
private:
    int *m_ptr;

public:
    A() : m_ptr(new int(0)) { cout << "construct" << endl; }
    A(const A &a) : m_ptr(new int(*a.m_ptr))
    {
        cout << "copy construct" << endl;
    }
    A(A &&a) : m_ptr(a.m_ptr)
    {
        a.m_ptr = nullptr;
        cout << "move construct" << endl;
    }
    ~A()
    {
        cout << "destruct" << endl;
        delete m_ptr;
    }

    void print()
    {
        cout << m_ptr << endl;
    }
};

A Get(bool flag)
{
    A a;
    A b;
    if (flag)
    {
        return a;
    }
    else
    {

        return b;
    }
}

int main()
{
    Get(false);
}