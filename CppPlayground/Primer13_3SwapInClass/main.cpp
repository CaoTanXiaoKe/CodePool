#include <iostream>
#include <string>
using namespace std;

/**********************************************************
                        ֪ʶ���ܽ�
### ����֪ʶ��ο� CopyContructor
���˶��忽�����Ƴ�Ա��������Դ����ͨ��������һ����Ϊ swap �ĺ�����
������Щ������Ԫ��˳����㷨һ��ʹ�õ��ࡣ�����㷨����Ҫ��������
Ԫ��ʱ�����swap�� ���ǿ��������Լ��� swap�� ���⣬����swap ����
ͨ���� swap ���������ǵĸ�ֵ�������

***********************************************************/
class HasPtr
{
public:
    // ���ر�׼���ﶨ��� swap
    friend void swap(HasPtr&, HasPtr&);
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) { }
    // �� ps ָ��� string, ÿ�� HasPtr �������Լ��Ŀ���
    HasPtr(const HasPtr& p) : ps(new std::string(*p.ps)), i(p.i) { } // �������캯��
    // �� swap ����ʵ�ֿ�����ֵ�����
    HasPtr& operator=(HasPtr p);  // ע�������õ���ֵ����
    // ���ڵ��Ե� �������
    ostream& display(ostream&);
    ~HasPtr()               // �����ͷ� new ������ڴ����������
    {
        delete ps;
    }
private:
    std::string *ps;
    int i;
};

inline
void swap(HasPtr &lhs, HasPtr&rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);       // ����ָ�룬������ string ����
    swap(lhs.i, rhs.i);         // ���� int ��Ա
}

// �� swap ����ʵ�ֿ�����ֵ�����
HasPtr& HasPtr::operator=(HasPtr rhs)
{
    // ��������������;ֲ����� rhs ������
    swap(*this, rhs);       // rhs ����ָ�򱾶�������ʹ�õ��ڴ�
    return *this;           // rhs �����٣� �Ӷ� delete �� rhs �е�ָ��
}

// ���������ʵ��
ostream& HasPtr::display(ostream&os)
{
    os << *(this->ps) << "\t" << this->i << endl;
    return os;
}
int main()
{
    string s("copy constructor");
    HasPtr hp1(s);
    HasPtr hp2=hp1; // ������ʼ��
    HasPtr hp3; hp3 = hp1;  // ������ֵ
    hp1.display(cout);
    hp2.display(cout);
    hp3.display(cout);
    return 0;
}
