int pinData  = 2;
int pinLatch = 3;
int pinClock = 4;
#define TIEMPO 200

void ledWrite(int aLed,int bLed,int cled,int dled,int eled,int fled,int gled,int hled){
  
   shiftOut(pinData, pinClock, LSBFIRST, aLed);
   shiftOut(pinData, pinClock, LSBFIRST, bLed);
   shiftOut(pinData, pinClock, LSBFIRST, cled);
   shiftOut(pinData, pinClock, LSBFIRST, dled);
   shiftOut(pinData, pinClock, LSBFIRST, eled);
   shiftOut(pinData, pinClock, LSBFIRST, fled);
   shiftOut(pinData, pinClock, LSBFIRST, gled);
   shiftOut(pinData, pinClock, LSBFIRST, hled);
   digitalWrite(pinLatch, HIGH);
   digitalWrite(pinLatch, LOW);
}

void setup(){
   pinMode(pinData, OUTPUT);
   pinMode(pinLatch, OUTPUT);
   pinMode(pinClock, OUTPUT);
   Serial.begin(9600);
}

void loop(){
  char palabra[9]={};
  char palabra2[9]={};
  
  //ledWrite(255,255,255,255,255,255,255,255);
  //cadena_a_enteros(palabra);
  
  
 /* verificacion2(palabra);delay(800);
  verificacion2(palabra2);delay(800);
  verificacion2(palabra3);delay(800);
  verificacion2(palabra4);delay(800);
  verificacion2(palabra5);delay(800);
  verificacion2(palabra6);delay(800);
  verificacion2(palabra7);delay(800);
  verificacion2(palabra8);delay(800);
  int j=atoi(palabra);
  int m=atoi(palabra2),z=atoi(palabra3),x=atoi(palabra4);
  int c=atoi(palabra5),v=atoi(palabra6),b=atoi(palabra7),n=atoi(palabra8);
  
  delay(800);
  Serial.println("posicion de mierda");*/
  
 // Serial.println(mierda[]);

  int pospatron=0;
  int lmao=0;
  int iterador=0;
  int contador=0;
  Serial.println("ingrese patrones;");
  verificacion2(palabra2);
  lmao=atoi(palabra2);
  int auxlmao=lmao;
  lmao=8*lmao-1;
  char patron[lmao+1]={}; 
    for (int j=0;j<=lmao;j++){
        char palabra2[9]={};
        Serial.println("ingrese valor en fila");
  	    verificacion2(palabra2);delay(800);
        iterador=atoi(palabra2);
        patron[j]=iterador;
    }
  delay(2000);
  for(int k=0;k<auxlmao;k++){
    ledWrite(patron[contador],patron[contador+1],patron[contador+2],patron[contador+3],patron[contador+4],patron[contador+5],patron[contador+6],patron[contador+7]);
  	contador=contador+8;
    Serial.println(patron[contador-1]);
    delay(2000);
  }
    //}
  
  
  
}
void verificacion2(char palabra[8]){
  int verif=0,posicion=0;
  //Serial.flush();
  while (true){
    
    if (Serial.available()){
    posicion=0;
    while(Serial.available()>0) 
    {
      delay(50);
      palabra[posicion]=Serial.read();
      posicion++;
      
      
    }
      Serial.print("Ingresado: ");
  	  Serial.println(palabra);
      //delay(500);
      break;
      
   }
  
    
  }
}
int cadena_a_enteros(char CaracteresNum[])
{
    long unsigned int valor=0,suma=0,contador=0,paso=0, aux;
    while(CaracteresNum[contador]!='\0')  //Pa saber el tamaño de CaracteresNum
        contador+=1;
    for(int n=0;n<contador ;n++)
    {
        valor=CaracteresNum[n]-48;    //esto es -48 por que si ejemplo es el 9  en la tabla ascii es 57 y se le resta 48 y queda 9
        aux=potencia(10,(contador-1)-paso);  //Aqui hay que restarle paso por que si primero es centena ya despues seria decenas y asi
        valor=valor*aux;
        suma+=valor;
        paso+=1;

    }
    return suma;
}


int potencia(int valor,int potencia)   // esta funcion calcula la potencia
{
    int producto=1;
    for(int n=0;n<potencia;n+=1)
        producto*=valor;
    return producto;
}
