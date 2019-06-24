#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"
#include <time.h>
#include <string.h>

int main()
{

    char seleccion='p',seleccionaccion, columnaingresada, tablerousuario[tam][tam], nombrepartidanueva[25], nombrepartidacargada[25];
    int filaingresada,terminado=0,ganador=0,seguirjugando=1;
    char tablero[tam][tam]; //tam est� definido en "libreria.h"
    while (seguirjugando==1){
        LimpiaPantalla();
        Titulo();
        printf("N: Nueva Partida");
        printf("\nC: Cargar Partida");
        printf("\nRecuerda que puedes guardar la partida en cualquier momento presionando G",162);
        printf("\n\nSelecciona que deseas hacer: ");
        seleccion=0;
        seleccion=ValidacionSeleccion(seleccion);


        if(seleccion=='n' || seleccion=='N'){
            ValidacionNombrePartidaNueva(nombrepartidanueva);
            strcat(nombrepartidanueva, ".txt");
        }
        if(seleccion=='c' || seleccion=='C'){
            ValidacionNombrePartidacargada(nombrepartidacargada);

            CargarPartidas(tablero,tablerousuario,nombrepartidacargada);

        }

        if (seleccion=='n' || seleccion=='N'){
            construir_tablero(tablero);
            VaciarTablaUsuario(tablerousuario);
        }
        terminado=0;
        while(terminado!=1 && ganador !=1){
            LimpiaPantalla();
            Titulo();
            //mostrar_tablero(tablero, 1); //tablero original, usado para debug
            mostrar_tablero(tablerousuario, 1);
            seleccionaccion=SeleccionAccion(seleccionaccion);
            while (seleccionaccion=='g' || seleccionaccion=='G'){
                GuardarPartida(tablero,tablerousuario,nombrepartidanueva,nombrepartidacargada,seleccion);
                seleccionaccion=SeleccionAccion(seleccionaccion);
            }
            printf("\nSeleccione la posici%cn.",162);
            filaingresada=ValidacionFilaIngresada(filaingresada);
            columnaingresada=ValidacionColumnaIngresada(columnaingresada);



            terminado=LlenarTableroUsuario(tablerousuario,tablero,filaingresada,columnaingresada,terminado,seleccionaccion);
            if(terminado==0){
                ganador=VerificarGanador(tablero,tablerousuario,ganador);
            }
        }
        if (ganador==1){
            printf("Felicidades Ganaste");
        }
        else if (ganador==0){
            LimpiaPantalla();
            Titulo();
            printf("\nPerdiste\n");
            printf("La solucion era:\n\n");
            mostrar_tablero(tablero, 1);
        }
        printf("\n%cDesea seguir jugando?",168);
        printf("\n1.-Si");
        printf("\n2.-No\n");
        scanf(" %i", &seguirjugando);
    }
    printf("\n\n");
    return 0;
}
