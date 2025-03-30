#include <iostream>
#include <windows.h>
using namespace std;
const int n =262144;
int sum = 0;
int a[n];

void sum_chain(int n)
{
    int sum1 = 0; int sum2 = 0;
    for (int i = 0; i < n; i += 2)
    {
        if (a[i]) { sum1 += a[i]; }
        if (a[i + 1]) { sum2 += a[i + 1]; }
    }
    sum = sum1 + sum2;
}
int main()
{
    for (int i = 0; i < n; i++) { a[i] = i; }
    long long head, tail, freq;
    QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
    QueryPerformanceCounter((LARGE_INTEGER*)&head);

    sum_chain(n);


    QueryPerformanceCounter((LARGE_INTEGER*)&tail);
    cout << "Time: " << (tail - head) * 1000.0 / freq << "ms" << endl;
    return 0;
}