/*
�����������㷨���۵�һ����ҵ�����������
ʱ�䣺2016/10/21
���ߣ�WS
��ע��1.���⣺��ô���㵥����
      2.���⣺��ô��ÿ�����ʵ��ַ���ʾ����
	  3.���⣺��ô�Ѳ�ͬ�����ݷ���һ�� 
*/
#include<string>                     //�����ַ���������õ�ͷ�ļ� 
#include<iostream>
#include<fstream>
using namespace std;

int wordcount(fstream &outfile);  
int main()
{
	//string s; 
	//cout<<"Please enter s:";
	char filename[256];
    
    cout<<"please input your filename:"<<endl; //����Ҫͳ�Ƶ��ı��ľ���·��
    cin.getline(filename,256);
	
    fstream outfile(filename,ios::in);
	//getline(cin,s);
	wordcount(outfile);                    //���㵥���� 
	outfile.close();
	return 0;
} 

int wordcount(fstream &outfile)
{
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
	cout<<word_num<<endl;
	
} 
