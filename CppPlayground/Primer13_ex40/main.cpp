#include <iostream>
#include "StrVec.h"
using namespace std;
/** \brief
Exercise  13.40:  Add  a  constructor  that  takes  an
initializer_list<string> to your StrVec class.
 *
 * ��ֵ���ð󶨵Ķ��ǳ־�ֵ�� ����ֵ���ð���ʱֵ��
 * ��ֵ����ָ��Ҫ�����ٵĶ�����ˣ����ǿ��ԴӰ�
 * ������ֵ���õĶ�����ȡ��״̬��
 * ���ƶ�����֮���ƶ�Դ������뱣����Ч�ģ�������
 * ��״̬�������û����ܶ���ֵ�����κμ��衣
 */

int main()
{
    StrVec sv, sv2{"So", "fun"};
    sv.push_back("So");
    sv.push_back("Good");
    for (auto &m : sv)
        cout << m << " ";
    cout << endl;

    for (auto &m : sv2)
        cout << m << " ";
    cout << endl;

    const int &i = 3;       // �������������ģ� ��Ϊ���ǲ���ͨ�� i �ı���ʱ�� 3 ��ֵ��
    cout << i << endl;
    return 0;
}
