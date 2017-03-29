#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

NODE createList(){
  NODE list = NULL;
  return list;
}


DATA createData(){
  DATA datos = NULL;
  return datos;
}

NODE createNodeList(){
  NODE newNode;

  newNode = (NODE)malloc(sizeof(Node));
  if(newNode == NULL)
    exit(0);

  return newNode;

}


DATA createDataPackage(DATA nuevosDatos){
  DATA datos = createData();

  datos -> idCliente = malloc(strlen (nuevosDatos->idCliente) );
  datos -> nombre = malloc(strlen (nuevosDatos->nombre) );
  datos -> apPaterno = malloc(strlen ( nuevosDatos->apPaterno) );
  datos -> apMaterno = malloc(strlen ( nuevosDatos->apMaterno) );
  datos -> fechaAlta = malloc(strlen (nuevosDatos-> fechaAlta) );

  datos -> idCliente =  nuevosDatos-> idCliente;
  datos -> nombre = nuevosDatos-> nombre;
  datos -> apPaterno = nuevosDatos-> apPaterno;
  datos -> apMaterno = nuevosDatos-> apMaterno;
  datos -> fechaAlta = nuevosDatos-> fechaAlta;
  datos -> credito = nuevosDatos-> credito;
  datos -> deuda = nuevosDatos-> deuda;


  return datos;

}

DATA createDataPackagePerField(char* idCliente, char*nombre, char* apPaterno, char* apMaterno, char* fechaAlta, float deuda, float credito){

  DATA datos = createData();
  datos -> idCliente = malloc(strlen (idCliente) );
  datos -> nombre = malloc(strlen (nombre) );
  datos -> apPaterno = malloc(strlen ( apPaterno) );
  datos -> apMaterno = malloc(strlen ( apMaterno) );
  datos -> fechaAlta = malloc(strlen ( fechaAlta) );

  datos -> idCliente =  idCliente;
  datos -> nombre = nombre;
  datos -> apPaterno = apPaterno;
  datos -> apMaterno = apMaterno;
  datos -> fechaAlta = fechaAlta;
  datos -> credito = credito;
  datos -> deuda = deuda;

  return datos;

}

int emptyList(NODE list){
  if (list == NULL)
    return TRUE;

  return FALSE;
}

void showList(NODE list){

  NODE aux = list;
  int index = 0;

  if(emptyList(list))
    return;

  while (aux != NULL){
    printf("\nCliente %d\n", index);
    printf("\n%s", aux->data->idCliente);
    printf("\n%s", aux->data->nombre);
    printf("\n%s", aux->data->apPaterno);
    printf("\n%s", aux->data->apMaterno);
    printf("\n%s", aux->data->fechaAlta);
    printf("\n%0.2f", aux->data->credito);
    printf("\n%0.2f", aux->data->deuda);
    aux = aux->next;
    index++;

  }
  printf("\n\n");

  return;
}


int size(NODE list){

  NODE aux = list;
  int size = 0;

  while(aux != NULL){
    size++;
    aux = aux -> next;
  }
  return size;

}

NODE insertTail(NODE lista, DATA nuevosDatos){

  NODE aux;
  NODE newNode = createNodeList();
  DATA datos = createDataPackage(nuevosDatos);
  newNode -> data = datos;


  if (lista == NULL){
    return newNode;
  }

  aux = lista;

  while (aux->next != NULL){
    aux = aux->next;
  }

  aux->next = newNode;


  return lista;
}

DATA returnElementOnIndex(NODE lista, int index){

  NODE aux = lista;

  if(emptyList(lista) || index >= size(lista) || index < 0)
   return NULL;

  for(int i = 0 ; i <= index ; i++){

    aux = aux->next;

  }

  return aux->data;

}

void freeNodeOnIndex(NODE lista, int index){

  NODE aux;

  aux = lista;

  if(emptyList(lista) || index < 0 || index >= size(lista) )
    return;

  if(index == 0){

    free(aux -> data -> idCliente);
    free(aux -> data -> nombre);
    free(aux -> data -> apPaterno);
    free(aux -> data -> apMaterno);
    free(aux -> data -> fechaAlta);

    free(aux -> data);
    free(lista);
    return;

  }


  for (int i = 0 ; i < index ; i++){
    aux = aux -> next;
  }

  free(aux -> next -> data -> idCliente);
  free(aux -> next -> data -> nombre);
  free(aux -> next -> data -> apPaterno);
  free(aux -> next -> data -> apMaterno);
  free(aux -> next -> data -> fechaAlta);

  free(aux -> next -> data);
  free(aux -> next);


  return;
}
