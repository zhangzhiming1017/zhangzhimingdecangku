/*不使用运算符 + 和 - ​​​​​​​，计算两整数 ​​​​​​​a 、b ​​​​​​​之和。

示例 1:

输入: a = 1, b = 2
输出: 3
示例 2:

输入: a = -2, b = 3
输出: 1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-two-integers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#include <iostream>
using namespace std;

class Solution {
public:
//a^b 相加但不进位，a&b进位
/*3+2
0011+0010  ^ 0001    &<1  0100
0001+0100  ^ 0101    &<1  0000  return 0101
*/

//<<、>>优先级高于&、|、^
    int getSum(int a, int b) {
        int sum = 0;
        int carry = 0;
        while (b!=0)
        {
            sum = a^b;
            carry = (unsigned int )(a&b)<<1;
            a = sum;
            b = carry;
        }
        return a;

    }
};