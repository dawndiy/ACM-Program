/***********************************************
����:
����һ��4λ��Ȼ��������ɸ����ĸ�λ�����������У�
�γ�һ���������һ����С����֮����������������
Ϊһ����Ȼ�����ظ������������㣬���ջ����һ����
�ص������������������ص�����

����:��·
***********************************************/



#include <iostream>

using namespace std;

int counter=0;//���ڼ�����

int check(char *in)
{
	int i=0,n=0;//iΪ�����ַ����±�,n���ڴ���ת��������
	//�����ŵ����ų�����
	if (in[0]=='-' || in[0]=='+')
	{
		i=1;
	}
	//ת��Ϊ����,���жϴ�������
	while (in[i]!=NULL)
	{
		if (!isdigit(in[i]))
		{
			cout<<"��������ݴ���,���ܰ����������ַ�!\n";
			system("pause");
			exit(1);
		}
		n=atoi(in);
		i++;
	}

	if (n/10000>=1 || n/10000<=-1)
	{
		cout<<"��������ݴ���,���ִ���4λ��!\n";
		system("pause");
		exit(1);
	}
	else
		if (n/1000==0)
		{
			cout<<"��������ݴ���,����С��4λ��!\n";
			system("pause");
			exit(1);
		}
	else
		return n;
}
//����n�������Сֵ�Ĳ�ֵ
int getNumber(int n)
{
	int digi[5],value,i=1,Max,Min,temp;//4λ��,����ֵ,ѭ��,���,��С,��ʱ
	//�ж�����,����
	if (n>0)
		digi[0]=1;
	else
		digi[0]=0;
	n=abs(n);//ת��Ϊ��������
	//�ֽ�n�ĸ���λ
	while( n != 0 )
	{
		digi[i] = n % 10;
		n = n / 10;
		i++;
	}
	//ð������
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
	//�������
	if (digi[1]==digi[2] && digi[2]==digi[3] && digi[3]==digi[4])
	{
		cout<<"��������ݴ���,4�����ֲ���ȫ����ͬ!������������0.\n";
		system("pause");
		exit(1);
	}
	Min= digi[1]*1000 + digi[2]*100 + digi[3]*10 + digi[4] ;
	Max= digi[4]*1000 + digi[3]*100 + digi[2]*10 + digi[1] ;
	//��������
	if (digi[0]==0)
	{
		swap(Min,Max);
		Min=0-Min;
		Max=0-Max;
	}
	value=Max-Min;

	if (counter % 2 == 0)
	{
		cout<<"��"<<counter/2+1<<"�μ���:\n";
		cout<<"���ֵ:"<<Max<<endl<<"��Сֵ:"<<Min<<endl;
		cout<<"��ֵ:"<<value<<endl;
		cout<<"----------------------------\n";
	}
	counter++;//������
	return value;
}

//����ڶ���
int blackHoleNumber(int number)
{
	do
	{
		number=getNumber(number);
	}
	while (number != getNumber(number));
	return number;
}


//===================���������===================
int main(void)
{

	char *input=new char;//���ڴ�������
	int number;
	int v;
	cout<<"����:\n";
	cout<<"����������һ�� 4λ��Ȼ��������ɸ����ĸ�λ��������\n";
	cout<<"���У��γ�һ���������һ����С����֮�������������\n";
	cout<<"����Ϊһ����Ȼ�����ظ������������㣬���ջ����һ��\n";
	cout<<"���ص������������������ص�����\n";
	cout<<"\n����:";
	cin>>input;
	number=check(input);
	v=blackHoleNumber(number);
	cout<<"�ڶ���(������):"<<v<<endl;
	system("pause");
	delete input;
	return 0;
}
