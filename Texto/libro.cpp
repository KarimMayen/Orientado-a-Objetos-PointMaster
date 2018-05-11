#include<iostream>
#include<cstdio>
#include<stdio.h>
using namespace std;


///PROTITYPES///
void text_control();

/*



*/

int main(){
    text_control();
    return 0;
}


void text_control(){
    FILE *ptr; ///puntero de tipo FILE es un punetero a una estructura de tipo FILE, aounta a varias cosas que define a un archivo
               ///como su NOMBRE, ESTADO, y LA ACUTAL POSICIÓN EN EL ARCHIVO.

    ///PROTOTIPO PARA ABRIR UN ARCHIVO
    ///FILE *open(const char *filename,const char *mode);

    if((ptr=fopen("prueba.txt","r"))==NULL){
        cout<<"No se puedo abrir el archivo o no hay base de datos aun"<<endl;
        ///poner codigo aquí para cuando no hay base de dato
        return ;
        }

    char text[80];
    string textf;
    //ptr_text=text;

    while(!feof(ptr)){
        fgets(text,79,ptr);
        textf=text;
        cout<<textf;
    }


    if( ( fclose(ptr))!=0)
        cout<<" Error cerrando Archivo"<<endl;
}
