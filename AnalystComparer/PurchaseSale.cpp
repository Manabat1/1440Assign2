//
// Created by manab on 2/1/2017.
//

#include <vector>
#include <sstream>
#include "PurchaseSale.hpp"
#include "Utils.h"


PurchaseSale::PurchaseSale(std::string& toSplit){
    std::string theInputs[8];
    split(toSplit,',',theInputs,8);
    for(int i = 0; i<8;i++){
      switch(i){
          case 0 :
            m_symbol = theInputs[i];
              break;
          case 1 :
              m_quantity = atoi(theInputs[i].c_str());
              break;
          case 2 :
              m_purchaseTime = atoi(theInputs[i].c_str());
              break;
          case 3 :
              m_purchasePrice = atoi(theInputs[i].c_str());
              break;
          case 4 :
              m_purchaseFee = atoi(theInputs[i].c_str());
              break;
          case 5 :
              m_saleTime = atoi(theInputs[i].c_str());
              break;
          case 6 :
              m_salePrice = atoi(theInputs[i].c_str());
              break;
          case 7 :
              m_saleFee = atoi(theInputs[i].c_str());
              break;
      }

    }
        //std::cout << "PS:" <<m_symbol << " "<<m_quantity<< " "<<m_purchaseTime<< " "<<m_purchasePrice<< " "<<m_purchaseFee<< " "<<m_saleTime  << " "<<m_salePrice<< " "<<m_saleFee << std::endl;

}
int PurchaseSale::computeInvestmentAmount() const {
    return m_quantity*m_purchasePrice + m_purchaseFee + m_saleFee;
}
int PurchaseSale::computeProfit() const {
    return m_quantity*m_salePrice - computeInvestmentAmount();
}

std::string PurchaseSale::getSymbol() const{
    return m_symbol;
}
