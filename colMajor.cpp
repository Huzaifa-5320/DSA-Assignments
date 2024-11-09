#include <iostream>
using namespace std;

int main() {
    int n = 7;
    int I[n];
    int S[n];
    int sum = 0;

    for (int j = 0; j <= n - 1; j++) {  // Outer loop iterates over columns (j)
        int mul = I[j];  // Start with I[j], as we are in column-major order
        
        for (int i = j + 1; i <= n - 1; i++) {  // Inner loop iterates over rows (i) within each column
            mul *= S[i];  // Multiply by elements in S (column-major access)
            sum += mul;
        }
    }
    return 0;
}