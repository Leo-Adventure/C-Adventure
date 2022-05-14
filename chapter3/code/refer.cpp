#include <iostream>
#include <type_traits>
#include <memory>
using namespace std;

template <typename T>
struct Construct
{

    typedef typename std::remove_reference<T>::type U;
    Construct() : m_ptr(new U()){};
    typename std::add_lvalue_reference<T>::type Get() const{
        return *m_ptr.get();
    }

private:
    unique_ptr<U> m_ptr;
};
int main(){
    Construct<int> c;
    int a = c.Get();
    cout << a << endl;
    return 0;
}