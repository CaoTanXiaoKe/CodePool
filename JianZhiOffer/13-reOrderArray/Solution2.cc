/*************************************************************************
* File Name: Solution2.cc
* Author: Chen WenKe
* Email: chenwenke666@gmail.com
* Blog: https://caotanxiaoke.github.io
* Created Time: Wed 19 Jul 2017 04:55:09 AM PDT
*
* Description: 
    调整数组顺序使奇数位于偶数前面。     
 ************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <stdexcept>
#include <cstdio>
#include <cstdlib>
using namespace std;

class Solution
{
public:
    void reOrderArray(vector<int> &array)
    {
        if(array.size() <= 1)
            return; 

        int i = 0; 
        for(i = 0; i < array.size(); i++)
            if(array[i] % 2 == 0)
                break; 
        int j = i + 1; 
        while(j < array.size())
        {
            if(array[j] % 2)
            {
                int key = array[j]; 
                int pos = j; 
                while(pos > i)
                {
                    array[pos] = array[pos-1]; 
                    pos--; 
                }
                array[pos] = key; 
                i++; 
            }
            j++; 
        }
    }
}; 

int main()
{

    return 0; 
}
