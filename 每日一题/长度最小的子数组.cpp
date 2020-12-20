/*给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组，并返回其长度。如果不存在符合条件的连续子数组，返回 0。

示例: 

输入: s = 7, nums = [2,3,1,2,4,3]
输出: 2
解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
进阶:

如果你已经完成了O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-size-subarray-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty()) return 0;
        if(nums[0]>= s) return 1;
        
        int n = nums.size();
        int temp = 0;
        for(int k = 0 ; k < n ; k ++)
        {
            temp+=nums[k];
        }
        if(temp < s) return 0;
        int i = 0,j = 1;
        int sum = nums[0];
        int ans = nums.size();
        while (i < n && j < n)
        {
            while(sum < s) sum+=nums[j++];
            while(sum >= s) sum-=nums[i++];
            ans = min(j - i,ans);
        }
        if(sum < s) return 0;
        return ans;


    }
};