#include<stdio.h>
#include<stdlib.h>
int main()
{

int n,j,i,a[10],t;
int w[10],v[10],W,temp,amount,p[10],sol[10];


printf("\t\tFRACTIONAL KNAPSACK PROBLEM\n\n\n");

printf("ENTER NO. OF ITEMS\t:");
scanf("%d",&n);

for(i=0;i<n;i++)
{
a[i]=i;
printf("\nENTER WEIGHT OF ITEM A%d\t:",i);
scanf("%d",&w[i]);
printf("\nENTER VALUE OF ITEM A%d\t:",i);
scanf("%d",&v[i]);
}

printf("\n\nENTER MAXIMUM CAPACITY OF KNAPSACK\t:");
scanf("%d",&W);

for(i=0;i<n;i++)
p[i]=v[i]/w[i];

for(i=0;i<n;i++)
for(j=0;j<n-1;j++)
{
if(p[j]<=p[j+1])
{
temp=p[j];
p[j]=p[j+1];
p[j+1]=temp;
temp=w[j];
w[j]=w[j+1];
w[j+1]=temp;
t=a[j];
a[j]=a[j+1];
a[j+1]=t;
}
}

i=0;
amount=0;

while(W!=0)
{

if(W<w[i])
amount=W;
else
amount=w[i];
W=W-amount;
sol[i]=amount;
i++;

}

printf("FINAL SOLUTION IS\t:");

for(j=0;j<i;j++)
printf("A%d\t%d\n",a[j],sol[j]);

getch();
}
