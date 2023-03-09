#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	int key;
}element;

typedef struct stack* stackPointer;
typedef struct stack{
	element data;
	stackPointer link;
}stack;

typedef struct queue* queuePointer;
typedef struct queue{
	element data;
	stackPointer link;
}queue;
stackPointer top;
queuePointer front, rear;

int stackPush(element d, stackPointer *top, int level){
/*	if(is_full(top)){
		printf("ERROR : stack is full\n");
		return -1;
	}*/

	stackPointer new=(stackPointer)malloc(sizeof(stack));
	new->data=d;
	new->link=*top;
	*top=new;
	level++;
	//printf("	%d\n", (*top)->data.key);
	return level;
//	return 0;
}

int stackPop(stackPointer *top, int level){
/*	if(is_empty(top)==1){
		printf("ERROR : stack is empty\n");
		return -1;
	}*/
	if(level==0){
		printf("ERROR:stack is empty\n");
		return 0;
//		exit(-1);
	}
	stackPointer t=*top;
	element d;
	d=t->data;
	*top=t->link;
	level--;
	free(t);
	return level;
//	return d;
}

int queuePush(element d, queuePointer *front, queuePointer *rear, int level){
	queuePointer new=(queuePointer)malloc(sizeof(queue));
	new->data=d;
	new->link=NULL;
	if(*front){
		(*rear)->link=new;
	}
	else{
		*front=new;
	}
	*rear=new;
	level++;
//	free(new);
	return level;
}

int queuePop(queuePointer *front, queuePointer *rear, int level){
	if(level==0){
		printf("ERROR:queue is empty\n");
		exit(-1);
	}
	queuePointer t;
	t=*front;
	element d;
	d=t->data;
	*front=t->link;
	level--;
	free(t);
	return level;
//	free(t);
//	return d;
}

int main(void){
	int slevel=0;
	int qlevel=0;
	int i, input, k;
	element d;
	FILE *fp=fopen("input.txt", "r");
	FILE *output=fopen("output.txt", "w");
	while(EOF!=fscanf(fp, "%d", &input)){
	//	fscanf(fp, "%d", &input);
	//	if(input==EOF)	break;
		if(input==1){
			slevel=stackPop(&top, slevel);
			qlevel=queuePop(&front, &rear, qlevel);
		}
		else if(input==0){
			fscanf(fp, "%d", &k);
			d.key=k;
			slevel=stackPush(d, &top, slevel);

//			printf("%d\n", top->data.key);
			qlevel=queuePush(d, &front, &rear, qlevel);
		}
	}
	stackPointer s=(stackPointer)malloc(sizeof(stack));
	queuePointer q=(queuePointer)malloc(sizeof(queue));
	s=top;
	q=front;
	for(i=0;i<slevel;i++){
		fprintf(output, "%d ", (s->data).key);
		s=s->link;
	}
	fprintf(output, "\n");
	for(i=0;i<qlevel;i++){

		fprintf(output, "%d ", (q->data).key);
		q=q->link;
	}
	fprintf(output, "\n");
}




















