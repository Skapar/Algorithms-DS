#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void computeLPSArray(char* pat, int m, int* lps){
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}
int KMPsearch(char* pat, char* txt) {
    int cnt = 1;
    int m = strlen(pat);
    int n = strlen(txt);

    int* lps = new int[m];
    int i = 0;
    int j = 0;
    computeLPSArray(pat, m, lps);
    for(int k = 0; k < n; k++){
        if(txt[k] >= 'A' && txt[k] <= 'Z'){
            i = k;
        }
    }
    while ((n - i) >= (m - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
        if (j == m) {
            cnt+=1;
            j = lps[j - 1];
        } else if (i < n && pat[j] != txt[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i = i + 1;
            }
        }
    }
    delete[] lps;
}

int main() {
    string pattern, text;
    int count;
    cin >> pattern >> count >> text;
    char* pat = new char[pattern.length() + 1];
    char* txt = new char[text.length() + 1];

    strcpy(pat, pattern.c_str());
    strcpy(txt, text.c_str());

    vector<int>v = KMPsearch(txt, pat);

    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    // if(v.size() >= count){
    //     cout << "YES";
    // }
    // else{
    //     cout << "NO";
    // }



    

    

    return 0;
}
