// Header for Card classes
#ifndef CARD_H
#define CARD_H

#include <iostream>
#include <iomanip>
#include <limits>
#include <string>

class TransactionInfo {
public:
    double required_money_amount;
    std::string name;
    std::string address;
    std::string id;
    std::string expire_date;
    int ccv;

    TransactionInfo();
};

class ICard {
protected:
    TransactionInfo t;

public:
    virtual ICard* clone() = 0;
    virtual bool hasEnoughBalance(double amount) const = 0;
    virtual bool deductAmount(double amount) = 0;
    virtual double getAvailableBalance() const = 0;
    virtual bool refundAmount(double amount) = 0;

    virtual void read();
    virtual TransactionInfo& getTransactionInfo();
    virtual void printCard() const;
    virtual std::string getCardType() const = 0;
    virtual std::string getCardSummary() const;
};

class DebitCard : public ICard {
private:
    double avaliable_balance;

public:
    bool refundAmount(double amount) override;
    std::string getCardType() const override;
    ICard* clone() override;
    void read() override;
    bool hasEnoughBalance(double amount) const override;
    bool deductAmount(double amount) override;
    double getAvailableBalance() const override;
    std::string getCardSummary() const override;
    void printCard() const override;
};

class CreditCard : public ICard {
private:
    double credit_limit;
    double avaliable_credit;

public:
    CreditCard();
    bool refundAmount(double amount) override;
    std::string getCardType() const override;
    bool hasEnoughBalance(double amount) const override;
    bool deductAmount(double amount) override;
    double getAvailableBalance() const override;
    std::string getCardSummary() const override;
    ICard* clone() override;
    void read() override;
    void printCard() const override;
};

#endif
