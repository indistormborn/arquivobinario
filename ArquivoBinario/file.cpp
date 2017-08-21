#include "file.h"
#include <iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////

file::file (char* fileName)
{
   this->name = fileName;

   fs.open(fileName, ios::in | ios::binary);
   if (!fs) {
      fs.open(fileName, ios::out | ios::binary);
      fs.close();
   }
   else
      fs.close();
}

///////////////////////////////////////////////////////////////////////////////////////

int file::readValue (int index)
{
   int value = 0;
   int pos= index-1;

   fs.open(name, ios::in | ios::binary);

   if (fs.is_open()) {
      fs.seekg(pos * 4, ios::beg);
      fs.read((char *)&value, sizeof(value));
      fs.close();
   }

   return value;
}

int* file::readFile ()
{
   streampos size;
   int* datablock= nullptr;

   fs.open(name, ios::in | ios::binary | ios::ate);

   if (fs.is_open()) {
      fs.seekg(0, ios::end);
      size = fs.tellg();
      fs.seekg(0, ios::beg);

      int lastPos = size.seekpos();
      datablock = new int [lastPos / 4];

      for (int i = 0 ; i < lastPos / 4 ; i++) {
         fs.read((char *)&datablock[i], sizeof(int));
      }
      fs.close();
   }

   return datablock;
}

void file::write (int value)
{
   fs.open(name, ios::out | ios::app | ios::binary);
   if (fs.is_open()) {
      fs.write((char *)&value, sizeof(int));
      fs.close();
   }
}

void file::cleanFile()
{
   fs.open(name, ios::out | ios::trunc | ios::binary);
   fs.close();

}

void file::writePosition (int value, int pos)
{
   fs.open(name, ios::in | ios::out | ios::binary);
   if (fs.is_open()) {
      fs.seekp((pos-1)*4, ios::beg);
      fs.write((char *)&value, sizeof(int));
      fs.close();
   }
}

int file::fileSizeInBytes()
{
   streampos sizeInBytes;

   fs.open(name, ios::in | ios::binary | ios::ate);
   sizeInBytes = fs.tellg();
   fs.seekg(0, ios::beg);
   
   int size= sizeInBytes.seekpos();

   fs.close();
   return size;
}

int file::numberOfElements ()
{
  return fileSizeInBytes() / 4;
}

void file::movePointer (int pos)
{
   fs.open(name, ios::binary | ios::ate);
   fs.seekg(pos);
   fs.close();
}

