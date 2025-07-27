#include <stdio.h>
#include <string.h>
#include <ctype.h>

char keywords[][10] = {"int", "float", "if", "else", "while", "for", "return"};
char operators[] = "+-*/=<>";

int isKeyword(char *word) {
	int i;
    for (i = 0; i < 7; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int isOperator(char ch) {
	int i;
    for (i = 0; i < strlen(operators); i++) {
        if (ch == operators[i])
            return 1;
    }
    return 0;
}

int main() {
    char input[1000];
    char word[50];
    int i = 0, j = 0;

    printf("Enter your code:\n");
    getchar(); // clear buffer
    fgets(input, sizeof(input), stdin);

    while (input[i] != '\0') {
        if (isalnum(input[i])) {
            word[j++] = input[i];
        } else {
            word[j] = '\0';
            if (j > 0) {
                if (isKeyword(word))
                    printf("Keyword: %s\n", word);
                else
                    printf("Identifier: %s\n", word);
                j = 0;
            }
            if (isOperator(input[i]))
                printf("Operator: %c\n", input[i]);
        }
        i++;
    }

    return 0;
}
