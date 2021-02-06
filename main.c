/* M03. Programació bàsica */
/* Tasques:
❏ Validar que el programa funciona correctament (valida correctament les dades, no hi ha
errors de tipus, ...).
❏ Modificar el codi per tal que segueixi el disseny modular (vista l’estructura a classe).
❏ Implementar la funcionalitat, amb les funcions necessàries, per tal que afegeixi els
registres al fitxer .txt. Recorda:
❏ Afegir una capçalera al fitxer
❏ Comprovar si aquest ja existeix (crear/sobreescriure/afegir)*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "header.h"
#include "header.c"
void main(){
  
    char of[50];
    int len;
    bool valid=true;
    
    do
    {
        if (valid==false){
            printf("El fichero tiene en el formato '.txt'.\n");
        }
        printf("Introduce el nombre del fichero o la ruta del fichero:\n");
        gets(of);
        len=strlen(of);
        if (of[len-4]=='.' && of[len-3]=='t' && of[len-2]=='x' && of[len-1]=='t' ){
            valid=true;
        }
        else{
            valid=false;
        }
    } while (valid==false);
    
    open(of);
    
}