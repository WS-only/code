/*
问题描述：算法导论第一次作业，详情见附件
时间：2016/10/21
作者：WS
备注：1.问题：怎么计算单词数
      2.问题：怎么把每个单词的字符表示出来
	  3.问题：怎么把不同的数据放在一起 
*/
#include<string>                     //输入字符串所需调用的头文件 
#include<iostream>
#include<fstream>
using namespace std;

int wordcount(fstream &outfile);  
int main()
{
	//string s; 
	//cout<<"Please enter s:";
	char filename[256];
    
    cout<<"please input your filename:"<<endl; //输入要统计的文本的绝对路径
    cin.getline(filename,256);
	
    fstream outfile(filename,ios::in);
	//getline(cin,s);
	wordcount(outfile);                    //计算单词数 
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
