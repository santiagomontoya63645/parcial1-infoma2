#include <iostream>

using namespace std;
void verificacion(char palabra[6]);
void comparacion(char palabra[]);
int main()
{
    int b=0,c=0;
    char palabra[6]={};


    verificacion(palabra) ;
    comparacion(palabra);

    return 0;
}
void verificacion(char palabra[6]){
    int verif=0;
    while(true){
    cout<<"ingrese palabra"<<endl;
    cin>>palabra;

    cout<<"usted ingreso: ";
    cout<<endl;
    cout<<palabra<<endl;

    cout<<"ingrese 0 si desea imprimir eso sino ingrese 1"<<endl;cin>>verif;
    if (verif==0){
        break;
    }
    }
    cout<<endl;
}
void comparacion(char palabra[]){
    char Letras[36]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9'};
    int cantidad=0;
    char *p=palabra;
    while (*(p++)!='\0')cantidad++;
    for (int j=0;j<cantidad;j++){
        for (int i=0;i<cantidad;i++){
            if(palabra[j]==Letras[i]){
                //accion de imprimir en leds
            }
        }

    }
}
