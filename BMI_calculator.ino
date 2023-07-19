/* 
 *  Ex_11 - Conditional
 *  Simple communication through the Serial monitor.
 *  
 */
String ans1 = "";
String ans2 = "";
int weight = 0;
int height = 0;
float BMI;


void setup() {
   Serial.begin(115200); //set up serial library baud rate to 115200
   delay(2000);
   Serial.println("Am I overweight?");
}

void loop() { 
      Serial.println("Your weight is ");
    while (Serial.available()) {
      Serial.read();
    }
    while(Serial.available() == 0){}
    weight = Serial.parseInt();
      Serial.println(weight);

      Serial.println("Your height is ");
    while (Serial.available()) {
      Serial.read();
    }
    while(Serial.available() == 0){}
    height = Serial.parseInt();
      Serial.println(height);
  
      BMI = weight / ((height/100)^2);

      if (BMI > 24.9) {
        Serial.println("You are overweight!");
      }
      else if (BMI > 18.5 && BMI < 24.9) {
        Serial.println("You are normal!");
      }
      else {
        Serial.println("You are underweight");
      }

      Serial.println("");
      Serial.println("Am I overweight?");
   }

                