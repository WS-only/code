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

//int wordcount(fstream &outfile);  
int main()
{
	ifstream in;
	string filename; 
    
    cout<<"Please input your filename:"<<endl; //����Ҫͳ�Ƶ��ı��ľ���·��
    getline(cin,filename,'\n');
    
    open(filename);                         //���ļ� 
	
	if(!in)
	{
		cout<<"Error opening file!"<<endl;
		return 1;
	} 
	
	char ch;
	while(!in.eof())
	{
		in.read(&ch,1);
		cout<<ch;
	}
	in.close();
	return 0;
}

/*
int wordcount(string *s)
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
*/
