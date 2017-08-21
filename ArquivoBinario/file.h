#pragma once
#include <fstream>

using namespace std;


class file
{
private:
   fstream fs;
   string name;

public:
   ~file(){}
   file(){}
   file(char *);   

   int readValue(int value);
   int* readFile();
   void write(int value); 
   void cleanFile();
   void writePosition(int value, int pos);
   int fileSizeInBytes();
   int numberOfElements();
   void movePointer(int pos);
};