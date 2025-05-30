// Definition for a binary tree node.
class TreeNode {
  val: number;
  left: TreeNode | null;
  right: TreeNode | null;

  constructor(val?: number, left?: TreeNode | null, right?: TreeNode | null) {
    this.val = val === undefined ? 0 : val;
    this.left = left === undefined ? null : left;
    this.right = right === undefined ? null : right;
  }
}

function inorderTraversal(node: TreeNode | null): number[] {
  return !node ? [] : [
    ...inorderTraversal(node.left),
    node.val,
    ...inorderTraversal(node.right)
  ];
}

// !!Fails!! as it goes in an infinite loop
function inorderTraversalIterative(root: TreeNode | null): number[] {
  const traversal: number[] = []
  const stack: (TreeNode)[] = []

  let current: TreeNode | null = root;

  while (current) {
    console.log("🚀 ~ inorderTraversal ~ current:", current);

    if (!current.left && !current.right) {
      // Current node is a leaf node
      // 1. Visit the current leaf node (add it's value to traversal)
      traversal.push(current.val);

      // 2. Set current to it's parent (popped node from stack)
      const childNode = current;
      current = stack.pop() ?? null;

      // 3. Overwrite link to the visited node to prevent infinite loop
      if (current != null) {
        if (current.left === childNode) {
          current.left = null;
        } else if (current.right === childNode) {
          current.right = null;
        }
      }

    } else if (current.left && !current.right) {
      // Current node has only left child
      // 1. Push current node to stack
      stack.push(current);

      // 2. Set current to it's left node
      current = current.left;

    } else if (!current.left && current.right) {
      // Current node has only right child
      // 1. Visit the current root node
      traversal.push(current.val);

      // 2. Set current to it's right node
      current = current.right;

    } else if (current.left && current.right) {
      // Current node has both left & right children
      // 1. Push current node to stack
      stack.push(current);

      // 2. Set current to it's left node
      current = current.left;

    } else {
      break;
    }
  }

  return traversal;
}

const leftNode = new TreeNode(2, new TreeNode(4), new TreeNode(5, new TreeNode(6), new TreeNode(7)));
const rightNode = new TreeNode(3, null, new TreeNode(8, new TreeNode(9)));
const root = new TreeNode(1, leftNode, rightNode);
console.log(inorderTraversal(root));
