#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int mn(char *a, char *b, int o);
int kmp(char *a, char *b, int k);
//int *length(char* b);


int main(void){
	int o = 0, k = 0;
	int bool_o, bool_k;
	char *a, *b;
	a = (char*)malloc(sizeof(char)*100);
	b = (char*)malloc(sizeof(char)*100);
	scanf("%s", a);
	scanf("%s", b);
	//printf("%s\n", a);
	bool_o = mn(a, b, o);
	bool_k = kmp(a,b, k);
	if(bool_o>0){
		printf("YES %d\n", bool_o);
	}	
	else{
		printf("NO %d\n", bool_o);
	}
	if(bool_k>0){
		printf("YES %d\n", bool_k);
	}	
	else{
		printf("NO %d\n", bool_k);
	}

}

int mn(char *a, char *b, int o){
	int i=0, j=0, p=0, k=0, r;
	int a_len=strlen(a);
	int b_len=strlen(b);
	while(i<=a_len-b_len){
		if(r==1)	break;	
		if(a[i] == b[0]){
			//printf("i=%d\n", i);
			k=1;
			p=i;
			j=0;
			while(j<b_len){
				if(a[i]!=b[j]){
					o++;
					i++;
					j++;
					
				}
				else{
					i++;
					j++;
					o++;
					k++;
				}
				if(j==b_len-1&&k==b_len){
					o++;
					r=1;
				//	printf("right!!!!!!!!!!!!!!\n");
					break;
				}
					
				
			}
			i=p;
			
			
		}
		else{
			p=i;
			j=0;
			while(j<b_len){
				if(a[i]!=b[j]){
					o++;
					i++;
					j++;
					
				}
				else{
					i++;
					j++;
					o++;
			
				}
			}	
			i=p;
			
		}
	//	if(r==1)	break;
//		printf("o %d\n", o);	
		i++;
	//	printf("%d\n", i);
	}
	if(r==1)	return o;
	else 	return -o;
}
/*
int *length(char *b){
	int i=0, j=0;
//	int t=0;
	int *table = (int*)calloc(100, sizeof(int));
	int len=strlen(b);
	for(i=1;i<len;i++){
		while(b[i]!=b[j]){		
			j=table[j-1];
		}
		if(b[i]==b[j]){
			table[i] = ++j;
		}
	}
	return table;
}
*/
int kmp(char *a, char *b, int k){
	//printf("stwerarse");
	int i=0, j=0, t=0;
	k=0;
	//char *table=length(b);
	int a_len=strlen(a);
	int b_len=strlen(b);
	//printf("3333333333333");
	int *table=(int*)calloc(100, sizeof(int));
	for(i=1;i<b_len;i++){
		while(b[i]!=b[j]&&j>0){
			j=table[j-1];
		}
		if(b[j]==b[i]){
			table[i]=++j;
		}
	}
	//int b_len=strlen(b);	
	for(i=0;i<a_len;i++){
		k++;
		while(j>0&&a[i]!=b[j]){
			j=table[j-1];
			k++;
		}
		if(a[i]==b[j]){
			if(j==b_len-1){
				return k;
			}
			else{
				j++;
			}
		}

	}
	return -k;

}

















