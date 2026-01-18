// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <ctype.h>

// char stack[50];
// int top = -1;

// void push(char c) { stack[++top] = c; }
// char pop() { return stack[top--]; }

// int precedence(char c)
// {
//     if(c == '+' || c == '-') return 1;
//     if(c == '*' || c == '/') return 2;
//     return 0;
// }

// void reverse(char exp[])
// {
//     int i, j;
//     char temp;
//     for(i = 0, j = strlen(exp) - 1; i < j; i++, j--)
//     {
//         temp = exp[i];
//         exp[i] = exp[j];
//         exp[j] = temp;
//     }
// }

// void infixToPrefix(char infix[], char prefix[])
// {
//     int i, k = 0;
//     reverse(infix);

//     for(i = 0; infix[i]; i++)
//     {
//         if(isalnum(infix[i]))
//             prefix[k++] = infix[i];
//         else if(infix[i] == ')')
//             push(infix[i]);
//         else if(infix[i] == '(')
//         {
//             while(stack[top] != ')')
//                 prefix[k++] = pop();
//             pop();
//         }
//         else
//         {
//             while(top != -1 && precedence(stack[top]) > precedence(infix[i]))
//                 prefix[k++] = pop();
//             push(infix[i]);
//         }
//     }

//     while(top != -1)
//         prefix[k++] = pop();

//     prefix[k] = '\0';
//     reverse(prefix);
// }

// int evaluatePrefix(char prefix[])
// {
//     int i, a, b, stack2[50], top2 = -1;

//     for(i = strlen(prefix) - 1; i >= 0; i--)
//     {
//         if(isdigit(prefix[i]))
//             stack2[++top2] = prefix[i] - '0';
//         else
//         {
//             a = stack2[top2--];
//             b = stack2[top2--];
//             switch(prefix[i])
//             {
//                 case '+': stack2[++top2] = a + b; break;
//                 case '-': stack2[++top2] = a - b; break;
//                 case '*': stack2[++top2] = a * b; break;
//                 case '/': stack2[++top2] = a / b; break;
//             }
//         }
//     }
//     return stack2[top2];
// }

// int main()
// {
//     char infix[50], prefix[50];
//     int choice;

//     do
//     {
//         printf("\nLP-11 MENU");
//         printf("\n1.Infix to Prefix");
//         printf("\n2.Evaluate Prefix");
//         printf("\n0.Exit");
//         scanf("%d", &choice);

//         switch(choice)
//         {
//             case 1:
//                 printf("Enter infix expression: ");
//                 scanf("%s", infix);
//                 infixToPrefix(infix, prefix);
//                 printf("Prefix: %s\n", prefix);
//                 break;

//             case 2:
//                 printf("Enter prefix expression: ");
//                 scanf("%s", prefix);
//                 printf("Result: %d\n", evaluatePrefix(prefix));
//                 break;
//         }
//     } while(choice != 0);

//     return 0;
// }

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
# define MAX 100
typedef struct{
    char data[MAX];
    int top;
}CharStack;

typedef struct{
    char data[MAX];
    int top;
}IntStack;

int precednce(char);
int isOperator(char);
void pushChar(CharStack*, char);
char popChar(CharStack*);
char peekChar(CharStack*);
void pushInt(IntStack*, int);
int popInt(IntStack*);

int infixToPostfix(char[], char[]);
int evaluatePostfix(char[]);

int main(){
    int infix[MAX], postfix[MAX], choice;
    do{
        printf("\nLP-11 MENU");
        printf("\n1.Infix to Postfix");
        printf("\n2.Evaluate Postfix");
        printf("\n0.Exit");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter infix expression: ");
                scanf("%s",infix);
                infixToPostfix(infix,postfix);
                printf("Postfix: %s\n",postfix);
                break;
            case 2:
                printf("Enter postfix expression: ");
                scanf("%s",postfix);
                printf("Result: %d\n",evaluatePostfix(postfix));
                break;

            case 3:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }while(choice!=0);
    return 0;       
}

int precednce(char op){
    if(op=='+' || op=='-') return 1;
    if(op=='*' || op=='/') return 2;
    if(op=='^') return 3;
    return 0;       
}

int isOperator(char ch){
    return(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^');
}

void pushChar(CharStack *s, char ch){
    s->data[++(s->top)]=ch;

}

char popChar(CharStack *s){
    return s->data[(s->top)--];
}


char peekChar(CharStack *s){
    return s->data[s->top];
}

void pushInt(IntStack *s, int val){
    s->data[++(s->top)]=val;
}
int popInt(IntStack *s){
    return s->data[(s->top)--];
}

void infixToPrefix(char infix[], char postfix[])
{
        CharStack s;
        s.top=-1;
        int k=0;
        for(int i=0; i!='\0'; i++){
            char ch=infix[i];
            if(isalnum(ch)){
                postfix[k++]=ch;

            }
            else if (ch=='('){
                pusdhChar(&s, ch);  
            }
            else if(ch==')'){
                while(s.top!=-1 && peekChar(&s)!='9')
                    postfix[k++]=popChar(&s);
                popChar(&s);
            
            }
            else if (isOperator(ch)){
                while(s.top!=-1 && precednce(peekChar(&s)>precedence(ch)) || (precednce(peekChar(&s))==precednce(ch) && ch!='^'))
                    postfix[k++]=popChar(&s);
                pushChar(&s,ch);
            }

        
        }
        while(s.top!=-1){
            postfix[k++]=popChar(&s);
        }
 postfix[k]='\0';
}

int evaluatePostfix(char postfix[]){
    IntStack s;
    s.top=-1;
    for(int i=0; postfix[i]!='\0'; i++){
        char ch=postfix[i];
        if(isdigit(ch)){
            pushInt(&s,ch-'0');
        }
        else if(isOperator(ch)){
            int b=popInt(&s);
            int a=popInt(&s);
            int res;
            switch(ch){
                case '+': res=a+b ; break;
                case '-': res=a-b ; break;
                case '*': res=a*b ; break;
                case '/': res=a/b ; break;
                case '^': res=(int)pow(a,b); break;          
                
            }pushInt(&s,res);
        }
    }
    return popInt(&s);
}