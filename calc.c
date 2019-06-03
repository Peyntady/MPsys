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
        puts("1-Slocgenie\n2-Vichitanie\n3-Umnozenie\n4-Delenie\n5-Stepeni\n6-factorial\ncommand:");
        scanf("%i", &d);
        if ((d >= 1) && (d <= 6)) {
            if ((d <= 4) && (d > 0)) {
                printf("Resultat: %f\n", addition(d));
            } else {
                switch (d) {
                    case 5:
                        printf("resultat: %.2f\n", degree());
                        break;
                    case 6:
                        printf("resultat: %.2f\n", factorial());
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
