#include <iostream>
using namespace std;

/*
1.�Ѷ�Ԫ������ת��������˫������
��Ŀ��
����һ�ö�Ԫ�����������ö�Ԫ������ת����һ�������˫������
Ҫ���ܴ����κ��µĽ�㣬ֻ����ָ���ָ��
10
/ \
6 14
/ \ / \
4 8 12 16
ת����˫������
4=6=8=10=12=14=16��
�������Ƕ���Ķ�Ԫ�������ڵ�����ݽṹ���£�
struct BSTreeNode
{
int m_nValue; // value of node
BSTreeNode *m_pLeft; // left child of node
BSTreeNode *m_pRight; // right child of node
};
*/

struct BSTreeNode
{
    int m_nValue; // value of node
    BSTreeNode *m_pLeft; // left child of node
    BSTreeNode *m_pRight; // right child of node
};

void helper(BSTreeNode* &head, BSTreeNode* &tail, BSTreeNode *root){
    BSTreeNode *lt, *rh;
    if (root == NULL){
        head = NULL, tail = NULL;
        return;
    }
    helper(head, lt, root->m_pLeft);
    helper(rh, tail, root->m_pRight);
    if (lt != NULL)
    {
        lt->m_pRight = root;
        root->m_pLeft = lt;
    }
    else
    {
        head == root;
    }
    if (rh != NULL)
    {
        root->m_pRight = rh;
        rh->m_pLeft = root;
    }
    else
    {
        tail = root;
    }
}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
