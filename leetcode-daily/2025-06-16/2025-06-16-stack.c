// Title: Fun with stacks
// Date: 2025-06-16
// Created: Mon, 16 Jun 2025 18:31:42 +0530
// Tags: [stacks, daily-practice]

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/// {{
/// Problem: 20. Valid Parentheses
/// Links: https://leetcode.com/problems/valid-parentheses/

bool isValid(char* s) {
  int n = strlen(s);
  char stack[n];
  int stackSize = 0;

  bool doParensMatch = true;
  bool containsInvalidChars = false;

  for (int i = 0; i < n; i++) {
    const char cur = s[i];

    if (cur == '(' || cur == '{' || cur == '[') {
      stack[stackSize++] = cur;
    } else if (cur == ')' || cur == '}' || cur == ']') {
      if (stackSize > 0) {
        const char popped = stack[--stackSize];

        if (
          (popped == '(' && cur != ')') ||
          (popped == '{' && cur != '}') ||
          (popped == '[' && cur != ']')
        ) {
          doParensMatch = false;
          break;
        }
      } else {
        doParensMatch = false;
        break;
      }
    } else {
      containsInvalidChars = true;
      break;
    }
  }

  bool result = stackSize == 0 && !containsInvalidChars && doParensMatch;
  return result;
}

/// }}

/// {{
/// Problem: 150. Evaluate Reverse Polish Notation
/// Links: https://leetcode.com/problems/evaluate-reverse-polish-notation/

int evalRPN(char **tokens, int tokensSize) {
  int operandsStack[tokensSize], operandsStackSize = 0;

  for (int i = 0; i < tokensSize; i++) {
    const char *curToken = tokens[i];
    const int curTokenLength = strlen(curToken);

    if (
        curTokenLength == 1 && (*curToken == '+' ||
                                *curToken == '-' ||
                                *curToken == '*' ||
                                *curToken == '/'))
    {
      if (operandsStackSize >= 2)
      {
        const int operandB = operandsStack[--operandsStackSize];
        const int operandA = operandsStack[--operandsStackSize];
        int result;

        switch (*curToken) {
          case '+': {
            result = operandA + operandB;
            break;
          }
          case '-': {
            result = operandA - operandB;
            break;
          }
          case '*': {
            result = operandA * operandB;
            break;
          }
          case '/': {
            result = operandA / operandB;
            break;
          }
        }

        operandsStack[operandsStackSize++] = result;
      }
      else
      {
        break;
      }
    }
    else {
      int operand = 0;
      sscanf(curToken, "%d", &operand);
      operandsStack[operandsStackSize++] = operand;
    }
  }

  return operandsStack[0];
}

/// }}

/// {{
/// Problem: 1472. Design Browser History
/// Links: https://leetcode.com/problems/design-browser-history/

typedef struct ListNode {
  char *url;
  struct ListNode *prev;
} ListNode;

typedef struct {
  ListNode *currentPage;
  int pageSize;
} BrowserHistory;

BrowserHistory *browserHistoryCreate(char *homepage);
void browserHistoryVisit(BrowserHistory *history, char *url);

BrowserHistory *browserHistoryCreate(char *homepage) {
  BrowserHistory *history = calloc(1, sizeof(BrowserHistory));
  history->currentPage = NULL;
  history->pageSize = 0;
  browserHistoryVisit(history, homepage);

  return history;
}

void browserHistoryVisit(BrowserHistory *history, char *url) {
  ListNode *newPage = calloc(1, sizeof(ListNode));
  newPage->url = url;
  newPage->prev = history->currentPage;

  history->currentPage = newPage;
  history->pageSize++;
}

char *browserHistoryBack(BrowserHistory *history, int steps) {
}

char *browserHistoryForward(BrowserHistory *history, int steps) {
}

void browserHistoryFree(BrowserHistory *history) {
}

/**
 * Your BrowserHistory struct will be instantiated and called as such:

 * BrowserHistory* history = browserHistoryCreate(homepage);
 * browserHistoryVisit(history, url);
 * char* param_2 = browserHistoryBack(history, steps);
 * char* param_3 = browserHistoryForward(history, steps);
 * browserHistoryFree(history);
*/

/// }}
