/*给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。

 

示例 1:

输入: 12258
输出: 5
解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"
 

提示：

0 <= num < 231

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int translateNum(int num) {
        string str = std::to_string(num);
		int r = 1;//i 的方法数 f(0) = 1
		int q = 0; // i-1的方法数
		int p = 0; //i-2的方法数
		//f(i) = f(i-1) + f(i-2)(i>=1,9<x<26)
		for (int i = 0; i < str.size(); i++)
		{
			p = q;
			q = r;
			r = 0;
			r += q;
			if (i == 0) continue;
		
			int a = (str[i] - '0') + (str[i - 1] - '0') * 10;
			if (a > 9 && a < 26)  r = q + p;
			else  r = q;
		}
		return r;
        /*动态规划，斐波那契*/

    }
};