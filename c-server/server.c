#include <stdio.h>
#include <stdlib.h>

//Erklaerungen:
//argc = argument count ( anzahl der argumente, 0tes argument ist der Programmaufruf )
//argv = argument vector ( array/vector, welcher die uebergebenen argumente in ein array packt. Aufruf mit argv[0], argv[1], etc...)
//define variable, wert
//strtol nimmt drei parameter entgegen: pointer auf den string der konvertiert werden soll, pointer der auf das erste zeichen nach der zahl zeigt ( wenn keine zahl dann enptr == string ), basis, in der der String interpretiert werden soll.
//0=automatische erkennung, 2 = binaer, 8 = oktal, 10 = dezimal etc... 

#define OK 0
#define NOT_OK 1

int main(int argc, char *argv[]) 
{

    char operatorArray[4] = {'+', '-', '*', '/'};
    int size = sizeof(operatorArray);
    int reason = NOT_OK;

    if ( argc < 2 || argc > 4)
    {
        printf("Gebe eine Zahl, einen Operator und eine weitere Zahl an. Gueltige Operatoren sind +, -, *, /");
        reason = NOT_OK;
    }

    char *endptr;
    char *secondEndptr;

    long firstNmbr = strtol(argv[1], &endptr, 10);
    long secondNmbr = strtol(argv[3], &secondEndptr, 10);

    if (endptr == argv[1])
    {
        printf("Argument 1 ist keine gueltige Zahl!");
        reason = NOT_OK;
    }   

    if (endptr == argv[3])
    {
        printf("Argument 3 ist keine gueltige Zahl!");
        reason = NOT_OK;
    }   

    char target = argv[2];
    int index = indexFunktion(operatorArray, size, target);



    



    if ( reason == NOT_OK )
    {
        return 1;
    }
}

