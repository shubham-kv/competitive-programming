function calPoints(operations: string[]): number {
  const record: number[] = [];
  const arrayLength = operations.length;

  for (let i = 0; i < arrayLength; i++) {
    const operation = operations[i];

    if (operation === "C") {
      record.pop();
    } else if (operation === "D") {
      const doubleOfLastRecord = record[record.length - 1] * 2;
      record.push(doubleOfLastRecord);
    } else if (operation === "+") {
      const sumOfLastTwoRecords =
        record[record.length - 1] + record[record.length - 2];
      record.push(sumOfLastTwoRecords);
    } else if (/^[-]?\d+/gi.test(operation)) {
      const newRecord = parseInt(operation);
      record.push(newRecord);
    }
  }

  let sumOfAllRecords = 0;

  while (record.length > 0) {
    sumOfAllRecords += record.pop()!;
  }

  return sumOfAllRecords;
}
