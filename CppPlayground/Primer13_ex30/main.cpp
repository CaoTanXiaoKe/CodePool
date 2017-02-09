#include <iostream>
#include <string>
using namespace std;

/**********************************************************
Question Description:
 Write and test a swap function for your value like version of
HasPtr(Primer13_2_1ClassThatLikeValues). Give your swap a print
 statement that notes when it is executed.
***********************************************************/
class HasPtr
{
    friend void swap(HasPtr&, HasPtr&);
public:
    HasPtr(const std::string &s = std::string()):
        ps(new std::string(s)), i(0) { }
    // �� ps ָ��� string, ÿ�� HasPtr �������Լ��Ŀ���
    HasPtr(const HasPtr& p) : ps(new std::string(*p.ps)), i(p.i) { } // �������캯��
    // ������ֵ����
    HasPtr& operator=(const HasPtr& p);
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

inline void swap(HasPtr&lhs, HasPtr&rhs)
{
    using std::swap;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
    cout << "I have run swap(HasPtr&, HasPtr&)" << endl;
}
// ������ֵ������ʵ��
HasPtr& HasPtr::operator=(const HasPtr &rhs)
{
    auto newp = new string(*rhs.ps);    // �����ײ� string
    delete ps;              // �ͷž��ڴ�
    ps = newp;              // ���Ҳ�������󿽱����ݵ�������
    i = rhs.i;
    return *this;           // ���ر�����
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
    HasPtr hp2("So Fun");
    hp1.display(cout);
    hp2.display(cout);
    swap(hp1, hp2);
    hp1.display(cout);
    hp2.display(cout);
    return 0;
}
