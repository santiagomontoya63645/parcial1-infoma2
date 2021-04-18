/*
SER ---> Entrada serial
RLCK ---> Reloj de registro de salida
SRCLK ---> Reloj de registro de desplazamiento
*/
const int SRCLK_1 = 5;
const int RLCK_1 = 6;
const int SER_1 = 7;

const int SRCLK_2 = 2;
const int RLCK_2 = 3;
const int SER_2 = 4;

char ingresado[30];
int posicion=0;

void verificacion()
{
  for(int i=0;i<8;i++){
    digitalWrite(7,1);

  	digitalWrite(5,0);
  	digitalWrite(5,1);
  	digitalWrite(5,0);
  
  	digitalWrite(6,0);
  	digitalWrite(6,1);
  	digitalWrite(6,0);
  }
}

void setup()
{
  // Configuración de los puertos seriales
  for(int i=2;i<=7;i++){
    pinMode(i,OUTPUT);
    digitalWrite(i,0);
  }
  Serial.begin(9600);
  Serial.println("Escriba 'test' si desea realizar la verificacion de los LED");
}

void loop()
{
  if (Serial.available()){
    while(Serial.available()>0) 
    {
      delay(5);
      ingresado[posicion]=Serial.read();
      posicion++;
    }
    Serial.print("Ingresado: ");
  	Serial.println(ingresado);
    if(ingresado[0]==116 && ingresado[1]==101 && ingresado[2]==115 && ingresado[3]==116){
      verificacion();
    }
  }
}