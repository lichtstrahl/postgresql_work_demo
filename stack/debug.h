#ifndef DEBUG_H
#define DEBUG_H

#define DEBUG(var)      printf(#var " = %p;\n", var)
#define DEBUG_COMMAND(command)  printf(#command"\n");   command
#define PRINT_INT(var)  printf(#var " = %d;\n", var)
#define PRINT_FLT(var)  printf(#var " = %8.3lf;\n", var)
#define PRINT_PTR(var)  printf(#var " = %p;\n", var)

#define PRINT_LINE      printf("%d\n", __LINE__)
#define PRINT_FUNC      printf("%s\n", __func__);

/*
// Отслеживание ошибок, с запоминанием возвращаемого значения
#define TRAP_ERROR_VAR(var, command)\
if ((var = command) == -1)\
{\
    perror(#command ": ");\
}

// Отслеживание ошибок, с запоминанием возвращаемого значения. Завершение в случае ошибки.
#define TRAP_ERROR_VAR_EXIT(var, command)\
if ((var = command) == -1)\
{\
    perror(#command ": ");\
    exit(1);\
}
*/
// Отслеживание ошибок без присваивания результата.
#define TRAP_ERROR(command)\
if ((command) == -1)\
{\
    perror(#command ": ");\
}
// Отслеживание ошибок без присваивания результата. Завершение в случае ошибки.
#define TRAP_ERROR_EXIT(command)\
if ((command) == -1)\
{\
    perror(#command ": ");\
    exit(1);\
}

#endif
