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
#include<vector>
//#include<hash_map>
using namespace std;
//using namespace stdext;

void wordcount(fstream &outfile);  
int main()
{
	char filename[256]; 
	int n=0;
    
    cout<<"Please input your filename:"<<endl; //����Ҫͳ�Ƶ��ı��ľ���·��
    cin.getline(filename,256);
    
    fstream outfile(filename,ios::in);                         //���ļ� 
	wordcount(outfile);
	return 0;
}

class word {
//public:
//	void 
private:
	char w[64];
	int sum;
    vector<int>add(sum);
};

void wordcount(fstream &outfile)
{
	int n=0;
	char ch;
	//string s;
	char word[64];
	while(outfile.get(ch))
  	{   
  	    int i=0;
  	    if(ch!=' ')
  	    {
  	    
  	    }
  	    
		cout<<ch;       
    }

  
}

