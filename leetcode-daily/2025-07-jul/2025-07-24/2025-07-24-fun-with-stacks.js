// Title: Fun with stacks
// Date: 2025-07-24
// Created: `Thu, 24 Jul 2025 18:24:16 +0530`
// Tags: [stacks, daily-practice]

/// {{
/// Problem: 150. Evaluate Reverse Polish Notation
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/evaluate-reverse-polish-notation/
/// Topics: `array`, `math`, `stack`
/// Timestamp: `Thu, 24 Jul 2025 18:24:16 +0530`

const isOperator = (/** @type {string} */ c) =>
  c === "+" || c === "-" || c === "*" || c === "/";

/**
 * @param {string[]} tokens
 * @return {number}
 */
function evalRPN(tokens) {
  /** @type {number[]} */
  const operandsStack = [];

  for (const token of tokens) {
    if (token.length === 1 && isOperator(token)) {
      if (operandsStack.length > 1) {
        /** @type {number[]} */
        const [opB, opA] = [operandsStack.pop(), operandsStack.pop()];

        switch (token) {
          case "+":
            operandsStack.push(opA + opB);
            break;
          case "-":
            operandsStack.push(opA - opB);
            break;
          case "*":
            operandsStack.push(opA * opB);
            break;
          case "/":
            operandsStack.push(Math.trunc(opA / opB));
            break;
        }
      }
    } else {
      operandsStack.push(parseInt(token));
    }
  }

  return operandsStack.length > 0 ? operandsStack[0] : 0;
}

/// }}
