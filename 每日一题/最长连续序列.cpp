/*给定一个未排序的整数数组，找出最长连续序列的长度。

要求算法的时间复杂度为 O(n)。

示例:

输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-consecutive-sequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;
class Solution {
public:
/*自己答案正确，但是超时*/
    int longestConsecutive(vector<int>& nums) {
     unordered_set<int> num_set;
     for(auto i : nums)
     {
         num_set.insert(i);
     }
    int resultLenth = 0;
    int temLenth = 0;


        for (const int& num : num_set) {
           int j = num;
			temLenth++;
			while (num_set.count(--j))
			{
				temLenth++;
			}
			resultLenth = max(resultLenth, temLenth);
			temLenth = 0;
        }


        
    return resultLenth;
    
    }
/*官方答案*/
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        for (const int& num : nums) {
            num_set.insert(num);
        }

        int longestStreak = 0;
        

        for (const int& num : num_set) {
            if (!num_set.count(num - 1)) {
                int currentNum = num;
                int currentStreak = 1;

                while (num_set.count(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;           
    }
};