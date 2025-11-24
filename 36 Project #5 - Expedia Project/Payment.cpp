// Implementation for Payment classes

#include "Payment.h"
#include "json.hpp"
using namespace std;

// ================== PayPalPayment ==================

void PayPalPayment::setCardInfo(TransactionInfo& t) {
    p.name = t.name;
    p.address = t.address;
    p.id = t.id;
    p.expiry_date = t.expire_date;
    p.ccv = t.ccv;
    a.SetCardInfo(&p);
}

bool PayPalPayment::pay(double money, ICard* card) {
    if (!card->hasEnoughBalance(money)) {
        cout << "\n Payment Failed: Insufficient funds!\n";
        cout << "Required: $" << money << "\n";
        cout << "Available: $" << card->getAvailableBalance() << "\n";
        return false;
    }

    bool apiSuccess = a.MakePayment(money);

    if (apiSuccess) {
        if (card->deductAmount(money)) {
            cout << "\n Payment Successful via PayPal!\n";
            cout << "Amount charged: $" << money << "\n";
            cout << "Remaining balance: $" << card->getAvailableBalance() << "\n";
            return true;
        }
    }

    cout << "\n Payment processing failed!\n";
    return false;
}

// ================== StripePayment ==================

void StripePayment::setCardInfo(TransactionInfo& t) {
    sui.name = t.name;
    sui.address = t.address;
    sci.id = t.id;
    sci.expiry_date = t.expire_date;
}

bool StripePayment::pay(double money, ICard* card) {
    if (!card->hasEnoughBalance(money)) {
        cout << "\n Payment Failed: Insufficient funds!\n";
        cout << "Required: $" << money << "\n";
        cout << "Available: $" << card->getAvailableBalance() << "\n";
        return false;
    }

    bool apiSuccess = StripePaymentAPI::WithDrawMoney(sui, sci, money);

    if (apiSuccess) {
        if (card->deductAmount(money)) {
            cout << "\n Payment Successful via Stripe!\n";
            cout << "Amount charged: $" << money << "\n";
            cout << "Remaining balance: $" << card->getAvailableBalance() << "\n";
            return true;
        }
    }

    cout << "\n Payment processing failed!\n";
    return false;
}

// ================== SquarePayment ==================

void SquarePayment::setCardInfo(TransactionInfo& t) {
    json::JSON cardInfo;

    cardInfo["CCV"] = t.ccv;
    cardInfo["DATE"] = t.expire_date;
    cardInfo["ID"] = t.id;
    object["card_info"] = cardInfo;

    json::JSON userInfo = json::Array();
    userInfo.append(t.name);
    userInfo.append(t.address);
    object["user_info"] = userInfo;
}

bool SquarePayment::pay(double money, ICard* card) {
    if (!card->hasEnoughBalance(money)) {
        cout << "\n Payment Failed: Insufficient funds!\n";
        cout << "Required: $" << money << "\n";
        cout << "Available: $" << card->getAvailableBalance() << "\n";
        return false;
    }

    object["money"] = money;
    ostringstream oss;
    oss << object;
    string json_query = oss.str();

    bool apiSuccess = SquarePaymentAPI::WithDrawMoney(json_query);

    if (apiSuccess) {
        if (card->deductAmount(money)) {
            cout << "\n Payment Successful via Square!\n";
            cout << "Amount charged: $" << money << "\n";
            cout << "Remaining balance: $" << card->getAvailableBalance() << "\n";
            return true;
        }
    }

    cout << "\n Payment processing failed!\n";
    return false;
}
