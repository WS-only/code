/*
打开文件部分可以使用 
*/
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

bool isnum_str(char str)  //判断是否是字符或数字
{
  if((str >= 'A' && str <= 'z') || (str >= '0' && str <= '9') )
	  return true;
  else
	  return false;
}

void count(fstream &outfile, int *cnt )  //统计函数
{ char str[256];
  while(outfile.getline(str,256))
  { 
    int tmp = 0;
    
    for(int i = 0; i < strlen(str); i++)
	{
	  if(str[i] == ' ' || str[i] == '.' || str[i] == ',' || str[i] == '?' || str[i] == '!')
		  cnt[1]++;            //统计单词数
	  
	  if(isnum_str(str[i]))
	  { cnt[0]++;   tmp++;}    //统计字符数，tmp局部变量用来区分是不是一个空行。
	}
	
	if(tmp != 0)
	cnt[2]++;                 //统计行数
	tmp = 0;
  }
    
 return ;
}

int main()
{
    char filename[256];
    int cnt[3] = {0};
    
    
    cout<<"please input your filename:"<<endl; //输入要统计的文本的绝对路径
    cin.getline(filename,256);
	
    fstream outfile(filename,ios::in);
    count(outfile,cnt);
    //outfile<<"character:"<<cnt[0]<<"words:"<<cnt[1]<<"lines:"<<cnt[2]<<endl; //不知道这一行为啥输入不到文本，期待学习
	cout<<"characters: "<<cnt[0]<<endl;
	cout<<"words:"<<cnt[1]<<endl;
	cout<<"lines:"<<cnt[2]<<endl;
    outfile.close();
return 0;

}
