#pragma once

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution2 {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int len1 = getListLength(l1);
		int len2 = getListLength(l2);

		ListNode* pHeader = NULL;
		if (len1 > len2)
		{
			pHeader = CopyList(l1);
			addTwoList(l2, pHeader);
		}
		else
		{
			pHeader = CopyList(l2);
			addTwoList(l1, pHeader);
		}

		return pHeader;
	}

private:

	void addTwoList(ListNode* pFrom, ListNode* pTo)
	{
		int next = 0;
		for (ListNode* pStart = pFrom; pStart != NULL; pStart = pStart->next)
		{
			int sum = pStart->val + pTo->val + next;
			pTo->val = sum % 10;
			next = sum / 10;
			if (next > 0 && pTo->next == NULL)
			{
				pTo->next = new ListNode(0);
			}
			pTo = pTo->next;
		}
		
		while (next > 0)
		{
			int sum = pTo->val + next;
			pTo->val = sum % 10;
			next = sum / 10;

			if (next > 0)
			{
				if (pTo->next == NULL)
				{
					pTo->next = new ListNode(0);

				}
				pTo = pTo->next;
			}
		}
	}

	int getListLength(ListNode* pList)
	{
		int nLength = 0;
		while (NULL != pList)
		{
			nLength++;
			pList = pList->next;
		}
		return nLength;
	}

	ListNode* CopyList(ListNode* pList)
	{
		ListNode* pHeader = CopyNode(pList);
		if (NULL == pHeader)
		{
			return pHeader;
		}
		ListNode* pTmp = pHeader;
		while (NULL != pList->next)
		{
			pTmp->next = CopyNode(pList->next);
			pTmp = pTmp->next;
			pList = pList->next;
		}
		return pHeader;
	}

	ListNode* CopyNode(ListNode* pNode)
	{
		if (NULL == pNode)
		{
			return NULL;
		}
		else
		{
			return new ListNode(pNode->val);
		}
	}
};