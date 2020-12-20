/*给定两个字符串 s 和 t，它们只包含小写字母。

字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。

请找出在 t 中被添加的字母。

 

示例:

输入：
s = "abcd"
t = "abcde"

输出：
e

解释：
'e' 是那个被添加的字母。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/find-the-difference
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace  std;


class Solution {
public:

//位运算  A^A = 0, A^0 = A
    char findTheDifference(string s, string t) {

         char ans = s[0];
    for(int i = 1; i < s.size(); i++)
        ans ^= s[i];
    for(int j = 0; j < t.size(); j++)
        ans ^=t[j];
    return ans;
    }

    //用计数法
    char findTheDifference(string s, string t) {

       vector<char> map(26, 0);
        for(char c : s) ++map[c - 'a'];
        for(char c : t) --map[c - 'a'];
        for(int i = 0; i < 26; i++)
            if(map[i] != 0)
                return i + 'a';
        return ' ';
    }

    //用集合
     char findTheDifference(string s, string t) {
        unordered_map<char,int> s_map;
        for(auto it:s)
            s_map[it]++;
        
        unordered_map<char,int> t_map;
        for(auto it:t)
            t_map[it]++;

        for(auto it:t_map)
        {
            if(it.second != s_map[it.first])
                return it.first;
        }
    }
};