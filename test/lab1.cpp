/*
�����������㷨���۵�һ����ҵ�����������
ʱ�䣺2016/10/21
���ߣ�WS
��ע��1.���⣺��ô���㵥����
      2.���⣺��ô��ÿ�����ʵ��ַ���ʾ���� 
*/
#include<string>                     //�����ַ���������õ�ͷ�ļ� 
#include<iostream>
using namespace std;

int main()
{
	string s;
	cout<<"Plaese enter S:";
	getline(cin,s);
	int n;
	n=s.length();
	int word_num=0;
	for(int i=0; i<n; i++)
	{
		if(s[i]<48||s[i]>57){
			if(s[i+1]==' '||s[i+1]=='.')
			{
				word_num++;
			}
		}
	} 
	cout<<word_num;                    //���㵥���� 
	return 0;
} 
