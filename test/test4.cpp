#include<iomanip>
#include<fstream>
void main()
{
　　ofstream f1("e:/code/countword.txt");　　　　　　　　　　　//打开文件用于写，若文件不存在就创建它
　　if(!f1)return;　　　　　　　　　　　　　　　　　//打开文件失败则结束运行
　　f1<<setw(20)<<"姓名："<<"廉东方"<<endl;　　　　 //使用插入运算符写文件内容
　　f1<<setw(20)<<"家庭地址："<<"河南郑州"<<endl;
　　f1.close();　　　　　　　　　　　　　　　　　　 //关闭文件
}
