/*给你个整数数组 arr，其中每个元素都 不相同。

请你找到所有具有最小绝对差的元素对，并且按升序的顺序返回。

 

示例 1：

输入：arr = [4,2,1,3]
输出：[[1,2],[2,3],[3,4]]
示例 2：

输入：arr = [1,3,6,10,15]
输出：[[1,3]]
示例 3：

输入：arr = [3,8,-10,23,19,-4,-14,27]
输出：[[-14,-10],[19,23],[23,27]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/minimum-absolute-difference
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:


    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        
        sort(arr.begin(),arr.end());
        vector<vector<int>> result;
        
        if(arr.size()==2) {
            result.push_back(arr);
            return result;
            }

        int mx = arr[0];
        int ans = abs(arr[1]-arr[0]);
        
        for(int i = 1; i < arr.size();i++)
        {
            
            if(ans> min(ans,abs(arr[i]-mx))){//当最小值刷新时，清空输出
                ans = abs(arr[i]-mx);
                result.clear();
            };
            vector<int> temp;
            if(ans == abs(arr[i]-mx)){ //当arr[i]-arr[j]等于最小时，存入数据
                temp.push_back(mx);
                temp.push_back(arr[i]);
                result.push_back(temp);

            }
            mx = arr[i];
        }
        //for(int i = j)
        return result;

    }
};