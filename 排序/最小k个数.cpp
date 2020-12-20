/*设计一个算法，找出数组中最小的k个数。以任意顺序返回这k个数均可。

示例：

输入： arr = [1,3,5,7,2,4,6,8], k = 4
输出： [1,2,3,4]
提示：

0 <= len(arr) <= 100000
0 <= k <= min(100000, len(arr))

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/smallest-k-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

/*快排，堆排，研究研究*/

     int maxNum(vector<int>::iterator arr,int lenth)
     {
         sort(arr,arr+lenth+1);
         return *arr;
     }


    vector<int> smallestK(vector<int>& arr, int k) {
       


    }
};