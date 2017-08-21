#include "MyData.h"
#include <iostream>
#include <vector>
using namespace std;

void MyData::add (int value)
{
   file1->write(value);
} 

void MyData::add (int pos, int value)
{
   int index= pos;
   int copy;
   int newValue= value;
   int numberOfElements= noe + 1;

   if(index > 0){
      if(index > numberOfElements) {
         add(value);
         return;
      }

      while(index <= numberOfElements) {
         copy= file1->readValue(index);
         file1->writePosition(newValue,index);
         newValue= copy;
         index++;
      }
   }else
      add(1,value);
}

void MyData::del (int pos)
{
   vector<int> values;
   int value= 0;

   if (pos > 0 && pos <= noe) {
      for (int index = 1 ; index <= noe ; index++) {
         if (index != pos) {
            value = file1->readValue(index);
            values.push_back(value);
         }
      }

      noe--;
      file1->cleanFile();
      for (int index = 0 ; index < noe ; index++)
         file1->write(values[index]);
   }

  
}

void MyData::get (int pos)
{ 
   if(pos > 0 && pos <= noe) {
      int v= file1->readValue(pos);
      cout<< "value at position " << pos << " is: " << v << endl;
   }
}

void MyData::set (int pos, int value)
{
   if(pos > 0 && pos <= noe)
      file1->writePosition(value,pos);
}

void MyData::print ()
{
   int* vetor= file1->readFile();
   for(int i = 0 ; i < noe; i++)
      cout << vetor[i] << " ";

   cout << endl;

}

void MyData::clear ()
{
   file1->cleanFile();
}

bool MyData::bubblesort ()
{
   int countLaco1 = noe;
   int actualValue;
   int actualPos;

   while (countLaco1 > 0) {
      int countLaco2 = countLaco1 - 1;
      actualValue = file1->readValue(1);
      actualPos= 1;
      int indice= 2;
      while (countLaco2 > 0) {
         int nextValue = file1->readValue(indice);
         if (actualValue > nextValue) {
            file1->writePosition(actualValue, indice);
            file1->writePosition(nextValue, actualPos);
         }
         actualValue= file1->readValue(indice);
         actualPos= indice;
         countLaco2--;
         indice++;
         print();
      }
      countLaco1--;
   }
   return true;
}

file* MyData::getFile()
{
   return file1;
}
