/********
问题描述：计算SUM(n) = 1 + 2 + 3 + ... + n. 
时间：2016/10/10
作者：WS 
**********/

#include<iostream>
using namespace std;
int main()
{
	int n;
	int sum=0;
	cout<<"Please input the value of n:";
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		sum+=i;
	}
	cout<<"sum="<<sum<<endl;
	return 0;
}
