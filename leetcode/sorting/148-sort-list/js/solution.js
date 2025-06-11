// Definition for singly-linked list.
class ListNode {
  /**
   * @param {number} val
   * @param {ListNode | null} next
   */
  constructor(val, next) {
    this.val = val === undefined ? 0 : val;
    this.next = next === undefined ? null : next;
  }
}

/**
 * @param {ListNode} firstNode
 * @param {ListNode} middleNode
 * @param {ListNode} lastNode
 */
function merge(firstNode, middleNode, lastNode) {
  /** @type {ListNode | null} */
  let auxHead = null;

  for (
    let cur = firstNode, curAuxNode = null;
    cur !== lastNode;
    cur = cur.next
  ) {
    if (curAuxNode) {
      const newNode = new ListNode(cur.val, undefined);
      curAuxNode.next = newNode;
      curAuxNode = newNode;
    } else {
      curAuxNode = new ListNode(cur.val, undefined);
      auxHead = curAuxNode;
    }
  }

  for (
    let curOriginalNode = firstNode,
      curLeftNode = firstNode,
      curRightNode = middleNode.next;
    curOriginalNode !== lastNode && curOriginalNode;
    curOriginalNode = curOriginalNode.next
  ) {
    if (curLeftNode) {

    } else if () {

    } else if () {

    } else {

    }
  }
}

/**
 * @param {ListNode | null} firstNode
 * @param {ListNode | null} lastNode
 */
function sortListRecursive(firstNode, lastNode) {
  if (!firstNode || !lastNode) {
    return;
  }

  /** @type {(ListNode | null)[]} */
  let [fastPointer, slowPointer] = [firstNode, firstNode];

  while (
    (fastPointer !== lastNode || fastPointer.next !== lastNode) &&
    fastPointer.next?.next
  ) {
    slowPointer = slowPointer.next;
    fastPointer = fastPointer.next.next;
  }

  const middleNode = slowPointer;
  sortListRecursive(firstNode, middleNode);
  sortListRecursive(middleNode.next, lastNode);
  // merge();
}

/**
 * @param {ListNode} head
 * @return {ListNode}
 */
function sortList(head) {
  if (!head || !head.next) {
    return;
  }

  /** @type {ListNode} */
  let curNode = head;

  while (curNode.next) {
    curNode = curNode.next;
  }

  const firstNode = head;
  const lastNode = curNode;
  sortListRecursive(firstNode, lastNode);
}
