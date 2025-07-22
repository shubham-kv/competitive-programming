/// {{
/// Problem: 1598. Crawler Log Folder
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/crawler-log-folder/
/// Topics: `array`, `string`, `stack`
/// Timestamp: `Tue, 22 Jul 2025 12:32:26 +0530`

/**
 * @param {string[]} logs
 * @return {number}
 */
function minOperations(logs) {
  /** @type {string[]} */
  const stack = [];
  const logsLen = logs.length;

  for (let i = 0; i < logsLen; i++) {
    const log = logs[i];

    if (log === "../") {
      if (stack.length > 0) {
        stack.pop();
      }
    } else if (log === "./") {

    } else {
      stack.push(log);
    }
  }

  return stack.length;
}

/// }}
