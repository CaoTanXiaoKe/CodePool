## 把数组排成最小的数

### 题目描述：
输入一个正整数数组， 把数组里所有数字拼接起来排成一个数， 打印能拼接出的所有数字中最小的一个。 例如输入数组{3， 32， 321}. 则打印出这三个数字能排成的最小数字为 321323. 

### 解题思路：
1. 首先确定的是，一定需要排序。在排序算法上做文章。 
2. 考虑两个数的情况， 计算出这两个数两种排列方式那种最小，做成比较函数。
3. 考虑三个数的情况，比较函数好像也适用。推广到 n 个数。 
