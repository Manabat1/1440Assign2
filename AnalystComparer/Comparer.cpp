//
// Created by Stephen Clyde on 1/16/17.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include "Comparer.h"
#include "FormattedTable.h"


int Comparer::load(int argc, char* argv[])
{
    if (argc<3)
    {
        std::cout << "Invalid parameters" << std::endl;
        std::cout << "usage: AnalystComparer <output file> <input file 1> <input file 2> ..." << std::endl;
        return -1;
    }

    m_outputFilename = argv[1];
    m_analystCount = argc - 2;

    int analystIndex = 0;
    for (int i = 0; i < m_analystCount; i++)
    {
        //std::ifstream inputStream(argv[2 + analystIndex]);
        m_analysts.push_back(*(new Analyst((argv[2 + analystIndex]))));
        analystIndex++;
    }
   // loadSymbols();

    return 0;
}

int Comparer::compare() const
{
    if (m_analystCount < 2)
    {
        std::cout << "Cannot do comparison with " << m_analystCount << " analysts" << std::endl;
        return -1;
    }

    if (m_outputFilename == "")
    {
        std::cout << "Cannot do comparison because no output file is specified" << std::endl;
        return -1;
    }

    std::ofstream outputStream(m_outputFilename);
    outputStream.open(m_outputFilename);
    outputInvestorNames(outputStream);
    outputOverallPerformance(outputStream);
    outputStockPerformance(outputStream);
    outputStream.close();

    return 0;
}

void Comparer::loadSymbols()
{
    //Loops through the analysts
    for(int i = 0; i < m_analysts.size(); i++){
        std::vector<PurchaseSale> sales = (m_analysts[i].getHistory().getPurchaseSales());
        //Loops through the sales
        for(int j = 0; j < sales.size(); j++){
            //Loops through the symbols
            for(int k = 0; k <= m_symbols.size(); k++){
                //last loop through, no match found
                if(k == (m_symbols.size())){
                    m_symbols.push_back(sales[j].getSymbol());
                    break;
                }
                // if match is found, break loop
                if(m_symbols[j] == sales[j].getSymbol()){
                    break;
                }

            }
        }
    }
    // Adds the symbol to the symbols if it is not already in it

}


void Comparer::outputInvestorNames(std::ofstream& outputStream) const
{
    std::cout << "Investors:" << std::endl;
    for(int i = 0; i < m_analysts.size(); i++){
        std::cout << m_analysts[i].getName() << std::endl;
    }
//     TODO: Write out investor names
}

void Comparer::outputOverallPerformance(std::ofstream& outputStream) const
{
    // TODO: Write out Overall Performance table.  The classes from the FormattedTable example might be helpful.

    std::cout << "Overall Preformance:" << std::endl << std::endl;
    FormattedTable table(m_analystCount+1, 5);

    table.addColumn(new ColumnDefinition("Info", 10, ColumnDefinition::String, ColumnDefinition::Center));
    for(int i =0; i< m_analystCount; i ++){
        table.addColumn(new ColumnDefinition(m_analysts[i].getName(), 20, ColumnDefinition::String));
    }

    FormattedRow* row = new FormattedRow(&table);
    row->addCell(new FormattedCell("D (days)"));
    for(int i =0; i< m_analystCount; i ++){
        row->addCell(new FormattedCell(std::to_string(m_analysts[i].getHistory().getSimDays())));
    }
    row->addCell(new FormattedCell("$ (cents)"));
    for(int i =0; i< m_analystCount; i ++){
        row->addCell(new FormattedCell(std::to_string(m_analysts[i].getHistory().getSeedMoney())));
    }

    row->addCell(new FormattedCell("$ TPL"));
    for(int i =0; i< m_analystCount; i ++){
        row->addCell(new FormattedCell(std::to_string(m_analysts[i].getHistory().getTotalProfit())));
    }
    row->addCell(new FormattedCell("$ PLPD"));
    for(int i =0; i< m_analystCount; i ++){
        row->addCell(new FormattedCell(std::to_string(m_analysts[i].getHistory().getTotalProfit()/m_analysts[i].getHistory().getSimDays())));
    }




    table.write(std::cout);

    std::cout << std::endl << "Done" << std::endl << std::endl;
};

void Comparer::outputStockPerformance(std::ofstream& outputStream) const
{
    // TODO: Write out Stock Performance table.  The classes from the FormattedTable example might be helpful.
    std::cout << "Example 2: Create a table with 5 columns: Id, First Name, Last Name, GPA, Total Credits" << std::endl;
    std::cout << "           With 4 rows" << std::endl;

    FormattedTable table(4, 5);

    table.addColumn(new ColumnDefinition("Id", 8, ColumnDefinition::Integer, ColumnDefinition::Center));
    table.addColumn(new ColumnDefinition("First Name", 20, ColumnDefinition::String));
    table.addColumn(new ColumnDefinition("Last Name", 20, ColumnDefinition::String));
    table.addColumn(new ColumnDefinition("GPA", 8, ColumnDefinition::FixedPrecision, ColumnDefinition::Right, 1));
    table.addColumn(new ColumnDefinition("Total Credits", 14, ColumnDefinition::Integer));

    FormattedRow* row = new FormattedRow(&table);
    row->addCell(new FormattedCell((int) 1));
    row->addCell(new FormattedCell("Joe"));
    row->addCell(new FormattedCell("Jones"));
    row->addCell(new FormattedCell((float) 3.84));
    row->addCell(new FormattedCell((int) 84));
    table.addRow(row);

    row = new FormattedRow(&table);
    row->addCell(new FormattedCell((int) 2));
    row->addCell(new FormattedCell("Sue"));
    row->addCell(new FormattedCell("Samuelson"));
    row->addCell(new FormattedCell((float) 3.65));
    row->addCell(new FormattedCell((int) 64));
    table.addRow(row);

    row = new FormattedRow(&table);
    row->addCell(new FormattedCell((int) 3));
    row->addCell(new FormattedCell("Tammy"));
    row->addCell(new FormattedCell("Thompson"));
    row->addCell(new FormattedCell((float) 3.57));
    row->addCell(new FormattedCell((int) 97));
    table.addRow(row);

    row = new FormattedRow(&table);
    row->addCell(new FormattedCell((int) 4));
    row->addCell(new FormattedCell("Charles"));
    row->addCell(new FormattedCell("Carlson"));
    row->addCell(new FormattedCell((float) 3.43));
    row->addCell(new FormattedCell((int) 46));
    table.addRow(row);

    std::cout << "           And, then write to the standard output stream" << std::endl << std::endl;

    table.write(std::cout);

    std::cout << std::endl << "Done" << std::endl << std::endl;
}
