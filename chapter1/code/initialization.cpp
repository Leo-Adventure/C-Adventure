#include<iostream>
#include<vector>
#include<map>

using namespace std;
 
class FooVector{
    vector<int> content_;
public:
    FooVector(initializer_list<int> list){
        for(auto it = list.begin(); it != list.end(); ++it){
            content_.push_back(*it);
        }
    }
};

class FooMap{
    map<int, int> content_;
    using pair_t = map<int, int>::value_type; // 此时 pair_t 是 {int, int}类型
public:
    FooMap(initializer_list<pair_t> list){
        for (auto it = list.begin(); it != list.end(); ++it){
            content_.insert(*it);
        }
    }
};

FooVector foo_1 = {1, 2, 3, 4, 5};
FooMap foo_2 = {{1, 2}, {3, 4}};

int main(){
    int a {1.1};
    cout << a << endl;
}
