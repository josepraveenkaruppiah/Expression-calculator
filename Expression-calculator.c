#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_EXPR 256
double memory = 0.0;

int precedence(char op) {
    if(op == '+'|| op == '-') return 1;
    if(op == '*'|| op == '/' || op == '%') return 2;
    return 0;
}

double applyOp(double a, double b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return b == 0 ? 0 : a / b;
        case '%': return fmod(a, b);
        default: return 0;
    }
}

double evaluate(char* tokens) {
    double values[MAX_EXPR];
    char ops[MAX_EXPR];
    int valTop = -1, opsTop = -1;

    int i = 0;
    while(i < strlen(tokens)) {
        if(tokens[i] == ' ') {
            i++;
            continue;
        }

        if(isdigit(tokens[i]) || tokens[i] == '.') {
            char numBuffer[32];
            int j = 0;
            while(i < strlen(tokens) && (isdigit(tokens[i]) || tokens[i] == '.')) {
                numBuffer[j++] = tokens[i++];
            }
            numBuffer[j] = '\0';
            values[++valTop] = atof(numBuffer);
        }
        else if(tokens[i] == '(') {
            ops[++opsTop] = tokens[i++];
        }
        else if(tokens[i] == ')') {
            while(opsTop >= 0 && ops[opsTop] != '(') {
                double b = values[valTop--];
                double a = values[valTop--];
                values[++valTop] = applyOp(a, b, ops[opsTop--]);
            }
            opsTop--; // remove '('
            i++;
        }
        else {
            while(opsTop >= 0 && precedence(ops[opsTop]) >= precedence(tokens[i])) {
                double b = values[valTop--];
                double a = values[valTop--];
                values[++valTop] = applyOp(a, b, ops[opsTop--]);
            }
            ops[++opsTop] = tokens[i++];
        }
    }

    while(opsTop >= 0) {
        double b = values[valTop--];
        double a = values[valTop--];
        values[++valTop] = applyOp(a, b, ops[opsTop--]);
    }

    return values[valTop];
}

int main() {
    char input[MAX_EXPR];

    printf("Welcome to Expression Calculator\n");
    printf("You can enter expressions like: 10+20-30/2+5%%\n");
    printf("Type 'M+', 'M-', 'MR', 'MC', 'sqrt x', 'sq x' or 'exit'\n");

    while(1) {
        printf("\n>>> ");
        fgets(input, MAX_EXPR, stdin);
        input[strcspn(input, "\n")] = '\0'; // Remove newline

        if(strcmp(input, "exit") == 0) {
            printf("Goodbye!\n");
            break;
        } else if(strncmp(input, "M+", 2) == 0) {
            double val = atof(input + 2);
            memory += val;
            printf("Memory: %.2lf\n", memory);
        } else if(strncmp(input, "M-", 2) == 0) {
            double val = atof(input + 2);
            memory -= val;
            printf("Memory: %.2lf\n", memory);
        } else if(strcmp(input, "MR") == 0) {
            printf("Memory Recall: %.2lf\n", memory);
        } else if(strcmp(input, "MC") == 0) {
            memory = 0;
            printf("Memory Cleared.\n");
        } else if(strncmp(input, "sqrt", 4) == 0) {
            double val = atof(input + 4);
            if(val < 0) printf("Error: sqrt of negative\n");
            else printf("√%.2lf = %.2lf\n", val, sqrt(val));
        } else if(strncmp(input, "sq", 2) == 0) {
            double val = atof(input + 2);
            printf("%.2lf² = %.2lf\n", val, val * val);
        } else {
            double result = evaluate(input);
            printf("= %.2lf\n", result);
        }
    }

    return 0;
}
