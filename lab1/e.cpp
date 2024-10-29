#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> boris, nursik;
    for (int i = 0; i < 5; i++) {
        int a; cin>>a;
        boris.push(a);
    }

    for (int i = 0; i < 5; i++) {
        int a; cin>>a;
        nursik.push(a);
    }

    int cnt=0;
    while (!boris.empty() and !nursik.empty()) {
        int b1 = boris.front();
        int n1 = nursik.front();
        boris.pop();
        nursik.pop();
        if (b1 == 0 && n1 == 9) {
            boris.push(b1);
            boris.push(n1);
            cnt++;
        } else if (b1==9 and n1 == 0){
            nursik.push(b1);
            nursik.push(n1);
            cnt++;
        } else if(b1>n1){
            boris.push(b1);
            boris.push(n1);
            cnt++;
        } else if(b1<n1){
            nursik.push(b1);
            nursik.push(n1);
            cnt++;
        }
        if(cnt>=1000000){
            cout<<"blin nichya";
            return 0;
        }
    }
    if(boris.empty()){
        cout<<"Nursik "<<cnt;
    }else if(nursik.empty()){
        cout<<"Boris "<<cnt;
    }
}