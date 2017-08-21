
#include "file.h"

class MyData
{
private:
   file* file1;
   int noe;
   //file* file2;
   //file* actual;

public:
   ~MyData(){}
   MyData()
   {
      file1= new file("exemplo.bin");
      noe= file1->numberOfElements(); 
     // file2 = new file("file2.bin");
   }

   void add(int value);
   void add(int pos, int value);
   void del(int pos);
   void get(int pos);
   void set(int pos, int value);
   void print();
   void clear();
   void sort();
   bool bubblesort();
   file* getFile();
   //void conc();
   //void chooseFile(int number);

};
