/*给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶:

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-subarray
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
/*
第一次  ： 0 + -2 = -2 , pre = -2      maxAns = -2
第二次  : -2 +  1 <  1   pre =  1      maxAns =  1
第三次  :  1 -  3 > -3   pre = -2      maxAns =  1
第四次  : -2 +  4 <  4   pre =  4      maxAns =  4
第五次  :  4 -  1 > -1   pre =  3      maxAns =  4
第六次  :  3 +  2 >  2   pre =  5      maxAns =  5
第七次  :  5 +  1 >  6   pre =  6      maxAns =  6
第八次  :  6 -  5 > -5   pre =  1      maxAns =  6
第九次  :  1 +  4 >  4   pre =  5      maxAns =  6                                
*/
    int maxSubArray(vector<int>& nums) {
        int pre = 0, maxAns = nums[0];
        for (const auto &x: nums) {
            pre = max(pre + x, x);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }

};