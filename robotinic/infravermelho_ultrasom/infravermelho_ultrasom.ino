#include <Ultrasonic.h>

#include <Ultrasonic.h> //add biblioteca do sensor ultrasom

//Define os pinos para o trigger e echo do sensor ultrasom
#define pino_trigger 4
#define pino_echo 5

//sensor infravermelho
int sensorDireito = 2;
int sensorEsquerdo = 3;


//Inicializa o sensor nos pinos definidos acima do ultrasom
Ultrasonic ultrasonic(pino_trigger, pino_echo);
                      
void setup() {
  //sensor infravermelho
  pinMode(sensorDireito, INPUT);
  pinMode(sensorEsquerdo, INPUT);
  Serial.begin(9600);
  //sensor ultrassonico
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
  
}

void loop() {
  //sensor infravermelho
  
  int sensor_direito = digitalRead(sensorDireito);
  int sensor_esquerdo = digitalRead(sensorEsquerdo);
 
  Serial.print(" status do sensor direito: ");
  Serial.print(sensor_direito);
  Serial.print(" status do sensor esquerdo: ");
  Serial.println(sensor_esquerdo);
  delay(100);

  //sensor ultrassonico
  
  float cmMsec, inMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
  //Exibe informacoes no serial monitor
  Serial.print("Distancia em cm: ");
  Serial.print(cmMsec);
  Serial.print(" - Distancia em polegadas: ");
  Serial.println(inMsec);
  delay(1000);

}
    
                              
