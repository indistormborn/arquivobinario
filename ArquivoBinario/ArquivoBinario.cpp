// ArquivoBinario.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include "file.h"
using namespace std;


void print(int * vetor){
   for(int i=0; i < sizeof(&vetor); i++)
      cout<< vetor[i] <<" ";;
}

int main(int argc, _TCHAR* argv[])
{
  // fstream arquivo("example.bin", ios::out | ios::binary);
   char *a = new char(8);
   a= "nome.bin";
   file *f= new file(a);
   /*f->write(400);
   f->write(333);
   f->write(222);
   f->write(441);*/
   print(f->readFile());

   return 0;
}

