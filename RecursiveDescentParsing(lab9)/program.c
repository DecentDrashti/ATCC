// write a program to implement a recursive descent parser for following grammar 
//E->E+T | T
//T->T*F | F
//F->id 
//using function stack
//after reducing the grammar with left recursion we get
//E->T E'
//E'->+ T E' | ε
//T->F T'
//T'->* F T' | ε
//F->id
// Each non-terminal → one C function
// Input string → read character by character
// If grammar matches → Parsing Successful
// If grammar breaks → Parsing Error
// No parse tree is printed — only validation.

//Each non-terminal symbol = one function
// E() → handles T E'
// E_dash() → handles + T E'
// T() → handles F T'
// T_dash() → handles * F T'  Function T_Dash() → *
// F() → handles id Function F() → smallest unit
//The function calls act like a stack.

// What problem are we solving?

// We want to check whether an input string like

// id+id*id


// follows the grammar rules of arithmetic expressions.

// We are NOT evaluating the expression
// We are NOT printing a parse tree

// 👉 We are only checking syntax correctness.

// Why we can’t use this directly?

// Because of left recursion:

// E → E + T
// T → T * F This causes infinite recursion in recursive descent parsing.



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char input[100];
int i = 0;

/* Function declarations */
void E();
void E_dash();
void T();
void T_dash();
void F();

void error() {
    printf("Parsing Error\n");
    exit(1);
}

/* F → id */
void F() {
    if (input[i] == 'i' && input[i + 1] == 'd') {
        i += 2;   // consume "id"
    } else {
        error();
    }
}

/* T' → * F T' | ε */
void T_dash() {
    if (input[i] == '*') {
        i++;      // consume '*'
        F();
        T_dash(); // recursive call
    }
    // else ε
}

/* T → F T' */
void T() {
    F();
    T_dash();
}

/* E' → + T E' | ε */
void E_dash() {
    if (input[i] == '+') {
        i++;      // consume '+'
        T();
        E_dash(); // recursive call
    }
    // else ε
}

/* E → T E' */
void E() {
    T();
    E_dash();
}

int main() {
    printf("Enter the expression: ");
    scanf("%s", input);

    E();

    if (input[i] == '\0') {
        printf("Parsing Successful\n");
    } else {
        error();
    }

    return 0;
}
