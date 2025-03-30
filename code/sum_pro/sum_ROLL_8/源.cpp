#include <iostream>
#include <windows.h>
using namespace std;

// 采用宏技术彻底消除循环
#define ROLL_8(sum, a, i) \
    sum += a[i];            \
    sum += a[i + 1];        \
    sum += a[i + 2];        \
    sum += a[i + 3];        \
    sum += a[i + 4];            \
    sum += a[i + 5];        \
    sum += a[i + 6];        \
    sum += a[i + 7];      

const int n = 262144;
int sum = 0;
int a[n];

void sum_roll(int n)
{
    int i = 0;
    sum = 0;

    for (; i <= n - 8; i += 8)
    {
        ROLL_8(sum, a, i);
    }

    // 处理剩余部分
    for (; i < n; i++)
    {
        sum += a[i];
    }
}
int main()
{
    for (int i = 0; i < n; i++) { a[i] = i; }
    long long head, tail, freq;
    QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
    QueryPerformanceCounter((LARGE_INTEGER*)&head);

    sum_roll(n);


    QueryPerformanceCounter((LARGE_INTEGER*)&tail);
    cout << "Time: " << (tail - head) * 1000.0 / freq << "ms" << endl;
    return 0;
}