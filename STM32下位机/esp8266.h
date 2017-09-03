#ifndef __ESP8266_H
#define __ESP8266_H

//设备编号
//#define Temperature0 0
//#define Temperature1 1
//.........

//数据类型
#define Int 0
#define Float 1
#define String 2

//数据发送函数
//配置过USART，且支持printf函数，直接使用此函数发送数据
//num  设备编号
//type 参数类型
//...  要发送的数据
void assemble(int num,int type,...);

#endif