#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "funciones.h"
#include "lib2.h"


int main(int argc, char *argv[])
{
    FILE* fLibro;
    FILE* fCliente;
    FILE* fLibro2;
    FILE* fCliente2;
    
    int opcion=1;
    
        if((fLibro2=fopen("libros2.bin", "wb+"))==NULL)
        {
                                         if((fLibro2=fopen("libros2.bin", "rb+"))==NULL)
                                         {
                                                                          printf("ERROR, al abrir el archivo\n");
                                                                          exit(1);
                                                                          
                                                                          
                                         }
                                         
                                         
                                         
                                         
        } 
        if((fCliente2=fopen("cliente2.bin", "wb+"))==NULL)
        {
                                            if((fCliente=fopen("cliente2.bin", "rb+"))==NULL)
                                            {
                                                                               printf("error, al abrir el archivo\n");
                                                                               
                                                                               
                                            }
                                            
        }
        
    
        if((fLibro=fopen("Libros.bin", "rb+"))==NULL)
        {
                    if((fLibro=fopen("Libros.bin","wb+"))==NULL)
                    {
                                                                      printf("No se pudo abrir el archivo\n");
                                                                      exit(1);
                                                                      
                                                                      
                                                                      
                    }
                                             
                                             
                                             
        }
        
        
        if((fCliente=fopen("Clientes.txt", "rb+"))==NULL)
        {
                                                 if((fCliente=fopen("Clientes.txt", "wb+"))==NULL)
                                                 {
                                                                                    printf("No se pudo abrir el archivo\n");
                                                                                           
                                                                                           
                                                                                           
                                                 }
                                                 
                                                 
                                                 
                                                 
        }
    
    while(opcion!=9)
    {
                    opcion=mostrar_y_validar_menu();
                    
                    switch(opcion)
                    {
                                  case 1:
                                       
                                       altaLibro(fLibro);
                                       break;
                                       
                                  case 2:
                                       altaCliente(fCliente);
                                       break;
                                       
                                  case 3:     
                                       bajaLibro(fLibro);
                                       break;
                                   
                                   case 4:
                                        bajaCliente(fCliente);
                                        break;      
                                        
                                   case 5:
                                        mostrar(fCliente,fLibro);
                                        break;
                                        
                                  case 6:
                                       bajaFisica(fCliente, fCliente2,fLibro, fLibro2);
                                       break;
                                       
                                  case 7:
                                       cargar_libro_en_array(fLibro);
                                       break;
                                       
                                       
                                  case 8:
                                       alquilar(fLibro, fCliente);
                                       break;
                                       
                                  case 9:
                                       consultar_alquiler(fLibro, fCliente);
                                       break;
                                  
                                  
                    }
                    
                    
                    
                    
    }
  
  
  
  system("PAUSE");	
  return 0;
}
