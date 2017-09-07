#include <ESP8266WiFi.h>
#include <stdio.h>
#include "Ticker.h"

const char* serverIP  = "119.23.111.132";
int serverPort = 8765;
WiFiClient client;
bool bConnected = false;
char buff[512];
int nm = 0;
int counter;
float a=12.35;

Ticker tic;

void smartConfig()
{
  WiFi.mode(WIFI_STA);
  Serial.println("\r\nWait for Smartconfig");
  //调用smartconfig功能
  WiFi.beginSmartConfig();
  while (1)
  {
    Serial.print(".");
    delay(500);
    delay(500);
    //若配置完成打印获取到的ssid
    if (WiFi.smartConfigDone())
    {
      Serial.println("SmartConfig Success");
      Serial.printf("SSID:%s\r\n", WiFi.SSID().c_str());
      Serial.printf("PSW:%s\r\n", WiFi.psk().c_str());
      break;
    }
  }
}

void ticSend(){
  iSend(89,123456);
  fSend(46,895.364);
}

void iSend(int num,int data){
  char s[40];
  sprintf(s,"#%d#0#%d#",num,data);
  client.println(s);
}

void fSend(int num,float data){
  char s[40];
  sprintf(s,"#%d#1#%e#",num,data);
  client.println(s);
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
      Serial.println("TCPConnection failed");
      delay(5000);
      return; 
    }
    bConnected = true;
    Serial.println("TCP connected");
    //tic.attach(2,ticSend);
  }
  // 服务器接收
  else if (client.available())
  {
    while (client.available())
    {
      buff[nm++] = client.read();
      if (nm >= 511) break;
    }
    buff[nm] = 0x00;
    nm=0;
    Serial.print(buff);
  }
  // 串口接收
  if(Serial.available())
  {
    while(Serial.available())
    {
      buff[nm++] = Serial.read();
      if (nm >= 511) break;
    }
    buff[nm] = 0x00;
    nm=0;
    client.print(buff);
  }
}

