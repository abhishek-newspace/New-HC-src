#include "include/radio_config.h"

#ifdef GET_RADIO_CONFIG

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
   delay(1000); 
   Serial.println("Trying to obtain radio configurations...");
   delay(1000);             
   Serial3.print("+++"); 
   waitForResponse();   
   
}

void setParameter(String param, String val){
   delay(1000);
   Serial.println(String("setting value for ") + param + String(" to ") + val);
   Serial3.println(param + String('=') + val);
   waitForResponse();  
   delay(1000);
}

void writeParameters(){
   delay(1000);
   Serial3.println("RT&W"); 
   Serial3.println("AT&W"); 
   waitForResponse();  
}

void rebootRadio(){
   delay(1000);
   Serial3.println("RTZ"); 
   Serial3.println("ATZ");
}

void exitConfig(){
   Serial.println("\nExiting command mode...");
   Serial3.println("RTO"); 
   Serial3.println("ATO"); 
}

void performConfig(){

   initRadioConnection();


   // Serial.println("getting current local radio configurations");
   // getRadioConfigurations();

   // Serial.println("getting current remote radio configurations");
   // getRemoteRadioConfigurations();

   // exitConfig();
   // return;

   // Serial.println("configuring radio ... ");

   // setParameter("RTS2","128");
   // setParameter("RTS4","20");
   // setParameter("RTS10","10");


   // setParameter("ATS2","64");
   // setParameter("ATS4","20");
   // setParameter("RTS10","10");

   // Serial.println("writing parameters");
   // writeParameters();

   // Serial.println("rebooting radios");
   // rebootRadio();


   // Serial.println("getting current local radio configurations");
   // getRadioConfigurations();

   // Serial.println("getting current remote radio configurations");
   // getRemoteRadioConfigurations();

   requestParam("ATPP");

}


void requestParam(String param){
   delay(1000);
   Serial.println(String("Requesting ") + param + String("..."));
   Serial3.flush();
   Serial3.println(param); 
   while(!Serial3.available());
   unsigned long lastDataTime = millis();
   while (millis() - lastDataTime < 1000) { 
      while (Serial3.available()) {
            Serial.write(Serial3.read()); // Print it instantly to clear the buffer
            lastDataTime = millis();      // Reset the timeout clock
      }
   }
   delay(1000);
}


void getRemoteRadioConfigurations(){
   Serial.println("Requesting User Configurable Parameters");
   requestParam("RTI5");

   Serial.println("Requesting Radio Version");
   requestParam("RTI");

   Serial.println("Requesting Board Type");
   requestParam("RTI2");

   Serial.println("Requesting Board version");
   requestParam("RTI4");

   Serial.println("Requesting Board Frequency");
   requestParam("RTI3");

   Serial.println("Requesting TDM timing report");
   requestParam("RTI6");

}
void getRadioConfigurations(){
   Serial.println("Requesting User Configurable Parameters");
   requestParam("ATI5");

   Serial.println("Requesting Radio Version");
   requestParam("ATI");

   Serial.println("Requesting Board Type");
   requestParam("ATI2");

   Serial.println("Requesting Board version");
   requestParam("ATI4");

   Serial.println("Requesting Board Frequency");
   requestParam("ATI3");

   Serial.println("Requesting TDM timing report");
   requestParam("ATI6");

}

#endif