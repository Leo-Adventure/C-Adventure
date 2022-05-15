# type_traits——类型萃取
在一定程度上可以消除冗长的 switch-case 或者 if-else 的语句

## 基本的 type_traits

C++ 11 之前编译器常量定义方法:
- static const int value = 1;
- enum{value = 1};

C++11 定义编译期常量办法：
使用 interal_constant 派生

常用的判断类型：
- is_same 判断两种类型是否相同
- is_pointer 判断类型是否是指针类型
- is_same 判断两种类型是否相同
- is_base_of 判断前一种类型是否是后一种类型的基类
- is_convertible 判断前面的模板参数能否转换为后面的模板参数类型

根据模板类创建对象时，要注意移除引用
```cpp
template<typename T>
typename std::remove_reference<T>::type* Create(){
    typedef std::remove_reference<T>::type U;
    return new U();
}
```
在上述例子中，模板参数 T 可能是引用类型，而创建对象时，需要原始的类型，不能使用引用类型，所以需要将可能的引用移除。

创建智能指针时，需要通过 std::remove_reference<T> 获取 T 的原始类型 U，而获取智能指针指向的对象时，又需要对 U 添加左值引用 std::add_lvalue_reference<U>。

## decay
需要同时移除 cv 符以及 引用时，一方面可以使用 std::remove_cv<std::remove_reference<T>::type>::type 来获得原始类型

另一方面可以使用 std::decay
对于函数来说，decay 的作用是添加指针，所以可以将函数变成函数指针类型从而将函数指针变量保存起来，以便在后面延迟执行
即如果要保存函数，则先要获取函数对应的函数指针类型，这时就可以用 decay 来获取函数指针类型了

## 根据条件选择 traits
可以通过编译期的判断式来选择类型，给动态选择提供了很大的灵活性

typedef std::conditional<true, int, float>::type A; //A 是 int 类型

## 获取可调用对象返回类型的 traits
## 根据条件禁用或者启用某种或者某些类型 traits
使用 std::enable_if 来实现根据条件选择重载函数、模板定义、类模板特化以及入参类型的限定

原型：
template<bool B, class T = void>
struct enable_if;



