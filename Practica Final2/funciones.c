#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "funciones.h"
#include "lib2.h"




/*muestra un menu de opciones en pantalla
*/
void mostrar_menu()
{
        
        printf("\tMENU PRINCIPAL:\n\n\n");
        printf("\t1_ALTA LIBRO\n");
        printf("\t2_REGISTRAR CLIENTE\n");
        printf("\t3_BAJA LIBRO\n");
        printf("\t4_BAJA CLIENTE\n");
        printf("\t5_MOSTRAR\n");
        printf("\t6_BAJA FISICA\n");
        printf("\t7_CARGAR LIBRO EN ARRAY Y MOSTRAR DESDE ARRAY\n");
        printf("\t8_ALQUILAR\n");
        printf("\t9_CONSULTAR ALQUILER\n");
        printf("\t10_SALIR\n\n\n\n");
        printf("Ingrese un numero segun la opcion que desea realizar\n");
        
     
     
     
}

int mostrar_y_validar_menu()
{
    int a=0;
    int opcion;
    
    do
    {
        if(a)
             printf("ERROR,el numero ingresado no pertenece a una opcion valida para el menu\nIntente nuevamente\n\n");
             

             mostrar_menu();
             fflush(stdin);
             scanf("%d", &opcion);
             system("cls");
        
             a=1;
        
    }
    while(opcion<1||opcion>9);
    
    return opcion;
    
    
    
}



/*pide un entero por pantalla
 *recibe una cadena que es el dato que se mostrara en pantalle para recibir el valor
 *retorna el numero ingresado.
 */
int pedir_entero(char mensaje[])
{
    long int numero;
    
    printf("ingrese %s \n", mensaje);
    fflush(stdin);
    scanf("%d", &numero);
    
    return numero;
    
    
    
}

/* recibe el ingreso de una cadena por consola
/*El primer parametro que recibe es para mostrar un mensaje en pantalla en funcion del dato que se quiere obtener.
/*El segundo es donde se va a almacenar la cadena recibida.
*/

void pedir_cadena(char mensaje[],char vector[])
{
     
     
     printf("Ingrese %s\n", mensaje);
     fflush(stdin);
     gets(vector);
     system("cls");
     
     
     
     
}



/*recibe el ingreseo de una cadena por consola
/*valida que la cantidad de caracteres ingresados no supere el limite para el dato
/*el primero char que recibe es para el mensaje que se mostrara en pantalla el segundo para almacenar la cadena recibida
/*y el entero es el limite maximo de carateres.
*/
void pedir_y_validar_cadena(char mensaje[],char vector[],int max)
{
     char a=0;
     char aux[500];
     
     do
     {
          if(a)
          {     
                printf("Se excedio el maximo de caracteres a ingresar \nIntente nuevamente\n");
               
          }
          pedir_cadena(mensaje,aux);
          a=1;
          
          
          
     }
     while(strlen(aux)>max||strlen(aux)<1);
     
     strcpy(vector,aux);
     
     
}


         

          

void Bajaf_cliente(FILE* fCliente1, FILE* fCliente2)
{
     
     int cantidad;
     cliente auxCliente;
     cliente auxCliente2;
     int codigo;
     
     
     codigo=pedir_entero("Ingrese codigo del cliente a dar de baja");
     
     rewind(fCliente1);
     
     while(!feof(fCliente1))
     {
                            cantidad=fread(&auxCliente, sizeof(cliente), 1, fCliente1);
                            
                            if(cantidad<1)
                            {
                                          if(feof(fCliente1))
                                          {
                                                             break;
                                                             
                                          }
                                          else
                                          {
                                              printf("ERROR, al leer el archivo\n");
                                              break;
                                              
                                          }
                                          
                                          
                            }
                            
                            if(auxCliente.idCliente!=codigo)
                            {
                                                            
                                                            
                                                 auxCliente2=auxCliente;           
                                                            
                                                            
                            }
                            
                            
                            fseek(fCliente2,0L,SEEK_END);
                            fwrite(&auxCliente2, sizeof(cliente), 1, fCliente2);
                            
     }
     fclose(fCliente1);
     fclose(fCliente2);
     
     
     system("del clientes.txt");
     system("ren clientes2.bin clientes.txt");
     
     if((fCliente1=fopen("clientes.txt", "wb+"))==NULL)
     {
                                         if((fCliente1=fopen("clientes.txt", "wr+"))==NULL)
                                         {
                                                                             printf("ERROR, al abrir el archivo\n");
                                                                             exit(1);
                                                                             
                                                                             
                                                                             
                                         }
                                         
                                         
                                         
     }
     
     if((fCliente2=fopen("clientes2.bin", "wb+"))==NULL)
     {
                                          if((fCliente2=fopen("clientes2.bin", "rb+"))==NULL)
                                          {
                                                                               printf("ERROR, al abrir el archivo\n");
                                                                               exit(1);
                                                                               
                                                                               
                                                                               
                                                                               
                                                                               
                                          }
                                          
                                          
                                          
     }
     
     
     
     
}



