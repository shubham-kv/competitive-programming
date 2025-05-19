// Definition for _Node.
class _Node {
  val: number;
  next: _Node | null;
  random: _Node | null;

  constructor(val?: number, next?: _Node, random?: _Node) {
    this.val = val === undefined ? 0 : val;
    this.next = next === undefined ? null : next;
    this.random = random === undefined ? null : random;
  }
}

function copyRandomList(head: _Node | null): _Node | null {
  if (!head) {
    return null;
  }

  const originalNodeToCopyNodeMap: Map<_Node, _Node> = new Map();
  let copyListHead: _Node | null = new _Node(head.val, undefined, undefined);

  for (
    let curNode: _Node | null = head,
      prevNodeFromCopied: _Node | null = null,
      i = 0;
    curNode != null;
    curNode = curNode.next, i++
  ) {
    // Create a copy of the current node
    const copyNode = new _Node(curNode.val, undefined, undefined);

    if (!prevNodeFromCopied) {
      // This is the first iteration & so current copy node should be the head
      // node of copied linked list
      copyListHead = copyNode;
    } else {
      // Update the last node's next pointer
      prevNodeFromCopied.next = copyNode;
    }

    prevNodeFromCopied = copyNode;

    // Map original node to it's copied node
    originalNodeToCopyNodeMap.set(curNode, copyNode);
  }

  // Iterate through the copied linked list and set the node's random pointer
  for (
    let curCopyNode: _Node | null = copyListHead,
      curOriginalNode: _Node | null = head,
      i = 0;
    curCopyNode != null && curOriginalNode != null;
    curCopyNode = curCopyNode.next, curOriginalNode = curOriginalNode.next, i++
  ) {
    if (
      curOriginalNode.random &&
      originalNodeToCopyNodeMap.has(curOriginalNode.random)
    ) {
      const correspondingRandomCopyNode = originalNodeToCopyNodeMap.get(curOriginalNode.random);
      curCopyNode.random = correspondingRandomCopyNode ?? null;
    }
  }

  return copyListHead;
}
