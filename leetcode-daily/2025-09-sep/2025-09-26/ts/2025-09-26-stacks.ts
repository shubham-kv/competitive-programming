// Title: Fun with stacks
// Date: 2025-09-26
// Created: `Fri, 26 Sep 2025 10:21:10 +0530`
// Tags: [stacks, daily-practice]

/// {{
/// Problem: 150. Evaluate Reverse Polish Notation
/// Difficulty: `Medium`
/// Links: https://leetcode.com/problems/evaluate-reverse-polish-notation/
/// Timestamp: `Fri, 26 Sep 2025 10:21:47 +0530`

type Operator = "+" | "-" | "*" | "/";
const operators: Operator[] = ["+", "-", "*", "/"];

function evalRPN(tokens: string[]): number {
  const operandStack: number[] = [];

  for (const token of tokens) {
    const opToken = token as Operator;

    if (operators.includes(opToken)) {
      if (!(operandStack.length > 1)) {
        throw new Error('Invalid RPN tokens');
      }

      const num2 = operandStack.pop()!;
      const num1 = operandStack.pop()!;
      let result: number

      switch (opToken) {
        case "+": { result = num1 + num2; break; }
        case "-": { result = num1 - num2; break; }
        case "*": { result = num1 * num2; break; }
        case "/": { result = Math.trunc(num1 / num2); break; }
        default: {
          throw new Error("Invalid operator");
        }
      }

      operandStack.push(result);
    } else {
      operandStack.push(parseInt(token));
    }
  }

  const result = operandStack.pop();
  if (result === undefined) {
    throw new Error('Invalid operand stack state');
  }

  return result;
}

/// }}

