#include <iostream>
using namespace std;
using namespace myNum;   //��д�����ռ�Ĺؼ���
namespace myNum
{
    int x = 105;
}
int main()
{
    // ʹ��bool���Ͷ���isOdd����Ϊ״̬λ
    bool isFlag = false;       
	
	if(myNum::x % 2 == 0)
	{
		//�ı�״̬λ��ֵ��ʹ��Ϊfalse
        isFlag=false;
	}
	else
	{
	    //�ı�״̬λ��ֵ��ʹ��Ϊtrue
        isFlag=true;
	}
    // �ж�״̬λ��ֵ
    using namespace myNum;   //��д�����ռ�Ĺؼ���
	if(isFlag==true)
	{
	// ���״̬λ��ֵΪtrue�����ӡ����x������
        cout<<x<<"������"<<endl;
	}
	else
	{
    // ���״̬λ��ֵΪfalse�����ӡ����x��ż��            
    cout<<x<<"��ż��"<<endl;
    }
    return 0;
}
