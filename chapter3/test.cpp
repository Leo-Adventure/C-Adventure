#include <iostream>
using namespace std;
class A
{
private:
    const int &a;
    int b;

public:
    A(const int& num1, const int num2) : a(num1), b(num2){};
    void print() const
    {
        cout << a << b << endl;
    }
};
int main()
{
    int a = 0;
    int b = 1;
    std::cin >> a >> b;
    A aClass(a, b);
    std::cout << a << " " << b << '\n'; 
    aClass.print();
    return 0;
}