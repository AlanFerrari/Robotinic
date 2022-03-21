void setup() {
  pinMode(13, OUTPUT);
  pinMode(2, INPUT);
}

void loop() {
  int status_botao = digitalRead(2);
  if(status_botao == 1){
    digitalWrite(13, 1);  
  }
  else{
    digitalWrite(13, 0);  
  }
  delay(100);
}
    
                              
