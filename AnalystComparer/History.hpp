//
// Created by manab on 2/1/2017.
//

#ifndef ASSIGN2_HISTORY_HPP
#define ASSIGN2_HISTORY_HPP

#include <vector>
#include "PurchaseSale.hpp"
#include <fstream>


class History {
public:
    History(std::ifstream& fin);
    std::vector<PurchaseSale> getPurchaseSales();
    void addPurchaseSale(PurchaseSale purchaseSale);
    std::vector<PurchaseSale> purchaseSales;
    void printHistory();
    int getSimDays() const ;
    int getSeedMoney() const ;
    int getTotalProfit() const;
private:
    int totalSales;
    int simDays;
    int seedMoney;
};


#endif //ASSIGN2_HISTORY_HPP
