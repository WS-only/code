/*
�㷨��insert_sort 
��Ŀ��������ϸ��ʵ��һ�ļ�����Ҫ���output.dat�ļ�
ʱ�䣺2016/10/21 
��ע�� ����1,�ļ��Ķ�ȡ��д
       ����2��������ʾ����
	   ����3����ô��ÿ�����ʣ����ֵĴ��������ֵ�λ����ϵ��һ�� 
*/ 
#include <fstream>        //�ļ�����д 
#include <iostream>
#include<string>          //�ַ��� 
#include<map>
#include<utility>      
#include<vector>
#include<cctype>          //�����ĸ�������õ�ͷ�ļ� 
using namespace std;
typedef vector<int>::iterator vt;
typedef vector<pair<string, vector<int> > > se;
typedef pair<string, vector<int> > pr;
typedef vector<pair<string, vector<int> > >::iterator se_t;
typedef map<string, vector<int> > mp;
typedef map<string, vector<int> > ::iterator mpt;
typedef vector<string>::iterator vs;
/* compare�����Ƚ��������ʴ�С������Ϊ�����ʳ��ֵĴ��������Ӧ�ĵ��ʴ������ֵĵ��ʵĴ���
����򵥴ʵ��ֵ�����С�ĵ��ʴ�*/
bool compare(pr const &p1, pr const &p2)
{

	if (p1.second[0] > p2.second[0] || (p1.second[0] == p2.second[0] && p1.first<p2.first))
		return true;
	else
		return false;

}
//Ԫ�ؽ���������Ԫ������Ϊpair<string,vector<int>>
void swap(pr  &p1, pr &p2)
{
	pr temp;
	temp = p1;
	p1 = p2;
	p2 = temp;
}
//��������α������α��� 
void insert_sort(se &seq)
{
	pair<string, vector<int> > sr;//����Ҫ�����Ԫ�صı���
	int i, j;
	for (i = 1; i != seq.size(); i++)
	{
		j = i;
		if (compare(seq[i], seq[i - 1]))
		{
			sr = seq[i];
			while ((j - 1>-1) && compare(sr, seq[j - 1]))//����֮ǰ��Ԫ�أ���j--
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
		infile.get(ch);//���ļ���ȡ���ַ�
		if (ch > -1 && ch < 127)
		{
			if (isalpha(ch))//�ж��Ƿ�Ϊ��Сд��ĸ������string��洢���ļ��ж����ĵ���
				Ste += ch;
			else if (ch == '-')//�жϸ��������ַ�
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
				if (Ste.begin() != Ste.end())//��ȡ�����ʽ����ʴ���map���͵����ݽṹ��
				{
					if (*(Ste.end() - 1) == '-' || *(Ste.end() - 1) == 39 || *(Ste.end() - 1) == '/')
					{
						Ste.erase(Ste.end() - 1);
					}
					count++;
					if (M[Ste].begin() == M[Ste].end())//�����ʳ��ֵĴ����Լ�λ�ô���vector������
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
