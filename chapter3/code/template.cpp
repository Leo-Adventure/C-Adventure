#include <iostream>
#include <tuple>
using namespace std;

template <class... T>
void f(T... args)
{
    cout << sizeof...(args) << endl; // 打印变参个数
}

// template <typename T, typename std::enable_if<std::is_arithmetic<T>::value>::type>
void print()
{
    cout << "empty" << endl;
}
//展开函数
template <class T, class... args>
void print(T head, args... rest)
{
    cout << "parameter: " << head;
    cout << " sizeof() = " << sizeof...(rest) << endl;
    print(rest...);
}

template <size_t I = 0, typename Tuple>
typename std::enable_if<I == std::tuple_size<Tuple>::value>::type printp(Tuple t)
{
}
template<size_t I = 0, typename Tuple>
typename std::enable_if<I < std::tuple_size<Tuple>::value>::type printp(Tuple t){
    cout << std::get<I>(t) << endl;
    printp<I + 1>(t);
}

template<typename... args>
void print_tuple(args... rest){
    printp(std::make_tuple(rest...));
}

int main()
{
    /* part1
    f();
    f(1, 2);
    f(1, 2, "string");
    return 0;
    */
    print_tuple(1, 2, 3, 4);
}