#include <stdio.h>
#include <stdlib.h>
#define tam 6
#include <time.h>
#include <string.h>

char columnas[27] = "abcdefghijklmnopqrstuvwxyz";

void Titulo(void){
    printf("                  \n");
    printf("XXXX  X  X  XXXX  XXXX   XXX  XX XX X X   X  XXX  XXXX \n");
    printf("X  X  X  X  XX    XX    X   X X X X X XX  X X   X XX   \n");
    printf("XXXX  X  X  XXXX  XX    XXXXX X   X X X X X XXXXX XXXX \n");
    printf("X  X  X  X    XX  XX    X   X X   X X X  XX X   X   XX \n");
    printf("XXXX  XXXX  XXXX  XXXX  X   X X   X X X   X X   X XXXX \n");
	printf("\n\n\n");
}

void LimpiaPantalla(void){
    system("clear||cls");
}

void crear_minas(char tablero[tam][tam]){
    int i, random;
    srand(time(0));
    for (i = 0; i < tam; i++){
        random = rand() % tam;
        tablero[random][i] = '*';
    }
     for (i = 0; i < tam; i++){
        random = rand() % tam;
        tablero[random][i] = '*';
    }

}
//se posicionan minas al azar dentro de la matris tablero, tiene de entrada el tablero y no returna nada
void construir_tablero(char tablero[tam][tam]){
    int i, j;
    for(i = 0; i < tam; i++){
        for(j = 0; j < tam; j++){
            tablero[i][j] = ' ';
        }
    }
    crear_minas(tablero);
    NumeroDeMinas(tablero);
}
//imprime el tablero, recibe como parametro de entrada tablero y fin, y no retorna nada
void mostrar_tablero(char tablero[tam][tam],int fin){
	int i, j;
	printf("   ");
	for(j = 0; j < tam; j++){
		printf("  %c ", columnas[j]);
	}
    printf("\n\n");
	for(i = 0; i < tam; i++){
		printf("%2d ", i+1);
        for(j = 0; j < tam; j++){
            if(fin == 1)
    			printf("| %c ",tablero[i][j]);
            else if(tablero[i][j] != '*')
                printf("| %c ",tablero[i][j]);
            else
                printf("|   ");
		}
		printf("|");
		printf("\n   ");
        for(j = 0; j < tam; j++) printf("----");
        printf("\n");
	}
}
//cuenta el numero de bombas adyacentes a una casilla, de entrada recibe el tablero y no retorna nada
void NumeroDeMinas(char tablero[tam][tam]){
    int i,j,k=0;
    for (i=0; i<tam; i++){
        for (j=0; j<tam; j++){
            if(i>0 && j>0 && i<(tam-1) && j<(tam-1)){

                if(tablero[i-1][j-1]=='*'){
                    k++;
                }
                if(tablero[i-1][j]=='*'){
                    k++;
                }
                if(tablero[i-1][j+1]=='*'){
                    k++;
                }
                if(tablero[i][j-1]=='*'){
                    k++;
                }
                if(tablero[i][j+1]=='*'){
                    k++;
                }
                if(tablero[i+1][j-1]=='*'){
                    k++;
                }
                if(tablero[i+1][j]=='*'){
                    k++;
                }
                if(tablero[i+1][j+1]=='*'){
                    k++;
                }
            }
            else if (i==0 && j==0){

                if(tablero[i][j+1]=='*'){
                    k++;
                }

                if(tablero[i+1][j]=='*'){
                    k++;
                }
                if(tablero[i+1][j+1]=='*'){
                    k++;
                }

            }
            else if (i==0 && j>0 && j<(tam-1)){

                if(tablero[i][j-1]=='*'){
                    k++;
                }
                if(tablero[i][j+1]=='*'){
                    k++;
                }
                if(tablero[i+1][j-1]=='*'){
                    k++;
                }
                if(tablero[i+1][j]=='*'){
                    k++;
                }
                if(tablero[i+1][j+1]=='*'){
                    k++;
                }
            }
            else if (i==0 && j==(tam-1)){
                if(tablero[i][j-1]=='*'){
                    k++;
                }

                if(tablero[i+1][j-1]=='*'){
                    k++;
                }
                if(tablero[i+1][j]=='*'){
                    k++;
                }
            }
            else if(i>0 && i<(tam-1) && j==0){


                if(tablero[i-1][j]=='*'){
                    k++;
                }
                if(tablero[i-1][j+1]=='*'){
                    k++;
                }

                if(tablero[i][j+1]=='*'){
                    k++;
                }

                if(tablero[i+1][j]=='*'){
                    k++;
                }
                if(tablero[i+1][j+1]=='*'){
                    k++;
                }
            }
            else if(i==(tam-1) && j==0){

                if(tablero[i-1][j]=='*'){
                    k++;
                }
                if(tablero[i-1][j+1]=='*'){
                    k++;
                }

                if(tablero[i][j+1]=='*'){
                    k++;
                }
            }
            else if(i==(tam-1) && j>0 && j<(tam-1)){

                if(tablero[i-1][j-1]=='*'){
                    k++;
                }
                if(tablero[i-1][j]=='*'){
                    k++;
                }
                if(tablero[i-1][j+1]=='*'){
                    k++;
                }
                if(tablero[i][j-1]=='*'){
                    k++;
                }
                if(tablero[i][j+1]=='*'){
                    k++;
                }
            }
            else if(i==(tam-1) && j==(tam-1)){

                if(tablero[i-1][j-1]=='*'){
                    k++;
                }
                if(tablero[i-1][j]=='*'){
                    k++;
                }
                if(tablero[i][j-1]=='*'){
                    k++;
                }
            }
            else if(i>0 && i<(tam-1) && j==(tam-1)){

                if(tablero[i-1][j-1]=='*'){
                    k++;
                }
                if(tablero[i-1][j]=='*'){
                    k++;
                }
                if(tablero[i][j-1]=='*'){
                    k++;
                }
                if(tablero[i+1][j-1]=='*'){
                    k++;
                }
                if(tablero[i+1][j]=='*'){
                    k++;
                }
            }

            if(k==0 && tablero[i][j]!='*'){
                tablero [i][j]='-';
            }
            if(k==1 && tablero[i][j]!='*'){
                tablero [i][j]='1';
            }
            if(k==2 && tablero[i][j]!='*'){
                tablero [i][j]='2';
            }
            if(k==3 && tablero[i][j]!='*'){
                tablero [i][j]='3';
            }
            if(k==4 && tablero[i][j]!='*'){
                tablero [i][j]='4';
            }
            if(k==5 && tablero[i][j]!='*'){
                tablero [i][j]='5';
            }
            if(k==6 && tablero[i][j]!='*'){
                tablero [i][j]='6';
            }
            if(k==7 && tablero[i][j]!='*'){
                tablero [i][j]='7';
            }
            if(k==8 && tablero[i][j]!='*'){
                tablero [i][j]='8';
            }
            k=0;
        }
    }
}
//vacia la tabla de usuario, para eliminar la basura que tenga la ram en ese momento, recibe como entrada el tablerousuario y no retorna nada
void VaciarTablaUsuario(char tablerousuario[tam][tam]){
    int i,j;
    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
            tablerousuario[i][j]=' ';
        }
    }

}
//segun la accion elegida por el usuario, abre una casilla, marca una mina o elimina una marca de mina, recibe tablero usuario, tablero, filaingresada, columna ingresada, terminado y seleecionaccion, retorna terminado
int LlenarTableroUsuario(char tablerousuario[tam][tam], char tablero[tam][tam], int filaingresada, char columnaingresada, int terminado,char seleccionaccion){
    int ColumnaEnNumero;
    filaingresada = filaingresada - 1;
    if (columnaingresada=='a' || columnaingresada=='A'){
        ColumnaEnNumero=0;
    }
    if (columnaingresada=='b'  || columnaingresada=='B'){
        ColumnaEnNumero=1;
    }
    if (columnaingresada=='c' || columnaingresada=='C'){
        ColumnaEnNumero=2;
    }
    if (columnaingresada=='d' || columnaingresada=='D'){
        ColumnaEnNumero=3;
    }
    if (columnaingresada=='e' || columnaingresada=='E'){
        ColumnaEnNumero=4;
    }
    if (columnaingresada=='f' || columnaingresada=='F'){
        ColumnaEnNumero=5;
    }
    if (columnaingresada=='g' || columnaingresada=='G'){
        ColumnaEnNumero=6;
    }
    if (columnaingresada=='h' || columnaingresada=='H'){
        ColumnaEnNumero=7;
    }
    if (columnaingresada=='i' || columnaingresada=='I'){
        ColumnaEnNumero=8;
    }
    if (seleccionaccion=='1'){
        tablerousuario[filaingresada][ColumnaEnNumero] = tablero[filaingresada][ColumnaEnNumero];
    }
    if (seleccionaccion=='2'){
        tablerousuario[filaingresada][ColumnaEnNumero] = 'M';
    }
    if (seleccionaccion=='3' && tablerousuario[filaingresada][ColumnaEnNumero]=='M'){
        tablerousuario[filaingresada][ColumnaEnNumero] = ' ';
    }
    else if(seleccionaccion=='3'){
        printf("Esta casilla no esta marcada\n");
        system("pause");
    }
    if (tablerousuario[filaingresada][ColumnaEnNumero]=='*'){
        terminado=1;
    }
    return terminado;
}
//verifica si las posiciones marcadas por el usuario coinciden con las minas del tablero solucion, recibe tablero, tablero usuario y ganador, retorna ganador
int VerificarGanador(char tablero[tam][tam], char tablerousuario[tam][tam], int ganador){
    int i,j,CantidadDeMinas=0,CantidadDeAciertos=0;
    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
            if(tablero[i][j]=='*'){
                CantidadDeMinas++;
            }
        }
    }

    for(i=0;i<tam;i++){
        for(j=0;j<tam;j++){
            if(tablero[i][j]=='*' && tablerousuario[i][j]=='M'){
                CantidadDeAciertos++;
            }
        }
    }

    if(CantidadDeMinas==CantidadDeAciertos){
        ganador=1;
    }
    return ganador;
}
//guarda la partida en curso, recibe tabloro, tablerousuario, nombrepartidanueva, nombrepartidacargada, y seleccion, no retorna nada
void GuardarPartida(char tablero[tam][tam],char tablerousuario[tam][tam],char nombrepartidanueva[25],char nombrepartidacargada[25],char seleccion){
    int i,j;
    if (seleccion=='c' || seleccion=='C'){
        strcpy(nombrepartidanueva, nombrepartidacargada);
    }
    FILE *save1;
        save1=fopen(nombrepartidanueva,"w");
        for (i=0;i<tam;i++){
            for (j=0;j<tam;j++){
                fprintf(save1,"%c",tablero[i][j]);
            }
        }
        fputc('\n',save1);
        for (i=0;i<tam;i++){
            for (j=0;j<tam;j++){
                fprintf(save1,"%c",tablerousuario[i][j]);
            }
        }
        printf("\nPartida guardada exitosamente\n");
        fclose(save1);

}
//valida que la seleccion del usuario sea correcta, recibe seleccionaccion y retorna seleccionaccion
char SeleccionAccion(char seleccionaccion){
    seleccionaccion='0';
    int errores;
    errores=0;
    while (seleccionaccion!='1' && seleccionaccion!='2' && seleccionaccion!='3' && seleccionaccion!='g' && seleccionaccion!='G' ){
        if(errores>0){
            printf("Car%ccter ingresado no v%clido",160,160);
        }
        printf("\nSeleccione la acci%cn que desea realizar",162);
        printf("\n1.-Abrir una casilla");
        printf("\n2.-Marcar una mina");
        printf("\n3.-Eliminar Marca de mina.");
        printf("\nG.-Guardar partida.\n");
        scanf(" %c", &seleccionaccion);
        fflush(stdin);
        errores++;
    }
return seleccionaccion;
}
//carga una partida guardada previamente por el usuario recibe tablero, tablero usuario, nombrepartidacargada, no retorna nada
void CargarPartidas(char tablero[tam][tam],char tablerousuario[tam][tam],char nombrepartidacargada[25]){

    int i,j;
    char a;
    FILE *cargar1;
    strcat(nombrepartidacargada, ".txt");
    cargar1=fopen(nombrepartidacargada, "r");
    while(cargar1==0){
        printf("\nLa partida que desea cargar no existe");
        ValidacionNombrePartidacargada(nombrepartidacargada);
        strcat(nombrepartidacargada, ".txt");
        cargar1=fopen(nombrepartidacargada, "r");
    }
    for (i=0;i<tam;i++){
       for (j=0;j<tam;j++){
            tablero[i][j]=fgetc(cargar1);
            printf("%c", tablero[i][j]);
        }
    }
    a=fgetc(cargar1);
    for (i=0;i<tam;i++){
        for (j=0;j<tam;j++){
            tablerousuario[i][j]=fgetc(cargar1);
            fflush(stdin);
            printf(" %c", tablerousuario[i][j]);
        }
    }
    if (tablerousuario[0][0]==' '){
        tablerousuario[0][0]=='  ';
    }

        fclose(cargar1);
}
//valida que la seleccion del usuario sea correcta, recibe seleccion y retorna seleccion
char ValidacionSeleccion(char seleccion){
    int valido, errores;
    valido=0;
    errores=0;
    seleccion='p';
    while (valido==0){
        scanf("%c",&seleccion);
        if (seleccion=='n' || seleccion=='N' || seleccion=='c' || seleccion=='C'){
            valido=1;
            errores=0;
        }
        if(errores>0){
            printf("\nCar%ccter ingresado no v%clido",160,160);
            printf("\n\nSelecciona que deseas hacer: ");
            fflush(stdin);
        }
        errores++;
    }
    return seleccion;


}
//valida que el nombre de la partida que se desea guardar sea correcto segun los parametros de windows, recibe nombrepartidanueva y no retorna nada
void ValidacionNombrePartidaNueva(char nombrepartidanueva[25]){
    int valido = 0,i;
    while (valido==0){
        printf("\nIngrese el nombre de la partida que desea crear\n");
        scanf("%s", nombrepartidanueva);
        fflush(stdin);
        valido=1;
        for (i=0;nombrepartidanueva[i]!='\0';i++){
            if (nombrepartidanueva[i]=='/' || nombrepartidanueva[i]=='\\' || nombrepartidanueva[i]=='|' || nombrepartidanueva[i]==':' || nombrepartidanueva[i]=='*' || nombrepartidanueva[i]=='?' || nombrepartidanueva[i]=='"' || nombrepartidanueva[i]=='<' || nombrepartidanueva[i]=='>'){
                printf("\ncar%ccter ingresado no v%clido, no son v%clidos los car%ccteres ('/' ,'\', '|', ':', '?', '\"', '<', '>')",160,160,160,160);
                valido=0;
                nombrepartidanueva[i+1]='\0';
            }
        }
    }

}
//valida que el nombre de la partida que se desea cargar sea correcto segun los parametros de windows, recibe nombrepartidacargada y no retorna nada
void ValidacionNombrePartidacargada(char nombrepartidacargada[25]){
    int valido = 0,i;
    while (valido==0){
        printf("\nIngrese el nombre de la partida que desea cargar\n");
        scanf("%s", nombrepartidacargada);
        fflush(stdin);
        valido=1;
        for (i=0;nombrepartidacargada[i]!='\0';i++){
            if (nombrepartidacargada[i]=='/' || nombrepartidacargada[i]=='\\' || nombrepartidacargada[i]=='|' || nombrepartidacargada[i]==':' || nombrepartidacargada[i]=='*' || nombrepartidacargada[i]=='?' || nombrepartidacargada[i]=='"' || nombrepartidacargada[i]=='<' || nombrepartidacargada[i]=='>'){
                printf("\ncar%ccter ingresado no v%clido, no son v%clidos los car%ccteres ('/' ,'\', '|', ':', '?', '\"', '<', '>')",160,160,160,160);
                valido=0;
                nombrepartidacargada[i+1]='\0';
            }
        }
    }

}
//valida que el numero de fila que ingrese el usuario sea correcto, recibe filaingresada y retorna filaingresada
int ValidacionFilaIngresada(int filaingresada){
    int valido, errores;
    valido=0;
    errores=0;
    filaingresada=0;

    while (valido==0){
        if (errores>0){
            printf("\nfila ingresada no v%clida",160);
        }
        printf("\nIngrese Fila: ");
        scanf(" %i", &filaingresada);
        fflush(stdin);
        if (filaingresada==1 || filaingresada==2 || filaingresada==3 || filaingresada==4 || filaingresada==5 || filaingresada==6){
            valido=1;
        }
        errores++;
    }
    return filaingresada;
}
//validaca que la columna ingresada sea correcta, recibe columnainresada y retorna columnaingresada
char ValidacionColumnaIngresada(char columnaingresada){
    int valido=0, errores=0;

    while (valido==0){
        if (errores>0){
            printf("\nfila ingresada no v%clida",160);
        }
        printf("\nIngrese Columna (en letra): ");
        scanf(" %c", &columnaingresada);
        fflush(stdin);
        if (columnaingresada=='a' || columnaingresada=='b' || columnaingresada=='c' || columnaingresada=='d' || columnaingresada=='e' || columnaingresada=='f' || columnaingresada=='A' || columnaingresada=='B' || columnaingresada=='C' || columnaingresada=='D' || columnaingresada=='E' || columnaingresada=='F'){
            valido=1;
        }
        errores++;
    }
    return columnaingresada;
}

