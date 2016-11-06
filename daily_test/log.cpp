#include<iostream>
#include<cmath>
using namespace std; 
int main()
{
	double n=2;
	while(n<8*log2(n))
	      n++;
    cout<<"1<n<"<<n-1<<endl;
	return 0;
}
