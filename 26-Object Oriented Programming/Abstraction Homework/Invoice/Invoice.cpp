/*Invoice.cpp*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include "Invoice.h"

Invoice::Invoice(){
    item_number = price = quantity = 0;
}

void Invoice::setName(std::string new_name){
     if(new_name.empty()){
                std::cout << "Enter a valid name" << "\n";
                return;
            }
            name = new_name;
}

void Invoice::setItemNumber(std::string new_item_number){
    item_number = new_item_number;
}

void Invoice::setPrice(double new_price){
    if(new_price <= 0){
        std::cout << "Enter a valid price" << "\n";
        return;
    }
    price = new_price;
}

void Invoice::setQuantity(int new_quantity){
    if(new_quantity <= 0){
        std::cout << "Enter a valid quantity" << "\n";
        return;
    }
    quantity = new_quantity;
}

double Invoice::GetTotalPrice() const{
    return quantity * price;
}

std::string Invoice::toString()const{
    std::ostringstream oss;

    oss << name << "," << item_number << "," << std::fixed << std::setprecision(2)<< price << "," << quantity;

    return oss.str();
}

void Invoice::print(std::ostream& out) const {
    out << std::left  << std::setw(15) << "Name"
              << std::setw(12) << "Item#"
              << std::right << std::setw(10) << "Price"
              << std::setw(8) << "Qty"
              << std::setw(12) << "Total" << "\n";

    out << std::string(57, '-') << "\n";

    out << std::left  << std::setw(15) << name
              << std::setw(12) << item_number
              << std::right << std::fixed << std::setprecision(2)
              << std::setw(10) << price
              << std::setw(8) << quantity
              << std::setw(12) << GetTotalPrice() << "\n";
}
