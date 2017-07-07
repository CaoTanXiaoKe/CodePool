// ���δʹ�õ��ڴ���䷽ʽ
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
const int QSize = 3;    // �����ӵ�еĴ洢��������

struct event
{
    int val;
    int id;
    event(int x, int y):val(x), id(y) { }
};

bool operator<(const event &a, const event &b)
{
    return a.id > b.id;
}


int main()
{
    vector<int> work;
    int m;
    cout << "������ҵ����˳��\n";
    while(cin >> m)
    {
        work.push_back(m);
    }
    stack <event> temp;
    int flag[100];
    memset(flag, 0, sizeof(flag));
    priority_queue<event> qq;
    int losePage = 0;
    for(int i = 0; i < work.size(); i++)
    {
        if(qq.size() < QSize && flag[work[i]]==0)
        {
            qq.push(event(work[i],i));
            flag[work[i]]=1;
        }
        if(flag[work[i]]==0)
        {
            cout << "����ȱҳ����ҳ�棺" << qq.top().val << "����" << endl;
            losePage++;
            flag[qq.top().val] = 0;
            qq.pop();
            qq.push(event(work[i],i));
            flag[work[i]] = 1;
        }
        if(flag[work[i]]==1)
        {
            // ����
            while(qq.top().val != work[i])
            {
                temp.push(qq.top());
                qq.pop();
            }
            qq.pop();
            qq.push(event(work[i],i));
            while(!temp.empty())
            {
                qq.push(temp.top());
                temp.pop();
            }
        }
    }
    cout << "ȱҳ��Ϊ��" << losePage << "/" << work.size() << endl;
    return 0;
}
