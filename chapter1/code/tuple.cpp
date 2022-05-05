#include <iostream>
#include<tuple>
#include<string>

using namespace std;
int main()
{
    int x = 1;
    int y = 2;
    string s = "aa";
    auto tp = tie(x, s, y);
    int data = get<0>(tp);
    int a, b;
    string s_;
    tie(ignore, s_, b) = tp;
    cout << s_ << endl;
}