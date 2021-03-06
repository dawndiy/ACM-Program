/*************************************************************
数字回文
时间限制：1000 ms  |  内存限制：8192 KB

描述

    “回文”是一种特殊的数或者文字短语。他们无论是顺读还是倒读，结果都一样。例如：12321， 55555，45554。读入一个5位整数，判断它是否是回文数。

输入

    多组测试数据，每组一行，一个五位整数，数据以0结尾。
输出

    对每组输入数据输出一行，如果输入数是回文数，输出“Yes.” ，否则输出 “No.” 。
样例输入

    12345
    12321
    11111
    0

样例输出

    No.
    Yes.
    Yes.
*************************************************************/
// 3 ms 	44 KB 	g++

#include<iostream>
using namespace std;

void num(int b,int a[])
{
    for (int i=0;i<5;i++)
    {
        a[i]=b%10;
        b/=10;
    }
}

int main()
{

     while(true)
     {
         int a[5];
         int b;
         cin>>b;
         if (b==0) break;
         num(b,a);
         int i;
         for(i=0;i<2;i++)
         {
             if (a[i]!=a[4-i]) break;
         }
         if (i==2) cout<<"Yes."<<endl;
         else cout<<"No."<<endl;


     }
}

