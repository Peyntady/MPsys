#include <stdio.h>

#include <locale.h>
#include <stdlib.h>


int main(void)
{
    char exit = 0;
    char operation_type = 0;
    char data_type = 0; // переменная для хранения типа данных в файле
    int i = 0; //переменная для подсчета операций

    FILE *in_file; //дескриптор входного файла
    FILE *out_file; //дескриптор выходного файла
    setlocale(LC_ALL, "Russian");

    do //цикл подтверждения на выполнение оперции с файлом
    {
        puts("Vvedite luboy simvol ili 'q' dlya vihoda");

        scanf(" %c", &exit);
        if (exit == 'q')
        {
            break; //выход из цикла
        }

        in_file = fopen("input.txt", "r");
        out_file = fopen("output.txt", "w");
        // после того как выполнили fopen() в переменых in_file и out_file появляются значения типа 0x3456.

        // "+ v 2 1 1 -8 -2" операции с векторами
        // "+ s 52 34" операции с числами

        // файл открыт и по умолчанию система смотрит на начало файла, т.е. на символ "+"
        fscanf(in_file, "%c", &operation_type); // читаем тип данных %c, т.е. char. Прочитали тип операции "+" в переменную, теперь operation_type == '+'

        fscanf(in_file, " %c", &data_type);
        // после выполнения fscanf() система сдвинется на пробел и на один символ и смотрит теперь опять на пробел, который перед '2'
        switch (data_type)
        // теперь смотрим, какой же у нас тип данных в файле, который мы вычитали
        {
            case 's':
            {
                int number_1;
                int number_2;
                float result;
                // в этом месте программа смотрит на пробел после "+ s"
                fscanf(in_file, " %d", &number_1);
                fscanf(in_file, " %d", &number_2);

                switch (operation_type)
                {
                    case '+':
                        result = number_1 + number_2;
                        // функция fprintf работает точно так же как функция printf, только выводит результат не в консоль, а в файл, поэтому в нее нужно передать дескриптор на файл, куда хотим записать информацию
                        fprintf(out_file, "Otvet: %d + %d = %f \n", number_1, number_2,
                                result);
                        break;
                    case '-':
                        result = number_1 - number_2;
                        fprintf(out_file, "Otvet: %d - %d = %f \n", number_1, number_2,
                                result);
                        break;
                    case '*':
                        result = number_1 * number_2;
                        fprintf(out_file, "Otvet: %d * %d = %f \n", number_1, number_2,
                                result);
                        break;
                    case '/':
                        result = number_1 / number_2;
                        fprintf(out_file, "Otvet: %d / %d = %f \n", number_1, number_2,
                                result);
                        break;
                    case '^':
                        result = 1; // нужно задать значение result, чтобы не испортить первый шаг цикла

                        for (i = 0; i < number_2; i++)
                        {
                            result = result * number_1;
                        }
                        fprintf(out_file, "Otvet: %d ^ %d = %f \n", number_1, number_2,
                                result);
                        break;
                    case '!':
                        if (number_1 == 0)
                        {
                            result = 1;
                        }
                        else
                        {
                            result = 1;
                            for (i = 1; i <= number_1; i++)
                            {
                                result = result * i;
                            }
                        }
                        fprintf(out_file, "Otvet: %d! = %f \n", number_1, result);
                        break;
                    default:
                        puts(
                                "Oshibka, proverte file");
                        break;
                }
                break;
            }
            case 'v':
            {
                int *vector_1; // указатель на первый вектор. В этой переменной хранится адрес начала массива
                int *vector_2;
                float *vector_result; // указатель на вектор, содержащий результат. В этой переменной хранится адрес начала массива
                int size = 0; // размер всех векторов. Прочитаем его из файла

                fscanf(in_file, " %d", &size); // читаем из файла размер векторов

                vector_1 = calloc(size, sizeof(int)); // функция calloc выделяет память для вектора. size - количество элементов, sizeof(int) - размер одного элемента
                vector_2 = calloc(size, sizeof(int));
                vector_result = calloc(size, sizeof(float)); // функция calloc выделяет память для вектора. size - количество элементов, sizeof(int) - размер одного элемента
                // читаем значения 1 вектора из файла
                for (i = 0; i < size; i++)
                {
                    fscanf(in_file, " %d", &vector_1[i]);
                }
                // читаем значения 2 вектора из файла
                for (i = 0; i < size; i++)
                {
                    fscanf(in_file, " %d", &vector_2[i]);
                }
                // оператор switch сравнивает значение внутри (operation_type) с каждым из case. И если оно совпало, то идет в эту ветку
                switch (operation_type)
                {
                    case '+':
                        // выполняем сложее векторов
                        for (i = 0; i < size; i++)
                        {
                            vector_result[i] = vector_1[i] + vector_2[i];
                        }

                        fprintf(out_file, "(");
                        for (i = 0; i < size; i++)
                        {
                            if (i != size - 1)
                            {
                                fprintf(out_file, "%d ", vector_1[i]);
                            }
                            else
                            {
                                fprintf(out_file, "%d)", vector_1[i]);
                            }
                        }

                        fprintf(out_file, " + ");

                        fprintf(out_file, "(");
                        for (i = 0; i < size; i++)
                        {
                            if (i != size - 1)
                            {
                                fprintf(out_file, "%d ", vector_2[i]);
                            }
                            else
                            {
                                fprintf(out_file, "%d)", vector_2[i]);
                            }
                        }

                        fprintf(out_file, " = ");
                        fprintf(out_file, "(");
                        for (i = 0; i < size; i++)
                        {
                            if (i != size - 1)
                            {
                                fprintf(out_file, "%.2f ", vector_result[i]);
                            }
                            else
                            {
                                fprintf(out_file, "%.2f)", vector_result[i]);
                            }
                        }
                        break;
                    case '-':
                        // выполняем вычитание векторов
                        for (i = 0; i < size; i++)
                        {
                            vector_result[i] = vector_1[i] - vector_2[i];
                        }

                        fprintf(out_file, "(");
                        for (i = 0; i < size; i++)
                        {
                            if (i != size - 1)
                            {
                                fprintf(out_file, "%d ", vector_1[i]);
                            }
                            else
                            {
                                fprintf(out_file, "%d)", vector_1[i]);
                            }
                        }

                        fprintf(out_file, " - ");
                        fprintf(out_file, "(");
                        for (i = 0; i < size; i++)
                        {
                            if (i != size - 1)
                            {
                                fprintf(out_file, "%d ", vector_2[i]);
                            }
                            else
                            {
                                fprintf(out_file, "%d)", vector_2[i]);
                            }
                        }

                        fprintf(out_file, " = ");
                        fprintf(out_file, "(");
                        for (i = 0; i < size; i++)
                        {
                            if (i != size - 1)
                            {
                                fprintf(out_file, "%.2f ", vector_result[i]);
                            }
                            else
                            {
                                fprintf(out_file, "%.2f)", vector_result[i]);
                            }
                        }
                        break;
                    case '*':
                        // выполняем умножение векторов
                        for (i = 0; i < size; i++)
                        {
                            vector_result[i] = vector_1[i] * vector_2[i];
                        }

                        fprintf(out_file, "(");
                        for (i = 0; i < size; i++)
                        {
                            if (i != size - 1)
                            {
                                fprintf(out_file, "%d ", vector_1[i]);
                            }
                            else
                            {
                                fprintf(out_file, "%d)", vector_1[i]);
                            }
                        }

                        fprintf(out_file, " * ");
                        fprintf(out_file, "(");
                        for (i = 0; i < size; i++)
                        {
                            if (i != size - 1)
                            {
                                fprintf(out_file, "%d ", vector_2[i]);
                            }
                            else
                            {
                                fprintf(out_file, "%d)", vector_2[i]);
                            }
                        }

                        fprintf(out_file, " = ");
                        fprintf(out_file, "(");
                        for (i = 0; i < size; i++)
                        {
                            if (i != size - 1)
                            {
                                fprintf(out_file, "%.2f ", vector_result[i]);
                            }
                            else
                            {
                                fprintf(out_file, "%.2f)", vector_result[i]);
                            }
                        }
                        break;
                    case '/':
                        // выполняем деление векторов
                        for (i = 0; i < size; i++)
                        {
                            vector_result[i] = vector_1[i] / vector_2[i];
                        }

                        fprintf(out_file, "(");
                        for (i = 0; i < size; i++)
                        {
                            if (i != size - 1)
                            {
                                fprintf(out_file, "%d ", vector_1[i]);
                            }
                            else
                            {
                                fprintf(out_file, "%d)", vector_1[i]);
                            }
                        }

                        fprintf(out_file, " / ");
                        fprintf(out_file, "(");
                        for (i = 0; i < size; i++)
                        {
                            if (i != size - 1)
                            {
                                fprintf(out_file, "%d ", vector_2[i]);
                            }
                            else
                            {
                                fprintf(out_file, "%d)", vector_2[i]);
                            }
                        }

                        fprintf(out_file, " = ");
                        fprintf(out_file, "(");
                        for (i = 0; i < size; i++)
                        {
                            if (i != size - 1)
                            {
                                fprintf(out_file, "%.2f ", vector_result[i]);
                            }
                            else
                            {
                                fprintf(out_file, "%.2f)", vector_result[i]);
                            }
                        }
                        break;
                    default:
                        puts(
                                "Oshibka, proverte file");
                        break;
                }
                // free - освобождает память, которую выделили, используя calloc
                free(vector_1);
                free(vector_2);
                free(vector_result);
                break;
            }
            default:
                puts("Oshibka, proverte file");
                break;
        }
        fclose(in_file);
        fclose(out_file);

        puts("Operacia zavershena. Proverte file.");
    }
    while (exit != 'q');

    puts("Zavershenie");
}