// %2f

#include <stdio.h>
#include <stdlib.h>

int main(){
    
    printf("Digite 0 para sair.\n");

    float sum = 0, n = 0;
    char input[16];

    do{
        printf("%.2f: ", sum);
        fgets(input,16,stdin);
        n = atof(input);
        sum += n;
    }while(n != 0);

    printf("%f\n", sum);

    return 0;
}