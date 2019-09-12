#include <SimpleTimer.h>

SimpleTimer timer;

void RepeatTask() { // function to be called repeatedly
  Serial.println("15 second timer");        
}

void OnceOnlyTask() { // function to be called just once
  Serial.println("This timer only triggers once");  
}

void TenTimesTask() { // function to be called exactly 10 times
  static int k = 0;  
  Serial.print("called "); Serial.print(++k); Serial.println(" / 10 times.");
}
 
void setup() {
  Serial.begin(115200);
   
  Serial.println("SimpleTimer Example");
  Serial.println("One timer is triggered every 15 seconds");
  Serial.println("Another timer is set to trigger only once after 10 seconds");
  Serial.println("Another timer is set to trigger 10 times");
  Serial.println();
 
  // timed actions setup
  timer.setInterval(15000, RepeatTask);
  timer.setTimeout(10000, OnceOnlyTask);  
  timer.setTimer(1200, TenTimesTask, 10);
}

void loop() {
  timer.run();
}
