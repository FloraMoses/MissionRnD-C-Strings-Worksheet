/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/
#include <stdio.h>
char removeSpaces(char *str) {
	if (str == NULL || str == "")
		return '\0';
	int i = 0, j = 0;
	char temp;
	while (str[i] != '\0') {
		if (str[i] == ' ') {
			j = i;
			while ((str[j + 1] != '\0')) {
				if (str[j] != ' ')
					break;
				j++;
			}
			if (i != j) {
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
		}
		i++;
	}
	i = 0;
	while (str[i] != '\0') {
		if (str[i] == ' ') {
			str[i] = '\0';
			break;
		}
		i++;
	}
}