#include <iostream>
#include <vector>

using namespace std;

int main(){
    string s,t;
    cin >> s >> t;

    vector<char>vec;
    vector<char>vec1;

    for(int i = 0; i<s.size(); i++){
        if(s[i] != '#' ){
            vec.push_back(s[i]);
        }
        else if (!vec.empty() && s[i]=='#' ){
            vec.pop_back();
        }
    }
    for(int i = 0; i<t.size(); i++){
        if(t[i] != '#' ){
            vec1.push_back(s[i]);
        }
        else if (!vec1.empty() && t[i]=='#' ){
            vec1.pop_back();
        }
    }

    if(vec.size() == vec1.size()){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
    
}