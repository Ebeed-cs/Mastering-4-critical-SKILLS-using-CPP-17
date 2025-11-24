// Header for Payment classes

#ifndef PAYMENT_H
#define PAYMENT_H

#include <iostream>
#include "Card.h"
#include "Apis/expedia_payments_api.h"
#include <sstream>

class IPayment {
public:
    virtual void setCardInfo(TransactionInfo& t) = 0;
    virtual bool pay(double money, ICard* card) = 0;
};

class PayPalPayment : public IPayment {
private:
    PayPalCreditCard p;
    PayPalOnlinePaymentAPI a;

public:
    virtual void setCardInfo(TransactionInfo& t) override;
    bool pay(double money, ICard* card) override;
};

class StripePayment : public IPayment {
private:
    StripeUserInfo sui;
    StripeCardInfo sci;
public:
    virtual void setCardInfo(TransactionInfo& t) override;
    bool pay(double money, ICard* card) override;
};

class SquarePayment : public IPayment {
private:
    json::JSON object;
public:
    virtual void setCardInfo(TransactionInfo& t) override;
    bool pay(double money, ICard* card) override;
};

#endif
