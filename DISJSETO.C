#include<stdio.h>
struct disjset
{
int parent[10];
int rank[10];
int n;
}dis;
void makeset()
{
int i;
for(i=0;i<dis.n;i++)
{
dis.parent[i]=i;
dis.rank[i]=0;
}
}
void display()
{
int i;
printf("\n Parent Array\n") ;
for(i=0;i<dis.n;i++)
{
printf("%d",dis.parent[i]) ;
}
printf("\nRank Array\n") ;
for(i=0;i<dis.n;i++)
{
printf("%d",dis.rank[i]) ;
}
printf("\n");
}
int find(int x)
{
if(dis.parent[x]!=x)
{
dis.parent[x]=find(dis.parent[x]) ;
}
return dis.parent[x];
}
int union(int x,int y)
{
intxset=find(x);
intyset=find(y);
if(xset==yset)
return;
if(dis.rank[xset]<dis.rank[yset])
{
dis.parent[xset]=yset ;
dis.rank[xset]=-1;
}
if(dis.rank[xset]>dis.rank[yset])
{
dis.parent[yset]=xset;
dis.rank[yset]=-1;
}
else
{
dis.parent[yset]=xset;
dis.rank[xset]=dis.rank[xset]+1;
}
}
int main()
{
int n,x,y;
printf("How many elements ?") ;
scanf("%d",&dis.n);
makeset();
int ch,wish;
do
{
printf("------MENU------");
printf("\n1.Union\n2.Find\n3.Display\n");
printf("Enter choice\n");
scanf("%d",&choice);
switch(ch)
{
case 1:
printf("Enter elements to perfom union:");
scanf("%d%d",&x,&y);
union(x,y);
break;
case 2:
printf("Enter elements to check if connected:");
scanf("%d%d",&x,&y);
if(find(x)==find(y))
printf("Connected components\n");
else
printf("Not connected components\n");
break;
case 3:
displayset();break;
}
printf("\nDo you wish to continue?(0/1)\n");
scanf("%d",&wish);
}while(wish==1);
return 0;
}



