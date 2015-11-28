/*
OVERVIEW: Given a string, return the Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/
#include <stdio.h>
int findlength(char*);
char KthIndexFromEnd(char *str, int K) {
	if (str == NULL || str == "" || K < 0) {
		return '\0';
	}
	if (K > findlength(str))
		return '\0';
	int i = 0;
	while (str[i] != '\0') {
		if (str[i + K + 1] == '\0')
			return str[i];
		i++;
	}
	return '\0';
}
int findlength(char *str) {
	int i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}