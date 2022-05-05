#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

using namespace std;

class A
{
    int i_ = 0;
    void func(int x, int y)
    {
        auto x1 = [=]
        { return i_; };
        auto x2 = [&]
        { return i_ + x + y; };
    }
};
int main()
{
    auto f = [](int a) -> int
    { return a + 1; };
    cout << f(1) << endl;

    int a = 0;
    auto lam = [&]() -> int
    { return a; };
    a++;
    cout << lam() << endl;

    vector<int> v = {1, 2, 3, 4, 5, 6};
    int even_cnt = 0;
    for_each(v.begin(), v.end(), [&even_cnt](int val)
             {
        if(!(val & 1)){
            ++ even_cnt;
        } });
    cout << "The even cnt = " << even_cnt << endl;

    int cnt = count_if(v.begin(), v.end(), [](int val) -> bool
                       { return val > 3 && val <= 10; });
    cout << "cnt = " << cnt << endl;
    return 0;
}