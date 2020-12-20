/*给出一个区间的集合，请合并所有重叠的区间。

示例 1:

输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2:

输入: [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/merge-intervals
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         if (intervals.size() == 0) {
            return {};
        }
        sort(intervals.begin(),intervals.end(),[&](vector<int> &a,vector<int> &b){
            return a[0] < b[0];
        });
        vector<vector<int>> result;
        result.clear();
        for (int i = 0; i < intervals.size(); ++i) {
            int L = intervals[i][0], R = intervals[i][1];
            if (!result.size() || result.back()[1] < L) {
                result.push_back({L, R});
            }
            else {
                result.back()[1] = max(result.back()[1], R);
            }
        }
        return result;
        
    }
};