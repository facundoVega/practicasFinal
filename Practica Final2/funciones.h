#define INCREMENT 10

void mostrar_menu();
int mostrar_y_validar_menu();
int pedir_entero(char[]);
void pedir_cadena(char[],char[]);
void pedir_y_validar_cadena(char[],char[],int);
void Bajaf_cliente(FILE*, FILE*);
void bajaf_libro(FILE* , FILE*);
ArrayList* cargarLibrosEnArray(FILE*);
ArrayList* cargarClientesEnArray(FILE*);
void guardarLibrosEnArchivos(FILE*, ArrayList*);
void guardarClientesEnArchivos(FILE*, ArrayList*);
