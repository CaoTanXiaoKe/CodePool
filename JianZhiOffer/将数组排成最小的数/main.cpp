#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
/*
�� vector �����ڵ����ݽ������� ���� �� a �� b תΪ string ��
�� a + b < b + a  a ����ǰ�Ĺ���
�� 21 2 ��Ϊ 212 < 221 ���� ����Ϊ 21 2
to_string() ���Խ� int ת��Ϊ string
*/
class Solution {
    static bool cmp(int a, int b) {
        string A = "";
        string B = "";
        A += a;
        A += b;
        B += b;
        B += a;

        return A < B;
    }
public:
    string PrintMinNumber(vector<int> numbers)
    {
        string answer = "";
        sort(numbers.begin(), numbers.end(), cmp);
        for (int i = 0; i < numbers.size(); i++)
            answer += numbers[i];

        return answer;
    }

};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
