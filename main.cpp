
#include "Interface.h"
int main()
{
    /*
     El proyecto hace todo lo solcitado por el enunciado del examen
     el mismo fue desarollado en C++14 y el mismo es robusto con los ingresos de entradas

     Limitaciones:
     Las limitaciones son naturales como una recursividad excesiva, la impresion del mismo es en consola

     Opinion de Jose Bermudez hacia Gerardo Salazar

     Buen compañero de trabajo, cumplio con lo solicitado para  desarollar una buena comunicacion
     y ejecucion del desarollo de este proyecto, por lo tanto le doy un 100 como calificacion al
     apartado "Evaluacion de par un 100"



     Opinion de Gerardo hacia Geancarlo Bermudez:
     Jose Bermudez le doy un 100 por la colaboracion en las clases de trabajo,
     buen balance de trabajo, hubo buen
     feedback de tal manera que el codigo final fuera lo mas optimizado posible.


     */
    Interface* interface = new Interface;
    interface->menuPrincipal();
    delete interface;

    return 0;
}
