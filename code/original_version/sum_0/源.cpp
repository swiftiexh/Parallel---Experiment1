#include <iostream>
using namespace std;
const int n = 20;
int a[n];

void recursion(int size) {
	if (size == 1) return; 

	for (int i = 0; i < size / 2; i++) {
		a[i] = a[i * 2] + a[i * 2 + 1]; 
	}
	int next_size = (size + 1) / 2;
	if (size % 2 == 1) {
		a[next_size-1] = a[size - 1]; 
	}

	return recursion(next_size); 
}
int main()
{
	for (int i = 0; i < n; i++) { a[i] = i; }

	int sum = 0;
	//方法1 逐项相加
	for (int i = 0; i < n; i++) { sum += a[i]; }
	cout << sum << endl;

	sum = 0;
	//方法2 多路链式
	int sum1 = 0; int sum2 = 0;
	for (int i = 0; i < n; i+=2)
	{
		if (a[i]) { sum1 += a[i]; }
		if (a[i + 1]) { sum2 += a[i + 1]; }
	}
	sum = sum1 + sum2;
	cout << sum << endl;

	sum = 0;
	//方法3 递归实现
	recursion(n);
	sum = a[0];
	cout << sum<<endl;


	//方法4 双重循环
	for (int i = 0; i < n; i++) { a[i] = i; }
	sum = 0;
	for (int i = n; i > 1; i=(i+1)/ 2)
	{
		for (int j = 0; j < i / 2; j++)
		{
			a[j] = a[j * 2] + a[j * 2 + 1];
		}
		if (i % 2 == 1) {
			a[(i + 1) / 2 - 1] = a[i - 1];
		}
	}
	sum = a[0];
	cout << sum << endl;
	return 0;
}