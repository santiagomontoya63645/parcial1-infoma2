/*
pinData ---> Entrada serial
pinLatch ---> Reloj de registro de salida
pinClock ---> Reloj de registro de desplazamiento
*/

int pinData  = 2;
int pinLatch = 3;
int pinClock = 4;

int patrones;
float tiempo;
int *ptrp=&patrones;
float *ptrt=&tiempo;

//Fucnion verificacion, empleada para iluminar todos los LED.
void verificacion(){
   shiftOut(pinData, pinClock, LSBFIRST, 255);
   shiftOut(pinData, pinClock, LSBFIRST, 255);
   shiftOut(pinData, pinClock, LSBFIRST, 255);
   shiftOut(pinData, pinClock, LSBFIRST, 255);
   shiftOut(pinData, pinClock, LSBFIRST, 255);
   shiftOut(pinData, pinClock, LSBFIRST, 255);
   shiftOut(pinData, pinClock, LSBFIRST, 255);
   shiftOut(pinData, pinClock, LSBFIRST, 255);
   digitalWrite(pinLatch, HIGH);
   digitalWrite(pinLatch, LOW);
}

//Función imagen, tiene como parámetro de entrada un valor entero de cada fila de LED, ese valor entero
//corresponde al valor decimal de un patrón binario.

void imagen(int aled,int bled,int cled,int dled,int eled,int fled,int gled,int hled){
  
   shiftOut(pinData, pinClock, LSBFIRST, hled);
   shiftOut(pinData, pinClock, LSBFIRST, gled);
   shiftOut(pinData, pinClock, LSBFIRST, fled);
   shiftOut(pinData, pinClock, LSBFIRST, eled);
   shiftOut(pinData, pinClock, LSBFIRST, dled);
   shiftOut(pinData, pinClock, LSBFIRST, cled);
   shiftOut(pinData, pinClock, LSBFIRST, bled);
   shiftOut(pinData, pinClock, LSBFIRST, aled);
   digitalWrite(pinLatch, HIGH);
   digitalWrite(pinLatch, LOW);
}

//Función ingreso, es la empleada para recibir datos por el puerto serial.
void ingreso(char ing[8]){
  int verif=0,posicion=0;
  Serial.println("Ingrese el dato: ");
  while (true){
    if (Serial.available()){
    	posicion=0;
    	while(Serial.available()>0) 
    	{
     	 delay(50);
 	     ing[posicion]=Serial.read();
     	 posicion++; 
    	}
      	Serial.print("Ingresado: ");
  	  	Serial.println(ing);
      	//Condición que comprueba si un dato ingresado es la palabra 'test', y así hacer la verificación
      	if(ing[0]==116 && ing[1]==101 && ing[2]==115 && ing[3]==116){
      		verificacion();
      		//Se limpia el contenido del arreglo para seguir recibiendo el dato esperado.
      		for(int i=0;i<=posicion;i++){
      		  ing[i]=NULL;
      		}
    	}
    	else{
    	    break;
 	    }
    }
  }
}

//Función que permite convertir un arreglo que contiene un número binario a un entero decimal.
int BinToInt (char ing[8]){
  
  int i = 0;  //Variable para el contador
  int n = 0;  //Variable para calcular el resultado

  while ( ing[i] == '0' || ing[i] == '1' ) {
    if ( ing[i] == '0' )
      n <<= 1;
    else {
      n ^= 1;
      n <<= 1;
    }
  ++i;
  } 
  n >>= 1;
  
  //Serial.print("Prueba: ");
  //Serial.println(n);

  return(n);

}

//Función empleada para pedir e imprimir patrones.
void publik(int patrones, float tiempo){
  int cantidad=0;
  char patron[9]={};
  int patronA;
  cantidad=(patrones*8)-1;
  int array[cantidad+1];
  
  int aux=0;
  int tiempoaux=int (tiempo*1000.0);
  
  for(int i=0;i<patrones*8;i++){
    ingreso(patron);
  	//Serial.print("PATRON: ");
  	//Serial.println(patron);
    patronA=BinToInt(patron);
 	//Serial.println(patronA);
    array[aux]=patronA;
    aux=aux+1;
    if((i+1)%8==0){Serial.println("Ya ingresaste un patron.");}
  }
  while(true){ //Ciclo infinito que indica que los patrones ingresados por el usuario se presentarán hasta detener la simulación.
  for(int k=0;k<(patrones*8)-1;k=k+8){
    imagen(array[k],array[k+1],array[k+2],array[k+3],array[k+4],array[k+5],array[k+6],array[k+7]);
    delay(tiempoaux);
  }
  if(patrones==1){break;} //Si el usuario solo ingresó un patrón, el programa permitirá que siga ingresando patrones.
  }
}

void setup(){
   pinMode(pinData, OUTPUT);
   pinMode(pinLatch, OUTPUT);
   pinMode(pinClock, OUTPUT);
   
   digitalWrite(pinData, 0);
   digitalWrite(pinLatch, 0);
   digitalWrite(pinClock, 0);
  
   Serial.begin(9600);
   Serial.println("-El primer dato solicitado es el numero de patrones.");
   Serial.println("-Si la cantidad de patrones que ingreso es 1, puede seguir ingresando patrones una vez que se presente este, sin embargo, si presenta una ");
   Serial.println("secuencia, el codigo se seguira ejecutando con esta. "); 
   Serial.println("-Despues de brindar el numero de patrones, ingrese el tiempo entre patrones en segundos. ");
   Serial.println("-Acto seguido, se pide que ingrese 8 patrones diferentes, 1 por fila. los unos representan un LED encendido y los ceros un LED apagado. ");
   Serial.println("-Por ejemplo; si desea que el led de la columna 2 se ilumine y los demas esten apagados, ingrese: 01000000 ");
   Serial.println("-Si desea hacer la verificacion en cualquier momento, ingrese la palabra 'test' y luego ingrese el dato solicitado.");
}

void loop(){
  char *aux=new char[5];
  
  Serial.println("Ingrese cantidad de patrones: ");
  ingreso(aux);
  *ptrp=atoi(aux);
  Serial.print("Cantidad de patrones: ");
  Serial.println(patrones);
  
  delete [] aux;
  
  Serial.println("Ingrese tiempo entre patrones: ");
  ingreso(aux);
  *ptrt=atof(aux);
  Serial.print("Tiempo entre patrones :");
  Serial.println(tiempo);

  delete [] aux;
  
  Serial.println("A continuacion, ingrese sus patrones." );
  publik(patrones,tiempo);
  
  Serial.println("El patron ya ha sido mostrado, si desea volver a ingresar datos, empiece nuevamente por el # de patrones.");
}
