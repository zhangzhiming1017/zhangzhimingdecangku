/*给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

 

示例：

输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum-closest
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        sort(nums.begin(),nums.end());
        
        int res = abs(nums[nums.size()-1]+ nums[nums.size() - 1]+ nums[nums.size() - 1]-target); //定义初始绝对值
		int ans = nums[nums.size() - 1] + nums[nums.size() - 1] + nums[nums.size() - 1];//定义初始输出

        for(int first = 0; first < nums.size();first++){
            if(first>0 && nums[first] == nums[first-1]){
                continue;
            }
            int third = nums.size()-1;
            int temp = target - nums[first];

            for(int secend = first+1;secend <third;){
                if(res>abs(target - nums[first] - nums[secend]-nums[third])){ //更新绝对值
                    res = abs(target - nums[first] - nums[secend]-nums[third]);
                    ans = nums[first] + nums[secend] + nums[third];//更新输出

                }
               
                if(nums[secend] + nums[third] >temp) third--;
                else secend++;
            }

        }

        return ans;


    }
};