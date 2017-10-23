#ifndef __ESP8266_H
#define __ESP8266_H


#define Int 0
#define Float 1
#define String 2

extern int bConfirmed;
extern long long TimeCount;
typedef struct ResolvedData;


void assemble(long long time, int num,int type,...);
struct ResolvedData resolve(char str[]);
void getTimeCount(void);
int CheckUsartStatus(void);

#endif

