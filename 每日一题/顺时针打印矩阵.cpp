/*输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

 

示例 1：

输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
示例 2：

输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
 

限制：

0 <= matrix.length <= 100
0 <= matrix[i].length <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/shun-shi-zhen-da-yin-ju-zhen-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int>  result;
		result.clear();
		if(matrix.empty()) return result;	

		int up = 0,down = matrix.size() ,left = 0,right = matrix[0].size();
	
		int size = down * right;
		while (result.size() < size)
		{
			for (int i = left; i < right; i++)  result.push_back(matrix[up][i]);

			if (result.size() == size) return result;

			up++;
			for (int i = up; i < down; i++) result.push_back(matrix[i][right-1]);
	
			if (result.size() == size) return result;
			right--;

			for (int i = right-1; i >= left; i--) result.push_back(matrix[down-1][i]);
	
			if (result.size() == size) return result;
			down--;
			
			for (int i = down-1; i >= up; i--) result.push_back(matrix[i][left]);
	
			if (result.size() == size) return result;
			left++;
			if (up == right-1 && left == down-1)
				result.push_back(matrix[right-1][up]);
			
		}

		return result;
	}
    /*思路，先处理输入矩阵为空的特殊情况，再设置up,down,left,right作为起点，分别还是存入数组，
    每次循环完一次，判断结果数组与输入数组的大小是否一致，一致则返回结果，详细见代码*/
};