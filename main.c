#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

float stack[MAX];
int top = -1;

/* Function to check whether stack is full */
int isFull() {
    return top == MAX - 1;
}

/* Function to check whether stack is empty */
int isEmpty() {
    return top == -1;
}

/* Function to push value into stack */
void push(float value) {
    if (isFull()) {
        printf("Error: Stack Overflow\n");
    } else {
        top++;
        stack[top] = value;
    }
}

/* Function to pop value from stack */
float pop() {
    if (isEmpty()) {
        printf("Error: Stack Underflow\n");
        return 0;
    } else {
        float value = stack[top];
        top--;
        return value;
    }
}

/* Function to check operator */
int isOperator(char token[]) {
    return strlen(token) == 1 &&
           (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/');
}

/* Function to check number */
int isNumber(char token[]) {
    int i = 0;

    if (token[0] == '-' && token[1] != '\0') {
        i = 1;
    }

    for (; token[i] != '\0'; i++) {
        if (!isdigit(token[i]) && token[i] != '.') {
            return 0;
        }
    }

    return 1;
}

/* Function to evaluate reverse polish expression */
void evaluatePostfix(char expression[]) {
    char *token;
    float operand1, operand2, result;

    token = strtok(expression, " ");

    while (token != NULL) {
        if (isNumber(token)) {
            push(atof(token));
        }
        else if (isOperator(token)) {
            if (top < 1) {
                printf("Invalid postfix expression: Not enough operands.\n");
                return;
            }

            operand2 = pop();
            operand1 = pop();

            switch (token[0]) {
                case '+':
                    result = operand1 + operand2;
                    break;

                case '-':
                    result = operand1 - operand2;
                    break;

                case '*':
                    result = operand1 * operand2;
                    break;

                case '/':
                    if (operand2 == 0) {
                        printf("Error: Division by zero is not allowed.\n");
                        return;
                    }
                    result = operand1 / operand2;
                    break;
            }

            push(result);
        }
        else {
            printf("Invalid token found: %s\n", token);
            return;
        }

        token = strtok(NULL, " ");
    }

    if (top == 0) {
        printf("Final Result = %.2f\n", pop());
    } else {
        printf("Invalid postfix expression: Too many operands.\n");
    }
}

int main() {
    char expression[200];

    printf("=========================================\n");
    printf(" Reverse Polish Calculator Using Stack\n");
    printf("=========================================\n");

    printf("\nEnter postfix expression using spaces\n");
    printf("The Expression: a+b*c/d \n");
    printf("Postfix Expression: ");

    fgets(expression, sizeof(expression), stdin);

    expression[strcspn(expression, "\n")] = '\0';

    evaluatePostfix(expression);

    return 0;
}
