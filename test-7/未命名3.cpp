#include<bits/stdc++.h>
#define Del(a,b) memset(a,b,sizeof(a))
using namespace std;
int a[4000];  //������ɵ�ҳ 
int c;//�û�ҳ������ 
void init() //����ҳ 
{
	srand((unsigned int)time(NULL));
	for(int i=1;i<=320;i++)
	{
		int q=rand()%317;
		//a[i++]=q/10;
		a[i++]=(q+1)/10;
		int head=rand()%(q+2);
		//a[i++]=head/10;
		a[i++]=(head+1)/10;
		int tail=(rand()%(318-q))+q+3;
		a[i]=tail/10;
		//a[i]=(tail+1)/10;
	}
	c=(rand()%29)+4;
}
struct node
{
	int dis,val,pos;  //������һ����ͬԪ�صľ��룬Ԫ�أ�λ�� 
	node(){}
	node(int dd,int vv,int pp)
	{
		dis=dd;val=vv;pos=pp;
	}
	bool operator < (const node & a) const  //���ȶ��� 
	{
		if(a.dis!=dis) return a.dis>dis;
		else return a.val>val;
	}
};
void OPT() //�����̭�� �����ȶ���ʵ�֣� 
{
	
	int poss[400];
	int lack=0;
	int head[400],net[400];  //��ӱ�洢������� 
	Del(head,-1);
	Del(poss,0);
	
	priority_queue<node> q;
	for(int i=1;i<=320;i++)
	{
		net[i]=head[a[i]];
		head[a[i]]=i;
	}
	int t=1,tt=1;
	for(int i=1;i<=320;i++) //��������  cҳ
	{
		if(!poss[a[i]])
		{
			poss[a[i]]=t;
			t++;
		}
		q.push(node(net[i],a[i],poss[a[i]]));
		tt=i;
		if(t>c)
		break;
	}
	if(t<=c) 
	{
		printf("100%% ������\n");
		return; 
	} 
	for(int i=tt+1;i<=320;i++)
	{
		if(!poss[a[i]])
		{
			lack++;
			node p=q.top();
			q.pop();
			poss[a[i]]=p.pos;
			poss[p.val]=0;
		}
		q.push(node(net[i],a[i],poss[a[i]]));
	}
	printf("ȱҳ�� %d\n",lack);
	printf("%lf%%������\n",(1.0-((1.0*lack)/(1.0*320)))*100.0); 
}
void FIFO()
{
	int aim[400];
	int vis[400];
	Del(vis,0);
	int lack=0;
	int t=0,tt=0;
	queue<int>q;
	for(int i=1;i<=320;i++)
	{
		if(!vis[a[i]])
		{
			vis[a[i]]=1;
			t++;
			q.push(a[i]);
		}
		tt=i;
		if(t>c)
		break;
	}
	if(t<=c)
	{
		printf("100%% ������\n");
		return;
	}
	for(int i=tt+1;i<320;i++)
	{
		if(!vis[a[i]])
		{
			vis[a[i]]=1;
			vis[q.front()]=0;
			q.pop();
			lack++;
			q.push(a[i]);
		}
	}
	printf("ȱҳ�� %d\n",lack);
	printf("%lf%%������\n",(1.0-((1.0*lack)/(1.0*320)))*100.0);
}
void LRU()
{
	int time[400]={0};
	int vis[400]={0};
	int lack=0;
	int t=0,tt=0;
	queue<int>q;
	for(int i=1;i<=320;i++)
	{
		if(!vis[a[i]])
		{
			vis[a[i]]=1;
			t++;	
		}
		q.push(a[i]);
		time[a[i]]++;
		tt=i;
		if(t>c)
		break;
	}
	if(t<=c)
	{
		printf("100%% ������\n");
		return;
	}
	for(int i=tt+1;i<320;i++)
	{
		if(!vis[a[i]])
		{
			while(time[q.front()])
			{
				time[q.front()]--;
				if(time[q.front()]==0)
				break;
				q.pop();
			}
			vis[q.front()]=0;
			q.pop();
			vis[a[i]]=1;
			time[a[i]]++;
			q.push(a[i]);
			lack++;
		}
		q.push(a[i]);
		time[a[i]]++;
	}
	printf("ȱҳ�� %d\n",lack); 
	printf("%lf%%������\n",(1.0-((1.0*lack)/(1.0*320)))*100.0);
}
int main()
{
	//printf("!!\n");
	init();
	printf("OPT:\n");
	OPT();  //���ȶ��� 
	printf("FIFO:\n");
	FIFO(); //���� 
	printf("LRU:\n");
	LRU();  //���� 
}

