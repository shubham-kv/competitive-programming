#include <stdbool.h>
#include <stdlib.h>

#include "stack.h"

bool isValid(char *s)
{
  // Variables
  char *currentChar = s;
  bool isBalanced = true;
  bool didEnter = false;

  // Create the stack
  void *parenthesesStack = stackCreate();

  // Loop through individual characters
  while (currentChar != NULL && *currentChar != '\0')
  {
    if (*currentChar == '(' || *currentChar == '{' || *currentChar == '[')
    {
      char *openingBracket = calloc(2, sizeof(char));
      openingBracket[0] = *currentChar;
      stackPush(parenthesesStack, openingBracket);
      didEnter = true;
    }
    else if (*currentChar == ')' || *currentChar == '}' || *currentChar == ']')
    {
      didEnter = true;

      if (IS_STACK_EMPTY(parenthesesStack))
      {
        isBalanced = false;
        break;
      }
      else
      {
        char *lastOpeningBracket = stackPop(parenthesesStack);

        if (
            (*currentChar == ')' && *lastOpeningBracket != '(') ||
            (*currentChar == '}' && *lastOpeningBracket != '{') ||
            (*currentChar == ']' && *lastOpeningBracket != '['))
        {
          isBalanced = false;
          break;
        }
      }
    }

    currentChar++;
  }

  // Return the result
  bool result = IS_STACK_EMPTY(parenthesesStack) && didEnter && isBalanced;

  // Memory cleanup
  while (!IS_STACK_EMPTY(parenthesesStack))
    free(stackPop(parenthesesStack));

  stackDelete(parenthesesStack);

  return result;
}
