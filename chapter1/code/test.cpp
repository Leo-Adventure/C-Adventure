#include<iostream>
using namespace std;
static long product = 1;
using ll = long long;
long fac(ll n){
    product *= n;
    return product;
}
int main(){
    for(int i = 1; i <= 5; i++){
        cout << i << "!= " << fac(i) << endl;
    }
    cout << "Product = " << product << endl;
    return 0;
}