/*
��������������һ�����У�����˳�������ĺͣ��������������ĺͣ��ӵڼ���Ԫ�ؿ�ʼ���ڼ���Ԫ�ؽ���
          �û��������ò���������
ʱ�䣺2016/10/17
���ߣ�WS
��ע��10/12:δ��ɡ�����������岻�� 
      10/17:��ɣ�������ȷ�� 
*/

#include<iostream>
using namespace std;

int main()
{
	int n;
	int m;
	cout<<"Please input the number of cases(1~20):";
	cin>>n;
	int sum[20],min[20],max[20];        //�趨�������飬�ֱ��Ų�ͬcase��max_sum,��ʼλ�ã���ֹλ�� 
	int arr[100];                       //���ÿ��case�µ����ݣ���Ϊ����Ҫ��������Է�������������ʹ�ã� 
	int temp;                           //������ʱ��max_sum 
	for(int i=1 ;i<=n ;i++)             //�����������ݼ����� 
	{
		cin>>m;
		for(int j=0; j<m ;j++)
		{
			cin>>arr[j];
		}
		sum[i]=0;
		for(int p=0; p<m; p++)            //p,q����ʾ��ʱ����ĵ�ַλ 
		{
			temp=arr[p];                  //�㷨��Ҫ�Ǹ�sum����ֵ��Ȼ����temp�Ƚϴ�С����tempС������ֵ�� 
			for(int q=p+1; q<m; q++)      //���μ���ӵ�pλ��ʼ��ÿ�μ��Ϻ�һλ��tempֵ��Ȼ��Ƚϣ� 
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
	for(int i=1; i<=n; i++)                //������ݣ�������һ��FORѭ�������������ʽ�� 
	{
		cout<<"case "<<i<<":"<<endl;
		cout<<sum[i]<<" "<<min[i]<<" "<<max[i]<<endl;
	}
	return 0;
} 
