/**A partir de un IDUsuario que se ingresa por teclado, listar el entrenamiento de mayor cantidad de calorías y la fecha en que las registró.
 Si hay dos registro con misma cantidad, mostrar el primero de ellos.
**/
#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <ctime>
#include <string.h>
#include <cstring>
#include <cctype>
#include <algorithm>
#include "rutinas.h"
#include "usuarios.h"
#include "menus.h"
#include "fechas.h"
#include "ui.h"
#include "rlutil.h"
#include "reportes.h"
#include  "Modeloparcial.h"
#include "parcial.h".
using namespace rlutil;
using namespace std;


 void MayorCalorias(){
      FILE *p;
       Rutina *vecreg;
       int IdUsuario, cantidad, mayor , anio, pos;
       float calorias, aux=0 ;


       cout << "Ingrese ID : ";
       cin>> IdUsuario;

            pos = buscarIDRutina(buscarID(IdUsuario));

      cantidad = cantRutinasUsuario(IdUsuario, anio) ;
      vecreg = (Rutina*) malloc (cantidad*sizeof (Rutina));

            p = fopen ("Archivos/Entrenamientos.dat", "rb") ;
             if(p==NULL)
         {
        cout << "Error al abrir el archivo \n";
        return;
            }
            fseek (p,pos*sizeof(Rutina),SEEK_SET);
            fread (vecreg, sizeof (Rutina), 1,p);
            fclose(p) ;

               for (int i=0; i <cantidad; i++) {
                mayor=vecreg[i].calorias ;
                for (int j=1; i<cantidad; i++){
                      if (mayor<vecreg[j].calorias){
                         aux=vecreg[j].calorias ;
                         mayor=aux;
                      }
                }

               }
                calorias= mayor;
              cout<<"Mayor calorias :  "<<calorias;
 }


 /*Por cada usuario, listar los Apellidos y nombres y los códigos de las actividades que no realizó*/.

 void Puntob(){
    FILE *p;
    Usuario *vecUsuario;
     int cantidad =  contarRegistro();

     vecUsuario =(Usuario*) malloc (cantidad*sizeof (Usuario));

      p = fopen ("archivos/Usuarios.dat", "rb") ;
             if(p==NULL)
         {
        cout << "Error al abrir el archivo \n";
        return;
            }

          while (fread (vecUsuario, sizeof (Usuario), 1,p) == 1) {
            cout <<vecUsuario.nombres<<" "<<vecUsuario.apellidos<<endl;

          }

 }
