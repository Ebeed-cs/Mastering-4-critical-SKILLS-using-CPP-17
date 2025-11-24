// Implementation for Card classes
#include "Card.h"

// -------------------- TransactionInfo --------------------
TransactionInfo::TransactionInfo() {
    required_money_amount = 0.0;
    ccv = 0;
}

// -------------------- ICard --------------------
void ICard::read() {
    std::cout << "\n=== Enter Card Information ===\n";

    std::cout << "Cardholder Name: ";
    std::getline(std::cin >> std::ws, t.name);

    std::cout << "Billing Address: ";
    std::getline(std::cin >> std::ws, t.address);

    std::cout << "Card ID / Number: ";
    std::cin >> t.id;

    std::cout << "Expiration Date (MM/YY): ";
    std::cin >> t.expire_date;

    std::cout << "CCV (3 digits): ";
    while (!(std::cin >> t.ccv) || t.ccv < 100 || t.ccv > 999) {
        std::cout << " Invalid CCV. Please enter a 3-digit number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

TransactionInfo& ICard::getTransactionInfo() {
    return t;
}

void ICard::printCard() const {
    std::cout << "    Cardholder : " << t.name << "\n";
    std::cout << "    Card Number: ****" << t.id.substr(t.id.length() - 4) << "\n";
    std::cout << "    Expiry Date: " << t.expire_date << "\n";
}

std::string ICard::getCardSummary() const {
    return getCardType() + " Card (****" +
        t.id.substr(t.id.length() - 4) + ")";
}

// -------------------- DebitCard --------------------
bool DebitCard::refundAmount(double amount) {
    avaliable_balance += amount;
    return true;
}

std::string DebitCard::getCardType() const {
    return "Debit";
}

ICard* DebitCard::clone() {
    return new DebitCard(*this);
}

void DebitCard::read() {
    ICard::read();
    std::cout << "Enter the card balance: ";
    std::cin >> avaliable_balance;
}

bool DebitCard::hasEnoughBalance(double amount) const {
    return avaliable_balance >= amount;
}

bool DebitCard::deductAmount(double amount) {
    if (hasEnoughBalance(amount)) {
        avaliable_balance -= amount;
        return true;
    }
    return false;
}

double DebitCard::getAvailableBalance() const {
    return avaliable_balance;
}

std::string DebitCard::getCardSummary() const {
    return getCardType() + " Card (****" +
        t.id.substr(t.id.length() - 4) +
        ") - Balance: $" + std::to_string((int)avaliable_balance);
}

void DebitCard::printCard() const {
    std::cout << "  [Debit Card]\n";
    ICard::printCard();
    std::cout << "    Balance    : $" << std::fixed << std::setprecision(2)
        << avaliable_balance << "\n";
}

// -------------------- CreditCard --------------------
CreditCard::CreditCard() {
    credit_limit = 0.0;
    avaliable_credit = 0.0;
}

bool CreditCard::refundAmount(double amount) {
    avaliable_credit += amount;
    if (avaliable_credit > credit_limit) {
        avaliable_credit = credit_limit;
    }
    return true;
}

std::string CreditCard::getCardType() const {
    return "Credit";
}

bool CreditCard::hasEnoughBalance(double amount) const {
    return avaliable_credit >= amount;
}

bool CreditCard::deductAmount(double amount) {
    if (hasEnoughBalance(amount)) {
        avaliable_credit -= amount;
        return true;
    }
    return false;
}

double CreditCard::getAvailableBalance() const {
    return avaliable_credit;
}

std::string CreditCard::getCardSummary() const {
    return getCardType() + " Card (****" +
        t.id.substr(t.id.length() - 4) +
        ") - Available: $" + std::to_string((int)avaliable_credit);
}

ICard* CreditCard::clone() {
    return new CreditCard(*this);
}

void CreditCard::read() {
    ICard::read();
    std::cout << "Enter the card limit: ";
    std::cin >> credit_limit;
    avaliable_credit = credit_limit;
}

void CreditCard::printCard() const {
    std::cout << "  [Credit Card]\n";
    ICard::printCard();
    std::cout << "    Credit Limit: $" << std::fixed << std::setprecision(2)
        << credit_limit << "\n";
    std::cout << "    Available   : $" << std::fixed << std::setprecision(2)
        << avaliable_credit << "\n";
}
