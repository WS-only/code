/*
问题描述：用于多组加法计算，用户可以输入计算的组数
时间：2016/10/11
作者：WS
备注：题目中说的32位不太理解 
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
