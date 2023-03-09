#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _NODE *ptr;
typedef struct _NODE{
	int val;
	int k;
	ptr llink;
	ptr rlink;
	ptr tail;
}NODE;
/*
void inputfile(ptr *a, char *file){
	FILE *fp;
	fp=fopen(file, "r");
//	ptr newp=(NODE*)malloc(sizeof(NODE));
	int input;
	while(fscanf(fp, "%d", &input)==EOF){
		newp->val=input;
		newp->k=1;
		if((a)->rlink==(a)){
			newp->llink-(a);
			newp->rlink=(a);
			(a)->rlink-newp;
			(a)->llink=newp;
		}
		else{
			newp->llink=(a);
			newp->rlink=(a)->rlink;
			(a)->rlink->llink=newp;
			(a)->rlink=newp;
		}
		list_push(a, input);
	}
//	return a;
}*/
/*
ptr define(){
	NODE *newp=(NODE*)malloc(sizeof(NODE));
	newp->k==0;
	newp->rlink=newp;
	newp->llink=newp;
	return newp;
}
*/
NODE* list_push(ptr a, int input){
	NODE *newp=(NODE*)malloc(sizeof(NODE));
	newp->val=input;
	newp->k=1;
	//NODE *a=head;
	if(a->rlink==a){
//		printf("if\n");
		newp->llink=a;
		newp->rlink=a;
		a->rlink=newp;
		a->llink=newp;
		a->tail=newp;
/////		if(a->rlink==newp)	printf("	0\n");
	}
	else{
		a->tail->llink=newp;
		newp->llink=a;
		a->tail=newp;
		newp->rlink=a->rlink;
		a->rlink->llink=newp;
		a->rlink=newp;
	//	printf("else\n");
/*		newp->llink=(a);
	(source->llink->type != null_node);
	newp->rlink=(a)->rlink;
		(a)->rlink->llink=newp;
		(a)->rlink=newp;*/
	}
	
}


ptr inputfile(ptr head, char *file){
	FILE *f=fopen(file, "r");
	int input;
	NODE *a=(NODE*)malloc(sizeof(NODE));
	a->llink=a;
	a->rlink=a;
	a->k=0;
//	a=define();
	while(fscanf(f, "%d", &input)!=EOF){
		list_push(a, input);
//		printf("**");
	}
	return a;
}

void erase(ptr t){
	ptr temp;
	if(t->k==1){
		t->llink->rlink=t->rlink;
		t->rlink->llink=t->llink;
		free(t);
	//:	if()
//		temp=t->link;
//		t->link=temp->link;//
	}
}

void list_erase(ptr p, ptr q){
//	NODE *p=a;
//	NODE *q=b;
	NODE *f=(NODE*)malloc(sizeof(NODE));
	p=p->llink;
	f=p;
	int i, temp;
	do{
		i=0;
		temp=0;
		//q=q->llink;
		do{
			q=q->llink;
			if(p->val==q->val){
				i=1;
	//			break;
			}
		//	printf("0\n");
		}while(q->llink->k!=0);
	//	q=q->rlink;
		p=p->llink;
	//	printf("%d\n", i);
		
		if(i==1){
			erase(p->rlink);
		/*	if(temp==0){
				printf("0\n");
				a->tail->llink=p->llink;
			}

			else{
				printf("1\n");
				f->llink=p->llink;
				free(p);
			}*/
		//	f=p->rl
		}
		
		if(temp!=0)	f=p;
//		p=p->llink;	
		temp++;
	}while(p->k!=0);
}


void list_print(ptr a){
	NODE *p=a;
	p=p->llink;
	while(p->k!=0){
		printf("%d ", p->val);
		p=p->llink;
	}
	printf("\n");
}

int main(void){
	NODE *a, *b, *c;
/*	a->k=0;
	b->k=0;
	c->k=0;
	a->rlink=a;
	a->llink=a;	
	b->rlink=b;
	b->llink=b;
	c->rlink=c;
	c->llink=c;*/
//	FILE *f=fopen("A.txt", "r");	
	NODE *newp=(NODE*)malloc(sizeof(NODE));
	newp->llink=newp;
	newp->rlink=newp;
	newp->k=0;
/*	int input;
	while(fscanf(f, "%d", &input)!=EOF){
//		a=list_push(a, input);
//	NODE *newp=(NODE*)malloc(sizeof(NODE));
		newp->val=input;
		newp->k=1;
	//NODE *a=head;
		if(a->rlink==a){
			printf("if\n");
			newp->llink=a;
			newp->rlink=a;
			a->rlink-newp;
			a->llink=newp;
		}
		else{
			printf("else\n");
			newp->llink=(a);
			newp->rlink=(a)->rlink;
			(a)->rlink->llink=newp;
		}
	}*/
		
	a=inputfile(a, "A.txt");
	b=inputfile(b, "B.txt");
	c=inputfile(c, "C.txt");
//	printf("%d %d\n", a->llink->val, b->llink->val);
//	list_print(a);
//	list_print(b);
//	list_print(c);
	do{
		b=b->llink;
		list_push(a, b->val);
	}while(b->llink->k!=0);
	list_print(a);
	
	list_erase(a, c);
	list_print(a);
	
}







