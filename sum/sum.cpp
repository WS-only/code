/********
��������������SUM(n) = 1 + 2 + 3 + ... + n. 
ʱ�䣺2016/10/10
���ߣ�WS 
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
