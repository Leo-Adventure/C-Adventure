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


