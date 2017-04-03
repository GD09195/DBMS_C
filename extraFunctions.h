#include <stdlib.h>
#include <string.h>
#include <math.h>

int my_atoi(const char* snum){
    int idx, strIdx = 0, accum = 0, numIsNeg = 0;
    const unsigned int NUMLEN = (int)strlen(snum);

    /* Check if negative number and flag it. */
    if(snum[0] == 0x2d)
        numIsNeg = 1;

    for(idx = NUMLEN - 1; idx >= 0; idx--)
    {
        /* Only process numbers from 0 through 9. */
        if(snum[strIdx] >= 0x30 && snum[strIdx] <= 0x39)
            accum += (snum[strIdx] - 0x30) * pow(10, idx);

        strIdx++;
    }

    /* Check flag to see if originally passed -ve number and convert result if so. */
    if(!numIsNeg)
        return accum;
    else
        return accum * -1;
}



void validarID(char* idCliente){

  FILE* f = fopen("clientes.txt", "ab");
  char* string = malloc(TAM*5);


  fscanf(f, "%[^\n]", string);

  printf("\n%s\n", string);

  free(string);

}


void registrarTxt(DATA paqueteDeDatos){

  FILE *f = fopen("clientes.txt", "w");


  if (f == NULL){
    printf("\nError al abrir\n");
    exit(0);
  }

  fprintf(f, "%s, ", paqueteDeDatos->idCliente);
  fprintf(f, "%s, ", paqueteDeDatos->nombre);
  fprintf(f, "%s, ", paqueteDeDatos->apPaterno);
  fprintf(f, "%s, ", paqueteDeDatos->apMaterno);
  fprintf(f, "%s, ", paqueteDeDatos->fechaAlta);
  fprintf(f, "%0.2f, ", paqueteDeDatos->credito);
  fprintf(f, "%0.2f, ", paqueteDeDatos->deuda);
  fprintf(f, "\n");


  fclose(f);

  return;

}


int esFechaValida(char* fecha){


  char* diasString = malloc(TAM);
  char* mesesString = malloc(TAM);
  char* aniosString = malloc(TAM);
  int dias = 0;
  int meses = 0;
  int años = 0;


  if(strlen(fecha) != 10)
    return FALSE;

  if(fecha[2] != '/' || fecha[5] != '/')
      return FALSE;

  for(int i = 0; i < strlen(fecha) ; i++){

  }


  //obtener dias
  for(int i = 0; fecha[i] != '/'; i++){
    diasString[i] = fecha[i];
    
    if(diasString[i] < 48 || diasString[i] > 57)
      return FALSE;

  }

  dias = my_atoi(diasString);
  if(dias <= 0 || dias > 31)
    return FALSE;

  //obtener meses
  for(int i = 3; fecha[i] != '/'; i++){
    mesesString[i-3] = fecha[i];
     if(mesesString[i-3] < 48 || mesesString[i-3] > 57)
      return FALSE;
  }

  meses = my_atoi(diasString);
  if(meses <= 0 || meses > 12)
    return FALSE;

  //obtener años
  for(int i = 6; fecha[i] != '\0'; i++){
    aniosString[i-6] = fecha[i];

     if(aniosString[i-6] < 48 || aniosString[i-6] > 57)
      return FALSE;
  }

  años = my_atoi(aniosString);
  if ( años <= 0 ||años > 2017)
      return FALSE;


  return TRUE;
}