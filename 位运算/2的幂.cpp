/*给定一个整数，编写一个函数来判断它是否是 2 的幂次方。

示例 1:

输入: 1
输出: true
解释: 20 = 1
示例 2:

输入: 16
输出: true
解释: 24 = 16
示例 3:

输入: 218
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/power-of-two
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {

        if(n<=0) return false;

        if(n==1) return true;

        int temp = 0;

        for(int i = 0 ; i < 32 ; i++){
            temp+=(n>>i)&1;
        }
        if(temp == 1) return true;
        else return false;



    }
};