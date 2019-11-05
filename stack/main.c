#include <stdio.h>
#include "stack.h"
#include "debug.h"

ivStackDeclaration(StackDouble, NodeDouble, double)


void testDouble() {
    StackDouble stack = initStackDouble();

    for (int i = 0; i < 10; i++)
        stack.push(&stack, 0.1 *i);

    for (;stack.k;) {
        NodeDouble *nd = stack.pop(&stack);
        PRINT_FLT(nd->value);
        free(nd);
    }
}


ivStackDeclaration(StackInt, NodeInt, int)

void testInt() {
    StackInt st = initStackInt();

    for (int i = 0; i < 10; i++)
        st.push(&st, i);
    for (;st.k;) {
        NodeInt *nd = st.pop(&st);
        PRINT_INT(nd->value);
        free(nd);
    }

}

#define ALL 0

struct Igor {
    int x, y, z;
};
ivStackDeclaration(StackIgor, NodeIgor, struct Igor)

void testStruct() {
    StackIgor stack = initStackIgor();

    for (int i = 0; i < 4; i++)
    {
        struct Igor igor = {i,i,i};
        stack.push(&stack, igor);
    }

    for (;stack.k;) {
        NodeIgor *node = stack.pop(&stack);
        PRINT_INT(node->value.x);
        PRINT_INT(node->value.y);
        PRINT_INT(node->value.z);
        printf("\n");
        free(node);
    }
}

int main()
{
    testDouble();
    testInt();
    testStruct();
    return 0;
}
