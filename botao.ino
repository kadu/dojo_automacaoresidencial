#include <Button.h>

#define BUTTON_PIN 4

Button button1(BUTTON_PIN);

void setup() {
  Serial.begin(115220);  
  Serial.println("Dojo de automação residencial");
  
  pinMode(BUTTON_PIN, INPUT_PULLUP);  
  button1.begin();
}

void loop() {
  if (button1.pressed())
    Serial.println("Button 1 pressed");
//  if (button1.released())
//    Serial.println("Button 1 released");
//
//  if (button1.toggled()) {
//    if (button1.read() == Button::PRESSED)
//      Serial.println("Button 1 has been pressed");
//    else
//      Serial.println("Button 1 has been released");
//  }  
}
