#include <iostream>
using namespace std;

//使得函数只有在判断条件满足时才有效
template <typename T>
typename std::enable_if<std::is_arithmetic<T>::value, T>::type foo(T t)
{
    return t;
}

// 对函数入参做限定，即第二个入参类型为 integral 类型
template<class T>
T foo2(T t, typename std::enable_if<std::is_integral<T>::value, int>::type = 0){
    return t;
}

// 对模板参数 T 做限定，T只能是 integral 类型
template<class T, class = typename std::enable_if<std::is_integral<T>::value>::type>
T foo3(T t){
    return t;
}

template <typename, typename > class B; 

// 模板特化时，对模板参数做限定，模板参数类型只能为浮点型
template<class T>
class B<T, typename std::enable_if<std::is_floating_point<T>::value>::type>{};

int main(){
    /*part1
    auto r = foo(1);
    cout << r << endl;
    auto r1 = foo(1.2);
    cout << r1 << endl;
    auto r3 = foo((int)"string");
    cout << r3 << endl;
    */
   cout << foo2(3, 2) << endl;
   
}