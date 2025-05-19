#include <stdbool.h>
#include <stdlib.h>

#include "stack.h"

bool isValid(char *s)
{
  // Variables
  char *currentChar = s;
  bool isClosingBracketMatching = true;
  uint32_t count = 0;

  // Create the stack
  void *parenthesesStack = stackCreate();

  // Loop through individual characters
  while (*currentChar != '\0')
  {
    if (*currentChar == '(' || *currentChar == '{' || *currentChar == '[')
    {
      char *openingBracket = calloc(2, sizeof(char));
      openingBracket[0] = *currentChar;
      stackPush(parenthesesStack, openingBracket);
      ++count;
    }
    else if (*currentChar == ')')
    {
      char *lastOpeningBracket = stackPop(parenthesesStack);
      if (lastOpeningBracket[0] != '(')
      {
        isClosingBracketMatching = false;
        break;
      }
      ++count;
    }
    else if (*currentChar == '}')
    {
      char *lastOpeningBracket = stackPop(parenthesesStack);
      if (lastOpeningBracket[0] != '{')
      {
        isClosingBracketMatching = false;
        break;
      }
      ++count;
    }
    else if (*currentChar == ']')
    {
      char *lastOpeningBracket = stackPop(parenthesesStack);
      if (lastOpeningBracket[0] != '[')
      {
        isClosingBracketMatching = false;
        break;
      }
      ++count;
    }
    currentChar++;
  }

  // Return the result
  bool result = IS_STACK_EMPTY(parenthesesStack) && count > 0 ? isClosingBracketMatching : false;

  // Memory cleanup
  while (!IS_STACK_EMPTY(parenthesesStack))
    free(stackPop(parenthesesStack));

  stackDelete(parenthesesStack);

  return result;
}
