#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
bool isprime(int nu){
    if(nu <2){
        return false;
    }
    for (int i = 2; i <= sqrt(nu); i++) {
        if (nu % i == 0) {
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    cin >> n;
    vector<int>vec;
    for(int i = 0; i<10000; i++){
        if(isprime(i)){
            vec.push_back(i);
        }
    }
    cout << vec[n-1];
}