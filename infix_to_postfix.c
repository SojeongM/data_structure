#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef enum {
	lparen, rparen, plus, minus, times, divide, mod, eos, operand
} precedence;


char expr[1111];
int top=-1;
static int isp[] = {0, 19, 12, 12, 13, 13, 13, 0};
static int icp[] = {20, 19, 12, 12, 13, 13, 13, 0};

precedence stack[100];

void push(precedence val);
precedence pop();
precedence getToken(char *symbol, int *n);
precedence print_Token(precedence a);
void postfic();


void push(precedence val){
	stack[++top] = val;
}



precedence pop(){

	return stack[(top)--];

}

precedence getToken(char *symbol, int *n)

{

	*symbol = expr[(*n)++];
	switch (*symbol){
	case '(': return lparen;
	case ')': return rparen;
	case '+': return plus;
	case '-': return minus;
	case '/': return divide;
	case '*': return times;
	case '%': return mod;
	case '\0': return eos;
	default: return operand;

	}

}



precedence print_Token(precedence  a){
	switch (a)
	{
	case lparen: printf("(");
		break;
	case rparen: printf(")");
		break;
	case plus: printf("+");
		break;
	case minus: printf("-");
		break;
	case divide: printf("/");
		break;
	case times: printf("*");
		break;
	case mod: printf("%");
		break;
	case eos: printf(" ");
		break;
	default: printf("\n");
	}

}



void postfix(void){
	char symbol;
	precedence token;
	int n = 0;
	top = 0;
	stack[0] = eos;
	for (token = getToken(&symbol, &n); token != eos; token = getToken(&symbol, &n))
	{
		if (token == operand){
			printf("%c", symbol);
		}
		else if (token == rparen)	{
			while (stack[top] != lparen)
			{
				print_Token(pop());
			}
			pop();
		}
		else
		{
	//		printf("%d %d\n", isp[stack[top]], icp[token]);
			while (isp[stack[top]] >= icp[token])
			{
				print_Token(pop());
			}
			push(token);
		}
	}
	while ((token = pop()) != eos)	{
		print_Token(token);
	}
	printf("\n");



}



int main(){
	scanf("%s", expr);
	postfix();
	printf("%s\n", expr);
	return 0;
}




