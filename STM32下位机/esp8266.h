#ifndef __ESP8266_H
#define __ESP8266_H

//�豸���
//#define Temperature0 0
//#define Temperature1 1
//.........

//��������
#define Int 0
#define Float 1
#define String 2

//���ݷ��ͺ���
//���ù�USART����֧��printf������ֱ��ʹ�ô˺�����������
//num  �豸���
//type ��������
//...  Ҫ���͵�����
void assemble(int num,int type,...);

#endif