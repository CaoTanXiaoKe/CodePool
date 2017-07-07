#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x), left(NULL), right(NULL) {}
};

// �������
void preOrder(TreeNode* root)
{
    if(root == NULL)
        return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// �������
void inOrder(TreeNode* root)
{
    if(root == NULL)
        return;
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}

// �������
void lastOrder(TreeNode* root)
{
    if(root == NULL)
        return;
    lastOrder(root->left);
    lastOrder(root->right);
    cout << root->val << " ";
}

// �ǵݹ�д��
// ��������� ��ջ˳��  ������ -> ������ -> ��
//            ��ջ˳��  �� -> ������ -> ������
vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> temp;
        if(root == NULL)
            return res;
        temp.push(root);
        while(!temp.empty())
        {
            TreeNode* pos = temp.top();
            temp.pop();
            res.push_back(pos->val);
            if(pos->right != NULL)
                temp.push(pos->right);
            if(pos->left != NULL)
                temp.push(pos->left);
        }
        return res;
}

// �������
// ��ջ˳�� ������ -> �� -> ������
// ֻ�е��������Ѿ�������󣬲��ܷ��ʸ��ڵ�
/*
    ������һ�ڵ� P
    1)  �������Ӳ�Ϊ�գ��� P ��ջ���� P ��������Ϊ��ǰ P ,
        Ȼ��Ե�ǰ P �ٽ�����ͬ�Ĵ���
    2)  ��������Ϊ�գ���ȡջ��Ԫ�ز����г�ջ���������ʸ�ջ���ڵ㣬
        Ȼ�󽫵�ǰ P ��Ϊջ���ڵ���Һ��ӣ�
    3)  ֱ�� P Ϊ NULL ����ջΪ�������������
*/
vector<int> inOrderTraversal(TreeNode* root){
    vector<int> res;
    stack<TreeNode*> temp;
    if(root == NULL)
        return res;
    TreeNode* pos = root;
    while(!temp.empty() || pos != NULL)
    {
        if(pos != NULL){
            // push ��������ջ
            temp.push(pos);
            pos = pos->left;
        }
        else
        {
            pos = temp.top();
            temp.pop();
            res.push_back(pos->val);
            pos = pos->right;
        }
    }
    return res;
}

// �������
// ����ջ����Ȼ���������������������
// Ҫ�������ʸ��ڵ㣬 �����ʸø��ڵ�ʱ�������������������������
// ����ֻ��Ҫ��֤����ĳһ�ڵ�ʱ���ýڵ���������Ѿ������ʣ� ������Ҫ
// ���ýڵ�����ѹ��ջ��
/*
������һ��� P, ������ջ�� Ȼ������������һֱ���������� ֱ��������û�����ӵĽ�㣬
��ʱ�ý�������ջ�������Ǵ�ʱ���ܽ����ջ�����ʣ���Ϊ���Һ��ӻ�û�б����ʡ�
���Խ�����������ͬ�Ĺ������������������ͬ�Ĵ��������������Һ���ʱ���ý���ֳ�����
ջ������ʱ���Խ����ջ�����ʡ� �����ͱ�֤����ȷ�ķ���˳�� ���Կ���������������У�
ÿ����㶼���γ�����ջ��������ֻ�еڶ��γ�����ջ��ʱ�����ܷ�������
*/
 vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> tmp;
        if(root == NULL)
            return res;
        TreeNode* pos = root;   // ��¼���ڷ��ʵĽ��
        TreeNode* pre = NULL;   // ��¼ǰһ�����ʵĽ��
        do
        {
            while(pos != NULL)      // ����������㶼ѹ��ջ
            {
                tmp.push(pos);
                pos = pos->left;
            }
            pre = NULL;             // ����ѹ��󣬳�ʼ��ǰһ�����ʽ��Ϊ NULL
            while(!tmp.empty())
            {
                pos = tmp.top();
                tmp.pop();
                if(pos->right == pre)       // �Һ����Ѿ�������
                {
                    res.push_back(pos->val);    // �Һ����Ѿ������ʣ����Է��ʸý��
                    pre = pos;      // ��¼�ոշ��ʵĽ��
                }
                else
                {
                    tmp.push(pos);  // ��һ�η��ʸý�㣬�ٴη���ջ��
                    pos = pos->right;
                    break;
                }
            }
        } while(!tmp.empty());

        return res;
    }
int main()
{
    return 0;
}
