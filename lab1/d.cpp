#include <iostream>
#include <deque>

using namespace std;

int main(){
    string s;
    cin >> s;
    deque<char>q;

    for(int i = 0; i<s.size(); i++){
        if(!q.empty() && s[i] == q.back()){
            q.pop_back();
        }
        else{
            q.push_back(s[i]);
        }
    }
    
    if (q.empty()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }


}