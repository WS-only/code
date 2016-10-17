/*
问题描述：给出一个数列，计算顺序中最大的和，输出结果包括最大的和，从第几个元素开始，第几个元素结束
          用户可以设置测试组数。
时间：2016/10/17
作者：WS
备注：10/12:未完成。数组个数定义不会 
      10/17:完成，运行正确。 
*/

#include<iostream>
using namespace std;

int main()
{
	int n;
	int m;
	cout<<"Please input the number of cases(1~20):";
	cin>>n;
	int sum[20],min[20],max[20];        //设定三个数组，分别存放不同case的max_sum,起始位置，终止位置 
	int arr[100];                       //存放每种case下的数据（因为不需要输出，可以反复擦除，重新使用） 
	int temp;                           //用作临时性max_sum 
	for(int i=1 ;i<=n ;i++)             //进行输入数据及计算 
	{
		cin>>m;
		for(int j=0; j<m ;j++)
		{
			cin>>arr[j];
		}
		sum[i]=0;
		for(int p=0; p<m; p++)            //p,q都表示临时数组的地址位 
		{
			temp=arr[p];                  //算法主要是给sum赋初值，然后与temp比较大小，比temp小交换数值； 
			for(int q=p+1; q<m; q++)      //依次计算从第p位开始，每次加上后一位的temp值，然后比较； 
			{
				temp=temp+arr[q];
				if(sum[i]<temp)
				{
					sum[i]=temp;
					min[i]=p+1;
					max[i]=q+1;
				}
			}
		}
		
	}
	for(int i=1; i<=n; i++)                //输出数据（放在上一个FOR循环不符合输出格式） 
	{
		cout<<"case "<<i<<":"<<endl;
		cout<<sum[i]<<" "<<min[i]<<" "<<max[i]<<endl;
	}
	return 0;
} 
