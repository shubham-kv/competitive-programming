#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isValid(char *s)
{
  int strLength = strlen(s);

  char stack[strLength + 1];
  uint32_t stackSize = 0;
  bool containsInvalidChars = false, doParensMatch = true;

  for (int i = 0; i < strLength; i++)
  {
    const char currentChar = s[i];

    if (currentChar == '(' || currentChar == '{' || currentChar == '[')
    {
      stack[stackSize++] = currentChar; // push opening brackets on the stack
    }
    else if (currentChar == ')' || currentChar == '}' || currentChar == ']')
    {
      if (stackSize == 0)
      {
        doParensMatch = false;
        break;
      }
      else
      {
        const char peekedChar = stack[stackSize - 1]; // peek the top of stack
        stack[--stackSize] = '\0';                    // pop from stack

        if (
            (currentChar == ')' && peekedChar != '(') ||
            (currentChar == '}' && peekedChar != '{') ||
            (currentChar == ']' && peekedChar != '['))
        {
          doParensMatch = false;
          break;
        }
      }
    }
    else
    {
      // Some invalid character encountered
      containsInvalidChars = true;
      break;
    }
  }

  bool result = !containsInvalidChars && (stackSize == 0) && doParensMatch;
  return result;
}
