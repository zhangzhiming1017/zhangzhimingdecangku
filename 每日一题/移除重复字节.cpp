/*编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。

示例1:

 输入：[1, 2, 3, 3, 2, 1]
 输出：[1, 2, 3]
示例2:

 输入：[1, 1, 1, 1, 2]
 输出：[1, 2]
提示：

链表长度在[0, 20000]范围内。
链表元素在[0, 20000]范围内。
进阶：

如果不得使用临时缓冲区，该怎么解决？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/remove-duplicate-node-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

 // Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
//双重循环 时间复杂度o(n^2)
    ListNode* removeDuplicateNodes(ListNode* head) {

       ListNode* title = new ListNode(0);
		title->next = head;

		ListNode* temp = head;
		while (temp)
		{
			ListNode* temp1 = temp->next;
			ListNode* pretemp1 = temp;
			while (temp1) {
				if (temp1->val == temp->val) {
					ListNode* temp1next = temp1->next;
					pretemp1->next = temp1next;
					delete temp1;
					temp1 = temp1next;
				}
				else
				{
					pretemp1 = temp1;
					temp1 = temp1->next;
				}
			}

			temp = temp->next;
		}

		return title->next;
        
    }

    //哈希表 时间复杂度o(n)
    ListNode* removeDuplicateNodes2(ListNode* head) {

        if (head == nullptr) {
            return head;
        }
        unordered_set<int> occurred = {head->val}; //创建哈希表，将首节点带入
        ListNode* pos = head;
        // 枚举前驱节点
        while (pos->next != nullptr) {
            // 当前待删除节点
            
            ListNode* cur = pos->next; //当前节点
            ListNode* precur = pos; //当前节点前驱
            if (!occurred.count(cur->val)) { //判断集合中是否存在当前节点值
                occurred.insert(cur->val); //没有则添加
                precur = pos; //更新前驱
                pos = pos->next;//更新当前节点
            } else {
                ListNode * temp = pos->next; //有则删除该当前节点
                precur->next = temp->next; //前驱与当前节点得后驱相链接
                delete temp; //删除当前节点

            }
        }
        pos->next = nullptr;
        return head;       
    }
};