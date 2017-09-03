#include <stdio.h>
#include <stdarg.h>
#include ¡°esp8266.h"

void assemble(int num,int type,...)
{
    char str[20];
    char *s;
    int iData;
    double fData;
    va_list ls;
    va_start(ls,type);
    switch(type)
    {
    case 0:iData=va_arg(ls,int);sprintf(str,"#%d#%d#%d#",num,type,iData);break;
    case 1:fData=va_arg(ls,double);sprintf(str,"#%d#%d#%.4f#",num,type,fData);break;
    case 2:s=va_arg(ls,char*);sprintf(str,"#%d#%d#%s#",num,type,s);break;
    default:break;
    }
    printf("%s\r\n",str);
    va_end(ls);
}