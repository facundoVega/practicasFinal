#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "funciones.h"
#include <string.h>
#include "lib2.h"

void altaLibro(FILE* pFile)
{
     
     
     libro auxLib;
     
     auxLib.isbn=pedir_entero("isbn del libro");
     pedir_y_validar_cadena("titulo",auxLib.titulo,20);
     auxLib.activo=1;
     auxLib.cantidadStock=10;
     
     fseek(pFile,0L,SEEK_END);
     
     fwrite(&auxLib,sizeof(auxLib),1,pFile);
     
     
     
     
}


void altaCliente(FILE* pFile)
{
     cliente auxCliente;
     
     auxCliente.idCliente=pedir_entero("codigo de cliente");
     pedir_y_validar_cadena("nombre del cliente",auxCliente.nombre,20);
     auxCliente.activo=1;
     
     fseek(pFile,0L, SEEK_END);
     
     fwrite(&auxCliente,sizeof(auxCliente),1,pFile);
     
     
     
}



void bajaLibro(FILE* pFile)
{
     int codigo;
     int cant;
     libro auxLib;
     
     codigo=pedir_entero("ingrese codigo del libro a dar de baja");
     
     rewind(pFile);
     
     while(!feof(pFile))
     {
              cant=fread(&auxLib,sizeof(auxLib),1,pFile);
              
              if(cant<1)
              {
                        if(feof(pFile))
                        {
                                       break;
                                       
                                       
                                       
                        }
                        else
                        {
                            printf("No se pudo leer el archivo\n");
                            break;
                            
                            
                        }
                        
                        
                        
              }
              
              if(auxLib.isbn==codigo)
              {
                                     auxLib.activo=-1;
                                     
                                     
                                     
              }          
                        
              fseek(pFile,(long)(-1)*sizeof(auxLib), SEEK_CUR);
              fwrite(&auxLib,sizeof(auxLib), 1,pFile);
              break;
                        
                        
                        
     }
     
     
     
}

void bajaCliente(FILE* pFile)
{
     int codigo;
     cliente auxCliente;
     int cant;
     
     codigo=pedir_entero("ingrese codigo del cliente a dar de baja");
     
     rewind(pFile);
     
     while(!feof(pFile))
     {
                        cant=fwrite(&auxCliente,sizeof(auxCliente),1,pFile);
                        
                        
                        if(cant<1)
                        {
                                  if(feof(pFile))
                                  {
                                                 break;
                                                 
                                                 
                                                 
                                  }
                                  else
                                  {
                                      printf("No se pudo leer el archivo\n");
                                      break;
                                      
                                      
                                      
                                  }
                                  
                                  
                                  
                        }
                        
                        if(auxCliente.idCliente==codigo)
                        {
                                                        auxCliente.activo=-1;
                                                        
                                                        
                                                        
                        }
                        
                        fseek(pFile,(long)(-1)*sizeof(cliente),SEEK_CUR);
                        fwrite(&auxCliente,sizeof(cliente), 1,pFile);
                        break;
                        
                        
                        
                        
                        
     }
     
     
     
     
}



     
      
 



void mostrar_segun_tipo(FILE * pFile,int type)
{
     if(type==LIBROS)
     {
                     libro auxLib;
                     int cant;
                     
                     
                     rewind(pFile);
                     
                     
                     while(!feof(pFile))
                     {
                                        cant=fread(&auxLib,sizeof(libro), 1,pFile);
                                        
                                        if(cant<1)
                                        {
                                                  if(feof(pFile))
                                                  {
                                                                 break;
                                                                 
                                                                 
                                                  }
                                                  else
                                                  {
                                                      printf("error\n");
                                                      break;
                                                  }
                                                  
                                                  
                                        }
                                        
                                        printf("%s\n", auxLib.titulo);
                                        
                     }
                     system("PAUSE");
                     system("cls");
                     
                     
     }
     if(type==CLIENTES)
     {
                     cliente auxCliente;
                     int cantidad;
                     
                     rewind(pFile);
                     
                     while(!feof(pFile))
                     {
                                        cantidad=fread(&auxCliente,sizeof(cliente),1,pFile);
                                        
                                        if(cantidad<1)
                                        {
                                                      if(feof(pFile))
                                                      {
                                                                     break;
                                                                     
                                                                     
                                                      }
                                                      else
                                                      {
                                                          printf("error\n");
                                                          break;
                                                          
                                                      }
                                                      
                                                      
                                                      
                                                      
                                        }
                                        
                                        printf("%s\n", auxCliente.nombre);
                                        
                                        
                     }
                      
                      
                      
     }
     
     system("PAUSE");
     system("cls");
     
     
     
     
     
}


