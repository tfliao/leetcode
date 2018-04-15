/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& G) {
        set<int> s;
		for (auto e : G) { s.insert(e); }
		
		int cnt = 0;
		bool inset = false;
		while (head) {
			if (s.count(head->val) > 0) {
				if (!inset) {
					inset = true;
					++cnt;
				}
			} else {
				inset = false;
			}
			head = head->next;
		}
		return cnt;
    }
};