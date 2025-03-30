#include <iostream>
#include <windows.h>
using namespace std;
const int n = 262144;
int sum = 0;
int a[n];

void sum_recursion(int n)
{
    if (n == 1) return;

    for (int i = 0; i < n / 2; i++) {
        a[i] = a[i * 2] + a[i * 2 + 1];
    }
    int next_size = (n + 1) / 2;
    //对边界条件做额外处理，以适应各种规模的数据
    if (n % 2 == 1) {
        a[next_size - 1] = a[n - 1];
    }

    return sum_recursion(next_size);
}
int main()
{
    for (int i = 0; i < n; i++) { a[i] = i; }
    long long head, tail, freq;
    QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
    QueryPerformanceCounter((LARGE_INTEGER*)&head);

    sum_recursion(n);
    sum = a[0];

    QueryPerformanceCounter((LARGE_INTEGER*)&tail);
    cout << "Time: " << (tail - head) * 1000.0 / freq << "ms" << endl;
    return 0;
}