#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**<
unordered_map ������Ч����ߣ��� map ������Ч�ʽϵ͡����� map �ṩ���ȶ�Ч�ʲ������������С�
    map ռ�õ��ڴ�� unordered_map �ͣ� ���� unordered_map ռ�õ��ڴ������Ա��������ġ�
    ���ԣ���Ҫ�������������ٲ���ɾ�����������Ըߵ��ڴ�ʱ�� unordered_map�� ���������ȶ�����ɾ��
    Ч�ʣ��ڴ������ʱ�� map. */
vector<int> twoSum(vector<int> &numbers, int target)
{
    // �����Ŀ�Ĺؼ����ڣ� ���� vector��ֵ�����±��ӳ�䡣
    unordered_map<int, int> hash;
    vector<int> result;
    for (size_t i = 0; i < numbers.size(); i++)
    {
        int numberToFind = target - numbers[i];

        // ����ҵ�Ŀ��ֵ���������ǵ��±�
        if (hash.find(numberToFind) != hash.end())
        {
            result.push_back(hash[numberToFind]);
            result.push_back(i);
            return result;
        }
        // û���ҵ���Ӧ�����֣�������ӽ� hash
        hash[numbers[i]] = i;
    }
    return result;
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
