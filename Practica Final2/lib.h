#define INCREMENT 10
#define LIBROS 1
#define CLIENTES 2


typedef struct libro{
        
        
        char titulo[21];
        int isbn;
        int fkCliente;
        int activo;
        int cantidadStock;
        
        
        }libro;
        
typedef struct cliente{
        
        
        char nombre[21];
        int idCliente;
        int fkIsbn;
        int activo;
        
        }cliente;
        
        
        
        
  #define INCREMENT 10

typedef struct ArrayList{
        
        int size;
        void **pElements;
        int reservedSize;

        
        
        void (*set)();
        void (*add)();
        int(*Size)();
        void (*remov)();
        void(*clear)();
        struct ArrayList* (* clone)();
        void* (*Get)();
        int (*contains)();
        void(*push)();
        int(*indexOf)();
        int(*isEmpty)();
        void* (*pop)();
        struct ArrayList* (*subList)();
        int (* containsAll)();
        
        
        
        }ArrayList;
        
        
        
        
ArrayList* newArrayList(void);
void add(ArrayList*,void*);
void deleteArrayList(ArrayList*);
int Size(ArrayList*);
void* get(ArrayList* , int);
int contains(ArrayList*, void*);
int resizeUp(ArrayList*);
void set(ArrayList*, int,void*);
void remov(ArrayList*,int);
void clear(ArrayList*);
ArrayList* clone(ArrayList*);
void expand(ArrayList*,int);
void push(ArrayList*, int, void*);
int indexOf(ArrayList*, void*);
int isEmpty(ArrayList*);
void contract(ArrayList*,int);
void* pop(ArrayList*,int);
ArrayList* subList(ArrayList*,int,int);
int containsAll(ArrayList*,ArrayList*);      



void altaLibro(FILE*);
void altaCliente(FILE*);
void bajaLibro(FILE*);
void bajaCliente(FILE*);
void mostrar_segun_tipo(FILE *,int);
void mostrar(FILE *,FILE*);
void bajaFisica(FILE*,FILE*,FILE*, FILE *);
void cargar_libro_en_array(FILE*);
void alquilar(FILE*, FILE*);
void consultar_alquiler(FILE*,FILE*);
