#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"
#include "extraFunctions.h"


NODE menuPrincipal(NODE lista);
NODE agregarRegistroEnLista(NODE);
void agregarRegistroArchivo(NODE);
void modificarRegistro();
void borrarRegistro();
void mostrarRegistros();

int main(){

  NODE lista = createList();

  menuPrincipal(lista);

  return 0;
}


NODE menuPrincipal(NODE lista){



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
        lista = agregarRegistroEnLista(lista);
        break;
      case 2:

        break;
      case 3:

        break;
      case 4:

        break;
    }

  }while(opc != 5);

  return lista;
}

NODE agregarRegistroEnLista(NODE lista){

  DATA paqueteRegistro = createData();

  char* idCliente = malloc(TAM);
  char* nombre = malloc(TAM);
  char* apPaterno = malloc(TAM);
  char* apMaterno = malloc(TAM);
  char* fechaAlta = malloc(TAM);
  float credito = 0 ;
  float deuda = 0;

  printf("\nIngrese los siguientes datos: ");
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

  printf("\nFecha de Alta: ");
  getchar();
  scanf("%[^\n]", fechaAlta);
  //Validar Formato de fecha de alta.

  insertTail(lista, paqueteRegistro);



  return lista;
}
