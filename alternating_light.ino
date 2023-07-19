/* 
 *  Ex_14 - Physical Computing
 *  Revisit Input & Output
 *  
 *  LED 
 *  -- GP12
 *  Switch
 *  -- GP7
 *  
 */

#define ONBOARD_LED 12    // LED GP12
#define ONBOARD_SW  7    // Switch GP7
int mode = 0;
boolean pressed = false;

int current_LED = LOW;

void setup() {
   Serial.begin(115200); //set up serial library baud rate to 115200
   pinMode(ONBOARD_LED, OUTPUT);
   pinMode(ONBOARD_SW, INPUT_PULLUP);

   digitalWrite(ONBOARD_LED, current_LED);    // turn the LED off by making the voltage LOW   

   current_LED = LOW;
}

void loop() {

   if (digitalRead(ONBOARD_SW) == LOW) {  // Switch is asserted Low (Active Low)
      if (pressed == false) {
          if (mode != 3) {
        mode += 1;
      }
      else {
        mode = 0;
      }
      pressed = true;
      }
   }

  if (digitalRead(ONBOARD_SW) == HIGH) {
    pressed = false;
  }
      
    if (mode == 1) {
      digitalWrite(ONBOARD_LED, (millis() / 1000) % 2);
    }
     else if (mode == 2) {
      digitalWrite(ONBOARD_LED, (millis() / 500) % 2);
    }
     else if (mode == 3) {
      digitalWrite(ONBOARD_LED, (millis() / 100) % 2);
    }
    else if (mode == 0) {
         current_LED = LOW;
    }
}
                    
                