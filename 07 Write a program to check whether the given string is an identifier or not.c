#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
void main()
{
int i,j,flag=1,len;
char str[10];
clrscr();
puts("Enter the string :: ");
gets(str);
len=strlen(str);
for(i=1,j=0;i<len;i++)
{
if(isdigit(str[0]))
{
flag=0;
break;
}
else if(isalpha(str[0]))
{
flag++;
continue;
}
if(isalnum(str[i]))
{
flag++;
continue;
}
if(str[i]=='_')
{
flag++;
continue;
}
else if(!isdigit(str[i]))
{
flag=0;
break;
}
else if(!isalnum(str[i]))
{
flag=0;
break;
}
}
if(flag==0)
puts("Not Identifier");
else
puts("Identifier");

getch();
}