void mostrar(FILE* fCliente ,FILE* fLibros)
{
     int opcion;
     
     opcion=pedir_entero("que desea ver \n1_libros 2_clientes");
     if(opcion==2)
     {
                  mostrar_segun_tipo(fCliente,CLIENTES);
                  
                  
                  
     }
     else
     {
         mostrar_segun_tipo(fLibros,LIBROS);
         
     }
     
     
     
}



void bajaFisica(FILE* fCliente, FILE* fCliente2 ,FILE* fLibro, FILE* fLibro2 )
{
     int opcion;
     
     opcion=pedir_entero("que desea dar de baja \n1 libro 2cliente");
     
     if(opcion==CLIENTES)
     {
                         Bajaf_cliente(fCliente,fCliente2);
                        
                        
     }
     if(opcion==LIBROS)
     {
                      
                   bajaf_libro(fLibro, fLibro2);    
                      
     }
     
     
     
}


void cargar_libro_en_array(FILE* fLibro)
{
     int cantidad;
     libro* auxLibro;
     ArrayList* bookList;
     int i=0;
     
     
     bookList=newArrayList();
     
     rewind(fLibro);
     
     while(!feof(fLibro))
     {
                         auxLibro=(libro *)malloc(sizeof(libro));
                         
                         cantidad=fread(auxLibro,sizeof(libro),1,fLibro);
                         
                                        if(cantidad<1)
                                        {
                                                      if(feof(fLibro))
                                                      {
                                                                     break;
                                                                     
                                                                     
                                                      }
                                                      else
                                                      {
                                                          printf("ERROR\n");
                                                          break;
                                                          
                                                      }
                                        }
                                        
                         bookList->add(bookList,auxLibro);
                         
                         
                         
     }
     
     for(i=0;i<bookList->size;i++)
     {
                     printf("%s\t%d\n", (((libro *)(bookList->pElements[i]))->titulo), (((libro *)(bookList->pElements[i]))->isbn));
     
     }
     getch();
     
     free(bookList);
     free(auxLibro);
     
}


void alquilar(FILE* fLibro, FILE* fCliente)
{
     int codLibro;
     int codCliente;
     ArrayList* libros;
     ArrayList* clientes;
     int i,j;
     int posLibro,posCliente;
     
     libros=cargarLibrosEnArray(fLibro);
     clientes=cargarClientesEnArray(fCliente);
     
     codLibro=pedir_entero("ingrese codigo del libro a alquilar");
     codCliente=pedir_entero("ingrese codigo del cliente que va a realizar el alquiler");
     
     
     for(i=0;i<libros->size;i++)
     {
                  if(((libro *)(libros->pElements[i]))->isbn==codLibro)              
                                
                                posLibro=i;
     }
     
     
     for(j=0;j<clientes->size;j++)
     {
                                  if((((cliente *)(clientes->pElements[j]))->idCliente)==codCliente)
                                  
                                               posCliente=j;
                                  
                                  
                                  
     }
     
     
     (((libro *)(libros->pElements[posLibro]))->fkCliente)=(((cliente *)(clientes->pElements))->idCliente);
     (((cliente *)(clientes->pElements[posCliente]))->fkIsbn)=(((libro *)(libros->pElements[posLibro]))->isbn);
     
     
     guardarLibrosEnArchivos(fLibro, libros);
     guardarClientesEnArchivos(fCliente, clientes);
     
     
}


void consultar_alquiler(FILE* fLibro,FILE* fCliente)
{
     
     ArrayList* libros;
     ArrayList* clientes;
     int codLibro;
     int j,i;
     int codCliente;
     int posLibro;
     int posCliente;
     
     libros=cargarLibrosEnArray(fLibro);
     clientes=cargarClientesEnArray(fCliente);
     
     codLibro=pedir_entero("ingrese el codigo del libro que quiere saber por quien fue alquilado");
     
     
     for(i=0;i<libros->size;i++)
     {
                  if((((libro *)(libros->pElements[i]))->isbn)==codLibro)              
                  {          
                                posLibro=i;
                                break;             
                                
                  }
     }
     codCliente=(((libro *)(libros->pElements[posLibro]))->fkCliente);
     
     
     for(j=0;j<clientes->size;j++)
     {
                                  if((((cliente *)(clientes->pElements[j]))->idCliente)==codCliente)
                                  {
                                               posCliente=j;
                                               break;
                                  }
                                  
     }
     printf("antes de mostrar\n");
     
     printf("el que alquilo el libro fue: %s\n", ((cliente *)(clientes->pElements[posCliente]))->nombre);
     
     guardarLibrosEnArchivos(fLibro, libros);
     guardarClientesEnArchivos(fCliente, clientes);
     
     
}
