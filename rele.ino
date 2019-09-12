#define RELE1_PIN 5
#define RELE2_PIN 6

void setup() {
  Serial.begin(115220);  
  Serial.println("Dojo de automação residencial");
  
  pinMode(RELE1_PIN, OUTPUT);  
  pinMode(RELE2_PIN, OUTPUT);
}

void loop() {
  digitalWrite(RELE1_PIN, HIGH);
  digitalWrite(RELE2_PIN, LOW);
  delay(2000);
  digitalWrite(RELE1_PIN, LOW);
  digitalWrite(RELE2_PIN, HIGH);
  delay(2000);
}
