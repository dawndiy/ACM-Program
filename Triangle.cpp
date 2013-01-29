/******************************************************
构成三角形的条件
时间限制：1000 ms  |  内存限制：8192 KB

描述

    读入3个非零的double数后，判别这三个值是否可以表示一个三角形的三条边。

输入

    第一行是测试数据组数n。下面有n行，每行分别是用空格隔开的3个double，代表三角形的三条边。
输出

    输出为n行，对应第n行输入的结果。判断输入的三个值是否可以表示一个三角形的三条边，如果能则输出1，如果不能输出0 。
样例输入

    2
    1 1 1
    5 6 -1

样例输出

    1
    0
******************************************************/
// 3 ms 	44 KB 	g++

#include<iostream>
using namespace std;

int main()
{
     int a,b,c,n;
     cin>>n;
     while(n--)
     {
         cin>>a>>b>>c;
         if ((a+b)>c && (a+c)>b && (b+c)>a)
            cout<<1<<endl;
         else cout<<0<<endl;
     }
}


