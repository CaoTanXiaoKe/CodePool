#include <iostream>
#include <vector>
using namespace std;

// ��������
// ���������ʱ����Ѹ��Ӷ� O(n), �����ź������Ӷ� O(n^2)
void insertSort(int vec[], int len);

// �鲢����

int main()
{
    int A[6] =  {5, 2, 4, 6, 1, 3};
    insertSort(A, 6);
    for(int i = 0; i < 6; i++)
        cout << A[i] << " ";
    cout << endl;
    return 0;
}

void insertSort(int vec[], int len)
{
    for(int j=1; j < len; j++)
    {
        int key = vec[j];
        int i = j - 1;
        while(i>=0 && vec[i] > key)
        {
            vec[i+1] = vec[i];
            i--;
        }
        vec[i+1] = key;
    }
}
