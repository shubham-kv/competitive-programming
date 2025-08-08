/// {{
/// Problem: 21. Merge Two Sorted Lists
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/merge-two-sorted-lists/
/// Topics: `linked-list`, `recursion`
/// Timestamp: `Mon, 14 Jul 2025 14:25:32 +0530`

// Definition for singly-linked list.
function ListNode(val, next) {
    this.val = (val===undefined ? 0 : val)
    this.next = (next===undefined ? null : next)
}

/**
 * @param {ListNode} list1
 * @param {ListNode} list2
 * @return {ListNode}
 */
function mergeTwoLists (list1, list2) {
  let l3 = new ListNode(0);

  /** @type {(ListNode|null)[]} */
  let [cur1, cur2, cur3] = [list1, list2, l3];

  for (;;) {
    if (cur1 === null) {
      cur3.next = cur2;
      break;
    }
    else if (cur2 === null) {
      cur3.next = cur1;
      break;
    }
    else if (cur2.val < cur1.val) {
      cur3.next = cur2;
      cur2 = cur2.next;
      cur3 = cur3.next;
    }
    else {
      cur3.next = cur1;
      cur1 = cur1.next;
      cur3 = cur3.next;
    }
  }

  return l3.next;
};

//}}
