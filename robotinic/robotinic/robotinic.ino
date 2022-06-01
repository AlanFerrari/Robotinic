#include <Ultrasonic.h> //add biblioteca do sensor ultrasom

//Definição dos pino infravermelho
int sensorDireito = 2;
int sensorEsquerdo = 3;

//Define os pinos para o trigger e echo do sensor ultrasom
#define pino_trigger 4
#define pino_echo 5

//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);

//Definicoes pinos Arduino ligados a entrada da Ponte H
int IN1 = 6;
int IN2 = 7;
int IN3 = 8;
int IN4 = 9;
                      
void setup() {
  //sensor infravermelho
  pinMode(sensorDireito, INPUT);
  pinMode(sensorEsquerdo, INPUT);
  Serial.begin(9600);
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

  //lógica do robo
  while(cmMsec <= 10){
    if(cmMsec <= 10){
    andar_frente();
    }
    else{
      gira_MA_horario;
      delay(2000)
      para_MA();
    }
  }
  
}

void andar_frente(){
  //anda para frente ou tras?
  gira_MA_horario();
  gira_MB_antiHorario();
}

void andra_tras(){
  //anda para frente ou tras?
  gira_MA_antiHorario();
  gira_MB_horario();
}

void gira_MA_horario(){
  //Gira o Motor A no sentido horario
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
}

void para_MA(){
  //Para o motor A
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
}

void gira_MB_horario(){
  //Gira o Motor B no sentido horario
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void para_MB(){
  //Para o motor B
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
}
 
void gira_MA_antiHorario(){
  //Gira o Motor A no sentido anti-horario
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
}

void gira_MB_antiHorario(){
  //Gira o Motor B no sentido anti-horario
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}
                              
