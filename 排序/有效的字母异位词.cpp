/*给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。

示例 1:

输入: s = "anagram", t = "nagaram"
输出: true
示例 2:

输入: s = "rat", t = "car"
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-anagram
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        #define arryLength 26
        char s1[arryLength];
        char t1[arryLength];

        for(int i = 0 ; i < s.size();i++)
        {
            s1[s[i]-'a']++;
            t1[t[i]-'a']++;
        }
        if(s1==t1) return true;
        else return false;

    }
};