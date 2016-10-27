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

void wordcount(fstream &outfile);  
int main()
{
	char filename[256]; 
	int n=0;
    
    cout<<"Please input your filename:"<<endl; //输入要统计的文本的绝对路径
    cin.getline(filename,256);
    
    fstream outfile(filename,ios::in);                         //打开文件 
	wordcount(outfile);
	return 0;
}

void wordcount(fstream &outfile)
{
	int n=0;
	char ch;
	while(outfile.get(ch))
  	{   
  	    if(ch=' ')
  	    
		cout<<ch<<endl;       
    }

  
}

