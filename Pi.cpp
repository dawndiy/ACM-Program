/****************************************************
PI的来历
时间限制：1000 ms  |  内存限制：8192 KB

描述

    PI = 4 – 4/3 + 4/5 – 4/7 + 4/9 – 4/11 + …

输入

    第一行是测试数据组数n，下面有n行，每行有一个整数m。
输出

    对每组输入数据输出一行，包含要求该数列的前m项的和，精确到小数点后5位。
样例输入

    3
    1
    3
    200000

样例输出

    4.00000
    3.46667
    3.14159
************************************************************/
// 8 ms 	44 KB    g++

#include<iostream>
using namespace std;

double pi(int n)
{
	double p = 0;
	int m = 1;
	int l = 1;
	for(int i = 1; i <= n; i++)
	{
		m = 2 * i -1;
		p = p + l * 4.0/m;
		l = 0 - l;
	}

	return p;
}

int main()
{
	int n;
	cin>>n;
	double a[100];
	int i = 0;
	while(n--)
	{
		int m;
		cin>>m;
		a[i++] = pi(m);
		//cout<<pi(m)<<endl;
	}
	for(int o = 0; o < i; o++)
	{
		cout.setf(ios:: showpoint);
		//cout.precision( 6 );
		cout<<a[o]<<endl;
	}
}
