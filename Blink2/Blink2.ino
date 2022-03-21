void setup() {
  pinMode(13, OUTPUT);
  pinMode(2, INPUT);
  Serial.begin(9600);
}

void loop() {
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
}
    
                              
