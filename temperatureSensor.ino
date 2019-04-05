#include <LiquidCrystal.h>                  //import LCD library to use print function
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);    // tell the RedBoard what pins are connected to the display

float voltage = 0;                          //the voltage measured from the TMP36
float degreesC = 0;                         //the temperature in Celsius, calcuated from the voltage
float degreesF = 0;                         //the temperature in Farenheit, calcuated from the voltage

void setup() {

  lcd.begin(16, 2);                         //tell the lcd library that we are using a display that is 16 characters wide and 2 characters high
  lcd.clear();                              //clear the display    
  Serial.begin(9600);
}

void loop() {
  
  voltage = analogRead(A0) * 0.004882814;   //convert the analog reading, which varies from 0 to 1023, back to a voltage value from 0-5 volts
  degreesC = (voltage - 0.5) * 100.0;       //convert the voltage to a temperature in degrees Celsius
  degreesF = degreesC * (9.0/5.0) + 32.0;   //convert the calculated celcius into Farenheit 

  lcd.clear();                              //clear the LCD

  lcd.setCursor(0,0);                       //set the cursor to the top left position
  lcd.print("Degrees C: ");                 //print a label for the data
  lcd.print(degreesC);                      //print the degrees Celsius
  
  lcd.setCursor(0,1);                       //set the cursor to the lower left position
  lcd.print("Degrees F: ");                 //Print a label for the data
  lcd.print(degreesF);                      //print the degrees Fahreheit
  
  delay(1000);                              //delay for 1 second between each reading (this makes the display less noisy)
  Serial.print("Celcius: ");                //output celcius in Serial console
  Serial.println(degreesC);                 // ""
}
