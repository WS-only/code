/*
算法：insert_sort 
题目描述：详细见实验一文件，需要输出output.dat文件
时间：2016/10/21 
备注： 问题1,文件的读取和写
       问题2，怎样表示单词
	   问题3，怎么把每个单词，出现的次数，出现的位置联系在一起 
*/ 
#include <fstream>        //文件读和写 
#include <iostream>
#include<string>          //字符串 
#include<map>
#include<utility>      
#include<vector>
#include<cctype>          //检测字母函数所用的头文件 
using namespace std;
typedef vector<int>::iterator vt;
typedef vector<pair<string, vector<int> > > se;
typedef pair<string, vector<int> > pr;
typedef vector<pair<string, vector<int> > >::iterator se_t;
typedef map<string, vector<int> > mp;
typedef map<string, vector<int> > ::iterator mpt;
typedef vector<string>::iterator vs;
/* compare函数比较两个单词大小，规则为若单词出现的次数大则对应的单词大，若出现的单词的次数
相等则单词的字典排序小的单词大*/
bool compare(pr const &p1, pr const &p2)
{

	if (p1.second[0] > p2.second[0] || (p1.second[0] == p2.second[0] && p1.first<p2.first))
		return true;
	else
		return false;

}
//元素交换函数，元素类型为pair<string,vector<int>>
void swap(pr  &p1, pr &p2)
{
	pr temp;
	temp = p1;
	p1 = p2;
	p2 = temp;
}
//插入排序（伪代码见课本） 
void insert_sort(se &seq)
{
	pair<string, vector<int> > sr;//保存要排序的元素的变量
	int i, j;
	for (i = 1; i != seq.size(); i++)
	{
		j = i;
		if (compare(seq[i], seq[i - 1]))
		{
			sr = seq[i];
			while ((j - 1>-1) && compare(sr, seq[j - 1]))//大于之前的元素，则j--
			{
				seq[j] = seq[j - 1];
				j--;
			}
			seq[j] = sr;

		}

	}

}
void write_out(se & seq)
{
	for (se_t itor = seq.begin(); itor != seq.end(); itor++)
	{
		cout << itor->first << " ";
		for (vt iter = itor->second.begin(); iter != itor->second.end(); iter++)
			cout << *iter << " ";
		cout << endl;
	}

}
int main(void)
{

	ifstream  infile;
	string filename;
	string str, Ste;
	char ch;
	int i = 1, count = 0;
	mp M;
	vs it;
	se_t set, s_i;
	vector<int> tm;
	vector<string> vec;
	cin >> filename;
	infile.open(filename.c_str());
	if (!infile)
	{
		cerr << "error:unable open file" << filename << endl;
	}

	while (!infile.eof())
	{
		infile.get(ch);//从文件中取出字符
		if (ch > -1 && ch < 127)
		{
			if (isalpha(ch))//判断是否为大小写字母，并用string类存储从文件中读出的单词
				Ste += ch;
			else if (ch == '-')//判断各种特殊字符
			{
				if (Ste.begin() != Ste.end() && isalpha(*(Ste.begin()))&&*(Ste.end()-1)!='-')
					Ste += ch;
			}
			else if (ch == 39)
			{
				if (Ste.begin() != Ste.end() && isalpha(*(Ste.begin())))
					Ste += ch;
			}
			else if (ch == '/')
			{
				if (Ste.begin() != Ste.end() && isalpha(*(Ste.begin())))
					Ste += ch;
			}
			else
			{
				if (Ste.begin() != Ste.end())//若取出单词将单词存入map类型的数据结构中
				{
					if (*(Ste.end() - 1) == '-' || *(Ste.end() - 1) == 39 || *(Ste.end() - 1) == '/')
					{
						Ste.erase(Ste.end() - 1);
					}
					count++;
					if (M[Ste].begin() == M[Ste].end())//将单词出现的次数以及位置存入vector向量中
					{
						M[Ste].push_back(1);
						M[Ste].push_back(count);
					}
					else
					{
						M[Ste].push_back(count);
						M[Ste][0]++;
					}
					Ste.clear();
				}
			}
		}
	}
	infile.close();
	se sequence;
	mpt itor;
	for (itor = M.begin(); itor != M.end(); itor++)
		sequence.push_back(*itor);

	insert_sort(sequence);
	ofstream outfile("output.txt");
	outfile << count << "\n";
	for (se::iterator itor = sequence.begin(); itor != sequence.end(); itor++)
	{

		outfile << itor->first << " ";
		for (vt iter = itor->second.begin(); iter != itor->second.end(); iter++)
		if (iter != itor->second.end() - 1)
			outfile << *iter << " ";
		else
			outfile << *iter << "\n";

	}
	outfile << flush;
	outfile.close();
    return 0;
}
