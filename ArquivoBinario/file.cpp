#include "StdAfx.h"
#include "file.h"
#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////
file::~file(){}

file::file(){}

file::file(char *fileName)
{
   this->name= fileName;
   
   fs.open(fileName, ios::in | ios::binary);
   if(!fs){
      fs.open(fileName, ios::out | ios::binary);
      fs.close();
   }else
      fs.close();  
}
///////////////////////////////////////////////////////////////////////////////////////

int file::readValue(){
   int value= 0;
   return value;
}

int * file::readFile(){
   streampos size;
   int * datablock;
   
   fs.open(name, ios::in | ios::binary | ios::ate);
   
   if ( fs.is_open() )
   {
      fs.seekg(0, ios::end);
      size= fs.tellg();
      fs.seekg(0, ios::beg);

      int lastPos= size.seekpos();
      datablock = new int [lastPos/4];

      for (int i= 0; i < lastPos/4; i++){
         fs.read ( (char *)&datablock[i], sizeof(int) );
      }
      fs.close();
   }
   
   

   return datablock;
}

void file::write(int value)
{
   fs.open(name, ios::out | ios::app | ios::binary);
   if(fs.is_open()){
      fs.write((char *)&value, sizeof(int));
      fs.close();
   }
}

