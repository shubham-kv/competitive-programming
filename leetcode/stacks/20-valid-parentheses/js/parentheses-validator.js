/**
 * @param {string} s
 * @return {boolean}
 */
function isValid(s) {
  const length = s.length;

  /** @type {string[]} */
  const stack = [];

  /** @type {string[][]} */
  const [openingBrackets, closingBrackets] = [
    ["(", "{", "["],
    [")", "}", "]"],
  ];

  /** @type {boolean[]} */
  let [doParensMatch, containsInvalidChars] = [true, false];

  for (let i = 0; i < length; i++) {
    const currentChar = s[i];

    if (openingBrackets.includes(currentChar)) {
      stack.push(currentChar);
    } else if (closingBrackets.includes(currentChar)) {
      if (stack.length === 0) {
        doParensMatch = false;
        break;
      } else {
        const popped = stack.pop();

        if (
          (currentChar === ")" && popped !== "(") ||
          (currentChar === "}" && popped !== "{") ||
          (currentChar === "]" && popped !== "[")
        ) {
          doParensMatch = false;
          break;
        }
      }
    } else {
      containsInvalidChars = true;
    }
  }

  const result = !containsInvalidChars && doParensMatch && stack.length === 0;
  return result;
}
