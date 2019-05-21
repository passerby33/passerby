#include <stdio.h>
#include <stdlib.h>
#include <windows.h> 
#define TRUE 1
#define FALSE 0
#define INVALID -1
#define NULL 0
#define total_instruction 320 /* ָ������ */
#define total_vp 32
#define clear_period 50 /* �� 0 ����*/
typedef struct /* ҳ��ṹ */
{
int pn,pfn,counter,time;
} pl_type;
pl_type pl[total_vp]; /* ҳ��ṹ���� */
struct pfc_struct{ /* ҳ����ƽṹ */
int pn,pfn;
struct pfc_struct *next;
};
typedef struct pfc_struct pfc_type;
pfc_type
pfc[total_vp],*freepf_head,*busypf_head,*busypf_tail;
int diseffect, a[total_instruction];
int page[total_instruction], offset[total_instruction];
int initialize(int);
int FIFO(int);
int LRU(int);
int LFU(int); 

int NUR(int);
int OPT(int);
int main( )
{
 int s,i,j;
 srand(10*getpid()); /* ����ÿ������ʱ���̺Ų�ͬ��
�ʿ�������Ϊ��ʼ����������еġ����ӡ� */
s=(float)319*rand( )/32767/32767/2+1; //
for(i=0;i<total_instruction;i+=4) /* ����ָ����� */
{
 if(s<0||s>319)
 {
 printf("When i==%d,Error,s==%d\n",i,s);
 exit(0);
 }
 a[i]=s; /* ��ѡһָ����ʵ� m*/
 a[i+1]=a[i]+1; /* ˳��ִ��һ��ָ�� */
 a[i+2]=(float)a[i]*rand( )/32767/32767/2; /* ִ��ǰ��ַָ
�� m' */
 a[i+3]=a[i+2]+1; /* ˳��ִ��һ��ָ�� */
 s=(float)(318-a[i+2])*rand( )/32767/32767/2+a[i+2]+2;
 if((a[i+2]>318)||(s>319))
 printf("a[%d+2],a number which is :%d ands==%d\n",i,a[i+2],s);
}
for (i=0;i<total_instruction;i++) /* ��ָ�����б任��ҳ��ַ�� */
{
 page[i]=a[i]/10;
 offset[i]=a[i]%10;
}
for(i=4;i<=32;i++) /* �û��ڴ湤������ 4 ��ҳ�浽 32 ��ҳ�� */
{ 

 printf("---%2d page frames---\n",i);
 FIFO(i);
 LRU(i);
 LFU(i);
 NUR(i);
 OPT(i);
}
 return 0;
}
int initialize(total_pf); /* ��ʼ��������ݽṹ */
int total_pf; /* �û����̵��ڴ�ҳ���� */
{int i;
diseffect=0;
for(i=0;i<total_vp;i++)
{
 pl[i].pn=i;
 pl[i].pfn=INVALID; /* ��ҳ����ƽṹ�е�ҳ�ţ�ҳ��Ϊ�� */
 pl[i].counter=0;
 pl[i].time=-1;/* ҳ����ƽṹ�еķ��ʴ���Ϊ 0��ʱ��Ϊ -1*/
}
for(i=0;i<total_pf-1;i++)
{
 pfc[i].next=&pfc[i+1];
 pfc[i].pfn=i;
} /* ���� pfc[i-1] �� pfc[i] ֮������� */
pfc[total_pf-1].next=NULL;
pfc[total_pf-1].pfn=total_pf-1;
freepf_head=&pfc[0]; /* ��ҳ����е�ͷָ��Ϊ pfc[0]*/
return 0;
} 

