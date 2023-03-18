//Program that converts Roman Numbers to Decimal numbers

#include <stdio.h>
#include <string.h>

int romanToDecimal(char c) {
    switch(c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int main() {
    char roman[20];
    int i, decimal = 0;

    printf("Digite um número romano: ");
    scanf("%s", roman);

    int len = strlen(roman);

    /*
    Se o número seguinte for superior ao anterior, temos que adicionar ao nosso
    valor o numero seguinte - o numero atual, ex:
    
    [Execução com XIV]
    i=1
    (I = 1) > (X = 10) = False
    decimal =+ 10 
    i=2
    (V = 5) > (I = 1) = True
    decimal =+ 5 - 1
    */

    for(i = 0; i < len; i++) {
        int current = romanToDecimal(roman[i]);
        int next = romanToDecimal(roman[i+1]);

        if(next > current) {
            decimal += (next - current);
            i++;
        } else {
            decimal += current;
        }
    }

    printf("O número decimal equivalente é: %d\n", decimal);

    scanf("%s", roman);
}
