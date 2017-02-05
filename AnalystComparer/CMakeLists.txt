cmake_minimum_required(VERSION 3.6)
project(AnalystComparer)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp ColumnDefinition.cpp ColumnDefinition.h FormattedCell.cpp FormattedCell.h FormattedRow.h FormattedRow.cpp FormattedTable.h FormattedTable.cpp Utils.cpp Utils.h Comparer.cpp Comparer.h Constants.h Analyst.cpp Analyst.hpp PurchaseSale.cpp PurchaseSale.hpp History.cpp History.hpp)
add_executable(AnalystComparer ${SOURCE_FILES})

