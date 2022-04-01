#include <Ultrasonic.h> //add biblioteca do sensor ultrasom

//Define os pinos para o trigger e echo do sensor ultrasom
#define pino_trigger 4
#define pino_echo 5

//Definicoes pinos Arduino ligados a entrada da Ponte H
int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;

void setup() {
  //sensor infravermelho
  pinMode(13, OUTPUT);
  pinMode(2, INPUT);
  //sensor ultrassonico
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
  //ponte H
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  //sensor infravermelho
  
  int status_botao = digitalRead(2);
  Serial.print("status do sensor: ");
  Serial.println(status_botao);
  if(status_botao == 1){
    digitalWrite(13, 1);  
  }
  else{
    digitalWrite(13, 0);  
  }
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

  //Ponte H

  //Gira o Motor A no sentido horario
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  delay(2000);
  //Para o motor A
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  delay(500);
  //Gira o Motor B no sentido horario
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(2000);
  //Para o motor B
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
  delay(500);
     
  //Gira o Motor A no sentido anti-horario
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  delay(2000);
  //Para o motor A
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  delay(500);
  //Gira o Motor B no sentido anti-horario
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(2000);
  //Para o motor B
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
  delay(500);
}
    
                              
