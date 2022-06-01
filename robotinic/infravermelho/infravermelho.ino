
int sensorDireito = 2;
int sensorEsquerdo = 4;

void setup() {
  pinMode(sensorDireito, INPUT);
  pinMode(sensorEsquerdo, INPUT);
  Serial.begin(9600);
}

void loop() {
  int sensor_direito = digitalRead(sensorDireito);
  int sensor_esquerdo = digitalRead(sensorEsquerdo);
 
  Serial.print(" status do sensor direito: ");
  Serial.print(sensor_direito);
  Serial.print(" status do sensor esquerdo: ");
  Serial.println(sensor_esquerdo);
  delay(100);
}
    
                              
