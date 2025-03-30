#include <iostream>
#include <windows.h>
using namespace std;
const int n = 262144;
int sum = 0;
int a[n];

void sum_unroll(int n)
{
    for (int i = 0; i < n; i++) { sum += a[i]; }
}
int main()
{
    for (int i = 0; i < n; i++) { a[i] = i; }
    long long head, tail, freq;
    QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
    QueryPerformanceCounter((LARGE_INTEGER*)&head);

    sum_unroll(n);
    

    QueryPerformanceCounter((LARGE_INTEGER*)&tail);
    cout << "Time: " << (tail - head) * 1000.0 / freq << "ms" << endl;
    return 0;
}