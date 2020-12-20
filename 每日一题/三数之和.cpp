/*给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。

注意：答案中不可以包含重复的三元组。

 

示例：

给定数组 nums = [-1, 0, 1, 2, -1, -4]，

满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/3sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    unordered_map<int, int> Vmap(vector<int>& nums,int begin, int end) {
		unordered_map<int, int> Vmap2;
		
		for (int i = begin; i <= end; i++)  Vmap2.insert(std::pair<int, int>(nums[i], i));
		return Vmap2;
	}
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;
		result.clear();
		if (nums.size()<3) return result;
		if (nums[0] == nums[nums.size() - 1] && nums[0] == 0) {
			vector<int> temp;
			temp.push_back(0);
			temp.push_back(0);
			temp.push_back(0);
			result.push_back(temp);
			return result;
		}
		sort(nums.begin(), nums.end());
		unordered_map<int, int> Vmap2;
		for (int i = 0, j = nums.size() - 1; i < j;)
		{
			vector<int> temp;
			Vmap2 = Vmap(nums, i + 1, j - 1);
			if (Vmap2.find(-(nums[i] + nums[j])) != Vmap2.end())
			{
				temp.push_back(nums[i]);
				temp.push_back(nums[j]);
				temp.push_back(-(nums[i] + nums[j]));
			}

			if ((nums[i] + nums[j]) < 0) {
				while (i + 1 < nums.size() && nums[i++] == nums[i]);
			}
			else if ((nums[i] + nums[j]) > 0) {
				while (j > 0 && nums[j--] == nums[j]);
			}
			else {
				if (i + 1 < nums.size() && (nums[i + 1] + nums[j]) > 0) i++;
				else j--;
			}

			if (!temp.empty()) result.push_back(temp);
			temp.clear();
			Vmap2.clear();
		}

		return result;
	}

//双指针法
	vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        // 枚举 a
        for (int first = 0; first < n; ++first) {
            // 需要和上一次枚举的数不相同
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            // c 对应的指针初始指向数组的最右端
            int third = n - 1;
            int target = -nums[first];
            // 枚举 b
            for (int second = first + 1; second < n; ++second) {
                // 需要和上一次枚举的数不相同
                if (second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }
                // 需要保证 b 的指针在 c 的指针的左侧
                while (second < third && nums[second] + nums[third] > target) {
                    --third;
                }
                // 如果指针重合，随着 b 后续的增加
                // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
                if (second == third) {
                    break;
                }
                if (nums[second] + nums[third] == target) {
                    ans.push_back({nums[first], nums[second], nums[third]});
                }
            }
        }
        return ans;
    }
};