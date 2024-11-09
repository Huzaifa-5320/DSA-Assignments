#include <iostream>
using namespace std;

int main()
{
    int n = 7;
    int I[n];
    int S[n];
    int sum = 0;

    for (int i = 0; i <= n-1; i++)
    {
        int mul = I[i];
        for (int j = i + 1; j <= n-1; j++)
        {
            mul *= S[j];
            sum += mul;
        }

    }
    return 0;
}