/************************************************
U盘测试
时间限制：5000 ms  |  内存限制：65536 KB

描述

    你知道吗？一个质检及格的U盘从10层楼高处自由落体到地并不会带来任何数据损失！而一个质检及格的ACM牌U盘，采用北航最尖端的RP材料技术，结构上符合RP守恒定律，从100层高楼自由落体到地可以毫发无伤！ 

    这天，突然来了一位火星人，他说想在火星上测试一下这种ACM牌U盘是否能通过H层高楼的自由落体测试，你需要具体测出在哪一层U盘会摔坏（即在第P层测试会摔坏，在P-1层不会坏，或者在楼顶摔也不会坏）。 

    实验总是有风险的，摔坏的U盘不能再参加测试，可惜这种U盘太畅销了，你只能带有限的N个U盘去火星测试。所以你需要知道在H和N确定的情况下，制定一套方案，宁可把这N个U盘砸坏，也要找到一个最小的次数K，使得无论U盘质量如何，总可以在K次实验后完成测试。 

     

输入

    输入文件有多组数据。 

    每组数据只有一行，即两个正整数N和H（1≤N≤15, 1≤H≤1000）。 

    输入以0 0结束。 
输出

    对每组数据，只需输出一行，为最少的次数K。
样例输入

    1 2
    3 7
    4 15
    4 16
    0 0

样例输出

    2
    3
    4
    5

提示

    1. 火星上的楼层数都是连续的，所以对H=2的情况，可能得到的测试结果是：

    a) 在1层摔坏；

    b) 在1层摔不坏而在2层摔坏；

    c) 在2层摔不坏。

    故对（N=1，H=2）情形，先在1层测，如果没摔坏，再在2层测，K=2。

    2. 你带去的N个U盘质量都是相同的，实验时的条件也是一致的。

    3. 在低层摔坏的在高层一定摔坏，在高层摔不坏的在低层一定摔不坏。
*********************************************************************/
// 51 ms 	100 KB 	g++

#include <stdio.h>


int vf[16][1001];

int main()
{
	int i,j,k,max,min,n,h;
	for(i=1;i<=1000;i++)
	vf[1][i]=i;
	for(i=1;i<=15;i++)
	{
		vf[i][1]=1;
		vf[i][2]=2;
	}
	for(i=2;i<=15;i++)
	for(j=3;j<=1000;j++)
	{
			min=1000000000;
			for(k=1;k<=(j+1)/2;k++)
			{
				max=vf[i-1][k];
				if(vf[i][j-k-1]>max)
				max=vf[i][j-k-1];
				max++;
				if(max<min)
				min=max;
			}
			vf[i][j]=min;
	}
	scanf("%d%d", &n, &h);
	while(n)
	{
		printf("%d\n",vf[n][h]);
		scanf("%d%d",&n,&h);
	}
	return 0;
}

