/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
void reverse(char*, int);
void number_to_str(float number, char *str, int afterdecimal) {
	int actualNumber = (int)number, decimalPos = -1;
	if (afterdecimal == 1) {
		actualNumber = (int)(number * (10));
		decimalPos = 1;
	}
	else if (afterdecimal == 2) {
		actualNumber = (int)(number * (10 * 10));
		decimalPos = 2;
	}
	if (number < 0)
		actualNumber = -(int)(actualNumber);
	else
		actualNumber = (int)actualNumber;
	int temp = actualNumber, remainder, i = 0, pos = 0;
	while (temp != 0) {
		if (pos++ == decimalPos)
			str[i++] = '.';
		else {
			remainder = temp % 10;
			str[i++] = (char)(48 + remainder);
			temp /= 10;
		}
	}
	if (number < 0) {
		str[i] = '-';
		i++;
	}
	str[i] = '\0';
	reverse(str, i);
}
void reverse(char *str, int len) {
	int i = 0, j = len - 1;
	char temp;
	while (i < j) {
		temp = str[i];
		str[i++] = str[j];
		str[j--] = temp;
	}
}
