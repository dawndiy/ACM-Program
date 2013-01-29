/*************************************************************
数的阶乘
时间限制：1000 ms  |  内存限制：8192 KB

描述

    给定一个正整数m，打印它的阶乘。

输入

    第一行是测试数据组数n，下面n行每一行是一个正整数。
输出

    输出有n行，分别为对应输入数的阶乘。
样例输入

    2
    4
    5

样例输出

    24
    120
*************************************************************/
// 2 ms 	44 KB 	g++


#include<iostream>
using namespace std;

int factorial(int n)
{
        int res=1; 
        while(n>=2) res=res*(n--); 
        return res; 
 }


int main()
{
     int n;
cin>>n;
     while(n--)
     {
           int a;
           cin>>a;
           cout<<factorial(a)<<endl;
     }
}
