#include <iostream>
#include <string>
using namespace std;

/**********************************************************
                        ֪ʶ���ܽ�
### ��Ϊ��ֵ����(Classes that act like values)
/CopyConstructor�е� HasPtr �� ���ĳ� ��Ϊ��ֵ����
* ����һ���������캯������� string �Ŀ����������ǿ���ָ��
* ����һ�������������ͷ� string
* ����һ��������ֵ��������ͷŶ���ǰ�� string�� �����Ҳ�
  ������󿽱� string

#### ��ֵ������ֵ�����
    ��ֵ�����ͨ����������������͹��캯���Ĳ�������������
    ��������ֵ�����������������������Դ�� ���ƿ�������
    ��������ֵ��������Ҳ�������󿽱����ݡ�����Ҫ������Щ
    ����Ҫ����ȷ��˳����У���ʹ��һ��������������Ҳ��
    ֤��ȷ�� ���ң�����п��ܣ����Ǳ�д�ĸ�ֵ�������Ӧ����
    �쳣��ȫ�� ---- ���쳣����ʱ�ܽ���������������һ����
    �����״̬��

��ǿ��һ�£������д��ֵ�����ʱ����������Ҫ��ס��
* �����һ����������������ֵ�������������������
* �������ֵ�������������������Ϳ������캯���Ĺ���

***********************************************************/
class HasPtr
{
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
    HasPtr hp2=hp1; // ������ʼ��
    HasPtr hp3; hp3 = hp1;  // ������ֵ
    hp1.display(cout);
    hp2.display(cout);
    hp3.display(cout);
    return 0;
}
