/*
������룬������в����� 
*/
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
#define M 20000
//���µ��ʸ���

typedef struct
{
   char danci[19];//���浥��??
   int count;//��¼���ʸ���,������ּ���??
}sq;


int main()
{
    sq word[M]; 
    sq t_word;
    int K,n=0,i,j;

    FILE *fp;
    char ch;
    fp=fopen("E://1ѧϰ//������//�㷨//ʵ��//input.dat","r");//��ȡ�ļ������Ϊ��Ҫ��ȡ���ļ��ľ���·��??
    cout <<"ͳ���ļ���Ƶ����ߵ�ʮ������";
    while (!feof(fp))//feof()����Ƿ�ﵽ�ļ�β��??
   {
      ch=getc(fp);//��ȡ��ǰ�ַ�??
	  if(ch==' '||ch==10)
      {//ASCLL����10Ϊ���з���������Ϊ�����ո���������??
         continue;
      }
      if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))//����һ������?
	  {
	  K=0;
      t_word.count=1;
      while((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch=='\''))
      {
	  if(ch>='A'&&ch<='Z')
	  {ch+=32;//ת����Сд??
	  t_word.danci[K++]=ch;//�ѵ�ǰ��ĸ��������??
      ch=getc(fp);
      }
      t_word.danci[K++]='\0';//������־\0??
	  //һ�����ʽ���??
	  j=n;


      for(i=0;i<j;i++)//��ǰ��ĵ��ʱȽ�??
      {
	  if(strcmp(t_word.danci,word[i].danci)==0)//����е�����ͬ??
      {
	  word[i].count++;//����൥�ʼ�1??
      break;
      }
	  }


      if(n==0||i==j)//ǰ�����û����ͬ�ĵ���??
      {
	  word[n]=t_word;//��Ϊ���൥�ʿ����µ�Ԫ??
	  n++;
	  }
	  }
   }

//���Ƶ����ߵ�ʮ������??
    sq frequency_max[11];
    sq temp;
    for(i=0;i<10;i++)
    {
        frequency_max[i]=word[i];//��ʼ��Ƶ����ߵ�ʮ������Ϊǰʮ������??
    }
//ǰʮ������??
//ð������??

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
        cout<<setiosflags(ios::left)<<setw(10)<<frequency_max[i].danci<<frequency_max[i].count<<endl;//setw()����������Ĭ���Ҷ���??
    }
}
    return 0;
}
