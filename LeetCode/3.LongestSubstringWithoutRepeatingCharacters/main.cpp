#include <iostream>
#include <vector>
#include <string>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    vector<int> dict(256, -1);
    int ansLen = 0, start = -1;
    for (int i = 0; i < s.length(); i++)
    {
        if (dict[s[i]] > start) // ���ظ�
            start = dict[s[i]]; // ������㵽�ظ�λ��
        dict[s[i]] = i;
        ansLen = max(ansLen, i - start);    // ά�� ������Ӵ��ĳ���
    }
    return ansLen;
}

int main()
{
    cout << lengthOfLongestSubstring("abcabcbb") << endl;
    cout << lengthOfLongestSubstring("bbbbbb") << endl;
    cout << lengthOfLongestSubstring("pwwkew") << endl;
    return 0;
}
