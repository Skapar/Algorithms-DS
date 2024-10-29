#include <iostream>
#include <string>
using namespace std;

int main(){
    string a;
    cin >> a;
    // a = "idi nahui"

    for(int i = 0; i<a.size(); i++){
        // i == 0 
        // a[0] == i;
        // idi nahui
        if(a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u'){
            a[i] = '*';
        }
        // a[0] == 'a' немесе a[0] == 'e' немесе a[0] == 'i' немесе a[0] == 'o' немесе a[0] == 'u'
        // a[0] = '*'
        // idi nahui
    }
    cout << a;
}