
/*DELETE QUE DELETA A POSICAO MAS NAO DELETA A ULTIMA, SO FAZ UMA COPIA*/
int actualPos= pos;
   int index= pos+1;
   int numberOfElements= file1->numberOfElements();
   int value;

   while(actualPos < numberOfElements) {
      value= file1->readValue(index);
      
      if(actualPos == numberOfElements)
         value= NULL;

      file1->writePosition(value, actualPos);
      index++;
      actualPos++;
      print();
   }

//add na posicao utilizando 4 loops, sacanagi ne
vector<int> leftSide;
   vector<int> rightSide;
   int numerOfElements= file1->fileSize() / 4; 
   int index= pos-1;

   for(int i= 0 ; i < index ; i++) {
      int v= file1->readValue(i);
      leftSide.push_back(v);
   }
   for(int i= index ; i < numerOfElements ; i++) {
      int v= file1->readValue(i);
      rightSide.push_back(v);
   }
   file1->cleanFile();

   for(int i= 0 ; i < index ; i++) {
      int v= leftSide[i];
      file1->write(v);
   }
   file1->write(value);
   for (int i= 0 ; i < rightSide.size() ; i++) {
      int v= rightSide[i];
      file1->write(v);
   }

   /* if (posToCompare <= noe) {
      for (int i = 0 ; i < posToCompare ; i++) {
         actualValue = file1->readValue(posToCompare);
         while (leftPositions < posToCompare) {
            int lowerValue;
            nextValue = file1->readValue(leftPositions);
            if (actualValue < nextValue) { }
         }
         posToCompare++;
         leftPositions = 1;
      }
   }*/

   /*for(int i= 1; i <= noe; i++) {
      actualValue= file1->readValue(i);
      for(int j= i+1; j <= noe; j++) {
         nextValue= file1->readValue(j);
         if(actualValue <= nextValue) {
            
         }
      }
   }*/
int pivoPosition= noe / 2;
   int pivo= file1->readValue(pivoPosition);
   int lowerValue;
   int lowerValuePosition;
   int higherValue;
   int higherValuePosition;
   int actualValue= 0;
   
   while(true) {
      lowerValue= pivo;
      higherValue= 0;
      
      //right loop
      for (int r= noe; r > pivoPosition; r--) {
         actualValue= file1->readValue(r);
         if(actualValue <= pivo && actualValue <= lowerValue) {
            lowerValue= actualValue;
            lowerValuePosition= r;
         }
      }
      
      file1->writePosition(lowerValue, pivoPosition);
      file1->writePosition(pivo, lowerValuePosition);
      pivoPosition= lowerValuePosition;
      print();

      //left loop
      for (int l= 1; l < pivoPosition; l++) {
         actualValue= file1->readValue(l);
         if(actualValue >= pivo && actualValue >= higherValue){
            higherValue= actualValue;
            higherValuePosition= l;
         }
      }

      file1->writePosition(higherValue, pivoPosition);
      file1->writePosition(pivo, higherValuePosition);
      pivoPosition= higherValuePosition;
      print();
   }

}