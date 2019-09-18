#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Button.h>
#include <SimpleTimer.h>

#define DHTPIN  2
#define DHTTYPE DHT22

DHT_Unified dht(DHTPIN, DHTTYPE);
SimpleTimer timer;
Button interruptor(4);
Button movimento(3);


int guarda20   = 0;
int RELAYPIN_1 = 4; // luz
int RELAYPIN_2 = 5; // ventilador

void conta20() {
  static int k=0;
  ++k;
  if(k > 18) {
    digitalWrite(RELAYPIN_1, LOW); // desliga na 19 vez que for chamado
    timer.disable(guarda20);
  }
}

float getTemperature() {
  sensors_event_t event;
  dht.temperature().getEvent(&event);

  if (!isnan(event.temperature)) {
    return event.temperature;
  }
  return -99.1;
}

float getHumidity() {
  sensors_event_t event;
  dht.humidity().getEvent(&event);
  if (!isnan(event.relative_humidity)) {  
    return event.relative_humidity;
  }
  return -99.1;
}

void setup() {  
  dht.begin();
  interruptor.begin();
  movimento.begin();
  pinMode(RELAYPIN_1, OUTPUT);
  pinMode(RELAYPIN_2, OUTPUT);

  guarda20 = timer.setTimer(1000, conta20, 20);
  timer.disable(guarda20);
  
  Serial.begin(115200);

  Serial.println("Testes...");

  Serial.println("Testando detector de movimento");
  while(true) {
    if (movimento.pressed()) {
      Serial.println("Movimento detectado");
      break;
    }
  }

  Serial.print("Temperatura : "); Serial.println(getTemperature());
  Serial.print("Umidade ....: "); Serial.println(getHumidity());

  Serial.println("Testando botao, pressione o botao"); 
  while(true) {
    if(interruptor.pressed()) {
      Serial.println("Botao pressionado");
      digitalWrite(RELAYPIN_1, HIGH);
      Serial.println("Aperte novamente para apagar a luz");
      break;
    }
  }

  while(true) {
    if(interruptor.pressed()) {
      Serial.println("Botao pressionado");
      digitalWrite(RELAYPIN_1, LOW);
      Serial.println("Luz apagada");
      break;
    }
  }
}

void loop() {
  if (interruptor.released()) {
    Serial.println("Botao pressionado");
  }

  if (movimento.pressed()) {
    Serial.println("Movimento detectado");
  
    //ligar luz
    digitalWrite(RELAYPIN_1, HIGH);

    //habilitar timer
    timer.enable(guarda20);
  }

  //verificar temperatura
  if(getTemperature() > 23.99) {
    digitalWrite(RELAYPIN_2, HIGH);
  }
  if(getHumidity() > 22) {
    digitalWrite(RELAYPIN_2, LOW);
  }
}
