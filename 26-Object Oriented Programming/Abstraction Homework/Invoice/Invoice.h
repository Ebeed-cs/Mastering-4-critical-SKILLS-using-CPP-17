/*Invoice.h*/

#ifndef INVOICE_H
#define INVOICE_H

#include <fstream>
class Invoice{
    private:
        std::string name;
        std::string item_number;
        double price;
        int quantity;

    public:
        Invoice(); 

        void setName(std::string new_name);

        void setItemNumber(std::string new_item_number);

        void setPrice(double new_price);

        void setQuantity(int new_quantity);

        double GetTotalPrice()const;

        std::string toString() const;

        void print(std::ostream & out = std::cout)const;
};

#endif