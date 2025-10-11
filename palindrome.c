#include <stdio.h>

char get_line(char str[]) {

	char c;
	int i=0;
	printf("Enter a line: ");

	while((c=getchar()) !=EOF && c!='\n' && i<99) {
		str[i++]=c;
	}
	str[i]='\0';

	printf("You entered %s: ", str);
	printf("\n");
	return 0;
}

void clean(char input[], char cleaned[]) {
	int i;
	int j=0;
	for(i=0;input[i]!=0;i++) {
		char c=input[i];

		if(c>='A' && c<='Z') {
			cleaned[j++]=c+32;
		}
		else if(c>='a' && c<='z' || c>='0' && c<='9' ) {
			cleaned[j++]=c;
		}

	}
	cleaned[j]='\0';
}

int isPalindrome(const char cleaned[]) {
	int end=0;
	int start=0;

	while(cleaned[end] != '\0') {
		end++;
	}
	end--; //gets the last character (the one before \0)

	while(start<end) {
		if(cleaned[start] != cleaned[end])
			return 0; //not palindrome
		end--;
		start++;
	}
	return 1; //palindrome
}

int main(){
	char line[1000];
	char nline[1000];

	get_line(line);
	clean(line, nline);
	isPalindrome(nline);
	int result= isPalindrome(nline);

	if (result)
		printf("The line is Palindrome\n");
	else
		printf("The line is not Palindrome\a\n");

	return 0;
}


