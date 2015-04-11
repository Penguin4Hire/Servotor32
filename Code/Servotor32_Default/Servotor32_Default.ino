#include "Servotor32.h" // call the servotor32 Library

Servotor32 platform; // create a servotor32 object

void setup() {
  platform.begin();
}

void loop() {
  // blink the status led
  digitalWrite(STATUS_LED, HIGH);
  platform.delay_ms(500); // wait 500mS
  digitalWrite(STATUS_LED, LOW);
  platform.delay_ms(500); // wait 500mS
  
  // kill all servos
  for(int i=0; i<32; i++){
    platform.changeServo(i,-1);
  }
  
  // center servos 0,1,2,3
  platform.changeServo(0,1500);
  platform.changeServo(1,1500);
  platform.changeServo(2,1500);
  platform.changeServo(3,1500);
  
  platform.delay_ms(100); // wait 100mS
 
  while(true){
    // get a ping from the ultrasonic sensor in CM
    //Serial.print("CM: ");
    //Serial.println(platform.ping());
    //platform.delay_ms(200); // wait 200mS
    
    platform.process(&Serial); //process input from the USB
    platform.process(&Serial1); //process input from the board serial (i.e. bluetooth)
  }
  
}






