## 两个链表的第一个公共结点

### 题目描述：
输入两个链表， 找出它们的第一个公共结点。 

### 解题思路：
1. 先计算出两个链表的长度， Len1, Len2
2. 长链表先走 |Len1 - Len2|, 然后两个链表一起往后走，第一次相交的点即为第一个公共结点。 
