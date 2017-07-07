#include <iostream>
#include <map>
using namespace std;

struct RandomListNode{
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
        label(x), next(NULL), random(NULL) { }
};

// �ȸ����ٷ���
/*
    1. ����ÿ���ڵ㣬 �磺���ƽڵ� A �õ� A1, ��A1����ڵ� A ����
    2. ��������A1->random = A->random->next (��Ϊÿ��ԭ�ڵ�������ĸ���)
    3. �������ֳ�ԭ����͸��ƺ������
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (!pHead)
            return NULL;
        RandomListNode* currNode = pHead;
        // ���� 1
        while(currNode)
        {
            RandomListNode* node = new RandomListNode(currNode->label);
            node->next = currNode->next;
            currNode->next = node;
            currNode = node->next;
        }

        // ���� 2
        currNode = pHead;
        while(currNode)
        {
            RandomListNode* node = currNode->next;
            if (currNode->random)
            {
                node->random = currNode->random->next;
            }
            currNode = node->next;
        }

        // ���� 3
        RandomListNode* pCloneHead = pHead->next;
        RandomListNode* tmp;
        currNode = pHead;
        // currNode �ֻ���ָ��ԭ�ڵ㣬���ƽڵ㣬��ÿ��һ���ڵ�����
        while(currNode->next)
        {
            tmp = currNode->next;
            currNode->next = tmp->next;
            currNode = tmp;
        }

        return pCloneHead;
    }
};

// �ݹ�
/*
    ����ת��Ϊһ��ͷ�ڵ�ͳ�ȥͷ�ڵ�ʣ�ಿ�֣� ʣ�ಿ�ֲ�����ԭ����һ��
*/
class Solution2 {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(!pHead)
            return NULL;

        // ����һ���½ڵ�
        RandomListNode* pCloneHead = new RandomListNode(pHead->label);
        pCloneHead->next = pHead->next;
        pCloneHead->random = pHead->random;

        // �ݹ������ڵ�
        pCloneHead->next = Clone(pHead->next);
        return pCloneHead;
    }
};

// Hash�� || map
class Solution3 {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (!pHead)
            return NULL;
        map<RandomListNode*, RandomListNode*> mm;
        RandomListNode* pos1 = pHead;
        RandomListNode* pAns = new RandomListNode(pHead->label);
        RandomListNode* pos2 = pAns;
        mm[pos1] = pos2;
        while(pos1)
        {
           	if (pos1->next)
                pos2->next = new RandomListNode(pos1->next->label);
            else
                pos2->next = NULL;
            pos1 = pos1->next;
            pos2 = pos2->next;
            mm[pos1] = pos2;
        }

        pos1 = pHead;
        pos2 = pAns;
        while(pos1)
        {
            pos2->random = mm[pos1->random];
            pos1 = pos1->next;
            pos2 = pos2->next;
        }
        return pAns;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
