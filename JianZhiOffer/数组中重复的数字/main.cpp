#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        vector<int> dic(length, 0);
        if (length <= 1)
            return false;
        for(int i = 0; i < length; i++)
        {
            if(dic[numbers[i]] == 1)
            {
                *duplication = numbers[i];
                return true;
            }
            dic[numbers[i]] = 1;
        }

        return false;
    }
};

// �������¿ռ䣨���飬bool���飩�����Žⷨ
// ���ǿ��ܳ�������Խ��
class Solution2 {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if(length <= 1)
            return false;
        for(int i = 0; i < length; i++)
        {
            int index = numbers[i];
            if(index >= length)
                index -= length;

            if(numbers[index] >= length)
            {
            	*duplication = index;
                return true;
            }

            numbers[index] += length;
        }

        return false;
    }
};

// �� - length ���� + length ��������Խ��
class Solution3 {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if(length <= 1)
            return false;
        for(int i = 0; i < length; i++)
        {
            int index = numbers[i];
            if(index < 0)
                index += length;

            if(numbers[index] < 0)
            {
            	*duplication = index;
                return true;
            }

            numbers[index] -= length;
        }

        return false;
    }
};

// �� ���� -1 ���� ��������Խ��
class Solution4 {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        if(length <= 1)
            return false;
        for(int i = 0; i < length; i++)
        {
            int index = numbers[i];
            if(index < 0)
                index *= -1;

            if(numbers[index] < 0)
            {
            	*duplication = index;
                return true;
            }

            numbers[index] *= -1;
        }

        return false;
    }
};
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
