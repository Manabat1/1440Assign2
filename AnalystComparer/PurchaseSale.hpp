//
// Created by manab on 2/1/2017.
//

#ifndef ASSIGN2_PURCHASESALE_HPP
#define ASSIGN2_PURCHASESALE_HPP

#include <iostream>

class PurchaseSale{
public:
    //static std::vector<std::string> usedStockSymbols;
    PurchaseSale(std::string& toSplit);
    int computeInvestmentAmount() const;
    int computeProfit() const;
    std::string getSymbol() const;
private:
    std::string m_symbol;
    int m_quantity;
    int m_purchaseTime;
    int m_purchasePrice;
    int m_purchaseFee;
    int m_saleTime;
    int m_salePrice;
    int m_saleFee;
};


#endif //ASSIGN2_PURCHASESALE_HPP
