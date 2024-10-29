#include <iostream>
#include <string>
using namespace std;

// d is the number of characters in the input alphabet
#define d 256

// G 71
// E 69
// E 69
// K 75
// S 83
void search(string pat, string txt, int q)
{
    int M = pat.length();
    int N = txt.length();
    int i, j;
    int p = 0; // hash value for pattern
    int t = 0; // hash value for txt
    int h = 1;

    // The value of h would be "pow(d, M-1)%q"
    for (i = 0; i < M - 1; i++)
        h = (h * d) % q;
        // h = 2
    // Calculate the hash value of pattern and the first
    // window of text

    // 4
    // i==0
    // i == 1
    for (i = 0; i < M; i++) {
        p = (d * p + pat[i]) % q;
        // p = 0
        t = (d * t + txt[i]) % q;
        // t = 0
    }

    // Slide the pattern over text one by one
    for (i = 0; i <= N - M; i++) {

        // Check the hash values of the current window of text
        // and pattern. If the hash values match, then only
        // check for characters one by one
        if (p == t) {
            /* Check for characters one by one */
            for (j = 0; j < M; j++) {
                if (txt[i + j] != pat[j]) {
                    break;
                }
            }

            // If p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
            if (j == M)
                cout << "Pattern found at index " << i << endl;
        }

        // Calculate the hash value for the next window of text:
        // Remove the leading digit and add the trailing digit
        if (i < N - M) {
            t = (d * (t - txt[i] * h) + txt[i + M]) % q;

            // We might get a negative value of t, so convert it to positive
            if (t < 0)
                t = (t + q);
        }
    }
}

int main()
{
    string txt = "GEEKS FOR GEEKS";
    string pat = "GEEK";

    // We use a large prime number as q to avoid collisions
    int q = 100;

    // Function Call
    search(pat, txt, q);
    return 0;
}
