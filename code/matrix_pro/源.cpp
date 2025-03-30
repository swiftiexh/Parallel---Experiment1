#include <iostream>
#include <windows.h>

using namespace std;

const  int n = 16384;
int a[n][n], b[n];
int sum[n];

int main()
{
    for (int i = 0; i < n; i++) { b[i] = i; }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) { a[i][j] = i + j; }
    }

    long long head, tail, freq;
    QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
    QueryPerformanceCounter((LARGE_INTEGER*)&head);

  
    for (int i = 0; i < n; i++) { sum[i] = 0; }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sum[j] += a[i][j] * b[i];
        }
    }
    
    QueryPerformanceCounter((LARGE_INTEGER*)&tail);
  
    cout << "Time: " << (tail - head) * 1000.0 / freq << "ms" << endl;

    return 0;
}
