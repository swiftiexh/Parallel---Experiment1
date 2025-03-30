#include <iostream>
using namespace std;
const int n = 10;

int main()
{
    int a[n][n], b[n];
    int sum[n];
    for (int i = 0; i < n; i++) { b[i] = i; }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) { a[i][j] = i + j; }
    }

    //核心部分
    //实现1
    for (int i = 0; i < n; i++)
    {
        sum[i] = 0;
        for (int j = 0; j < n; j++)
        {
            sum[i] += a[j][i] * b[j];
        }
    }
    //test
    for (int i = 0; i < n; i++) { cout << sum[i] << " "; }
    cout << endl;

    //实现2
    for (int i = 0; i < n; i++) { sum[i] = 0; }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) 
        {
            sum[j] += a[i][j] * b[i];
        }
    }
    //test
    for (int i = 0; i < n; i++) { cout << sum[i]<<" "; }
    return 0;
}
