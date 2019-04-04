#include <stdio.h>
#include <stdlib.h>

float tps(void)
{
    float numero=0;
    float mayor;
    int contador=0;

    while(numero!=-1)
    {
    printf("Ingrese el primer valor");
    scanf("%f",&numero);



        if(numero>mayor)
        {
        mayor=numero;
        }
        contador++;
    }
    printf("el numero mayor es: %.2f ",mayor);
     return 0;
}

int main()
{
    tps();
    return(0);
}
