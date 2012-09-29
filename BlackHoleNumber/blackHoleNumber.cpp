/***********************************************
问题:
任意一个4位自然数，将组成该数的各位数字重新排列，
形成一个最大数和一个最小数，之后两数相减，其差仍
为一个自然数。重复进行上述运算，最终会出现一个神
秘的数，请编程输出这个神秘的数。

程序:程路
***********************************************/



#include <iostream>

using namespace std;

int counter=0;//用于计数器

int check(char *in)
{
	int i=0,n=0;//i为输入字符的下标,n用于储存转换的数字
	//带符号的先排除符号
	if (in[0]=='-' || in[0]=='+')
	{
		i=1;
	}
	//转换为数字,并判断错误类型
	while (in[i]!=NULL)
	{
		if (!isdigit(in[i]))
		{
			cout<<"输入的数据错误,可能包含非数字字符!\n";
			system("pause");
			exit(1);
		}
		n=atoi(in);
		i++;
	}

	if (n/10000>=1 || n/10000<=-1)
	{
		cout<<"输入的数据错误,数字大于4位数!\n";
		system("pause");
		exit(1);
	}
	else
		if (n/1000==0)
		{
			cout<<"输入的数据错误,数字小于4位数!\n";
			system("pause");
			exit(1);
		}
	else
		return n;
}
//返回n的最大最小值的差值
int getNumber(int n)
{
	int digi[5],value,i=1,Max,Min,temp;//4位数,返回值,循环,最大,最小,临时
	//判断正负,分类
	if (n>0)
		digi[0]=1;
	else
		digi[0]=0;
	n=abs(n);//转换为整数处理
	//分解n的各个位
	while( n != 0 )
	{
		digi[i] = n % 10;
		n = n / 10;
		i++;
	}
	//冒泡排序
	for (int j = 0; j < 5; j++ )
	{
		for ( i = 1; i < 4 - j; i++)
		{
			if ( digi[i] > digi[i+1] )
			{
				temp = digi [i];
				digi[i] = digi[i+1];
				digi[i+1] = temp;
			}
		}
	}
	//特殊错误
	if (digi[1]==digi[2] && digi[2]==digi[3] && digi[3]==digi[4])
	{
		cout<<"输入的数据错误,4个数字不能全部相同!否则结果将会是0.\n";
		system("pause");
		exit(1);
	}
	Min= digi[1]*1000 + digi[2]*100 + digi[3]*10 + digi[4] ;
	Max= digi[4]*1000 + digi[3]*100 + digi[2]*10 + digi[1] ;
	//正负处理
	if (digi[0]==0)
	{
		swap(Min,Max);
		Min=0-Min;
		Max=0-Max;
	}
	value=Max-Min;

	if (counter % 2 == 0)
	{
		cout<<"第"<<counter/2+1<<"次计算:\n";
		cout<<"最大值:"<<Max<<endl<<"最小值:"<<Min<<endl;
		cout<<"差值:"<<value<<endl;
		cout<<"----------------------------\n";
	}
	counter++;//计数器
	return value;
}

//计算黑洞数
int blackHoleNumber(int number)
{
	do
	{
		number=getNumber(number);
	}
	while (number != getNumber(number));
	return number;
}


//===================主程序入口===================
int main(void)
{

	char *input=new char;//用于储存输入
	int number;
	int v;
	cout<<"问题:\n";
	cout<<"请输入任意一个 4位自然数，将组成该数的各位数字重新\n";
	cout<<"排列，形成一个最大数和一个最小数，之后两数相减，其\n";
	cout<<"差仍为一个自然数。重复进行上述运算，最终会出现一个\n";
	cout<<"神秘的数，请编程输出这个神秘的数。\n";
	cout<<"\n输入:";
	cin>>input;
	number=check(input);
	v=blackHoleNumber(number);
	cout<<"黑洞数(神秘数):"<<v<<endl;
	system("pause");
	delete input;
	return 0;
}
