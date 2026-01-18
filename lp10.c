#include <stdio.h>
#include <ctype.h>

int stack[50], top=-1;
char op[50];
int optop=-1;

void push(int x){ stack[++top]=x; }
int pop(){ return stack[top--]; }

void oppush(char x){ op[++optop]=x; }
char oppop(){ return op[optop--]; }

int prec(char c){
    if(c=='+'||c=='-') return 1;
    if(c=='*'||c=='/') return 2;
    return 0;
}

int main()
{
    char infix[50], postfix[50];
    int i,k=0,a,b,ch;

    printf("Enter infix: ");
    scanf("%s",infix);

    for(i=0;infix[i];i++){
        if(isdigit(infix[i])) postfix[k++]=infix[i];
        else{
            while(optop!=-1 && prec(op[optop])>=prec(infix[i]))
                postfix[k++]=oppop();
            oppush(infix[i]);
        }
    }
    while(optop!=-1) postfix[k++]=oppop();
    postfix[k]='\0';

    printf("Postfix: %s\n",postfix);

    for(i=0;postfix[i];i++){
        if(isdigit(postfix[i])) push(postfix[i]-'0');
        else{
            b=pop(); a=pop();
            switch(postfix[i]){
                case '+': push(a+b); break;
                case '-': push(a-b); break;
                case '*': push(a*b); break;
                case '/': push(a/b); break;
            }
        }
    }

    printf("Result: %d\n",pop());
    return 0;
}
