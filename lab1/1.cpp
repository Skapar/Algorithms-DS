#include <iostream>
#include <deque> 
 
using namespace std; 
 
void royalflush(int n){ 
    deque<int> a; 
    for(int i = n; i > 0 ; i--){ 
        a.push_front(i); 
        for(int j = 0 ; j < i; j++){ 
            int d = a.back(); 
            a.push_front(d); 
            a.pop_back(); 
    }   } 
    while(!a.empty()){ 
        cout << a.front() << " "; 
        a.pop_front(); 
    } 
    cout << '\n'; 
} 
 
 
int main(){ 
    int t; 
    cin >> t; 
    while(t--){ 
        int n; 
        cin >> n; 
        royalflush(n); 
    } 
}