#pragma once
#ifndef INCLUDED_MYUI_H
#define INCLUDED_MYUI_H

#include <stdlib.h>
#include <string>
#include <map>

class MyUI
{
private:
   std::map<int, std::string> errMsgs;
   std::map<int, std::string> insMsgs;
   std::map<int, std::string> infMsgs;

   int currentOption;

   void createErrorMessages();
   void createInsertMessages();
   void createInfoMessages();

public:
   ~MyUI(){}
   MyUI(){}

   enum mainOptions {FIRST_LIST=11, SECOND_LIST=22, CLOSE_APP=100};
   enum manipOptions {ADD_POS, ADD_END, DEL_POS, DEL_BEG, DEL_END, PRINT_F, PRINT_B, CLEAR, ORD, CONC, BACK=100};

   enum errorMessages {ERROR_DEL=10, ERROR_PRINT, ERROR_CLEAR, ERROR_ORD, ERROR_CONC, ERROR_OPTION};
   enum insertMessages {INSERT_V=20, INSERT_P, INSERT_V_P};
   enum infoMessages {VALUE_ADD=30, POS_REMOVED, BEG_EXCLUDED, END_EXCLUDED, PRINTED_BE, PRINTED_EB, EMPTY_LIST, ORD_LIST, CONCATENATED};
   
   int getMenuOption(int message);
   int getMenuOption();
   int getCurrentOption() { return currentOption; }

   void mainMenu();
   void manipMenu();

   std::string getMessage(int valueOf);

   static void clearScreen() { system("cls"); }
   
   void print(std::string s);
};

#endif //INCLUDED_MYUI_H
