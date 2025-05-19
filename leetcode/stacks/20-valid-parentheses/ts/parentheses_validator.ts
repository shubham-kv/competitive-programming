import { Stack } from "./stack";

function isValid(s: string): boolean {
  let didEnter = false;
  let isClosingBracketMatching = true;

  const parenthesesStack = new Stack<string>();

  for (let i = 0; i < s.length; i++) {
    const currentChar = s.charAt(i);

    if (["(", "{", "["].includes(currentChar)) {
      didEnter = true;
      parenthesesStack.push(s.charAt(i));
    } else if ([")", "}", "]"].includes(currentChar)) {
      if (parenthesesStack.isEmpty()) {
        isClosingBracketMatching = false;
        break;
      }

      const lastOpeningBracket = parenthesesStack.pop();
      didEnter = true;

      if (
        (currentChar === ")" && lastOpeningBracket !== "(") ||
        (currentChar === "]" && lastOpeningBracket !== "[") ||
        (currentChar === "}" && lastOpeningBracket !== "{")
      ) {
        isClosingBracketMatching = false;
        break;
      }
    }
  }

  const valid =
    didEnter && parenthesesStack.isEmpty() ? isClosingBracketMatching : false;

  return valid;
}