int FIFO(total_pf) /* �Ƚ��ȳ��㷨 */
int total_pf; /* �û����̵��ڴ�ҳ���� */
{
 int i,j;
 pfc_type *p;
 initialize(total_pf); /* ��ʼ�����ҳ����������ݽṹ */
 busypf_head=busypf_tail=NULL; /* æҳ�����ͷ������β���� */
 for(i=0;i<total_instruction;i++)
 {
 if(pl[page[i]].pfn==INVALID) /* ҳ��ʧЧ */
 {
 diseffect+=1; /* ʧЧ���� */
 if(freepf_head==NULL) /* �޿���ҳ�� */
 {
 p=busypf_head->next;
 pl[busypf_head->pn].pfn=INVALID;
 freepf_head=busypf_head; /* �ͷ�æҳ����еĵ�һ��ҳ�� */
 freepf_head->next=NULL;
 busypf_head=p;
 }
 p=freepf_head->next; /* �� FIFO��ʽ����ҳ�����ڴ�ҳ�� */
 freepf_head->next=NULL;
 freepf_head->pn=page[i];
 pl[page[i]].pfn=freepf_head->pfn;
if(busypf_tail==NULL)
 busypf_head=busypf_tail=freepf_head;
 else
 {
 busypf_tail->next=freepf_head; /*free ҳ�����һ�� */
 busypf_tail=freepf_head;
 }
 freepf_head=p; 

 }
}
printf("FIFO:%6.4f\n",1-(float)diseffect/320);
return 0;
}
int LRU (total_pf) /* ������δʹ���㷨 */
int total_pf;
{
 int min,minj,i,j,present_time;
 initialize(total_pf);
 present_time=0;
for(i=0;i<total_instruction;i++)
 {
 if(pl[page[i]].pfn==INVALID) /* ҳ��ʧЧ */
 {
 diseffect++;
 if(freepf_head==NULL) /* �޿���ҳ�� */
 {
 min=32767;
 for(j=0;j<total_vp;j++) /* �ҳ� time ����Сֵ */
 if(min>pl[j].time&&pl[j].pfn!=INVALID)
 {
 min=pl[j].time;
 minj=j;
 }
 freepf_head=&pfc[pl[minj].pfn]; // �ڳ�һ����Ԫ
 pl[minj].pfn=INVALID;
 pl[minj].time=-1;
 freepf_head->next=NULL;
 }
 pl[page[i]].pfn=freepf_head->pfn; // �п���ҳ�� , ��Ϊ

 pl[page[i]].time=present_time;
freepf_head=freepf_head->next; // ����һ�� free ҳ��
 }
 else
 pl[page[i]].time=present_time; // ���������Ӹõ�Ԫ�ķ��ʴ���
 present_time++;
 }
printf("LRU:%6.4f\n",1-(float)diseffect/320);
return 0;
}
int NUR(total_pf) /* ���δʹ���㷨 */
int total_pf;
{ int i,j,dp,cont_flag,old_dp;
pfc_type *t;
initialize(total_pf);
dp=0;
for(i=0;i<total_instruction;i++)
{ if (pl[page[i]].pfn==INVALID) /* ҳ��ʧЧ */
 {diseffect++;
 if(freepf_head==NULL) /* �޿���ҳ�� */
 { cont_flag=TRUE;
 old_dp=dp;
 while(cont_flag)
 if(pl[dp].counter==0&&pl[dp].pfn!=INVALID)
 cont_flag=FALSE;
 else
 {
 dp++;
 if(dp==total_vp)
 dp=0; 

 if(dp==old_dp)
 for(j=0;j<total_vp;j++)
 pl[j].counter=0;
 }
 freepf_head=&pfc[pl[dp].pfn];
 pl[dp].pfn=INVALID;
 freepf_head->next=NULL;
 }
 pl[page[i]].pfn=freepf_head->pfn;
 freepf_head=freepf_head->next;
 }
else
 pl[page[i]].counter=1;
 if(i%clear_period==0)
 for(j=0;j<total_vp;j++)
 pl[j].counter=0;
}
printf("NUR:%6.4f\n",1-(float)diseffect/320);
return 0;
}
int OPT(total_pf) /* ����û��㷨 */
int total_pf;
{int i,j, max,maxpage,d,dist[total_vp];
pfc_type *t;
initialize(total_pf);
for(i=0;i<total_instruction;i++)
{ //printf("In OPT for 1,i=%d\n",i);
//i=86;i=176;206;250;220,221;192,193,194;258;274,275,276,277,278;
 if(pl[page[i]].pfn==INVALID) /* ҳ��ʧЧ */
 {
 diseffect++;
 if(freepf_head==NULL) /* �޿���ҳ�� */
 {for(j=0;j<total_vp;j++) 

 if(pl[j].pfn!=INVALID) dist[j]=32767; /* ���" ����" */
 else dist[j]=0;
 d=1;
 for(j=i+1;j<total_instruction;j++)
 {
 if(pl[page[j]].pfn!=INVALID)
 dist[page[j]]=d;
 d++;
 }
 max=-1;
 for(j=0;j<total_vp;j++)
 if(max<dist[j])
 {
 max=dist[j];
 maxpage=j;
 }
 freepf_head=&pfc[pl[maxpage].pfn];
 freepf_head->next=NULL;
 pl[maxpage].pfn=INVALID;
 }
 pl[page[i]].pfn=freepf_head->pfn;
 freepf_head=freepf_head->next;
 }
}
printf("OPT:%6.4f\n",1-(float)diseffect/320);
return 0;
}
int LFU(total_pf) /* �����ʹ���û��� */
int total_pf;
{
 int i,j,min,minpage; 

 pfc_type *t;
 initialize(total_pf);
 for(i=0;i<total_instruction;i++)
 { if(pl[page[i]].pfn==INVALID) /* ҳ��ʧЧ */
 { diseffect++;
 if(freepf_head==NULL) /* �޿���ҳ�� */
 { min=32767;
 for(j=0;j<total_vp;j++)
 {if(min>pl[j].counter&&pl[j].pfn!=INVALID)
 {
 min=pl[j].counter;
 minpage=j;
 }
 pl[j].counter=0;
 }
 freepf_head=&pfc[pl[minpage].pfn];
 pl[minpage].pfn=INVALID;
 freepf_head->next=NULL;
 }
 pl[page[i]].pfn=freepf_head->pfn; // �п���ҳ�� , ��Ϊ��Ч
 pl[page[i]].counter++;
 freepf_head=freepf_head->next; // ����һ�� free ҳ��
 }
else
 pl[page[i]].counter++;
 }
printf("LFU:%6.4f\n",1-(float)diseffect/320);
return 0;
}
