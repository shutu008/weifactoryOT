#include <ESP8266WiFi.h>
#include <stdio.h>
#include "Ticker.h"

const char* serverIP  = "121.196.217.247";
const char* deviceNum = "ZWGC2017100800004$";
int serverPort = 8765;
WiFiClient client;
bool bConnected = false;
char buff[2048];
int nm = 0;
int counter;

void smartConfig()
{
  WiFi.mode(WIFI_STA);
  WiFi.beginSmartConfig();
  while (1)
  {
    delay(500);
    delay(500);
    if (WiFi.smartConfigDone())
      break;
  }
}



void setup() {
  //串口配置
  Serial.begin(115200);
  delay(10);

  smartConfig();
}

void loop() {
  if (bConnected == false)
  {
    if (!client.connect(serverIP, serverPort))
    {
      delay(5000);
      return; 
    }
    bConnected = true;
    client.print(deviceNum);
  }
  // 服务器接收
  else if (client.available())
  {
    while (client.available())
    {
      buff[nm++] = client.read();
      if (nm >= 2048) break;
    }
    buff[nm] = 0x00;
    nm=0;
    Serial.println(buff);
  }
  // 串口接收
  if(Serial.available())
  {
    while(Serial.available())
    {
      buff[nm++] = Serial.read();
      if (nm >= 2048) break;
    }
    buff[nm] = 0x00;
    nm=0;
    client.print(buff);
  }

  if(client.status())
    bConnected = true;
  else if(bConnected == true)
  {
    bConnected = false;
    Serial.println("TCP disconnected");
  }


}

