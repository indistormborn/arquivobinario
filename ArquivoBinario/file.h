#pragma once
#include <fstream>

using namespace std;


class file
{
private:
   fstream fs;
   string name;

public:
   ~file();
   file();
   file(char *);   

   int readValue();
   int * readFile();
   void write(int); 
};