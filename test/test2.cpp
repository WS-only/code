/*
网络代码，结果运行不出来 
*/
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
#define M 20000
//文章单词个数

typedef struct
{
   char danci[19];//储存单词??
   int count;//记录单词个数,后面出现几次??
}sq;


int main()
{
    sq word[M]; 
    sq t_word;
    int K,n=0,i,j;

    FILE *fp;
    char ch;
    fp=fopen("E://1学习//大三上//算法//实验//input.dat","r");//读取文件，需改为你要读取的文件的绝对路径??
    cout <<"统计文件下频率最高的十个单词";
    while (!feof(fp))//feof()检测是否达到文件尾部??
   {
      ch=getc(fp);//获取当前字符??
	  if(ch==' '||ch==10)
      {//ASCLL码中10为换行符，此条件为遇到空格或火车则跳过??
         continue;
      }
      if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))//发现一个单词?
	  {
	  K=0;
      t_word.count=1;
      while((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch=='\''))
      {
	  if(ch>='A'&&ch<='Z')
	  {ch+=32;//转换成小写??
	  t_word.danci[K++]=ch;//把当前字母存入数组??
      ch=getc(fp);
      }
      t_word.danci[K++]='\0';//结束标志\0??
	  //一个单词结束??
	  j=n;


      for(i=0;i<j;i++)//与前面的单词比较??
      {
	  if(strcmp(t_word.danci,word[i].danci)==0)//如果有单词相同??
      {
	  word[i].count++;//则此类单词加1??
      break;
      }
	  }


      if(n==0||i==j)//前面如果没有相同的单词??
      {
	  word[n]=t_word;//则为此类单词开辟新单元??
	  n++;
	  }
	  }
   }

//输出频率最高的十个单词??
    sq frequency_max[11];
    sq temp;
    for(i=0;i<10;i++)
    {
        frequency_max[i]=word[i];//初始化频率最高的十个单词为前十个单词??
    }
//前十个排序??
//冒泡排序法??

    for(j=0;j<10;j++)
    for(i=0;i<10-j;i++)
    if(frequency_max[i].count<frequency_max[i+1].count)
    {
     temp=frequency_max[i];
        frequency_max[i]=frequency_max[i+1];
        frequency_max[i+1]=temp;
    }
    for(i=10;i<n;i++)
    {
        if(frequency_max[9].count<word[i].count)
        {
             int a=8;
             while(frequency_max[a].count<word[i].count&&a>=0)
			 {
			 a--;
			 }
			 for(j=9;j>a+1;j--)
			 {
			 frequency_max[j]=frequency_max[j-1];
			 }
			 if(a<0)
			 frequency_max[0]=word[i];
			 else
			 frequency_max[j]=word[i];
	    }
	}
    for(i=0;i<10;i++)
    {
        cout<<setiosflags(ios::left)<<setw(10)<<frequency_max[i].danci<<frequency_max[i].count<<endl;//setw()设置输出域宽，默认右对齐??
    }
}
    return 0;
}
