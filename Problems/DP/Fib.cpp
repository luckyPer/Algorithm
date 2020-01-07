#include <vector>
#include <iostream>

using namespace std;

int rec_fib(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return rec_fib(n - 1) + rec_fib(n - 2);
    }
}

int dp_fib(int n)
{
    int fib[n];
    fib[0] = 1;
    fib[1] = 1;
    for (int i = 2; i < n; i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }
    
    return fib[n-1];
}

int main(int argc, char const *argv[])
{
    cout << dp_fib(5);
    system("pause");
    return 0;
}