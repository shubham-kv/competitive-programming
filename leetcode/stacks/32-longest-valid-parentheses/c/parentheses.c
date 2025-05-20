#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isValid(char *s)
{
  int stringLength = strlen(s);
  char stack[stringLength];
  uint32_t stackSize = 0;

  if (stringLength <= 1) {
    return false;
  }

  bool didEnter = false;
  bool doParenthesesMatch = true;

  for (int i = 0; i < stringLength; i++)
  {
    char currentChar = s[i];

    if (currentChar == '(')
    {
      didEnter = true;
      // Push onto stack
      stack[stackSize++] = currentChar;
    }
    else if (currentChar == ')')
    {
      didEnter = true;

      if (stackSize > 0 && stack[stackSize - 1] == '(') {
        // Pop from stack
        // const poppedChar = stack[stackSize - 1];
        stack[--stackSize] = '\0';
      } else {
        doParenthesesMatch = false;
        break;
      }

      // For longestValidParentheses
      // // Peek the parentheses stack for '('
      // if (stackSize > 0 && stack[stackSize - 1] == '(')
      // {
      //   // Pop from stack
      //   const poppedChar = stack[stackSize - 1];
      //   stack[stackSize - 1] = '\0';
      //   stackSize--;
      // } else { }
    }
  }

  bool result = stackSize == 0 && didEnter && doParenthesesMatch;
  return result;
}

int longestValidParentheses(char *s)
{
  int inputLength = strlen(s);

  if (inputLength <= 0)
    return 0;

  char stack[inputLength];
  uint32_t stackSize = 0;

  bool substringStarted = false;
  uint32_t longestValidSubstringLength = 0, curValidSubstringLength = 0;

  for (int i = 0; i < inputLength; i++)
  {
    char currentChar = s[i];

    if (currentChar == '(')
    {
      // Push onto stack
      stack[stackSize++] = currentChar;

      // Start a substring sequence if not already started
      if (!substringStarted) {
        substringStarted = true;
        curValidSubstringLength = 0;
      }

      // Increment current substring's length because it's valid
      curValidSubstringLength++;
    }
    else if (currentChar == ')')
    {
      // Peek the parentheses stack for '('
      if (stackSize > 0 && stack[stackSize - 1] == '(')
      {
        // Pop from stack
        stack[--stackSize] = '\0';

        // Increment current substring's length because it's valid
        curValidSubstringLength++;
      } else {
        // Parentheses don't match, started valid substring sequence ends
        if (substringStarted) {
          longestValidSubstringLength =
            curValidSubstringLength > longestValidSubstringLength
            ? curValidSubstringLength
            : longestValidSubstringLength;

          // Reset substring related state
          substringStarted = false;
          curValidSubstringLength = 0;
        }
      }
    }
  }

  if (stackSize > 0) {
    curValidSubstringLength -= stackSize;
  }

  longestValidSubstringLength =
    curValidSubstringLength > longestValidSubstringLength
    ? curValidSubstringLength
    : longestValidSubstringLength;

  return longestValidSubstringLength;
}

int main(int argc, char const *argv[])
{
  char input[128];
  printf("Enter parentheses string e.g. \"()()()(())\": ");
  fgets(input, sizeof(input), stdin);

  printf("Length of longest valid parentheses substring: %d\n", longestValidParentheses(input));
  printf("Parentheses string is %svalid.\n\n", !isValid(input) ? "not " : "");

  return 0;
}
