/*
问题描述：计算气球中颜色最多的
时间：2016/10/20
作者：WS
备注：1.初步想法定义一个类，类中包含气球个数和颜色； 
*/
#include<iostream>
using namespace std;
int main()
{
	int n;
	cout<<"Please input the value of N:";
	cin>>n;
	char str[15] ;
	for(int i=0; i<15; i++)
	{
		cin>>str[i];
	}
	for(int i=0; i<15; i++)
	{
		cout<<str[i];
	}
	
	return 0;
} 
