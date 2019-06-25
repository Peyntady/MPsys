#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


float addition(int d){
    float a,b;
    puts("Vvedite pervoe chislo");
    scanf("%f",&a);
    puts("Vvedite vtoroe chislo");
    scanf("%f", &b);
    switch (d) {
        case 1:
            return a + b;
        case 2:
            return a - b;
        case 3:
            return a * b;
        case 4:
            return a / b;
    }
    return 0;
}


float degree() {
    float a,k;
    int s;
    puts("Vvedite chislo:");
    scanf("%f", &a);
    puts("Vvedite stepen:");
    scanf("%i", &s);
    k = a;
    if (s != 0) {
        for (int i = 1; i < s; i++) {
            a = a * k;
        }
        return a;
    } else {
        return 1;
    }
}

float vectorchar(){
    float a,b,c,h; // Умножение вектора с 3 координатами на число h
    puts("enter the coordinates vector");
    scanf("%f %f %f",&a,&b,&c); //Ввод вектора
    puts("What number do you want to multiply the vector of?");
    scanf("%f",&h);// На какое число нам умножать вектора
    a = a * h;
    b = b * h;
    c = c * h;
    return printf("%.2f %.2f %.2f\t",a,b,c);
}

float vectorarifmetic() {
    int a, g; // C помощью переменной 'a' задаем длинну вектора, а с помощью переменной g команду для ветторов /сложение/вычитание/умнлжение

    float d; //Промежуточный контейнер для хранение результата операции над векторами. Нужен для удобства. Можно убрать при надобности. Убирать я его не хочу

    float *vector1 = NULL, *vector2 = NULL; //Два вектора незивестной длинны. Для них мы не освобождали память

    puts("V kakom n-mernom prostranstve budut vectora"); //Вычисление векторов может происходить в 2-х мерном пространстве, 3-х мерном и тд
    scanf("%i", &a); //Пользователь задает длинну вектора

    if (a > 0) {
        puts("Vvedite 1 vector");
        vector1 = malloc(a * sizeof(float)); //Выделиние памяти для 3-х чисел типа "float
        for (int i = 0; i < a; i++) {  //ввод каждого элемента вектора
            printf("vector1[%d]", i); //Просьба ввести вектор определенного номер
            scanf("%f", &vector1[i]); // Считывание вектора
        }

        puts("Vvedite 2 vector"); //Аналогичные операции и со 2 вектором
        vector2 = malloc(a * sizeof(float));
        for (int i = 0; i < a; i++) {
            printf("vector2[%d]", i);
            scanf("%f", &vector2[i]);
        }

        puts("What operation do you want to perform?\n"
             "1- Addition\n"
             "2-Subtraction\n"
             "3- Scalar product"); // Выбор операции с векторами
        scanf("%i", &g); //Выбор операции над уже заданными векторами

        switch (g) {
            case 1:
                printf("{"); // Скобка для красоты
                for (int i = 0; i < a; i++) { //Операции с ветором и вывод их на экрна
                    d = vector1[i] + vector2[i];
                    printf("%.2f\t", d);
                }
                puts("\b}");
                free(vector1);
                free(vector2); //Освобождеение памяти
                break;
            case 2:
                printf("{"); // Или для удобства
                for (int i = 0; i < a; i++) { //Операции с ветором и вывод их на экрна
                    d = vector1[i] - vector2[i];
                    printf("%.2f\t", d);
                }
                puts("\b}");
                free(vector1);
                free(vector2); //Освобождение памяти
                break;
            case 3:
                d = 0;
                for (int i = 0; i < a; i++) {
                    d = d + (vector1[i] * vector2[i]);
                }
                printf("%.2f\t", d);
                free(vector1);
                free(vector2);  //Освобождение памяти
                break;
        }
    }
    else {
        puts("Пространство не может быть без направлений или n-мерное пространство не может быть отрицательным");
    }
    return 0;
}

float factorial(){
    int y;
    float a;
    puts("Vvedite chislo dlya nahozhdenia factoriala");
    scanf("%f",&a);
    y = 1;
    for(int i=1;i <= a;i++) y = y * i;
    return y;
}

int main(void) {
    int d, returncom;
    while(true) {
        puts("1-Slocgenie\n2-Vichitanie\n3-Umnozenie\n4-Delenie\n5-Stepeni\n6-factorial\n7-vector operation\n8-multiply vector by number\ncommand:");
        scanf("%i", &d);
        if ((d >= 1) && (d <= 8)) {
            if ((d <= 4) && (d > 0)) {
                printf("Resultat: %f\n", addition(d));
            } else {
                switch (d) {
                    case 5:
                        printf("resultat: %.2f\n", degree());
                        break;
                    case 6:
                        printf("resultat: %.2f\n", factorial());
                    case 7:
                        vectorarifmetic();
                        break;
                    case 8:
                        vectorchar();
                        break;
                }
            }
        } else {
            puts("Nepravilnaya comanda");
        }
        puts("Prodolzhit? Vvedite 1 ili luboe chislo chtobi viyti");
        scanf("%i", &returncom);
        if (returncom == 1) {
            continue;
        } else {
            puts("Zachem vi vishli?!?!?! Vam ne ponravilsya calculator?!");
            break;
        }
    }
}