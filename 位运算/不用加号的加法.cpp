/*设计一个函数把两个数字相加。不得使用 + 或者其他算术运算符。

示例:

输入: a = 1, b = 1
输出: 2
 

提示：

a, b 均可能是负数或 0
结果不会溢出 32 位整数

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-without-plus-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    //a^b 相加   (a&b)<<1  进位
    int add(int a, int b) {

        int sum = 0 ;
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