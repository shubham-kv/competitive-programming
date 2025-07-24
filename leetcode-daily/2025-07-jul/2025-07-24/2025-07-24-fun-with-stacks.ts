// Title: Fun with stacks
// Date: 2025-07-24
// Created: `Thu, 24 Jul 2025 18:36:37 +0530`
// Tags: [stacks, daily-practice]

/// {{
/// Problem: 150. Evaluate Reverse Polish Notation
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/evaluate-reverse-polish-notation/
/// Topics: `array`, `math`, `stack`
/// Timestamp: `Thu, 24 Jul 2025 18:36:37 +0530`

const isOperator = (c: string) =>
  c === "+" || c === "-" || c === "*" || c === "/";

function evalRPN(tokens: string[]): number {
  const operandsStack: number[] = [];

  for (const token of tokens) {
    const tokenLen = token.length;

    if (tokenLen == 1 && isOperator(token)) {
      if (operandsStack.length > 1) {
        const [opB, opA] = [operandsStack.pop(), operandsStack.pop()];

        switch (token) {
          case "+":
            operandsStack.push(opA! + opB!);
            break;
          case "-":
            operandsStack.push(opA! - opB!);
            break;
          case "*":
            operandsStack.push(opA! * opB!);
            break;
          case "/":
            operandsStack.push(Math.trunc(opA! / opB!));
            break;
          default:
            break;
        }
      }
    } else {
      operandsStack.push(parseInt(token));
    }
  }

  return operandsStack.pop() ?? 0;
}

/// }}
