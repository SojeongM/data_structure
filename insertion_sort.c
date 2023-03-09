#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void insert(int *a, int size){
	int i, j, k;
	for(i=1;i<size;i++){
		k=*(a+i);
		for(j=i-1;j>=0;j--){
			if(*(a+j)>k){
				*(a+j+1)=*(a+j);
			}
			else{
				break;
			}		
		}	
		*(a+j+1)=k;
	}	
}

void duration(int size){
	//printf("4");
	int i, rep;
	int *a=(int*)malloc(sizeof(int)*size);
//	printf("$");
	if (size==0){
		rep=109;
	}
	else if(size%2==0){
		rep=800/size;
	}
	else{
		rep=800/(size-1);
	}
//	printf("rep %d\n", rep);
	double dur=0;
	int j;
	for(j=0;j<rep;j++){

		for(i=0;i<size;i++){
			*(a+i)=size-i;
		}
		//printf("%d size", size);
		clock_t start =clock();
		insert(a, size);
		dur+=((double)(clock()-start));
	}
	//free(a);
//	printf("d");
	dur=dur/CLOCKS_PER_SEC;
	printf("%12d %12d %12.6lf\n", size, rep, dur); 
}

void main(void){
//	char *file=(int*)malloc(sizeof(char)*10);
/*	*(file+0)=l;
	*(file+1)=a; 
	*(file+2)=b; 
	*(file+3)=1; 
	*(file+4)=.; 
	*(file+5)=d; 
	*(file+6)=a; 
	*(file+7)=t; 
	*(file+8)=a; */
//	char file[20]="lab1.data";

	int *a=(int*)malloc(sizeof(int)*20);
	FILE *f=fopen("lab1.data", "r");
	int input;
	int i=0;
	while(fscanf(f, "%d", &input)!=EOF){
		*(a+i)=input;
		i++;
	}
	fclose(f);
	*(a+i)='\0';
	printf("Input: ");
	int n=i;
	for(i=0;i<n;i++){
		printf("%d ", *(a+i));
	}
	printf("\n");
	insert(a, n);
	printf("Sorted: ");
	for(i=0;i<n;i++){
		printf("%d ", *(a+i));
	}
	printf("\n");
	printf("	   n	repetitions	time\n");
	for(i=0;i<=100;i+=10){
		//printf("i %d\n", i);
		duration(i);
	}
}
