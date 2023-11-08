const int pinPotenciometro = A0; // El pin analógico donde está conectado el potenciómetro
int valorMapeado=0; // Variable para almacenar el valor mapeado
int PULSADOR_START = 4;
int PULSADOR_STOP = 3;
int valorPulsadorStart = 0;
int valorPulsadorStop = 0 ;
boolean leerPotenciometro = false;
void setup() {
  Serial.begin(9600); // Inicia la comunicación serial a 9600 baudios
  pinMode(PULSADOR_START,INPUT_PULLUP);
  pinMode(PULSADOR_STOP,INPUT_PULLUP);
}

void loop() {
 
  //mapearPotenciometro();
  leerBotonStart();
  leerBotonStop();
  if(leerPotenciometro){
    mapearPotenciometro();
  }
  valorPulsadorStart =  digitalRead(PULSADOR_START);
  valorPulsadorStop = digitalRead(PULSADOR_STOP);
 
  delay(100); // Espera un breve periodo de tiempo antes de volver a leer el potenciómetro
}
void mapearPotenciometro(){
   int valorPotenciometro = analogRead(pinPotenciometro); // Lee el valor del potenciómetro (0-1023)

  // Mapea el valor del potenciómetro al rango de 30 a 90
  valorMapeado = map(valorPotenciometro, 0, 1023, 30, 90);
  Serial.print("Valor del potenciómetro: ");
  Serial.print(valorPotenciometro);
  Serial.print(" - Valor mapeado: ");
  Serial.println(valorMapeado);
}
void leerBotonStart(){
  if(digitalRead(PULSADOR_START)==LOW){
    Serial.println("Se activo boton start");
    leerPotenciometro = true;
  }
}
void leerBotonStop(){
  if(digitalRead(PULSADOR_STOP)==LOW){
    Serial.println("Se activo boton stop");
    leerPotenciometro = false;
  }
}
