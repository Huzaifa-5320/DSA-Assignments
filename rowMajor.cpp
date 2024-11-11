#include <iostream>
using namespace std;

int main()
{
    int n = 4;
    int I[n] = {1,2,3,4}; // Example initialization for I
    int S[n] = {5,5,5,5}; // Example initialization for S
    int sum = 0;

    
    for (int i = 0; i < n; i++)
    {
        int mul = I[i];
        for (int j = i + 1; j < n; j++)
        {
            mul *= S[j];
        }
        sum += mul;
    }

    cout << "Sum: " << sum << endl;
    return 0;
}