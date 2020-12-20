/*给定一个非负整数数组 A， A 中一半整数是奇数，一半整数是偶数。

对数组进行排序，以便当 A[i] 为奇数时，i 也是奇数；当 A[i] 为偶数时， i 也是偶数。

你可以返回任何满足上述条件的数组作为答案。

 

示例：

输入：[4,2,5,7]
输出：[4,5,2,7]
解释：[4,7,2,5]，[2,5,4,7]，[2,7,4,5] 也会被接受。
 

提示：

2 <= A.length <= 20000
A.length % 2 == 0
0 <= A[i] <= 1000*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
/*思路，先判断i,若i及A[i]符合要求，则判断下一个，
否则与下一个交换，若下一个还不满足，则继续下一个
的下一个，直到满足要求，再执行第一场循环*/
    vector<int> sortArrayByParityII(vector<int>& A) {
        for(int i = 0 ; i < A.size();i++)
        {
            if(i%2) {
                if(A[i]%2) continue;
                else{
                    for(int j =i+1 ; j < A.size();j++) {
                        sort(A[i],A[j]);
                        if(A[i]%2) break;
                    }
                }
            } 
            else
            {
                if(!(A[i]%2)) continue;
                else
                {
                    for(int j =i+1 ; j < A.size();j++) {
                        sort(A[i],A[j]);
                        if(!(A[i]%2)) break;
                    }
                }
                
            }
            
        }

        return A;

    }
    void sort(int &a,int &b){
        int c = a;
        a = b;
        b = c;
    }
    /*两次遍历，第一次遍历将所有的偶数放入ans[0]、ans[2]、ans[4]...
    第二次遍历将所有的奇数放入ans[1]、ans[3]、ans[5]...*/
    
    vector<int> sortArrayByParityII(vector<int>& A) {
      vector<int> ans1; //奇数
      vector<int> ans2; //偶数

      for(int i = 0 ; i < A.size();i++)
      {
          if(A[i]%2) ans1.push_back(A[i]);
          else     ans2.push_back(A[i]);
      }
      for(int i = 0 ; i < ans1.size();i++)
      {
          A[i*2]=ans1[i];
          A[i*2+1] = ans2[i];
      } 
      return A; 
    }
    /*双指针*/
    vector<int> sortArrayByParityII(vector<int>& A)
    {
            
    }
};