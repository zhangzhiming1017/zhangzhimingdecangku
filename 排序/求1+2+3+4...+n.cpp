/*求 1+2+...+n ，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

 

示例 1：

输入: n = 3
输出: 6
示例 2：

输入: n = 9
输出: 45

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/qiu-12n-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
#include<iostream>
using namespace std;

class Solution {
public:
    int sumNums(int n) {
        n&&(n+=sumNums(n-1));
        return n;
    }
/*思路 运用逻辑运算符的短路形状，即A&&B ,A为false时，A&&B整体为false，无需判断B
同理，A||B，A为true时，A||B整体为true，无需判断B。*/
    int sumNums1(int n){
        return sumRang(1,n);
    }

    int sumRang(int begin, int end)
    {
        int result = begin;
        int mid = begin + ((end -begin)>>1);
        (begin!=end)&&(result = sumRang(begin,mid)+sumRang(mid+1,end));

        return result;
    }
/*思路 在第一种方法的基础之上，用二分法的方式进行了改进*/

};
