#include <stdio.h>
#include <string.h>

int main() {
    char a[5][10] = {"printf", "scanf", "if", "else", "break"};
    char str[10];
    int i, flag = 0;

    printf("Enter the string :: ");
    gets(str);

    for (i = 0; i < 5; i++) {
        if (strcmp(str, a[i]) == 0) {
            flag = 1;
            break;
        }
    }

    if (flag == 1) {
        printf("Reserved Keyword\n");
    } else {
        printf("String\n");
    }

    return 0;
}
