#include <Arduino.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>

const char* ssid = "Boteon MikroTik";
const char* password = "Boteon12345";

const char* BotToken = "1339873060:AAH1h87egpt30g0zgAQ9IJU-bkVjTuBkaU4";

WiFiClientSecure net_ss1;
UniversalTelegramBot bot(BotToken, net_ss1);
void setup() 
{
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid,password);
  
  while(WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.print(".");
  }
   Serial.println("Connected");
  pinMode(19, OUTPUT);


}

void loop() 
{
 if(bot.getUpdates(bot.last_message_received + 1))
 {
   String chat_id = String (bot.messages[0].chat_id);
   String text = bot.messages[0].text;
   if(text == "ON")
   {
     digitalWrite(19, HIGH);
     bot.sendMessage(chat_id, "socket si ON");
   }
     else if(text == "OFF")
     {
       digitalWrite(19, LOW);
       bot.sendMessage(chat_id, "socket si OFF");
     }
     
 }


}