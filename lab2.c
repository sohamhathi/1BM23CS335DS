#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int prec(char c) {
    if (c == '^')   
        return 3;
    else if (c == '/' || c == '*')  
        return 2;
    else if (c == '+' || c == '-') 
        return 1;
    else 
        return -1; 
}


char associativity(char c) { 
    if (c == '^') 
        return 'R'; 
    return 'L'; 
}


void infixToPostfix(const char *expression) { 
    int length = strlen(expression);
    char *result = (char *)malloc(length + 1); 
    char *stack = (char *)malloc(length); 
    int resultIndex = 0; 
    int stackIndex = -1; 

    if (!result || !stack) { 
        printf("Memory allocation failed!\n"); 
        return; 
    }

    for (int i = 0; i < length; i++) { 
        char currentChar = expression[i];

        if ((currentChar >= 'a' && currentChar <= 'z') || 
            (currentChar >= 'A' && currentChar <= 'Z') || 
            (currentChar >= '0' && currentChar <= '9')) {
            result[resultIndex++] = currentChar; 
        }
        else if (currentChar == '(') { 
            stack[++stackIndex] = currentChar; 
        }
        else if (currentChar == ')') { 
            while (stackIndex >= 0 && stack[stackIndex] != '(') { 
                result[resultIndex++] = stack[stackIndex--];
            } 
            stackIndex--; 
        }
        else { 
            while (stackIndex >= 0 && 
                   (prec(currentChar) < prec(stack[stackIndex]) || 
                    (prec(currentChar) == prec(stack[stackIndex]) && associativity(currentChar) == 'L'))) {
                result[resultIndex++] = stack[stackIndex--]; 
            } 
            stack[++stackIndex] = currentChar; 
        } 
    } 

    while (stackIndex >= 0) { 
        result[resultIndex++] = stack[stackIndex--]; 
    }   
    result[resultIndex] = '\0'; 
    printf("%s\n", result); 
    free(result); 
    free(stack); 
}

int main() { 
    char expression[] = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix(expression);
    return 0;
}
