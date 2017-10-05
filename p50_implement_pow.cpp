#include<iostream>
#include <cmath>
using namespace std;



class Solution {
public:
    double myPow(double x, int n) {

    double ans = 1;
    int temp = n;
    n = abs(long(n));
    while (n>0)
    {
        if( (n&1) == 1)
        {
            ans = ans*x;
        }
        n = n >>1;
        x = x*x;
    }
    if(temp>=0)
    {
        return ans;
    }
    else
    {
        return 1/ans;
    }

    }

};


int main()
{
    Solution s;

    cout << s.myPow(3,5);


}
