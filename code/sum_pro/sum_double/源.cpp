#include <iostream>
#include <windows.h>
using namespace std;
const int n = 262144;
int sum = 0;
int a[n];

void sum_double(int n)
{
	for (int i = n; i > 1; i = (i + 1) / 2)
	{
		for (int j = 0; j < i / 2; j++)
		{
			a[j] = a[j * 2] + a[j * 2 + 1];
		}
		//�Ա߽����������⴦������Ӧ���ֹ�ģ������
		if (i % 2 == 1) {
			a[(i + 1) / 2 - 1] = a[i - 1];
		}
	}
	sum = a[0];
}
int main()
{
    for (int i = 0; i < n; i++) { a[i] = i; }
    long long head, tail, freq;
    QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
    QueryPerformanceCounter((LARGE_INTEGER*)&head);

    sum_double(n);

    QueryPerformanceCounter((LARGE_INTEGER*)&tail);
    cout << "Time: " << (tail - head) * 1000.0 / freq << "ms" << endl;
    return 0;
}