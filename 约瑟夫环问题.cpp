#include<stdio.h>
#include<stdlib.h>
#define N 40
#define dm 6
#define dstart 4
typedef struct node{
	int num;
	node *next;
	node*before;
}NODE;
NODE* creating(int n);
int fun(NODE* nod,int start,int m);
int main()
{
	NODE*head;
	head=creating(N);
	fun(head,dstart,dm);
	return 0;
}
NODE*creating(int n)
{
	NODE*head=NULL,*p1=NULL,*p2=NULL;
	for(int i=0,k=0;i<n;i++){
		p1=(NODE*)malloc(sizeof(NODE));
		p1->num=i+1;
		if(k==0){
			head=p2=p1;
		}
		else{
			p2->next=p1;
			p1->before=p2;
			p2=p1;
		}
		k++;
	}
	p1->next=head;
	head->before=p2;
	return head;
}
int fun(NODE* nod,int start,int m)
{
	for(int i=0;i<start-1;i++)nod=nod->next;
	while(1)
	{
		int j=0;
		for(j=0;j<m-1;){
			nod=nod->next;
			j++;
		}
		printf("%d\n",nod->num );
		NODE*p1=nod->before,*p2=nod->next;
		nod=nod->next;
		p1->next=p2;
		p2->before=p1;
		if(nod->next==nod){
			printf("%d",nod->num );
			break;
		}
	}
}













