#include <stdlib.h>

int validarID(NODE lista, char* idCliente){
  int state = 0;
  NODE aux = lista;

  if(emptyList(lista))
    return FALSE;

  while(aux->next != NULL){
    aux = aux->next;

  }
  return state;
}


int registrarTxt(DATA paqueteDeDatos){

  FILE *f = fopen("clientes.txt");
  int state = 0;

  if (f == NULL){
    printf("\nError al abrir\n");
    exit(0);
  }

  fprintf("%s, ", paqueteDeDatos->idCliente);
  fprintf("%s, ", paqueteDeDatos->nombre);
  fprintf("%s, ", paqueteDeDatos->apPaterno);
  fprintf("%s, ", paqueteDeDatos->apMaterno);
  fprintf("%s, ", paqueteDeDatos->fechaAlta);
  fprintf("%0.2f, ", paqueteDeDatos->credito);
  fprintf("%0.2f, ", paqueteDeDatos->deuda);







  return state;

}
