#include <stdbool.h>
#include <stdlib.h>
#include "linked_list.h"
#include "stack.h"

#define IS_NULL(p) (NULL == p)
#define IS_NOT_NULL(p) (NULL != p)

bool isPalindrome(struct ListNode *head)
{
  // Variables
  uint32_t listSize = 0;
  bool doesSecondHalfMatch = true;
  struct ListNode *fastPointer, *slowPointer;
  struct Stack stack;

  // Early return
  if (IS_NULL(head)) {
    return false;
  }

  // Calculate the size of the linked list
  for (fastPointer = head; IS_NOT_NULL(fastPointer); fastPointer = fastPointer->next)
    listSize++;

  stackInit(&stack);

  // Get to the middle of the linked list with fast & slow pointers and push the
  // first half nodes to stack
  for (
      fastPointer = head, slowPointer = head;
      IS_NOT_NULL(fastPointer) && IS_NOT_NULL(slowPointer);)
  {
    struct Node node = {.data = slowPointer->val};
    stackPush(&stack, &node);

    slowPointer = slowPointer->next;

    if (IS_NULL(fastPointer->next))
    {
      break;
    }

    fastPointer = fastPointer->next->next;
  }

  // Pop the middle node
  if (listSize > 0)
    stackPop(&stack);

  // Start popping items and compare them
  for (; IS_NOT_NULL(slowPointer); slowPointer = slowPointer->next)
  {
    struct Node *topNode = stackPop(&stack);

    if (slowPointer->val != topNode->data)
    {
      doesSecondHalfMatch = false;
      break;
    }
  }

  stackClear(&stack);

  return doesSecondHalfMatch;
}
