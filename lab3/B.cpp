#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long block(vector<long long>vect, long long k, long long mid){
    long long b = 0;
    long long curr = 0;

    for(int i = 0; i<vect.size(); i++){
        curr +=vect[i];

        if(curr > mid){
            b++;
            curr = vect[i];
        }
    }
    b+=1;

    return b <= k;
    
}
int main(){
    long long n, k;
    cin >> n >> k;

    vector<long long>vec(n);
    long long sum = 0;
    long long b = 0;

    for(int i = 0; i<n; i++){
        cin >> vec[i];
        sum+=vec[i];
        b = max(b, vec[i]);   
    }
    long long f = b;
    long long last = sum;
    long long res = sum; 

    while(last>=f){
        long long mid = (last + f)/2;

        if(block(vec, k, mid)){
            res = mid;
            last = mid - 1;
        }
        else{
            f = mid+1;
        }
    }
    cout << res;
}