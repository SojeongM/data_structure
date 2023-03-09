#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct threadedTree *threadedPointer;
typedef struct threadedTree {
	short int leftThread;
	threadedPointer leftChild;
	char data;
	threadedPointer rightChild;
	short int rightThread;
} threadedTree;
threadedPointer insucc(threadedPointer tree);
void tinorder(threadedPointer tree);
void insertRight(threadedPointer s, threadedPointer r);
void insertLeft(threadedPointer s, threadedPointer l);
threadedPointer getNewNode(char data);
int main() {
	threadedPointer root = getNewNode('-');
	insertLeft(root, getNewNode('A'));
	insertLeft(root->leftChild, getNewNode('B'));
	insertLeft(root->leftChild->leftChild, getNewNode('D'));
	insertLeft(root->leftChild->leftChild->leftChild, getNewNode('H'));
	insertRight(root->leftChild->leftChild->leftChild, getNewNode('I'));
	insertRight(root->leftChild->leftChild, getNewNode('E'));
	insertRight(root->leftChild, getNewNode('C'));
	insertLeft(root->leftChild->rightChild, getNewNode('F'));
	insertRight(root->leftChild->rightChild, getNewNode('G'));
	tinorder(root);
	return 0;
}

threadedPointer insucc(threadedPointer tree) {
	threadedPointer temp;
	temp=tree->rightChild;
	if(!tree->rightThread){
		while(!temp->leftThread){
			temp=temp->leftChild;
		}
	}
	return temp;
}
void tinorder(threadedPointer tree) {
//	printf("OO\n");
	threadedPointer temp=tree;
//	printf("			%c\n", tree->leftChild->data);
	while(1){
		temp=insucc(temp);
		if(temp==tree)	break;
		printf("%c ", temp->data);
	}
	printf("\n");
}
void insertRight(threadedPointer s, threadedPointer r) {
	threadedPointer temp;
	r->rightChild=s->rightChild;
	r->rightThread=s->rightThread;
	r->leftChild=s;
	r->leftThread=true;
	s->rightChild=r;
	s->rightThread=false;
//	printf("5\n");
	if(!r->rightThread){
//		printf("6");
		temp=insucc(r);
		temp->leftChild=r;
	}
//	printf("2	%c\n", s->rightChild->data);
}
void insertLeft(threadedPointer s, threadedPointer l) {

	threadedPointer temp;
	l->leftChild=s->leftChild;
	l->leftThread=s->leftThread;
	l->rightThread=true;
	l->rightChild=s;
	s->leftChild=l;
	s->leftThread=false;
	if(!l->leftThread){
		temp=insucc(l);
		temp->rightChild=l;
	}
//	printf("2	%c\n", s->leftChild->data);
//	printf("%d %d\n", s->leftThread, s->rightThread);
//	printf("%d %d\n\n", l->leftThread, l->rightThread);
}
threadedPointer getNewNode(char data) {
	threadedPointer root=(threadedPointer)malloc(sizeof(threadedTree));
	if(data=='-'){
		threadedPointer temp=getNewNode(0);
		root->data=data;
		root->leftChild=temp;
		root->rightChild=root;
		root->leftThread=true;
		root->rightThread=false;
	}
	else{
		root->data=data;
		root->leftChild=NULL;
		root->rightChild=NULL;
		root->leftThread=false;
		root->rightThread=false;

	}
//	printf("1   %c\n", data);
	return root;
}
