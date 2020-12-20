/*假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。

示例 1：

输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶
示例 2：

输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/climbing-stairs
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
//f(n) = f(n-1) + f(n-2);其中n>=1,f(1)=1,f(2) = 2

//第一种方式递归，复杂度o(2^n)
    int climbStairs(int n) {

        if(n==1)  return 1;
        if(n==2)  return 2;
        return climbStairs(n-1)+climbStairs(n-2);  
    }
    //第二种方式动态规划,复杂度o(n)
    int climbStairs(int n) {
        if(n==1)  return 1;
        if(n==2)  return 2;
        int pre = 1;
        int temp =2;
        int result = 0;
        for(int i= 3; i<=n;i++){
            result = pre + temp;
            pre = temp;
            temp = result;
        } 
        return result;       
    }
    //第三种方法,通项公式法，复杂度o(logn)
     int climbStairs(int n) {
        if(n==1)  return 1;
        if(n==2)  return 2;
        double mathsqrt = sqrtl(5);
        double find = powl((1+mathsqrt)/2,n) - powl((1-mathsqrt)/2,n);
        return find/mathsqrt;


         
    }
};