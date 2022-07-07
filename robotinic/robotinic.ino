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

int x = 0;

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
  
  float cmMsec;
  long microsec = ultrasonic.timing();
  float distancia = ultrasonic.convert(microsec, Ultrasonic::CM);
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  //Exibe informacoes no serial monitor
  Serial.print("Distancia em cm: ");
  Serial.println(cmMsec);
  delay(1000);

  //lógica do robo
  
  //Verifica se tem alguma coisa na sua frente e se os sensor estão na parte branca da pista
  if (distancia > 20 && sensor_direito == 0 && sensor_esquerdo == 0) {
    Serial.println("procurando oponente");
    //Procura em forma de quadrado
    procura();  
    x = 0;
    //Se encontrar a borda e não o oponente
    if (sensor_direito == 1 && sensor_esquerdo == 0) {
      parar();
      delay(500);
      Serial.println("Sensor Direito achou a borda");
      Serial.println("Parei o motor");
      andar_tras();
      delay(500);
    }  
    else if (sensor_direito == 0 && sensor_esquerdo == 1) {
      parar();
      delay(500);
      Serial.println("Sensor Esquerdo achou borda");
      Serial.println("Parei o motor");
      andar_tras();
      delay(500);
    }
    else if (sensor_direito == 1 && sensor_esquerdo == 1) {
      parar();
      delay(500);
      Serial.println("Sensor Esquerdo e o Direito acharam a borda");
      Serial.println("Parei o motor");
      andar_tras();
      delay(500);
    }
  }

  //Se encontrar algo na sua frente
  if (distancia < 20 && distancia > 0 && sensor_direito == 0 && sensor_esquerdo == 0) {
    //Permenace na mesma condição até o sensor encotrar a borda da arena
    while (x != 1) {
      Serial.println("achei o oponente");
      andar_frente();//Movimenta para frente
      if (distancia > 20){
        x = 1;
      }
    }
    if (sensor_direito == 1 && sensor_esquerdo == 0) {
      parar();
      delay(500);
      Serial.println("Sensor Direito achou a borda");
      Serial.println("Parei o motor");
      andar_tras();
      delay(500);
    }  
    else if (sensor_direito == 0 && sensor_esquerdo == 1) {
      parar();
      delay(500);
      Serial.println("Sensor Esquerdo achou borda");
      Serial.println("Parei o motor");
      andar_tras();
      delay(500);
    }
    else if (sensor_direito == 1 && sensor_esquerdo == 1) {
      parar();
      delay(500);
      Serial.println("Sensor Esquerdo e o Direito acharam a borda");
      Serial.println("Parei o motor");
      andar_tras();
      delay(500);
    }
  }

 
}

void parar(){
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
}

void procura() {
  andar_frente();
  delay(500);
  gira_MA_horario();
  delay(300);
  parar();
  delay(100);

}

void andar_tras(){
  //anda para tras
  gira_MA_horario();
  gira_MB_antiHorario();
}

void andar_frente(){
  //anda para frente
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
                              
