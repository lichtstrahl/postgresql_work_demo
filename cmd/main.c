#include <stdio.h>

struct Command;

typedef void (*exec)(struct Command *this);

struct  Command {
    void *arg;
    exec exe;
    void *result;
};

// РџСЂРёРЅРёРјР°РµС‚ 1 РґСЂРѕР±РЅС‹Р№ Р°СЂРіСѓРјРµРЅС‚ Рё СѓРјРЅРѕР¶Р°РµС‚ РµРіРѕ РЅР° 10
void func1(struct Command *cmd) {
    double tmp = (*(double*)cmd->arg);
    *((double*)cmd->result) = tmp * 10;
}

// РџР РёРЅРёРјР°РµС‚ 1 С†РµР»С‹Р№ Р°СЂРіСѓРјРµРЅС‚ Рё СѓРјРЅРѕР¶Р°РµС‚ РµРіРѕ РЅР° 2
void func2(struct Command *cmd) {
    int a = (*(int*)cmd->arg);
    *((int*)cmd->result) = a * 2;
}

// Р—РґР°РµРј СЃС‚СЂСѓРєС‚СѓСЂРµ РєРѕРјР°РЅРґС‹ С†РµР»РѕС‡РёСЃР»РµРЅРЅС‹Р№ РїР°СЂР°РјРµС‚СЂ
#define SET_ARG_INT(cmd, a) \
    cmd.arg = (int*)malloc(sizeof (int)*1);\
    *((int*)cmd.arg) = a;\
    cmd.result = (int*)malloc(sizeof (int) *1);

// Р—РґР°РµРј СЃС‚СЂСѓРєС‚СѓСЂРµ РєРѕРјР°РЅРґС‹ РґСЂРѕР±РЅС‹Р№ РїР°СЂР°РјРµС‚СЂ
#define SET_ARG_DOUBLE(cmd, d) \
    cmd.arg = (double*)malloc(sizeof(double)*1);\
    *((double*)cmd.arg) = d;\
    cmd.result = (double*)malloc(sizeof (double) *1);

struct Command returnCMD(int type) {
    struct Command cmd;
    switch (type) {
    case 1:
        SET_ARG_DOUBLE(cmd, 0.5);
        cmd.exe = func1;
        break;
    case 2:
        SET_ARG_INT(cmd, 2);
        cmd.exe = func2;
        break;
    }

    return cmd;
}

int main()
{
    struct Command cmd = returnCMD(2);
    cmd.exe(&cmd);
    printf("Result: %d\n", *((int*)cmd.result));

    cmd = returnCMD(1);
    cmd.exe(&cmd);
    printf("Result: %5.2lf\n", *((double*)cmd.result));

    return 0;
}
