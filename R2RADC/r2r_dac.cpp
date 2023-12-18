#include "r2r_dac.h"

void r2r(int input, int num_bits) {
    double v_out = 0.0;
    double r_total = R_VALUE;
    int i;

    printf("\n�������� ���������� (����������):\n");

    for (i = num_bits - 1; i >= 0; --i) {
        int bit_value = (input >> i) & 1;
        double r = (bit_value == 1) ? R_VALUE : 2 * R_VALUE;

        v_out += (r / r_total) * (5.0);  // 5.0 - ������� ����������
        r_total += r;

        printf("��� %d: %.4f �\n", i, v_out);
    }
    printf("\n����� �������� ����������: %.4f �\n", v_out);
}

void run()
{
    int num_bits = 8;  // ���������� ��� � �������� �����
    int input_value;

    while (true)
    {
        printf("������� �������� �������� (0-255): ");
        scanf_s("%d", &input_value);

        if (input_value < 0 || input_value >(int)pow(2, num_bits) - 1) {
            printf("������: ������� ����� �� 0 �� %d\n", (int)pow(2, num_bits) - 1);
            continue;
        }

        r2r(input_value, num_bits);
    }
}