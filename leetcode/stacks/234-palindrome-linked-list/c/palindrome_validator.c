#include <stdbool.h>
#include <stdio.h>
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
  if (IS_NULL(head))
    return false;

  // Calculate the size of the linked list
  for (fastPointer = head; IS_NOT_NULL(fastPointer); fastPointer = fastPointer->next)
    listSize++;

  if (listSize == 1)
    return true;

  stackInit(&stack);

  // Get to the middle of the linked list with fast & slow pointers and push the
  // first half nodes to stack
  for (
      fastPointer = head, slowPointer = head;
      IS_NOT_NULL(fastPointer) && IS_NOT_NULL(slowPointer);)
  {
    stackPush(&stack, slowPointer->val);

    // Increment
    slowPointer = slowPointer->next;

    if (IS_NOT_NULL(fastPointer->next))
      fastPointer = fastPointer->next->next;
    else
      break;
  }

  // Pop the middle node for odd sized lists
  if (listSize > 0 && listSize % 2 == 1) {
    stackPop(&stack);
  }

  // Start popping items and compare them
  for (; IS_NOT_NULL(slowPointer); slowPointer = slowPointer->next)
  {
    if (slowPointer->val != stackPop(&stack))
    {
      doesSecondHalfMatch = false;
      break;
    }
  }

  bool result = IS_STACK_EMPTY(&stack) && doesSecondHalfMatch;
  stackClear(&stack);

  return result;
}

int main(int argc, char const *argv[])
{
  struct ListNode node5 = {.val = 1, .next = NULL};
  struct ListNode node4 = {.val = 1, .next = NULL};
  struct ListNode node3 = {.val = 2, .next = &node4};
  struct ListNode node2 = {.val = 2, .next = &node3};
  struct ListNode node1 = {.val = 1, .next = &node2};
  printf("Is the list palindrome ? %s\n", isPalindrome(&node1) ? "Yes" : "No");

  return 0;
}
