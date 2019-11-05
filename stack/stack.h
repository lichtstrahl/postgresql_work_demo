#ifndef STACK_H
#define STACK_H

#include <stdlib.h>
#include "debug.h"

/*  Как пользоваться:
 *      1) Объявили стек для конкретного типа данных: ivStackDeclaration(ИмяСтека, ИмяУзла, тип)
 *          <Имя стека> и <Имя узла> не имеют значения. Несут только смысловую нагрузку.
 *          Тип должен соответствовать одному из допустимых типов данных, на момент объявления.
 *          Тип абсолютно любой
 *      2) Затем объявляем стек:
 *          ИмяСтека stack = initИмяСтека();
 *      3) Можно пользоваться. Только не забыть передавать в pop и push указатель. Пока это делается вручную.
 *      4) Важно! При выполнении pop, необходимо очищать память.
*/

// Отдельно не использовать! Иначе возникнет конфликт имен.
#define ivNode(NodeName, type)\
struct NodeName {\
    type value;\
    struct NodeName *next;\
};\
typedef struct NodeName NodeName

#define ivStackDeclaration(StackName, NodeName, Type)\
    ivNode(NodeName, Type);\
    typedef void (*pushPtr##StackName)(struct StackName *, Type);\
    typedef NodeName* (*popPtr##StackName)(struct StackName*);\
    struct StackName {\
        int k;\
        NodeName *top;\
        popPtr##StackName pop;\
        pushPtr##StackName push;\
};\
typedef struct StackName StackName;\
    NodeName* pop##NodeName(StackName *t) {\
        NodeName *n = t->top;\
        if (t->top)\
        {\
            t->k--;\
            t->top = t->top->next;\
            return n;\
        }\
        else\
            return NULL;\
    }\
    \
    void push##NodeName(StackName *t, Type c) {\
        t->k++;\
        NodeName *nd = (NodeName*)malloc(sizeof(NodeName));\
        nd->value = c;\
        nd->next = t->top;\
        t->top = nd;\
    }\
    StackName init##StackName() {\
        StackName st;\
        st.k = 0;\
        st.top = NULL;\
        st.push = push##NodeName;\
        st.pop = pop##NodeName;\
        return st;\
    }

#endif // STACK_H
