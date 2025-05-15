#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int d = 256;
int q = 101; 

char T[MAX] = "ababcababd";
char P[MAX] = "ababd";

int n, m;

void rk() {
    int p = 0;  // hash value for pattern
    int t0 = 0; // hash value for text window
    int h = 1;

    // Lengths
    n = strlen(T);
    m = strlen(P);

    // The value of h would be "pow(d, m-1) % q"
    for (int i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Calculate the hash value of pattern and first window of text
    for (int i = 0; i < m; i++) {
        p = (d * p + P[i]) % q;
        t0 = (d * t0 + T[i]) % q;
    }

    // Slide the pattern over text one by one
    for (int s = 0; s <= n - m; s++) {
        // Check hash values
        if (p == t0) {
            // Check characters one by one
            int match = 1;
            for (int i = 0; i < m; i++) {
                if (P[i] != T[s + i]) {
                    match = 0;
                    break;
                }
            }
            if (match)
                printf("Pattern found at index %d\n", s);
        }

        // Calculate hash for next window
        if (s < n - m) {
            t0 = (d * (t0 - T[s] * h) + T[s + m]) % q;
            if (t0 < 0)
                t0 += q;
        }
    }
}

int main() {
    rk();
    return 0;
}
