#line 1 "/home/nikhil/Hand Controller Project/scout-td0-HC/src/single_hand_controller/radio_config.cpp"
#include "include/radio_config.h"


 void waitForResponse(){
    delay(1000);             
    Serial.print("Response: ");
    while(Serial3.available()) {
        Serial.write(Serial3.read()); 
        delay(20); // Crucial: prevents outrunning the buffer
    }
    Serial.println(); // Add a newline for readability
 }

 void initRadioConnection(){
    delay(2000); 
    Serial.println("Trying to obtain radio configurations...");
    delay(1000);             
    Serial3.print("+++"); 
    waitForResponse();   
    
 }

 void setParameter(String param, String val){
    Serial3.print(param + String('=') + val);
    waitForResponse();  
 }

 void exitConfig(){
    Serial.println("\nExiting command mode...");
    Serial3.println("ATO"); 
 }

 void performConfig(){

    setParameter("ATS1","115");
    setParameter("ATS2","250");
    setParameter("ATS3","89");
    setParameter("ATS5","0");
    setParameter("ATS6","1");
    setParameter("ATS15","33");
 }



void getRadioConfigurations(){
  Serial.println("Requesting ATI5...");
  Serial3.flush();
  Serial3.println("ATI5"); 
  
  while(!Serial3.available());
  unsigned long lastDataTime = millis();
  while (millis() - lastDataTime < 1000) { 
      while (Serial3.available()) {
          Serial.write(Serial3.read()); // Print it instantly to clear the buffer
          lastDataTime = millis();      // Reset the timeout clock
      }
  }
  Serial.println("configuring radio ... ");

  

}