/*给定一个字符串S，通过将字符串S中的每个字母转变大小写，我们可以获得一个新的字符串。返回所有可能得到的字符串集合。

示例:
输入: S = "a1b2"
输出: ["a1b2", "a1B2", "A1b2", "A1B2"]

输入: S = "3z4"
输出: ["3z4", "3Z4"]

输入: S = "12345"
输出: ["12345"]
注意：

S 的长度不超过12。
S 仅由数字和字母组成。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/letter-case-permutation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {

public:
//网页答案1
    vector<string> letterCasePermutation1(string S) {
        vector<string> ans{ S };
		for (int i = 0; i < S.size(); ++i)
			if (isalpha(S[i])) //遇字母
				for (int j = ans.size() - 1; j >= 0; --j) {
					ans.push_back(ans[j]); //先保存 再转换大小写
					if (isupper(ans[j][i])) ans[j][i] = tolower(ans[j][i]);
					else ans[j][i] = toupper(ans[j][i]);
				}
		return ans;
    }
//网友答案2
    vector<string> letterCasePermutation2(string S) {
        vector<string> result{S};
        for (int i = 0; i < S.size(); i++) {
            if (isupper(S[i])) {
                int size = result.size();
                for (int j = 0; j < size; j++) {
                    string temp = result[j];
                    temp[i] = tolower(temp[i]);
                    result.emplace_back(move(temp));
                }
            } else if (islower(S[i])) {
                int size = result.size();
                for (int j = 0; j < size; j++) {
                    string temp = result[j];
                    temp[i] = toupper(temp[i]);
                    result.emplace_back(move(temp));
                }
            }
        }
        return result;

    }

//自己答案，错误
    vector<string> letterCasePermutation(string S) {
        char temp[12];
	
		for (int i = 0; i < S.size(); i++) {
			temp[i] = S[i];
		}
		vector<string> ans;
		for (int i = 0; i < S.size(); i++) {

			if (0 <= temp[i] - '0' && temp[i] - '0' < 10) continue;

			if (0 <= temp[i] - 'a' && temp[i] - 'a' < 26) {
				string pp;
				for (int j = 0; j < S.size(); j++) pp.push_back(temp[j]);
				ans.push_back(pp);
				pp[i] = pp[i] - 32;
				ans.push_back(pp);
				continue;

			}

			if (0 <= temp[i] - 'A' && temp[i] - 'A' < 26) {
				string pp;
				for (int j = 0; j < S.size(); j++) pp.push_back(temp[j]);
				ans.push_back(pp);
				pp[i] = pp[i] + 32;
				ans.push_back(pp);
				continue;

			}
		}

        if(ans.empty()) ans.push_back(S);


		return ans;


    }
};