#ifndef   funcArry_h
#define   funcArry_h

#include "../writeFuncs/writeFuncs.h"
#include  "../retrieveFuncs/retrieveFuncs.h"
#include "../../comBuffer/comBuffer.h"


#define MAC_COM_NUM  2

typedef void (*func) (ComBuffer*);
extern func functions[];

#endif
