#include <iostream>
using namespace std;

// �ǵݹ�
class Solution
{
public:
        double myPow(double x, int n) {
        if(n==0) return 1;
        if(n<0) {
            n = -n;
            x = 1/x;
        }
        double ans = 1;
        while(n>0){
            if(n&1) ans *= x;
            x *= x;
            n >>= 1;
        }
        return ans;
    }
};


// �ݹ��㷨
double myPow(double x, int x){
    if (x==0) return 1;
    if (n<0){
        n = -n;
        x = 1/x;
    }
    return n%2==0 ? myPow(x*x, n/2) : x*myPow(x*x, n/2);
}
int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
