#define TRUE 1
#define FALSE 0
#define TAM 30

typedef struct Data{

  char* idCliente;
  char* nombre;
  char* apPaterno;
  char* apMaterno;
  char* fechaAlta;
  float credito;
  float deuda;


}Data;

typedef Data* DATA;

typedef struct Node{

  DATA data;
  struct Node* next;

}Node;

typedef Node* NODE;

NODE createList();
DATA createData();


NODE createNodeList();
DATA createDataPackage(DATA);
DATA createDataPackagePerField(char*, char*, char*, char*, char*, float, float);

int emptyList(NODE);
void showList(NODE);
int size(NODE);

NODE insertTail(NODE, DATA);
DATA returnElementOnIndex(NODE, int);

void freeNodeOnIndex(NODE, int);
