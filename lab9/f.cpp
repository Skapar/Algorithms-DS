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
vector<int> KMPsearch(char* pat, char* txt) {
    vector<int>v;
    int cnt = 0;
    int m = strlen(pat);
    int n = strlen(txt);

    int* lps = new int[m];

    computeLPSArray(pat, m, lps);

    int i = 0;
    int j = 0;
    while ((n - i) >= (m - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
        if (j == m) {
            v.push_back(i-j+1);
            j = lps[j - 1];
        } else if (i < n && pat[j] != txt[i]) {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i = i + 1;
            }
        }
    }
    return v;
    delete[] lps;
}

int main() {
    string pattern, text;
    cin >> pattern >> text;
    char* pat = new char[pattern.length() + 1];
    char* txt = new char[text.length() + 1];

    strcpy(pat, pattern.c_str());
    strcpy(txt, text.c_str());

    vector<int>v = KMPsearch(txt, pat);

    cout << v.size() << endl;

    for(int i = 0; i<v.size(); i++){
        cout << v[i] << " ";
    }

    

    return 0;
}
