#ifndef PROJEKT_MONEY_H
#define PROJEKT_MONEY_H


class Money
{
    int value;
    int quantity;
public:
    Money(){
        this->value=0;
        this->quantity=0;
    }
    Money(int val,int quan=10){
        this->value=val;
        this->quantity=quan;
    }

    void setValue(int value) {
        Money::value = value;
    }

    int getValue() const {
        return value;
    }
    int getQuantity() const {
        return quantity;
    }
    void setQuantity(int quantity) {
        Money::quantity = quantity;
    }
};

#endif //PROJEKT_MONEY_H
