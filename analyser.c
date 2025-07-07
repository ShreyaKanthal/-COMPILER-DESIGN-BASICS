#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isKeyword(char *word) {
    char keywords[][10] = {"int", "float", "if", "else", "while", "return", "char"};
    for (int i = 0; i < 7; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char input[] = "int a = 5; float b = a + 3;";
    char word[20];
    int i = 0, j = 0;

    printf("Input Code:\n%s\n\n", input);
    printf("Lexical Analysis Output:\n");

    while (input[i] != '\0') {
        if (isalnum(input[i])) {
            word[j++] = input[i];
        } else {
            if (j > 0) {
                word[j] = '\0';
                if (isKeyword(word))
                    printf("Keyword: %s\n", word);
                else
                    printf("Identifier: %s\n", word);
                j = 0;
            }

            // Check for operators
            if (input[i] == '=' || input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/') {
                printf("Operator: %c\n", input[i]);
            }
        }
        i++;
    }

    return 0;
}
