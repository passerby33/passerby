#include <stdio.h>
#define MAX(a,b) a>b?a:b 
int fun(int a[],int n,int m)
{
	int min[1000][1000];
	int i=0;
	for(i=1;i<=n;i++)
	{
		min[i][1]=min[i-1][1]+a[i];
	}
	for(i=1;i<=n;i++)
	{
		for(int j=2;j<=m;j++)
		{
			int minvalue=99999;
			for(int k=1;k<i;k++)
			{
				int temp=MAX(min[i][1]-min[k][1],min[k][j-1]);
				if(temp<minvalue)
				{
					minvalue=temp;
				}
			}
			min[i][j]=minvalue;
		}
	 }
	return min[n][m];
}
int main()
{

	int n,m;
	int ret=0;
	int a[20]={0};
	FILE * p1,*p2; 
    p1 = fopen ("input.txt","r");
    p2= fopen ("output.txt","w"); 
	fscanf(p1,"%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		fscanf(p1,"%d",&a[i]);
	}
	ret=fun(a,n,m);
	fprintf(p2,"%d",ret);
	return 0;

} 
