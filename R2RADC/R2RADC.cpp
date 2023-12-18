#include <locale.h>
#include <stdlib.h>
#include "r2r_dac.h"

int main()
{
    system("chcp 1251");
    setlocale(LC_ALL, "UTF8");
    run();

    return 0;
}