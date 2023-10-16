#include<stdio.h>
#include<conio.h>
#include<string.h>
struct prod
{
char lhs[50];
char rhs[50];
}p[30];
int first[20][20],firstp[20][20],firsts[20][20],last[20][20],lastp[20][20],lasts[20][20],equals[20][20],lt[20][20],gt[20][20],temp[20][20];
char spm[20][20];
int tot,i,j,k,cnt=0,flag=0,sum=0,count=0,n;
char sym[30],ans='y',strpar[30],str[30],st,n1;

void display(int mat[20][20])
{
printf("display Matrix");
for(i=0;i<strlen(sym);i++)
{
printf(" %c",sym[i]);
}
printf("\n");
for(i=0;i<strlen(sym);i++)
{
printf("%c ",sym[i]);

for(j=0;j<strlen(sym);j++)
{
printf("%d ",mat[i][j]);
}
printf("\n");
}
}



void main()
{
tot=0;
clrscr();
while(ans=='y')
{
printf("\n\n Enter production (LHS RHS) : ");
scanf("%s %s",&p[tot].lhs,&p[tot].rhs);//Z bMb, L Ma)
tot=tot+1;
printf("\n continue? (y/n) : ");//n
ans=getche();
}
printf("\n\n Productions are : ");
for(i=0;i<tot;i++)
printf("\n\n %s -> %s",p[i].lhs,p[i].rhs);

cnt=0;
sym[cnt]=p[0].lhs[0];//Z,b
cnt=cnt+1;
for(i=0;i<tot;i++)
{
flag=0;
for(j=0;j<strlen(sym);j++)//1
{
if(sym[j]==p[i].lhs[0])//Z=Z
flag=1;
}
if(flag==0)
{
sym[cnt]=p[i].lhs[0];
cnt=cnt+1;
}
flag=0;
for(k=0;k<strlen(p[i].rhs);k++)
{
flag=0;
for(j=0;j<strlen(sym);j++)//2
{
if(sym[j]==p[i].rhs[k])//Z==M, b==M
flag=1;
}
if(flag==0)
{
sym[cnt]=p[i].rhs[k];
cnt=cnt+1;
}
}
}


printf("\n\n sym final : \n");
for(i=0;i<strlen(sym);i++)
{
printf("\t%c",sym[i]);
}


for(i=0;i<strlen(sym);i++)
for(j=0;j<strlen(sym);j++)
{
first[i][j]=0;firstp[i][j]=0;firsts[i][j]=0;
last[i][j]=0;lastp[i][j]=0;lasts[i][j]=0;
equals[i][j]=0;lt[i][j]=0;gt[i][j]=0;spm[i][j]=0;
}





k=0;
while(k<tot)
{
for(i=0;i<strlen(sym);i++)
{
for(j=0;j<strlen(sym);j++)//Z b M L a ) (
{
if(p[k].lhs[0]==sym[i] && p[k].rhs[0]==sym[j])
{
first[i][j]=1;
k=k+1;
}
}
}
}
printf("\n\n\t press c to continue : ");
scanf("%s",&ans);
printf("\n\n FIRST MATRIX : \n ");
display(first);






for(i=0;i<strlen(sym);i++)
for(j=0;j<strlen(sym);j++)
firstp[i][j]=first[i][j];


for(i=1;i<strlen(sym);i++)
for(j=0;j<strlen(sym);j++)
if(firstp[j][i]==1)
for(k=0;k<strlen(sym);k++)
firstp[j][k]=firstp[j][k]|firstp[i][k];
printf("\n\n\t press c to continue : ");
scanf("%s",&ans);
printf("\n\n FIRST PLUS MATRIX : \n ");
display(firstp);



for(i=0;i<strlen(sym);i++)
for(j=0;j<strlen(sym);j++)
firsts[i][j]=firstp[i][j];


for(i=0;i<strlen(sym);i++)
for(j=0;j<strlen(sym);j++)
if(i==j)
firsts[i][j]=1;
printf("\n\n\t press c to continue : ");
scanf("%s",&ans);
printf("\n\n FIRST STAR MATRIX : \n ");
display(firsts);


k=0;
while(k<tot)
for(i=0;i<strlen(sym);i++)
for(j=0;j<strlen(sym);j++)//Z bMb,L Ma)
if(p[k].lhs[0]==sym[i] && p[k].rhs[strlen(p[k].rhs)-1]==sym[j])
{
last[i][j]=1;
k=k+1;
}
printf("\n\n\t press c to continue : ");
scanf("%s",&ans);
printf("\n\n LAST MATRIX : \n ");
display(last);



for(i=0;i<strlen(sym);i++)
for(j=0;j<strlen(sym);j++)
lastp[i][j]=last[i][j];


for(i=1;i<strlen(sym);i++)
for(j=0;j<strlen(sym);j++)
if(lastp[j][i]==1)
for(k=0;k<strlen(sym);k++)
lastp[j][k]=lastp[j][k]|lastp[i][k];
printf("\n\n\t press c to continue : ");
scanf("%s",&ans);
printf("\n\n LAST PLUS MATRIX : \n ");
display(lastp);


for(i=0;i<strlen(sym);i++)
for(j=0;j<strlen(sym);j++)
lasts[i][j]=lastp[i][j];


for(i=0;i<strlen(sym);i++)
for(j=0;j<strlen(sym);j++)
if(i==j)
lasts[i][j]=1;
printf("\n\n\t press c to continue : ");
scanf("%s",&ans);
printf("\n\n LAST STAR MATRIX : \n ");
display(lasts);


for(cnt=0;cnt<tot;cnt++)//bMb
{
k=0;
if(strlen(p[cnt].rhs)>1)
for(i=0;i<strlen(sym);i++)
for(j=0;j<strlen(sym);j++)
if(p[cnt].rhs[k]==sym[i] && p[cnt].rhs[k+1]==sym[j])
{
equals[i][j]=1;
k=k+1;
i=0;
}
}
printf("\n\n\t press c to continue : ");
scanf("%s",&ans);
printf("\n\n EQUALS MATRIX : \n ");
display(equals);



for(i=0;i<strlen(sym);i++)
{
for(j=0;j<strlen(sym);j++)
{
sum=0;
for(k=0;k<strlen(sym);k++)
{
sum=sum+equals[i][k]*firstp[k][j];
}
lt[i][j]=sum;
}
}
printf("\n\n\t press c to continue : ");
scanf("%s",&ans);
printf("\n\n LESS THAN MATRIX : \n ");
display(lt);



for(i=0;i<strlen(sym);i++)
{
for(j=0;j<strlen(sym);j++)
{
sum=0;
for(k=0;k<strlen(sym);k++)
{
sum=sum+lastp[k][i]*equals[k][j];
}
temp[i][j]=sum;
}
}
for(i=0;i<strlen(sym);i++)
{
for(j=0;j<strlen(sym);j++)
{
sum=0;
for(k=0;k<strlen(sym);k++)
{
sum=sum+temp[i][k]*firsts[k][j];
}
gt[i][j]=sum;
}
}
printf("\n\n\t press c to continue : ");
scanf("%s",&ans);
printf("\n\n GREATER THAN MATRIX : \n ");
display(gt);


for(i=0;i<strlen(sym);i++)
{
for(j=0;j<strlen(sym);j++)
{
if(lt[i][j]==1)
spm[i][j]='<';
if(gt[i][j]==1)
spm[i][j]='>';
if(equals[i][j]==1)
spm[i][j]='=';
if(lt[i][j]!=1&&gt[i][j]!=1&&equals[i][j]!=1)
spm[i][j]='0';
}
}
printf("\n\n\t press c to continue : ");
scanf("%s",&ans);
printf("\n\n SPM MATRIX : \n ");
for(j=0;j<strlen(sym);j++)
printf(" %c",sym[j]);
printf("\n");
for(i=0;i<strlen(sym);i++)
{
printf(" %c",sym[j]);
for(j=0;j<strlen(sym);j++)
{
 printf(" %c",spm[i][j]);
 }
 printf("\n");
}
getch();
}