void bajaf_libro(FILE* fLibro1 , FILE* fLibro2)
{
     int cant;
     libro auxLibro,auxLibro2;
     int isbnLibro;
     
     isbnLibro=pedir_entero("isbn del libro a dar de baja fisicamente\n");
     
     
     rewind(fLibro1);
     
     while(!feof(fLibro1))
     {
                          cant=fread(&auxLibro,sizeof(libro), 1, fLibro1);
                          
                          if(cant<1)
                          {
                                    if(feof(fLibro1))
                                    {
                                                     break;
                                                     
                                                     
                                    }
                                    else
                                    {
                                        printf("error, al abrir el archivo\n");
                                        
                                        
                                        
                                    }
                          
                                    
                                    
                                    
                          }
                          
                          if(isbnLibro!=auxLibro.isbn)
                          {
                                                      auxLibro2=auxLibro;
                                                      
                                                      
                                                      
                          }
                          
                          
                          fseek(fLibro2, 0L, SEEK_END);
                          fwrite(&auxLibro2, sizeof(auxLibro2), 1, fLibro2);
                          
     }
     
     fclose(fLibro2);
     fclose(fLibro1);
     
     system("del libros.bin");
     system("ren libros2.bin libros.bin" );
     
     if((fLibro1=fopen("libros.bin", "wb+"))==NULL)
     {
                                     if((fLibro1=fopen("libros.bin", "rb+"))==NULL)
                                     {
                                                                     printf("ERROR, al abrir el archivo\n");
                                                                     exit(1);
                                                                     
                                                                     
                                     }
                                     
                                     
     }
     
     if((fLibro2=fopen("libros2.bin", "wb+"))==NULL)
     {
                                      if((fLibro2=fopen("libros2.bin", "rb+"))==NULL)
                                      {
                                                                       printf("ERROR, al abrir archivo\n");
                                                                       exit(1);
                                                                       
                                                                       
                                      }
                                      
                                      
     }
     
     
     
}


ArrayList* cargarLibrosEnArray(FILE* pFile)
{
           ArrayList* pList;
           int cant;
           libro* auxLibro;
           
           
           pList=newArrayList();
           rewind(pFile);
           
           while(!feof(pFile))
           {
                              auxLibro=(libro *)malloc(sizeof(libro));
                              cant=fread(auxLibro, sizeof(libro), 1, pFile);
                              
                              if(cant<1)
                              {
                                        if(feof(pFile))
                                        {
                                                       break;
                                                       
                                                       
                                        }
                                        else
                                        {
                                            printf("no se pudo leer el archivo\n");
                                            break;
                                            
                                            
                                        }
                                        
                              }
                              
                              pList->add(pList, auxLibro);
                              
                              
                              
           }
           
           free(auxLibro);
           return pList;
           
           
           
           
           
           
           
}

ArrayList* cargarClientesEnArray(FILE* pFile)
{
           ArrayList* pList;
           cliente* auxCliente;
           int cant;
           
           pList=newArrayList();
           
           rewind(pFile);
           
           while(!feof(pFile))
           {
                              auxCliente=(cliente *)malloc(sizeof(cliente));
                              cant=fread(auxCliente, sizeof(cliente), 1, pFile);
                              
                              if(cant<1)
                              {
                                        if(feof(pFile))
                                        {
                                                       break;
                                                       
                                                       
                                        }
                                        else
                                        {
                                            printf("no se pudo leer el archivo\n");
                                            break;
                                            
                                            
                                        }
                                        
                              }
                              
                              
                              pList->add(pList, auxCliente);
                              
                              
                              
                              
           }
           free(auxCliente);
           return pList;
           
           
           
           
           
           
           
}

void guardarLibrosEnArchivos(FILE* pFile, ArrayList* pList)
{
     int i;
     rewind(pFile);
     
     for(i=0;i<pList->size;i++)
     {
                               fwrite(((libro *)(pList->pElements[i])), sizeof(libro), 1, pFile);
                               
                               
                               
                               
                               
                               
     }
     
     free(pList);
     
     
     
     
     
}
void guardarClientesEnArchivos(FILE* pFile, ArrayList* pList)
{
     int i;
     rewind(pFile);
     
     for(i=0;i<pList->size;i++)
     {
                               fwrite(((cliente *)(pList->pElements[i])), sizeof(cliente), 1, pFile);
                               
                               
                               
                               
                               
                               
     }
     
     free(pList);
     
     
     
}

