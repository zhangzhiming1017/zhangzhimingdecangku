
/*根据每日 气温 列表，请重新生成一个列表，对应位置的输出是需要再等待多久温度才会升高超过该日的天数。如果之后都不会升高，请在该位置用 0 来代替。

例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。

提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/daily-temperatures
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
/*暴力算法，超时，o(n^2)复杂度*/
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> result;
        for(int i = 0 ; i< T.size();i++)
        {
            for(int j = i+1; j < T.size();j++)
            {
                if((T[j]-T[i])>0) 
                {
                    result.push_back(j-i);
                    break;
                }     
            }
        }
        return result;
    }

    /*单调栈*
以下用一个具体的例子帮助读者理解单调栈。对于温度列表 [73,74,75,71,69,72,76,73][73,74,75,71,69,72,76,73]，单调栈 \textit{stack}stack 的初始状态为空，答案 \textit{ans}ans 的初始状态是 [0,0,0,0,0,0,0,0][0,0,0,0,0,0,0,0]，按照以下步骤更新单调栈和答案，其中单调栈内的元素都是下标，括号内的数字表示下标在温度列表中对应的温度。

当 i=0i=0 时，单调栈为空，因此将 00 进栈。

\textit{stack}=[0(73)]stack=[0(73)]

\textit{ans}=[0,0,0,0,0,0,0,0]ans=[0,0,0,0,0,0,0,0]

当 i=1i=1 时，由于 7474 大于 7373，因此移除栈顶元素 00，赋值 ans[0]:=1-0ans[0]:=1−0，将 11 进栈。

\textit{stack}=[1(74)]stack=[1(74)]

\textit{ans}=[1,0,0,0,0,0,0,0]ans=[1,0,0,0,0,0,0,0]

当 i=2i=2 时，由于 7575 大于 7474，因此移除栈顶元素 11，赋值 ans[1]:=2-1ans[1]:=2−1，将 22 进栈。

\textit{stack}=[2(75)]stack=[2(75)]

\textit{ans}=[1,1,0,0,0,0,0,0]ans=[1,1,0,0,0,0,0,0]

当 i=3i=3 时，由于 7171 小于 7575，因此将 33 进栈。

\textit{stack}=[2(75),3(71)]stack=[2(75),3(71)]

\textit{ans}=[1,1,0,0,0,0,0,0]ans=[1,1,0,0,0,0,0,0]

当 i=4i=4 时，由于 6969 小于 7171，因此将 44 进栈。

\textit{stack}=[2(75),3(71),4(69)]stack=[2(75),3(71),4(69)]

\textit{ans}=[1,1,0,0,0,0,0,0]ans=[1,1,0,0,0,0,0,0]

当 i=5i=5 时，由于 7272 大于 6969 和 7171，因此依次移除栈顶元素 44 和 33，赋值 ans[4]:=5-4ans[4]:=5−4 和 ans[3]:=5-3ans[3]:=5−3，将 55 进栈。

\textit{stack}=[2(75),5(72)]stack=[2(75),5(72)]

\textit{ans}=[1,1,0,2,1,0,0,0]ans=[1,1,0,2,1,0,0,0]

当 i=6i=6 时，由于 7676 大于 7272 和 7575，因此依次移除栈顶元素 55 和 22，赋值 ans[5]:=6-5ans[5]:=6−5 和 ans[2]:=6-2ans[2]:=6−2，将 66 进栈。

\textit{stack}=[6(76)]stack=[6(76)]

\textit{ans}=[1,1,4,2,1,1,0,0]ans=[1,1,4,2,1,1,0,0]

当 i=7i=7 时，由于 7373 小于 7676，因此将 77 进栈。

\textit{stack}=[6(76),7(73)]stack=[6(76),7(73)]

\textit{ans}=[1,1,4,2,1,1,0,0]ans=[1,1,4,2,1,1,0,0]

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/daily-temperatures/solution/mei-ri-wen-du-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。*/
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        vector<int> ans(n);
        stack<int> s;
        for (int i = 0; i < n; ++i) {
            while (!s.empty() && T[i] > T[s.top()]) {
                int previousIndex = s.top();
                ans[previousIndex] = i - previousIndex;
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }


};