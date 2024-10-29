#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main(){
    int n; cin>>n;
    vector<int>vec;
    deque<int>deq;

    for(int i = 0; i<n; i++){
        int a;
        cin >> a;
        vec.push_back(a);
    }
    
    for(int i=0;i<vec.size(); i++){
        bool a = true;
        while (a)
        {
            if(!deq.empty() && deq.back() > vec[i]){
                deq.pop_back();
            }
            else{
                a = false;
            }
        }
        if(deq.empty()){
            cout << "-1" << " ";
        }
        else{
            cout << deq.back() << " ";
        }
        deq.push_back(vec[i]);
    }
}