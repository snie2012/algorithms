#include <stdio.h>
#include <stdlib.h>

void reverse_string(char *str) {
	char* end = str;
	char tmp;
	if (str) {
		while (*end) end++;
		end--;
		while(str < end) {
			tmp = *str;
			*str++ = *end;
			*end-- = tmp;
		}
	}
}

int main() {
	char str[] = "this";
	reverse_string(str);
	printf("%s\n", str);
	return EXIT_SUCCESS;
}