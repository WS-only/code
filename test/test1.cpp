//������룬�������ȷ 
#include<iostream>
#include<string>
using namespace std;
int main()
{
	char str[200];
	char *string;
	int i=0,k=0,j;
	char str1[20][10];
	cin.getline(str,200);
	string=str;
	for(;*string!='\0';string++)
	{
	if(*string=='?')
	{
	str1[k][i]='\0';
	i=0;
	k++;
	}
	str1[k][i]=*string;
	i++;
	}
	if((str1[k][i]>'a'&&str1[k][i]<'z')||(str1[k][i]>'A'&&str1[k][i]<'Z'))
	str1[k][i]='\0';
	else
	str1[k][i-1]='\0';
	cout<<"һ����"<<k+1<<"������"<<endl;
	cout<<"�ֱ��ǣ�";
	for(j=0;j<k;j++)
	cout<<str1[j]<<',';
	cout<<str1[j]<<endl;
	return 0;
}
