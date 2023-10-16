#include<stdio.h>
#include<conio.h>
#include<string.h>
struct prod
{
char lhs[50];
char rhs[50];
}p[30];
int first[20][20],firstp[20][20],firsts[20][20],last[20][20],lastp[20][20],lasts[20][20],equals[20][20],lt[20][20],gt[20][20],temp[20][20],last_term[20][20],first_term[20][20],temp1[20][20],temp2[20][20];
char opm[20][20];
int tot,i,j,k,cnt=0,flag=0,sum=0,count=0,n;
char sym[30],ans='y',strpar[30],str[30],st,n1,ch='\0';
void display(int mat[20][20])
{
//printf("display Matrix");
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
scanf("%s %s",&p[tot].lhs,&p[tot].rhs);
tot=tot+1;
printf("\n continue? (y/n) : ");
ans=getche();
}
printf("\n\n Productions are : ");
for(i=0;i<tot;i++)
printf("\n\n %s -> %s",p[i].lhs,p[i].rhs);

cnt=0;
sym[cnt]=p[0].lhs[0];
cnt=cnt+1;
for(i=0;i<tot;i++)
{
flag=0;
for(j=0;j<strlen(sym);j++)
{
if(sym[j]==p[i].lhs[0])
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
for(j=0;j<strlen(sym);j++)
{
if(sym[j]==p[i].rhs[k])
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
last_term[i][j]=0;first_term[i][j]=0;temp1[i][j]=0;temp2[i][j]=0;
first[i][j]=0;firstp[i][j]=0;firsts[i][j]=0;
last[i][j]=0;lastp[i][j]=0;lasts[i][j]=0;
equals[i][j]=0;lt[i][j]=0;gt[i][j]=0;opm[i][j]=0;
}
k=0;
while(k<tot)
{
for(i=0;i<strlen(sym);i++)
{
for(j=0;j<strlen(sym);j++)
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
for(j=0;j<strlen(sym);j++)
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
for(cnt=0;cnt<tot;cnt++)
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
cnt=0;



while(cnt<tot)
{
for(k=0;k<strlen(p[cnt].rhs);k++)
{
if(!isupper(p[cnt].rhs[k]))
for(i=0;i<strlen(sym);i++)
for(j=0;j<strlen(sym);j++)
if(p[cnt].lhs[0]==sym[i]&&p[cnt].rhs[k]==sym[j])
{
first_term[i][j]=1;
flag=1;
}
if(flag==1)
break;
}
cnt++;
flag=0;
}
printf("\n\n\t press c to continue : ");
scanf("%s",&ans);
printf("\n\n FIRST TERM MATRIX : \n ");
display(first_term);



cnt=0;
while(cnt<tot)
{
for(k=0;k<strlen(p[cnt].rhs);k++)
{
if(!isupper(p[cnt].rhs[k]))
ch=p[cnt].rhs[k];
}
if(ch!='\0')
for(i=0;i<strlen(sym);i++)
for(j=0;j<strlen(sym);j++)
if(p[cnt].lhs[0]==sym[i]&&ch==sym[j])
last_term[i][j]=1;
cnt++;
ch='\0';
}
printf("\n\n\t press c to continue : ");
scanf("%s",&ans);
printf("\n\n LAST TERM MATRIX : \n ");
display(last_term);


for(i=0;i<strlen(sym);i++)
{
for(j=0;j<strlen(sym);j++)
{
sum=0;
for(k=0;k<strlen(sym);k++)
{
cnt=equals[i][k]*firsts[k][j];
sum=sum+cnt;
}
temp1[i][j]=sum;
}
}
for(i=0;i<strlen(sym);i++)
{
for(j=0;j<strlen(sym);j++)
{
sum=0;
for(k=0;k<strlen(sym);k++)
{
cnt=temp1[i][k]*first_term[k][j];
sum=sum+cnt;
}
lt[i][j]=sum;
}
}
printf("\n\n\t press c to continue : ");
scanf("%s",&ans);
printf("\n\n LESS THAN MATRIX : \n ");
display(lt);

cnt=0;
for(i=0;i<strlen(sym);i++)
{
for(j=0;j<strlen(sym);j++)
{
sum=0;
for(k=0;k<strlen(sym);k++)
{
cnt=lasts[i][k]*last_term[k][j];
sum=sum+cnt;
}
temp1[i][j]=sum;
}
}
cnt=0;
for(i=0;i<strlen(sym);i++)
{
for(j=0;j<strlen(sym);j++)
{
sum=0;
for(k=0;k<strlen(sym);k++)
{
cnt=temp1[k][i]*equals[k][j];
sum=sum+cnt;
}
temp2[i][j]=sum;
}
}
cnt=0;
for(i=0;i<strlen(sym);i++)
{
for(j=0;j<strlen(sym);j++)
{
sum=0;
for(k=0;k<strlen(sym);k++)
{
cnt=temp2[i][k]*firsts[k][j];
sum=sum+cnt;
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
equals[i][j]=0;
}

for(i=0;i<tot;i++)
{
k=0;
for(j=0;j<strlen(p[i].rhs);j++)
{
if(isupper(p[i].rhs[j]))
k--;//0
else
k++;//1
}
if(k==2||k==1 && strlen(p[i].rhs)>1)
{
for(j=0;j<strlen(sym);j++)
{
if(p[i].rhs[0]==sym[j])
{
for(k=0;k<strlen(sym);k++)
if(p[i].rhs[strlen(p[i].rhs)-1]==sym[k])
equals[j][k]=1;
}
}
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
if(lt[i][j]==1)
opm[i][j]='<';
if(gt[i][j]==1)
opm[i][j]='>';
if(equals[i][j]==1)
opm[i][j]='=';
if(lt[i][j]!=1&&gt[i][j]!=1&&equals[i][j]!=1)
opm[i][j]='0';
}
}
printf("\n\n\t press c to continue : ");
scanf("%s",&ans);



printf("\n\nOperator Precedence Matrix :\n\n  ");
for(i=0;i<strlen(sym);i++)
{
if(!isupper(sym[i]))
printf("%c ",sym[i]);
}
printf("\n");
for(i=0;i<strlen(sym);i++)
{
if(!isupper(sym[i]))
{
printf("%c ",sym[i]);
for(j=0;j<strlen(sym);j++)
{
if(!isupper(sym[j]))
printf("%c ",opm[i][j]);
}
printf("\n");
}
}
getch();
}
