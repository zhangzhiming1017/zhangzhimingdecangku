/*给你一个整数数组 arr 和一个目标值 target ，请你返回一个整数 value ，使得将数组中所有大于 value 的值变成 value 后，数组的和最接近  target （最接近表示两者之差的绝对值最小）。

如果有多种使得和最接近 target 的方案，请你返回这些整数中的最小值。

请注意，答案不一定是 arr 中的数字。

 

示例 1：

输入：arr = [4,9,3], target = 10
输出：3
解释：当选择 value 为 3 时，数组会变成 [3, 3, 3]，和为 9 ，这是最接近 target 的方案。
示例 2：

输入：arr = [2,3,5], target = 10
输出：5
示例 3：

输入：arr = [60864,25176,27249,21296,20204], target = 56803
输出：11361

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-of-mutated-array-closest-to-target
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
//自己写得，有待完善

    int findBestValue(vector<int>& arr, int target) {
		std::sort(arr.begin(), arr.end());
		int isum = sumtemp(arr.end(), arr);
		if (isum <= target) return *(arr.end() - 1);
		int tempResult = target / arr.size();
		if (tempResult < *arr.begin()) {
			int tempResult = target % arr.size();
			if (tempResult >= arr.size() / 2) return target / arr.size() + 1;
			else return target / arr.size();
		}

		vector<int>::iterator addre = lower_bound(arr.begin(), arr.end(), tempResult);

		//std::sort(arr.begin(),arr.end(),std::greater());
		//std::sort(arr.begin(),arr.end(),std::less());

		return 0;
	}


	int sumtemp(vector<int>::iterator add, vector<int>& arr)
	{
		int sum = 0;
		for (auto iter = arr.begin(); iter != add; iter++)
			sum += *iter;
		if (add == arr.end()) return sum;
		else return sum += (arr.end() - add) * (*add);
	}



    /*网友答案*/
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end()); //排序
        vector<int> presum(arr.size() + 1); //初始每个元素为0
        for (int i = 1; i <= arr.size(); i ++) presum[i] = presum[i - 1] + arr[i - 1]; //前缀和
        int l = 1, r = arr[arr.size() - 1];  //(1,max)
        while (l < r) {
            int mid = l + r >> 1; // 分区间
            getsum(arr, presum, mid) < target ? l =  mid + 1 : r = mid; 
        }
        return abs(getsum(arr, presum, l) - target) < abs(getsum(arr, presum, l - 1) - target) ?  l : l - 1; 
    }
    int getsum(vector<int>& arr, vector<int>& presum, int value) {
        vector<int>::iterator iter = lower_bound(arr.begin(), arr.end(), value); //迭代器，返回第一个大于等于value的位置
        //同理upper_bound返回第一个小于等于value的位置
        int sum = presum[iter - arr.begin()] + (arr.end() - iter) * value; //前缀和 + value和
        return sum;
    }

};