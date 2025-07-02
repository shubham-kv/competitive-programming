// Title: Fun with stacks
// Date: 2025-07-02
// Created: Wed, 02 Jul 2025 10:57:47 +0530
// Tags: [stacks, daily-practice]

#include <stdlib.h>
#include <string.h>
#include <memory.h>

/// {{
/// Problem: 2000. Reverse Prefix of Word
/// Difficulty: `Easy`
/// Links: https://leetcode.com/problems/reverse-prefix-of-word/
/// Topics: `two-pointers`, `string`, `stack`
/// Timestamp: `Wed, 02 Jul 2025 11:01:51 +0530`

char *reversePrefix(char* word, char ch) {
	int n = strlen(word);
	int i;

	for (i = 0; i < n; i++) {
		if (ch == word[i]) {
			break;
		}
	}

	if (i >= n) {
		return word;
	}

	char *result = calloc(n + 1, sizeof(char));

	for (int j = i, k = 0; k < n; k++) {
		if (k <= i) {
			result[k] = word[j--];
		} else {
			result[k] = word[k];
		}
	}

	return result;
}

/// }}

