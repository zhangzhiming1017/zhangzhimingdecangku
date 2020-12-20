/*给定两个数组，编写一个函数来计算它们的交集。

示例 1:

输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2]
示例 2:

输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [9,4]
说明:

输出结果中的每个元素一定是唯一的。
我们可以不考虑输出结果的顺序。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/intersection-of-two-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>

using namespace std;

class Solution {
public:
/*放到两个set内，用set_intersection求交集*/
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        set<int> s1(nums1.begin(),nums1.end());
        set<int> s2(nums2.begin(),nums2.end());
        set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),insert_iterator<vector<int>> (ans,ans.begin()));
        return ans;
    }
/*一个放到set，然后遍历另一个数组*/
    vector<int> intersection1(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> ans;
        set<int> s(nums1.begin(), nums1.end());
        for(auto &i : nums2){
            if(s.erase(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
/*排序+双指针*/
    vector<int> intersection2(vector<int>& nums1, vector<int>& nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        set<int> s;
        vector<int>::iterator i = nums1.begin(), j = nums2.begin();
        while(i != nums1.end() && j != nums2.end()){
            if(*i == *j){
                s.insert(*i);
                i++;
                j++;
            }
            else if(*i < *j){
                i++;
            }
            else{
                j++;
            }
        }
        vector<int> ans(s.begin(), s.end());
        return ans;
    }
    /*用自己的想法解决*/
 vector<int> intersection3(vector<int>& nums1, vector<int>& nums2)
 {

 }
};


