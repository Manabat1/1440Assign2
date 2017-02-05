//
// Created by manab on 2/1/2017.
//

#include "History.hpp"
#include "FormattedTable.h"
#include "Utils.h"
#include <fstream>
#include <sstream>

History::History(std::ifstream& fin){
    simDays = atoi(getTrimmedLine(fin).c_str());
    seedMoney= atoi(getTrimmedLine(fin).c_str());
    totalSales = atoi(getTrimmedLine(fin).c_str());
    //std::cout << "Total Sales: " << totalSales << std::endl;
    for(int i = 0; i < totalSales; i++){
        std::string parse = getTrimmedLine(fin);
        purchaseSales.push_back(*(new PurchaseSale(parse)));
    }
    fin.close();
}
void History::addPurchaseSale(PurchaseSale purchaseSale){
    purchaseSales.push_back(purchaseSale);
}
std::vector<PurchaseSale> History::getPurchaseSales(){
    return purchaseSales;
}
int History::getSimDays()const{
    return simDays;
}

void History::printHistory() {

}

int History::getTotalProfit() const{
    int profits;
    for(int i = 0; i<purchaseSales.size(); i++){
        profits+=purchaseSales[i].computeProfit();
    }

    return profits;
}

int History::getSeedMoney()const {
    return seedMoney;
}
