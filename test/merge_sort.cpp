//#include "stdafx.h"
#include <fstream>
#include <iostream>
#include<string>
#include<map>
#include<utility>
#include<vector>
#include<cctype>
using namespace std;
typedef vector<int>::iterator vt;
typedef vector<pair<string, vector<int> > > se;
typedef pair<string, vector<int> > pr;
typedef vector<pair<string, vector<int> > >::iterator se_t;
typedef map<string, vector<int> > mp;
typedef map<string, vector<int> >::iterator mpt;
typedef vector<string>::iterator vs;
bool compare(pr const &p1, pr const &p2)
{

	if (p1.second[0] > p2.second[0] || (p1.second[0] == p2.second[0] && p1.first<p2.first))
		return true;
	else
		return false;

}
/*void swap(pr  &p1, pr &p2)
{
pr temp;
temp = p1;
p1 = p2;
p2 = temp;
}*/
void sort(se &seq, int p, int r)
{
	int z;
	int i, j;
	se  sep;
	if (r > p){//r>p则将序列一份为二
		z = (p + r) / 2;//取序列中间下标值
		sort(seq, p, z);//递归调用自身，排序范围变成前一半序列
		sort(seq, z + 1, r);//递归调用自身，排序范围变成后一半序列
		i = p; j = z + 1;
		while (i <= z&&j <= r)//基于前面两次调用sort函数使得前一半与后一半是有序序列的前提下，进行归并
		{
			sep.push_back(compare(seq[i], seq[j]) ? seq[i++] : seq[j++]);//用相同类型的vector向量存储归并的序列，两个序列从开始依次比较，
			                                                             //  较大的放入向量中，并且该序列下标变量加一，继续相互比较，直至任一序列达到尾部
		}
		while (i != z + 1)//若其中任一序列中仍有未比较的元素，继续放入向量中
		{
			sep.push_back(seq[i++]);
		}
		while (j != r + 1)
		{
			sep.push_back(seq[j++]);
		}

	}
   else
		sep.push_back(seq[p]);
	se_t itor;
	for (itor = sep.begin(); itor != sep.end(); itor++)//最后将元素从存储变量中重新放回到原向量中，此时序列已是排好序的
		seq[p++] = *itor;

}
void merge_sort(se & seq)//merge_sort排序入口
{
	int p = 0;
	int r = seq.size();
	sort(seq, p, r - 1);
}
void write_out(se & seq)
{
	int count = 0;
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
		infile.get(ch);
		if (ch > -1 && ch < 127)
		{
			if (isalpha(ch))
				Ste += ch;
			else if (ch == '-')
			{
				if (Ste.begin() != Ste.end() && isalpha(*(Ste.begin())))
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
				if (Ste.begin() != Ste.end())
				{
					if (*(Ste.end() - 1) == '-' || *(Ste.end() - 1) == 39 || *(Ste.end() - 1) == '/')
					{
						Ste.erase(Ste.end() - 1);
					}
					count++;
					if (M[Ste].begin() == M[Ste].end())
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

	/*cout << "********before merge_sort********" << endl;
	write_out(sequence);
	merge_sort(sequence);
	cout << "********after merge_sort********" << endl;
	write_out(sequence);
	cout << "the total words:" << count << endl;*/
	merge_sort(sequence);
	ofstream outfile("output.dat");
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

