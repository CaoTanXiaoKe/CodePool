## 链表中倒数第k个结点

### 题目描述：
输入一个链表， 输出该链表中倒数第 k 个结点。 

### 解题思路：
1. 用两个指针， 第一个先走 k 步 
2. 然后第二个指针和第一个指针一起走到第一个指针为 NULL. 

Note: 注意 链表为空， k == 0, k < 0, k 大于链表总长度的情况。 

