/*
���ļ����ֿ���ʹ�� 
*/
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

bool isnum_str(char str)  //�ж��Ƿ����ַ�������
{
  if((str >= 'A' && str <= 'z') || (str >= '0' && str <= '9') )
	  return true;
  else
	  return false;
}

void count(fstream &outfile, int *cnt )  //ͳ�ƺ���
{ char str[256];
  while(outfile.getline(str,256))
  { 
    int tmp = 0;
    
    for(int i = 0; i < strlen(str); i++)
	{
	  if(str[i] == ' ' || str[i] == '.' || str[i] == ',' || str[i] == '?' || str[i] == '!')
		  cnt[1]++;            //ͳ�Ƶ�����
	  
	  if(isnum_str(str[i]))
	  { cnt[0]++;   tmp++;}    //ͳ���ַ�����tmp�ֲ��������������ǲ���һ�����С�
	}
	
	if(tmp != 0)
	cnt[2]++;                 //ͳ������
	tmp = 0;
  }
    
 return ;
}

int main()
{
    char filename[256];
    int cnt[3] = {0};
    
    
    cout<<"please input your filename:"<<endl; //����Ҫͳ�Ƶ��ı��ľ���·��
    cin.getline(filename,256);
	
    fstream outfile(filename,ios::in);
    count(outfile,cnt);
    //outfile<<"character:"<<cnt[0]<<"words:"<<cnt[1]<<"lines:"<<cnt[2]<<endl; //��֪����һ��Ϊɶ���벻���ı����ڴ�ѧϰ
	cout<<"characters: "<<cnt[0]<<endl;
	cout<<"words:"<<cnt[1]<<endl;
	cout<<"lines:"<<cnt[2]<<endl;
    outfile.close();
return 0;

}
