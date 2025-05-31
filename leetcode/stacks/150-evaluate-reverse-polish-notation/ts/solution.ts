function evalRPN(tokens: string[]): number {
  const tokensLength = tokens.length;
  const operands: number[] = [];

  for (let i = 0; i < tokensLength; i++) {
    const token = tokens[i];

    if (["+", "-", "*", "/"].includes(token)) {
      const operandB = operands.pop();
      const operandA = operands.pop();

      if (operandA != undefined && operandB != undefined) {
        let result =
          token === "+"
            ? operandA + operandB
            : token === "-"
            ? operandA - operandB
            : token === "*"
            ? operandA * operandB
            : token === "/"
            ? Math.trunc(operandA / operandB)
            : undefined;

        if (result !== undefined) {
          operands.push(result);
        }
      }
    } else if (/^[-]?\d+$/gi.test(token)) {
      operands.push(parseInt(token));
    }
    console.log(operands);
  }

  const result = operands.pop() ?? -1;
  return result;
}

console.log(evalRPN(["2", "1", "+", "3", "*"]));
console.log(evalRPN(["4", "13", "5", "/", "+"]));
console.log(
  evalRPN(["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"])
);
