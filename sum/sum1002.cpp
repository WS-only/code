/*
�������������ڶ���ӷ����㣬�û�����������������
ʱ�䣺2016/10/11
���ߣ�WS
��ע����Ŀ��˵��32λ��̫��� 
*/

#include<iostream>
using namespace std;

int main()
{
	int n;
	int a[30],b[30],sum[30];
	cout<<"Please input the number of the cases(1~20):";
	cin>>n;
	cout<<"Please input the number of each case in order:"<<endl;
	for(int i=1; i<=n; i++)
	{
		cin>>a[i]>>b[i];
		sum[i]=a[i]+b[i];
	} 
	for(int i=1; i<=n; i++)
	{
		cout<<"case "<<i<<":"<<endl;
		cout<<a[i]<<" + "<<b[i]<<" = "<<sum[i]<<endl;
	}
	return 0;
} 
