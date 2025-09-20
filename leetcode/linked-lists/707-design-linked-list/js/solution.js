/// {{
/// Problem: 707. Design Linked List
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/design-linked-list/
/// Timestamp: `Sat, 20 Sep 2025 12:08:33 +0530`

function _Node(
  /** @type {number} */ val,
  /** @type {_Node | null | undefined} */ prev = null,
  /** @type {_Node | null | undefined} */ next = null
) {
  /** @type {number} */
  this.val = val;

  /** @type {_Node | null} */
  this.prev = prev ?? null;

  /** @type {_Node | null} */
  this.next = next ?? null;
}

function MyLinkedList() {
  /** @type {_Node | null} */
  this.first = null;

  /** @type {_Node | null} */
  this.last = null;

  /** @type {number} */
  this.size = 0;
}

/** @returns {_Node | null} */
function _ithNode(
  /** @type {MyLinkedList} */ list,
  /** @type {number} */ index
) {
  if (!list) { return null; }

  const n = list.size;
  if (!(0 <= index && index < n)) {
    return null;
  }
  let node = list.first;
  for (let i = 1; i <= index; i++) {
    if (node && node.next) {
      node = node.next;
    } else {
      throw new Error('Failed! Invalid list state');
    }
  }
  return node;
}

/** 
 * @param {number} index
 * @return {number}
 */
MyLinkedList.prototype.get = function(index) {
  const node = _ithNode(this, index);
  return node?.val ?? -1;
};

/** 
 * @param {number} val
 * @return {void}
 */
MyLinkedList.prototype.addAtHead = function(val) {
  const node = new _Node(val, null, this.first);
  if (this.first) {
    this.first.prev = node;
  }
  if (!this.last) {
    this.last = node;
  }
  this.first = node;
  this.size++;
};

/** 
 * @param {number} val
 * @return {void}
 */
MyLinkedList.prototype.addAtTail = function(val) {
  const node = new _Node(val, this.last, null);
  if (this.last) {
    this.last.next = node;
  }
  if (!this.first) {
    this.first = node;
  }
  this.last = node;
  this.size++;
};

/** 
 * @param {number} index 
 * @param {number} val
 * @return {void}
 */
MyLinkedList.prototype.addAtIndex = function(index, val) {
  const n = this.size;
  if (!(0 <= index && index <= n)) {
    return;
  }

  if (index === 0) {
    this.addAtHead(val);
  } else if (index === n) {
    this.addAtTail(val);
  } else {
    const ithNode = _ithNode(this, index);
    if (!ithNode) {
      throw new Error('Failed to get ithnode');
    }

    const newNode = new _Node(val, ithNode.prev, ithNode);
    if (ithNode.prev) {
      ithNode.prev.next = newNode;
    }
    ithNode.prev = newNode;
    this.size++;
  }
};

/** 
 * @param {number} index
 * @return {void}
 */
MyLinkedList.prototype.deleteAtIndex = function(index) {
  const n = this.size;
  if (!(0 <= index && index < n)) {
    return;
  }

  if (index === 0) {
    this.first = this.first?.next ?? null;
  } else if (index === n - 1) {
    this.last = this.last?.prev ?? null;
  } else {
    const ithNode = _ithNode(this, index);
    if (!ithNode) {
      throw new Error('Failed to get ithnode');
    }

    const {prev, next} = ithNode;
    (prev) && (prev.next = next);
    ithNode.prev = null;

    (next) && (next.prev = prev);
    ithNode.next = null;
  }
  this.size--;
};

/** 
 * Your MyLinkedList object will be instantiated and called as such:
 * var obj = new MyLinkedList()
 * var param_1 = obj.get(index)
 * obj.addAtHead(val)
 * obj.addAtTail(val)
 * obj.addAtIndex(index,val)
 * obj.deleteAtIndex(index)
 */

/// }}

