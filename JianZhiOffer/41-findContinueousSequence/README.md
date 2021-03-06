## 和为 S 的连续正数序列

### 题目描述：
小明很喜欢数学,有一天他在做数学作业时,要求计算出9~16的和,他马上就写出了正确答案是100。但是他并不满足于此,他在想究竟有多少种连续的正数序列的和为100(至少包括两个数)。没多久,他就得到另一组连续正数和为100的序列:18,19,20,21,22。现在把问题交给你,你能不能也很快的找出所有和为S的连续正数序列? Good Luck!

### 输出描述:
> 输出所有和为S的连续正数序列。序列内按照从小至大的顺序，序列间按照开始数字从小到大的顺序

### 解题思路：
推导公式：
1. m + (m+1) + (m+2) + ... + n = S  ==> (m + n)(n - m + 1) = 2*S
2. 假设 p*q = 2*S (q >= p), 则可以令： (m + n) = q, (n - m + 1) = p
3. 解得： 2 * m = p - q + 1,  2 * n = p + q - 1
4. 从 2 到 sqrt(2*S), 把 2*S 分解成两个整数（p和q）相乘的形式,从而求出 m, n.    
