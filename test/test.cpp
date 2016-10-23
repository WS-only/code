//网络代码，输出单词带标点 
#include<iostream> 
#include<string> 
#include<map> 
#include<vector> 
#include <algorithm> 
#include <functional> 
using namespace std; 
class wordcount 
{ 
public: 
string word; 
int times; 
wordcount(string s,int t) 
{ 
word=s; 
times=t; 
} 
int operator < (wordcount &w){return times<w.times;} 
int operator > (wordcount &w){return times>w.times;} 
}; 
int UDgreater ( wordcount elem1, wordcount elem2 ) 
{ 
return elem1 > elem2; 
} 
int main() 
{ 
string s; 
map<string,int> word; 
vector<wordcount> word_count; 
while(cin>>s)//ctrl+z结束 
word[s]++; 
for(map<string,int>::iterator itr=word.begin();itr!=word.end();itr++) 
{ 
wordcount w(itr->first,itr->second); 
word_count.push_back(w); 
} 
sort(word_count.begin(),word_count.end(),UDgreater); 
for(vector<wordcount>::size_type i=0;i<word_count.size();i++) 
{ 
cout<<word_count[i].word<<" "<<word_count[i].times<<endl; 
} 
return 0;
}
