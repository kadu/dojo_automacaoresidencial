#define PIR_PIN 3

void setup() {
  Serial.begin(115220);  
  Serial.println("Dojo de automação residencial");
  
  pinMode(PIR_PIN, INPUT);  
}

void loop() {
  int movimento = digitalRead(PIR_PIN);
  if(movimento == HIGH) {
    Serial.println("Detectei movimento");
  } else {
    Serial.println("Sem movimento");
  }
}
