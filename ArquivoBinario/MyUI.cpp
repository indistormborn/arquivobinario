#include "MyUI.h"
#include <iostream>

int MyUI::getMenuOption(int message)
{
   int t;

   std::cout << getMessage(message);
   std::cin >> t;
   std::cout << std::endl;
   return t;
}

int MyUI::getMenuOption()
{
   int t;
   std::cout << "Entre com a opcao: ";
   std::cin >> t;
   std::cout << std::endl;
   currentOption= t;
   return t;
}


//////////////////////////////////////////////////////////////////////////////////////////////////

void MyUI::mainMenu()
{
   std::cout << "--------------- MENU PRINCIPAL ---------------"<< std::endl;
   std::cout << "|                                            |"<<std::endl;
   std::cout << "| 11- Configurar Primeira Lista              |"<<std::endl;
   std::cout << "| 22- Configurar Segunda Lista               |"<<std::endl;
   std::cout << "| 100- Fechar aplicacao                      |"<< std::endl;
   std::cout << "|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |"<<std::endl;
   
}

void MyUI::manipMenu()
{
   std::cout << "------------------- Opcoes de manipulacao -------------------" <<std::endl;
   std::cout << "0- Adicionar na posicao" <<std::endl;
   std::cout << "1- Adicionar no fim"<<std::endl;
   std::cout << "-----------------" <<std::endl;
   std::cout << "2- Deletar posicao" <<std::endl; 
   std::cout << "3- Deletar inicio da lista"<<std::endl;
   std::cout << "4- Deletar fim da lista"<<std::endl;
   std::cout << "-----------------" <<std::endl;
   std::cout << "5- Imprimir sentido inicio-fim"<<std::endl;
   std::cout << "6- Imprimir sentido fim-inicio"<<std::endl;
   std::cout << "-----------------" <<std::endl;
   std::cout << "7- Esvaziar lista" <<std::endl;
   std::cout << "8- Ordenar" <<std::endl;
   std::cout << "9- Concatenar" <<std::endl;
   std::cout << "100- Voltar para o menu principal" <<std::endl;
   
}

//////////////////////////////////////////////////////////////////////////////////////////////////

void MyUI::createErrorMessages()
{
   errMsgs[ERROR_DEL]= "Impossivel deletar! Posicao informada nao existe na lista ou a lista esta vazia \n";
   errMsgs[ERROR_PRINT]= "Nenhum elemento a ser impresso pois a lista esta vazia! \n";
   errMsgs[ERROR_CLEAR]= "IMPOSSIVEL esvaziar uma lista que ja esta vazia \n";
   errMsgs[ERROR_ORD]= "IMPOSSIVEL ordenar uma lista vazia \n";
   errMsgs[ERROR_CONC]= "IMPOSSIVEL concatenar pois uma das listas esta vazia";
   errMsgs[ERROR_OPTION]= "Opcao invalida! Insira outra:  \n";
}

void MyUI::createInsertMessages()
{
   insMsgs[INSERT_V]= "Insira valor:  \n";
   insMsgs[INSERT_P]= "Insira a posicao:  \n";
   insMsgs[INSERT_V_P]= "Insira valor e posicao:  \n";
}

void MyUI::createInfoMessages(){
   infMsgs [VALUE_ADD]= "Valor adicionado com sucesso! \n";
   infMsgs [POS_REMOVED]= "Posicao removida da lista! \n";
   infMsgs [BEG_EXCLUDED]= "Inicio da lista excluido! \n";
   infMsgs [END_EXCLUDED]= "Fim da lista excluido! \n";
   infMsgs [PRINTED_BE]= "Impressao da lista no sentido INICIO-FIM \n";
   infMsgs [PRINTED_EB]= "Impressao da lista no sentido FIM-INICIO \n";
   infMsgs [EMPTY_LIST]= "Lista esvaziada! \n";
   infMsgs [ORD_LIST]= "Lista ordenada! \n";
   infMsgs [CONCATENATED]= "Lista concatenada! \n";

}

//////////////////////////////////////////////////////////////////////////////////////////////////

std::string MyUI::getMessage(int value){
   //10,11,12,13,14,15
   if(value >= 10 && value <=15){
      if ( errMsgs.find(value) != errMsgs.end())
         return errMsgs.find(value)->second;
   }
  //20,21,22
   else if(value >=20 && value <= 22){
      if ( insMsgs.find(value) != insMsgs.end())
         return insMsgs.find(value)->second;
   }
   //30,31,32,33,34,35,36,37,38,39
   else { 
      if ( infMsgs.find(value) != infMsgs.end())
         return infMsgs.find(value)->second;
   }

   return "mensagem n encontrada \n";
}
/////////////////////////////////////////////////////////////////////////
void MyUI::print(std::string s) { std::cout << s << std::endl; }