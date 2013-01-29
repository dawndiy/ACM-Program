/***********************************************

三角形面积
时间限制：1000 ms  |  内存限制：8192 KB

描述

    用海伦公式计算三角形面积。已知3个边长A，B，C。 设S = (A+B+C)/2。面积 = SQRT(S*(S-A)*(S-B)*(S-C))。

输入

    第一行一个正整数T，表示有T组测试数据。第二行～第T+1行，每行3个实数A，B，C。
输出

    对于每组A，B，C， 输出一行，该行包含一个实数，表示面积S，保留3位小数。
样例输入

    2
    6.0 6.0 6.0
    3.0 4.0 5.0

样例输出

    15.588
    6.000

提示

    注意精度
**********************************************/
// 3 ms 48 KB

#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
            double a,b,c,s;
            cin>>a>>b>>c;
            s=(a+b+c)/2;
            double ss=sqrt(s*(s-a)*(s-b)*(s-c));
            cout.setf(ios:: showpoint);
            cout.precision( 3 );
            cout.setf(ios:: fixed );
            cout<<ss<<endl;
    }

}

