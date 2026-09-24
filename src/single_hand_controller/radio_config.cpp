#include "include/radio_config.h"

#ifdef GET_RADIO_CONFIG

void waitForResponse(){
   delay(1000);           
   while(!RADIO_PORT.available());
   Serial.print("Response: ");
   while(RADIO_PORT.available()) {
      Serial.write(RADIO_PORT.read()); 
      delay(20); // Crucial: prevents outrunning the buffer
   }
   Serial.println(); // Add a newline for readability
}

void initRadioConnection(){
   delay(1000); 
   Serial.println("Trying to obtain radio configurations...");
   delay(1000);             
   RADIO_PORT.print("+++"); 
   waitForResponse();   
   
}

void setParameter(String param, String val){
   delay(1000);
   Serial.println(String("setting value for ") + param + String(" to ") + val);
   RADIO_PORT.println(param + String('=') + val);
   waitForResponse();  
   delay(1000);
}

void writeParameters(){
   delay(1000);
   RADIO_PORT.println("RT&W"); 
   RADIO_PORT.println("AT&W"); 
   waitForResponse();  
}

void rebootRadio(){
   delay(1000);
   RADIO_PORT.println("RTZ"); 
   RADIO_PORT.println("ATZ");
}

void exitConfig(){
   Serial.println("\nExiting command mode...");
   RADIO_PORT.println("RTO"); 
   RADIO_PORT.println("ATO"); 
}

void performConfig(){

   initRadioConnection();


   // Serial.println("getting current local radio configurations");
   // getRadioConfigurations();

   // Serial.println("getting current remote radio configurations");
   // getRemoteRadioConfigurations();

   // exitConfig();
   // return;

   Serial.println("configuring radio ... ");

   // setParameter("RTS6","1");
   // setParameter("ATS6","1");
   // // setParameter("RTS4","20");
   // // setParameter("RTS10","10");


   // // setParameter("ATS2","64");
   // // setParameter("ATS4","20");
   // // setParameter("RTS10","10");

   setParameter("ATPI","5");
   setParameter("RTPO","5");
   writeParameters();
   rebootRadio();

   initRadioConnection();

   setParameter("ATPM","5");
   setParameter("RTPM","5");
   //Serial.println("writing parameters");

   // Serial.println("rebooting radios");


   // Serial.println("getting current local radio configurations");
   // getRadioConfigurations();

   // Serial.println("getting current remote radio configurations");
   // getRemoteRadioConfigurations();

   requestParam("ATPP");
   requestParam("RTPP");
   rebootRadio();

   

}


void requestParam(String param){
   delay(1000);
   Serial.println(String("Requesting ") + param + String("..."));
   RADIO_PORT.flush();
   RADIO_PORT.println(param); 
   while(!RADIO_PORT.available());
   unsigned long lastDataTime = millis();
   while (millis() - lastDataTime < 1000) { 
      while (RADIO_PORT.available()) {
            Serial.write(RADIO_PORT.read()); // Print it instantly to clear the buffer
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