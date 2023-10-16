#include <stdio.h>
#include <conio.h>
#include <string.h>
char Nt[10];
char ts[10];
char prod[50][10];
int i, j, k, l, m, n;
char *p;
char left[10], right[20][20];
print()
{
    printf("\n");
    printf("\n");
    printf("Enter the number of production do you want to convert ==");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter prodution number %d in the form of (X = bY) \n", i + 1);
        scanf("%s", prod[i]);
    }
    printf("\n\nThe number of productions are as below\n");
    for (i = 0; i < n; i++)
    {
        printf("%d) %s", i + 1, prod[i]);
        printf("\n");
    }
    printf("\n\nLeft linear grammar is-->\n");
    for (i = 0; i < n; i++)
    {
        p = strtok(prod[i], "=");
        left[i] = *p;
        p = strtok(NULL, "=");
        strcpy(right[i], p);
        printf("%c", right[i][1]);
        printf("--> %c%c", left[i], right[i][0]);
        printf("\n\n");
    }
    return 0;
}
void main()
{
    print();
    getch();
    clrscr();
}
