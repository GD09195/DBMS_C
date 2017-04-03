#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "extraFunctions.h"


void menuPrincipal(void);
void agregarRegistroEnLista(void);
void agregarRegistroArchivo(void);
void modificarRegistro();
void borrarRegistro();
void mostrarRegistros();

int main(){

  menuPrincipal();
  validarID("myID");

  return 0;
}


void menuPrincipal(){

  int opc = 0 ;

  do{

    printf("\n1. Agregar un nuevo registro");
    printf("\n2. Modificar un dato de un registo en particular");
    printf("\n3. Borrar un registro");
    printf("\n4. Mostrar registros");
    printf("\n5. Salir ");
    printf("Opcion: ");
    scanf("%d", &opc);

    switch(opc){

      case 1:
        printf("\n----Agregar Registro----\n");
        agregarRegistroEnLista();
        break;
      case 2:

        break;
      case 3:

        break;
      case 4:

        break;
    }

  }while(opc != 5);

  return;
}

void agregarRegistroEnLista(){

  DATA paqueteRegistro = createData();

  char* idCliente = malloc(TAM);
  char* nombre = malloc(TAM);
  char* apPaterno = malloc(TAM);
  char* apMaterno = malloc(TAM);
  char* fechaAlta = malloc(TAM);
  float credito = 0 ;
  float deuda = 0;


  printf("\nIngrese los siguientes datos: \n ");
  printf("\nidCliente: ");
  getchar();
  scanf("%[^\n]", idCliente);
  //Validar que el idCliente sea unico

  printf("\nNombre:  ");
  getchar();
  scanf("%[^\n]", nombre);

  printf("\nApellido paterno: ");
  getchar();
  scanf("%[^\n]", apPaterno);

  printf("\nApellido materno: ");
  getchar();
  scanf("%[^\n]", apMaterno);

  do{

    getchar();
    printf("\nFecha de Alta (dd/mm/aaaa): ");
    scanf("%[^\n]", fechaAlta);
   
  }while(!esFechaValida(fechaAlta));

  getchar();

  do{
    
    printf("\nCredito: ");
    scanf("%f", &credito);

  }while(credito < 0);
  
  do{
    
    printf("\nDeuda: ");
    scanf("%f", &deuda);

  }while(deuda < 0);
  
  paqueteRegistro =createDataPackagePerField(idCliente, nombre, apPaterno, apMaterno, fechaAlta, credito, deuda);
  registrarTxt(paqueteRegistro);

  return;
}






