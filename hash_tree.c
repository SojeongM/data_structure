#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
	struct node *left;
	struct node *right;
	struct node *parent;
	int num;
} NODE;

typedef struct qnode{
	NODE *data;
	struct	qnode *link;	
}Qnode;

typedef struct queue{
	Qnode *front;
	Qnode *rear;
}Queue;

NODE* CreateBTree(NODE* parent, int max_num);
NODE *create(NODE* parent, int *a, int i, int n, NODE *p);
NODE* SearchBFS(NODE* root, int num);
void init(Queue *q);
void enqueue(Queue *q, NODE *n);
NODE *dequeue(Queue *q);

int main(void){
	NODE *root=(NODE*)malloc(sizeof(NODE));
	int num, s;
	char input;
	scanf("%d %c", &num, &input);
//	printf("%c %d\n", num, input);
	root=CreateBTree(root, num);
///	printf("%c \n\n", root->left->right->left->num);
//	printf("%c ", root->left->num);
//	printf("%d\n", root->right->right->left->num);
	NODE *find;
	NODE *merkle;
	find=SearchBFS(root, input);
//	printf("%c\n", find->num);
	while(1){
		if(find->parent->right==NULL){
			s=input;
			merkle=SearchBFS(root, s);
			printf("%c ", merkle->num);
		}
		else{
//			printf("%c %c\n", find->parent->right->num, find->parent->left->num);
			if(find->parent->left->num==find->num){
				s=find->parent->right->num;
				merkle=SearchBFS(root, s);
				if(merkle->num>=65){
					printf("%c ", merkle->num);
				}
				else{
					printf("%d ", merkle->num);
				}
			}
			else{
				s=find->parent->left->num;
				merkle=SearchBFS(root, s);
				if(merkle->num>=65){
					printf("%c ", merkle->num);
				}
				else{
					printf("%d ", merkle->num);
				}
			}
		}
		if(find->parent->parent==NULL)	break;
		if(find->parent->parent->left->num==merkle->parent->num){
			
			find=find->parent->parent->left;
		}
		else{
			find=find->parent->parent->right;
		}
	}
	printf("\n");
//	printf("%d ", root->num);
}

NODE* CreateBTree(NODE* parent, int max_num){
	NODE *p;
	NODE *temp=(NODE*)malloc(sizeof(NODE));
	int a[56];
	int i=1, j=0, c=65;
	int n;
	if(max_num==0){
		temp->parent=temp;
		temp->left=NULL;
		temp->right=NULL;
		temp->num=c;
		return parent;
	}
	
	temp->parent=temp;
	temp->left=NULL;
	temp->right=NULL;
	temp->num=c;
	if(max_num<3){
		a[0]=1;
		for(j=0;j<max_num;j++){
			a[i]=c;
			i++;
			c++;
		}
		n=1+max_num;
	}	
	else if(max_num<5){
		for(j=0;j<3;j++){
			a[j]=j+1;
		}
		i=j;
		for(j=0;j<max_num;j++){
			a[i]=c;
			i++;
			c++;
		}
		n=3+max_num;
	}
	else if(max_num<9){
		for(j=0;j<7;j++){
			a[j]=j+1;
		}
		i=j;
		for(j=0;j<max_num;j++){
			a[i]=c;
			i++;
			c++;
		}
		n=max_num+7;
	}
	else if(max_num<17){
		for(j=0;j<15;j++){
			a[j]=j+1;
		}
		i=j;
		for(j=0;j<max_num;j++){
			a[i]=c;
			i++;
			c++;
		}
		n=max_num+15;
	}
	else{
		for(j=0;j<31;j++){
			a[j]=j+1;
		}
		i=j;
		for(j=0;j<max_num;j++){
			a[i]=c;
			i++;
			c++;
		}
		n=max_num+31;
	}
	parent=create(parent, a, 0, n, parent);
	return parent;
}

NODE *create(NODE* parent, int *a, int i, int n, NODE*p){
//	printf("tt");
	if(i<n){		
		NODE *temp=(NODE*)malloc(sizeof(NODE));
		temp->left=NULL;
		temp->right=NULL;
		temp->num=a[i];
		if(i==0)	temp->parent=NULL;
		else	temp->parent=p;
	
		parent=temp;
		//printf("%d ", a[1]);
		parent->left=create(parent->left, a, 2*i+1, n, parent);
		parent->right=create(parent->right, a, 2*i+2, n, parent);
	}
	return parent;
}
NODE* SearchBFS(NODE* root, int num){
	if(root==NULL)	return root;
	NODE *temp;
	NODE *find;
	Queue q;
	init(&q);
	enqueue(&q, root);
	while(1){
		temp=dequeue(&q);
		if(temp==NULL){
			break;
		}
		if(num==temp->num){
			find=temp;
		}
		if(temp->left!=NULL){
			enqueue(&q, temp->left);
		}
		if(temp->right!=NULL){
			enqueue(&q, temp->right);
		}
	}

/*	NODE *merkle;
	init(&q);
	while(1){
		if(find->parent->left->num==find->num){
			if(find->parent->right->
		}

		
		temp=dequeue(&q);
		if(temp==NULL){
			break;
		}
		if(
	}*/

/*	if(find->parent->num!=1){
		while(1){
			if(find->parent->left->num==find->num){
				if(find->parent->right==NULL){
					if(find->num>=65){
					printf("%c ", find->num);
						}
					else{	
						 printf("%d ", find->num);
					}
				}
				else{
					if(find->parent->right->num>=65){
						printf("%c ", find->parent->right->num);
					}
					else printf("%d ", find->parent->right->num);
				}
			}
		else{
				if(find->parent->left->num>=65){
					printf("%c ", find->parent->left->num);
				}
				else printf("%d ", find->parent->left->num);
			
			}
			if(find->parent->parent->left->num==find->parent->num){
				find=find->parent->parent->left;
			}
			else{
				find=find->parent->parent->right;
			}
			if(find->parent->parent==NULL)	break;
		}
	}
	if(find->parent->right==NULL){
		100
		if(find->num>=65){
			printf("%c\n", find->parent->left->num);
		}
		else{
			printf("%d\n", find->parent->left->num);
		}
	}
	else if(find->parent->left->num==find->num){
		if(find->num>=65){
			printf("%c\n", find->parent->right->num);
		}
		else{
			printf("%d\n", find->parent->right->num);
		}
	}
	else{
		if(find->num>=65){
			printf("%c\n", find->parent->left->num);
		}
		else{
			printf("%d\n", find->parent->left->num);
		}

	}*/
//	printf("%c %d\n", find->parent->left->num, find->parent->num);
	return find;
}



void init(Queue *q){
	q->rear=NULL;
	q->front=NULL;
}
void enqueue(Queue *q, NODE *n){
	Qnode *newp=(Qnode*)malloc(sizeof(Qnode));
	newp->data=n;
	newp->link=NULL;
	if(q->front==NULL){
		q->front=newp;
		q->rear=newp;
	}
	else{
		q->rear->link=newp;
		q->rear=newp;
	}
}
NODE *dequeue(Queue *q){
	if(q->front==NULL){
		return NULL;
	}
	Qnode *p=q->front;
	NODE *temp=p->data;
	q->front=q->front->link;
	free(p);
	return temp;
}

