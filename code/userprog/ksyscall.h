/**************************************************************
 *
 * userprog/ksyscall.h
 *
 * Kernel interface for systemcalls 
 *
 * by Marcus Voelp  (c) Universitaet Karlsruhe
 *
 **************************************************************/

#ifndef __USERPROG_KSYSCALL_H__ 
#define __USERPROG_KSYSCALL_H__ 


#include "kernel.h"
#include "synchconsole.h"

void SysHalt()
{
  kernel->interrupt->Halt();
}


int SysAdd(int op1, int op2)
{
  return op1 + op2;
}

int SysOSAdd(int op1, int op2)
{
  return op1 + op2;
}

int SysOSSub(int op1, int op2)
{
  return op1 - op2;
}

int SysOSMul(int op1, int op2)
{
  return op1 * op2;
}

int SysOSDiv(int op1, int op2)
{
  return op1 / op2;
}

int SysPrint(char *input, int length){

  int data[1];

  for(int i=0;i<=length;i++){
    kernel->machine->ReadMem((int)input+i, 1, data);
    kernel->synchConsoleOut->PutChar(data[0]);
  }
  return 0;
}

int Print(char *input, int length){
  for(int i=0; i<length; i++){
    kernel->synchConsoleOut->PutChar(input[i]); 
  }
}

int PrintInt(int num){

  int length = 0;
  bool neg =    num<0? true   : false;
  int tmp =     num<0? -1*num : num;

  while(tmp!=0){
    length++;
    tmp /= 10;
  }

  if(neg){
    kernel->synchConsoleOut->PutChar( '-' ); 
    num *= -1;
  }

  char out[length];
  for(int i=0; i<length; i++){
    out[length-i-1] = num%10+'0';
    num/=10;
  }

  for(int i=0; i<length; i++){
    kernel->synchConsoleOut->PutChar( out[i] ); 
  }

  return 0;
}



#endif /* ! __USERPROG_KSYSCALL_H__ */
