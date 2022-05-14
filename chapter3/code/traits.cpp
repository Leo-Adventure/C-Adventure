#include <iostream>
#include <type_traits>

using namespace std;

int main()
{
    const int i = 3;
    cout.setf(ios::boolalpha); 
    cout << "is_const: " << endl;
    cout << "int: " << is_const<int>::value << endl;
    cout << "i: " << is_const<const int>::value << endl;
    cout << is_same<decltype(i), add_const<int>::type>::value << endl;
    return 0;
}