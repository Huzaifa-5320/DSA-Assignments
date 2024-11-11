#include <iostream>
using namespace std;

int main()
{
    int n = 4;
    int I[n] = {1,2,3,4}; // Example initialization for I
    int S[n] = {5,5,5,5}; // Example initialization for S
    int sum = 0;

    // Iterate from n-1 down to 0
    for (int i = n - 1; i >= 0; i--)
    {
        int mul = I[i];
        for (int j = i - 1; j >= 0; j--)
        {
            mul *= S[j];
        }
        sum += mul;
    }

    cout << "Sum: " << sum << endl;
    return 0;
}