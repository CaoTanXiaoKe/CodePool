// URL: http://www.cnblogs.com/cyjb/p/digitOccurrenceInRegion.html
#include <iostream>
using namespace std;

// �������� X �� 1 - n �г��ֵĴ�����0���⣩
int count(int n, int x);

// �������� 0 �� 1 - n �г��ֵĴ���
int count0(int n);
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

int count(int n, int x)
{
    int cnt = 0, k;
    // i ��ʾ���� �� i λ����
    for (int i = 1; k = n / i; i *= 10)
    {
        // k / 10 Ϊ��λ����
        cnt += (k / 10) * i;
        // ��ǰλ������
        int cur = k % 10;
        if (cur > x)
            cnt += i;
        else if(cur == x)
        {
            // n - k * i Ϊ��λ������
            cnt += n - k * i + 1;
        }
    }
    return cnt;
}

