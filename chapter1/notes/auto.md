## auto类型推导
### 意义
隐式类型定义的类型推导发生在编译期，编译器自动推断类型
### 推导规则
当表达式带有 const 属性的时候，auto 会把 const 属性抛弃掉
当 auto 和引用相结合的时候，auto 的推导将会保留表达式的 const 属性（引用不能退化）

### 限制
- auto 不能用作函数参数
- auto 不能用作非静态成员变量
- auto 不能定义数组

虽然 C++11 支持非静态成员变量的就地初始化，但是不支持 auto 类型非静态成员变量的初始化

### 适用时机
```cpp
for (auto it = aMap.begin(); it != aMap.end(); ++it){
    //do something
}
```

在多个具有同名 静态 方法的类，且不同类的静态方法返回值不同时，在使用模板的时候，使用 auto 自动根据传入的类来推断返回值的类型


## decltype 关键字

### 获知表达式类型
如果想通过某个表达式得到类型但是又不希望新变量和这个表达式具有同样的值，此时 auto 便不再适用

```cpp
int x = 0;
decltype(x) y = 1;
decltype(x + y) z = 0;

const decltype(z) * p = &z;
// etc.
```

对于一般的标记符表达式， decltype 将精确地推导出表达式定义本身的类型，不会像 auto 一样在某些情况下舍弃引用 和 cv 修饰符

### decltype 的推导规则
以 decltype(exp) 为例

- 如果 exp 是一个标识符，则与 exp 类型完全一致
- 如果 exp 是一个函数调用，则与该函数调用的返回值类型一致

如果函数返回值是 const int, 那么返回的 int 就是一个纯右值，对于纯右值而言，只有类类型可以携带 cv 限定符，此外一般就会忽略 cv 限定符
- 如果 exp 是一个左值，那么 decltype 是 exp 类型的左值引用，否则 和 exp 类型一致

### 使用
decltype 的应用多出现在泛型编程当中

返回类型后置写法：
```cpp
template <typename T, typename U>
auto add(T t, U u) -> decltype(t + u){
    return t + u;
}
```

```cpp
int& foo(int &i);
float foo(float& f);

template<typename T>
auto func(T& val) -> decltype(foo(val)){
    return foo(val);
}
```

### 模板别名
```c++
template<typename Val>
using str_map_t = std::map<std::string, Val>;

//...

str_map_t<int> map1;
```

使用C++11 的别名写法比typedef 更加清晰

C++11 当中，定义模板别名只是在普通类型别名语法的基础上增加了 template 的参数列表。使得可以使用 using 轻松地创建一个新的模板别名，而不需要使用外敷模板

### 模板默认参数

```cpp
template<typename T = int>
void func(void){
    //...
}

int main(){
    func(); // 当所有模板参数都有默认参数的时候，函数模板的调用如同一个普通函数。
}
```
对于类模板来说，即使所有参数都有默认参数，在使用时也必须在模板名后面跟随 <> 来实例化

注意在使用函数模板的时候，若显式指定模板的默认参数，需要从左往右填充模板参数
