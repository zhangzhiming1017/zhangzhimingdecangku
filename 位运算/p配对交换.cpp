/*
配对交换。编写程序，交换某个整数的奇数位和偶数位，尽量使用较少的指令（也就是说，位0与位1交换，位2与位3交换，以此类推）。

示例1:

 输入：num = 2（或者0b10）
 输出 1 (或者 0b01)
示例2:

 输入：num = 3
 输出：3
提示:

num的范围在[0, 2^30 - 1]之间，不会发生整数溢出。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/exchange-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/
#include <iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
 //本人方法
    int exchangeBits(int num) {
        int result = 0;
		for (int i = 0; i < 32; i+=2) {
			if (!(num & 0x0000003))
			{
				num = num >> 2;
				continue;
			}
				
			int a = num & 0x00000001;
			int b = num & 0x00000002;
			num = num >> 2;

			a = a << 1;
			b = b >> 1;
			int pp = (a + b) <<(i);
			result = result + pp;

		}
		return result;
    }
    //网上代码一行搞定
    /*
    分别取出数字二进制奇数位和偶数位
    将奇数位的二进制放在偶数位（即右移
    将偶数位的二进制放在奇数位（即左移
    */
    int exchangeBitss(int num){
        return (num<<1 & 0xAAAAAAAA) | (num>>1 & 0x55555555); 
    }

};