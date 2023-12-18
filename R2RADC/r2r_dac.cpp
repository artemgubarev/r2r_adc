#include "r2r_dac.h"

void r2r(int input, int num_bits) {
    double v_out = 0.0;
    double r_total = R_VALUE;
    int i;

    printf("\nВыходное напряжение (аналоговое):\n");

    for (i = num_bits - 1; i >= 0; --i) {
        int bit_value = (input >> i) & 1;
        double r = (bit_value == 1) ? R_VALUE : 2 * R_VALUE;

        v_out += (r / r_total) * (5.0);  // 5.0 - опорное напряжение
        r_total += r;

        printf("Бит %d: %.4f В\n", i, v_out);
    }
    printf("\nОбщее выходное напряжение: %.4f В\n", v_out);
}

void run()
{
    int num_bits = 8;  // Количество бит в цифровом слове
    int input_value;

    while (true)
    {
        printf("Введите цифровое значение (0-255): ");
        scanf_s("%d", &input_value);

        if (input_value < 0 || input_value >(int)pow(2, num_bits) - 1) {
            printf("Ошибка: Введите число от 0 до %d\n", (int)pow(2, num_bits) - 1);
            continue;
        }

        r2r(input_value, num_bits);
    }
}