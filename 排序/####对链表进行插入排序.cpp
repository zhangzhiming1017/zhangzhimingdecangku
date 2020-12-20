/*对链表进行插入排序。


插入排序的动画演示如上。从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。
每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。

 

插入排序算法：

插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
重复直到所有输入数据插入完为止。
 

示例 1：

输入: 4->2->1->3
输出: 1->2->3->4
示例 2：

输入: -1->5->3->4->0
输出: -1->0->3->4->5

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/insertion-sort-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#include<iostream>

using namespace std;


 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
   ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
      if (!head || !head->next)
		return head;
	ListNode *dummyhead = new ListNode(-1);//伪头指针
	dummyhead->next = head;
	ListNode *prev = head;
	ListNode *node = head->next;
	while (node)
	{
		if (node->val < prev->val)
		{
			ListNode* temp = dummyhead;//！！temp要等于dummyhead，这样才可以比较第一个元素
			while (temp->next->val < node->val)//！！！这里是temp->next：因为要修改前面的temp的指向
			{
				temp = temp->next;//指针后移
			}
			prev->next = node->next;
			node->next = temp->next;
			temp->next = node;
			node = prev->next;//此时不用改变prev指向！因为prev没有变，只是待排序元素变了位置。
		}
		else
		{
			prev = prev->next;
			node = node->next;
		}
	}
	return dummyhead->next;//!!!不能返回head！！因为后面会改变head所指向内存的位置！

    }
};