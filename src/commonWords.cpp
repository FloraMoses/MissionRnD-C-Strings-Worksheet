/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include <stdbool.h>
#define SIZE 31
bool strcmp(char*, char*);
bool isSpaces(char*);
char ** commonWords(char *str1, char *str2) {
	if (str1 == NULL || str2 == NULL)
		return NULL;
	if (isSpaces(str1) || isSpaces(str2))
		return NULL;
	char *result[SIZE], tokens1[5][SIZE], tokens2[5][SIZE];
	int i = 0, count = -1, count_res = 0, count_1 = 0, count_2 = 0, index;
	while (str1[i] != '\0') {
		if (str1[i] == ' ' || str1[i + 1] == '\0') {
			if (str1[i + 1] == '\0') {
				for (int k = count, h = 0; k <= i; k++, h++) {
					tokens1[count_1][h] = str1[k];
					index = h;
				}
				tokens1[count_1][index + 1] = '\0';
				count_1++;
			}
			else {
				for (int k = count, h = 0; k < i; k++, h++) {
					tokens1[count_1][h] = str1[k];
					index = h;
				}
				tokens1[count_1][index + 1] = '\0';
				count_1++;
			}
			count = -1;
		}
		else
			if (count == -1)
				count = i;
		i++;
	}
	i = 0, count = -1;
	while (str2[i] != '\0') {
		if (str2[i] == ' ' || str2[i + 1] == '\0') {
			if (str2[i + 1] == '\0') {
				for (int k = count, h = 0; k <= i; k++, h++) {
					tokens2[count_2][h] = str2[k];
					index = h;
				}
				tokens2[count_2][index + 1] = '\0';
				count_2++;
			}
			else {
				for (int k = count, h = 0; k < i; k++, h++) {
					tokens2[count_2][h] = str2[k];
					index = h;
				}
				tokens2[count_2][index + 1] = '\0';
				count_2++;
			}
			count = -1;
		}
		else
			if (count == -1)
				count = i;
		i++;
	}
	for (int m = 0; m < count_1; m++) {
		for (int n = 0; n < count_2; n++) {
			if (strcmp(tokens1[m], tokens2[n])){
				result[count_res] = tokens1[m];
				printf("%s", result[count_res]);
				count_res++;
			}
		}
	}
	if (count_res == 0)
		return NULL;
	return result;
}
bool strcmp(char *str1, char *str2) {
	while (*str1 && *str2) {
		if (*str1 != *str2) {
			return false;
		}
		str1++;
		str2++;
	}
	return !*str1 && !*str2;
}
bool isSpaces(char *str) {
	int i = 0;
	while (str[i] != '\0') {
		if (str[i] != ' ')
			return false;
		i++;
	}
	return true;
}