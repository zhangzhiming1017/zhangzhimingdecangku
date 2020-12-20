/*给你一个 m * n 的整数矩阵 mat ，请你将同一条对角线上的元素（从左上到右下）按升序排序后，返回排好序的矩阵。

 

示例 1：



输入：mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
输出：[[1,1,1,1],[1,2,2,2],[1,2,3,3]]
 

提示：

m == mat.length
n == mat[i].length
1 <= m, n <= 100
1 <= mat[i][j] <= 100

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-the-matrix-diagonally
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
/*一种比较蠢的方式，先把所有的对角线元素存入数组，然后将所有数组排序，排序结束后再放回矩阵
放回矩阵的方式就是，将对角线数组存入队列，然后按存入数组的顺序弹出，详情见代码*/
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
       int rows = mat.size();
		int cols = mat[0].size();
		vector<vector<int>>  temp;
		for (int i = 0; i < cols; i++)
		{
			vector<int> tempVec;
			for (int j = rows - 1, k = i; j >= 0 && k >= 0; j--, k--)
				tempVec.push_back(mat[j][k]);
			temp.push_back(tempVec);
		}
		for (int i = rows - 2; i >= 0; i--)
		{
			vector<int> tempVec;
			for (int j = cols - 1, k = i; j >= 0 && k >= 0; j--, k--)
				tempVec.push_back(mat[k][j]);
			temp.push_back(tempVec);
		}

	
		for (auto& i : temp) {
			sort(i.begin(), i.end(), [&](int &x, int &y) {return x < y; });
		}
		queue<vector<int>> tempstack;
		for (auto i : temp) tempstack.push(i);
		for (int i = 0; i < cols; i++)
		{
			vector<int> tempresult = tempstack.front();
			tempstack.pop();
			for (int j = rows - 1, k = i, m = tempresult.size() - 1; j >= 0 && k >= 0; j--, k--, m--)
					mat[j][k] = tempresult[m];
		}
		for (int i = rows - 2; i >= 0; i--)
		{
			vector<int> tempresult = tempstack.front();
			tempstack.pop();
			for (int j = cols - 1, k = i, m = tempresult.size() - 1; j >= 0 && k >= 0; j--, k--, m--)
				mat[k][j] = tempresult[m];

		}
		return mat;
    }
};