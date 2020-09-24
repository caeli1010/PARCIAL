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

using namespace rlutil;
using namespace std;

 float Promedio(){
     FILE *p;
     Rutina reg;
     int contador = 0, acumulador = 0;
     float promedio=0;

      p= fopen("Archivos/Entrenamientos.dat", "rb") ;
      if( p ==NULL) {
        cout << "El archivo no se pudo abrir";
        return - 1;
      }
   while( fread(&reg, sizeof(Rutina), 1, p) == 1){
          acumulador += reg.tiempo;
          contador ++;
 }
 fclose(p) ;
 promedio = ((float)acumulador / contador);

 return promedio;
 }


 void PuntoA (){
     Rutina *vsuperior;
     int  tamanio;
     float prom;
     FILE *p;

     prom = Promedio();
    tamanio =contarRutinas();
    vsuperior =(Rutina *) malloc(tamanio*sizeof(Rutina)) ;


   p = fopen("Archivos/Entrenamientos.dat", "rb") ;
   if( p == NULL)  {
    cout << "No se pudo abrir el archivo"  ;
    return;
   }

   fread(vsuperior, sizeof(Rutina), tamanio, p) ;
   fclose(p);

   for (int  i = 0; i < tamanio; i++){
      if(vsuperior[i].tiempo > prom){
        mostrarRutina(vsuperior[i]);
      }
   }
   free(vsuperior);
   anykey();
 }


 void MostrarB(){
       FILE *p;
       Usuario regUsuario;
       int IdUsuario, anio, cantidad;

       cout << "Ingrese ID : ";
       cin>> IdUsuario;
        cout << "Anio : " ;
        cin>> anio;
        cantidad = cantRutinasUsuario(IdUsuario, anio);

            regUsuario = leerUsuario(buscarID(IdUsuario));
            cout << regUsuario.nombres<<  "  "  << regUsuario.apellidos << endl;
            cout <<"La cantidad : "<< cantidad << endl;
           anykey() ;
 }
