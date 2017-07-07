#include <iostream>
using namespace std;

// �ݹ��
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL) { }
};

class Solution {
public:
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL)
            return NULL;
        if(pRootOfTree->left == NULL && pRootOfTree->right == NULL)
            return pRootOfTree;
        // 1. �������������˫��������������ͷ�ڵ�
        TreeNode* left = Convert(pRootOfTree->left);
        TreeNode* pos = left;
        // 2. ��λ��������˫�������һ���ڵ�
        while(pos!=NULL && pos->right != NULL)
            pos = pos->right;
        // 3. �������������Ϊ�յĻ�������ǰ root ׷�ӵ�����������
        if(left != NULL)
        {
            pos->right = pRootOfTree;
            pRootOfTree->left = pos;
        }
        // 4. �������������˫���� ����������ͷ�ڵ�
        TreeNode* right = Convert(pRootOfTree->right);

        // 5. �����������Ϊ�յĻ��� ��������׷�ӵ� root �ڵ�֮��
        if (right != NULL)
        {
            right->left = pRootOfTree;
            pRootOfTree->right = right;
        }

        return left!=NULL ? left : pRootOfTree;
    }
};

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
