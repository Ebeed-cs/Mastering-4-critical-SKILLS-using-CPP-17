/*main.cpp*/

#include <iostream>
#include "Invoice.h"

int main() {
    std::ofstream fout("out.txt" , std::ios::app);
    if(fout.fail())
        std::cout << "fail in opening the output file" << "\n";

    Invoice inv1;
    inv1.setName("Ahmed Laptop");
    inv1.setItemNumber("1223");
    inv1.setPrice(1200);
    inv1.setQuantity(2);
    inv1.print(fout);


    Invoice inv2;
    inv2.setName("Mohamed Laptop");
    inv2.setItemNumber("1234");
    inv2.setPrice(1500);
    inv2.setQuantity(3);
    inv2.print(fout);

    return 0;
}
