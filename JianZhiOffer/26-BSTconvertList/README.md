## 二叉搜索树与双向链表

### 题目描述：
输入一棵二叉搜索树， 将该二叉搜索树转换成一个排序的双向链表。 要求不能创建任何新的节点，只能调整树中节点指针的指向。 

### 解题思路： 
递归求解。 
1. 转换左子树，然后遍历左子树，最后一个节点跟根节点互指
2. 转换右子树， 根节点与右子树第一个节点互指。 
