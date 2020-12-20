/*编写一个方法，找出两个数字a和b中最大的那一个。不得使用if-else或其他比较运算符。

示例：

输入： a = 1, b = 2
输出： 2*/

#include <iostream>

using namespace std;

class Solution {
public:
    int maximum(int a, int b) {
        unsigned aa = a, bb = b;
        bool x = (aa >> 31) ^ 1, y = bb >> 31, z = (bb - aa) >> 31;
        bool ans = (x & y) | (x & z) | (y & z);
        return ans * a + (ans ^ 1) * b;

// 作者：windy
// 链接：https://leetcode-cn.com/problems/maximum-lcci/solution/cjie-fa-bu-yong-64wei-zheng-xing-bu-yong-shu-xue-h/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
    }
};