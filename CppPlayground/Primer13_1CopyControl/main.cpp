#include <iostream>
#include <vector>
using namespace std;

/************************************************
        ��⿽�����Ƴ�Ա����������
************************************************/
struct X
{
    X() { cout << "X()" << endl; }
    X(const X&) { cout << "X(const X&)" << endl; }
    X& operator=(const X&){ cout << "X& operator=(const X&)" << endl; return *this; }
    ~X(){ cout << "~X()" << endl; }
};

void refX(X &x1)
{

}

void valX(X x1)
{

}

int main()
{
    X x1;
    //vector<X> vec;            // ����
    //vec.push_back(x1);

    //X x2(x1);         // ֱ�ӳ�ʼ��
    //X x3=x1;          // ���������ʼ��
    //X x4;             // ������ֵ
    //x4 = x1;
    //refX(x1);         // ����
    valX(x1);         // ֵ���� -->��������
    //X *x7 = new X(x1);
    //delete x7;
    cout << "Hello world!" << endl;
    return 0;
}
