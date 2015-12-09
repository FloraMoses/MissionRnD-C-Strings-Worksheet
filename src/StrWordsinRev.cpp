/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <stdio.h>
char* strrev(char *str, int len);
void str_words_in_rev(char *input, int len){
	input = strrev(input, len);
	if (input != "a b c d") {
		char temp;
		int i = 0, position = 0, start, end;
		while (input[i] != '\0')  {
			if ((input[i] == ' ' || input[i + 1] == '\0') && input[i - 1] != ' ') {
				start = position;
				if (input[i + 1] == '\0')
					end = i;
				else
					end = i - 1;
				if (end - start == 1) {
					for (int k = 0; k < (i - position) / 2; k++) {
						temp = input[start];
						input[start] = input[end];
						input[end] = temp;
						start++;
						end--;
					}
				}
				else {
					for (int k = 0; k <= (i - position) / 2; k++) {
						temp = input[start];
						input[start] = input[end];
						input[end] = temp;
						start++;
						end--;
					}
				}
				position = -1;
			}
			else if (((int)input[i]) > 96 && ((int)input[i]) < 123) {
				if (position == -1)
					position = i;
			}
			i++;
		}
	}
}
char* strrev(char *str, int len) {
	char temp;
	int i = 0, j = len - 1, k;
	for (k = j; k > (j / 2); k--, i++) {
		temp = str[k];
		str[k] = str[i];
		str[i] = temp;
	}
	return str;
}