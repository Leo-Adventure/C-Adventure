#include <iostream>
#include <functional>

using namespace std;

/* part 1
void func()
{
    cout << __FUNCTION__ << endl;
}

class Foo
{
public:
    static int foo_func(int a)
    {
        cout << __FUNCTION__ << "(" << a << ") -> : ";
        return a;
    }
};

class Bar
{
public:
    int operator()(int a)
    {
        cout << __FUNCTION__ << "(" << a << ") -> : ";
        return a;
    }
};
*/
/* part 2
class A
{
    function<void()> callback_;

public:
    A(const function<void()> &f) : callback_(f)
    {
    }

    void notify(void)
    {
        callback_();
    }
};
*/

class Foo
{
public:
    void operator()()
    {
        cout << __FUNCTION__ << endl;
    }
};

class A
{
public:
    int i_ = 0;
    void output(int x, int y)
    {
        cout << x << " " << y << endl;
    }
};

void call_when_even(int x, const function<void(int)> &f)
{
    if (!(x & 1))
    {
        f(x);
    }
}

void output(int x)
{
    cout << x << endl;
}

int main()
{
    /* part 1
    function<void()> fr1 = func;
    fr1();


    function<int(int)> fr2 = Foo::foo_func;
    cout << fr2(123) << endl;

    Bar bar;
    fr2 = bar;
    cout << fr2(123) << endl;

    return 0;
    */
    /* part2
    Foo foo;
    A aa(foo);
    aa.notify();
    return 0;
    */
    /* part 3
    auto fr = bind(output, placeholders::_1);

    for (int i = 0; i < 10; ++i)
    {
        call_when_even(i, fr);
    }
    cout << endl;
    return 0;
    */

   A a;
   function<void(int, int)> fr = bind(&A::output, &a, placeholders::_1, placeholders::_2);
   fr(1,2);

   function<int&(void)> fr_i = bind(&A::i_, &a);
   fr_i() = 123;
   cout << a.i_ << endl;

   auto bind1 = bind(greater<int>(), placeholders::_1, 5);
   auto bind2 = bind(less_equal<int>(), placeholders::_1, 10);
   
   return 0;

}
