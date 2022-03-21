#include "shop.h"
bool Shop::change_money(int i,Money * money){
    int j=i-1;
    while(j>=0){
        if(money[j].getQuantity()>0){
            money[j].setQuantity(money[j].getQuantity()-1);
            if(i%3==1 && j==i-1){
                money[i].setQuantity(money[i].getQuantity()+2);
                money[i+1].setQuantity(money[i+1].getQuantity()+1);
            }
            else{
                int v=(int)(money[j].getValue()/money[i].getValue());
                money[i].setQuantity(money[i].getQuantity()+v);
            }
            return true;
        }
        else{
            j--;
        }
    }
    return false;
}

void Shop::pay_rest(int &rest,Money *money){
    int i=0;
    while(rest>0){
        if(money[i].getValue()<=rest){
            if(money[i].getQuantity()==0){
                if(change_money(i,money)){
                    rest-=money[i].getValue();
                    money[i].setQuantity(money[i].getQuantity()-1);
                }
            }
            else{
                rest-=money[i].getValue();
                money[i].setQuantity(money[i].getQuantity()-1);
            }
        }
        else{
            i++;
        }
    }
}

void Shop::add_money_to_cash_register(int amount_paid, Money * money){
    int i=0;
    while(amount_paid>0){
        if(money[i].getValue()<=amount_paid){
            money[i].setQuantity(money[i].getQuantity()+1);
            amount_paid-=money[i].getValue();
        }
        else{
            i++;
        }
    }
}
void Shop::run(){
    string str1;
    string str2;
    Event event;
    int tmp=0;
    int to_be_paid,paid,rest;
    int val[9]={500,200,100,50,20,10,5,2,1};
    for (int i=0;i<9;i++){
        money[i].setValue(val[i]);
        money[i].setQuantity(10);
    }
    while (window.isOpen())
    {
        window.clear();
        while(window.pollEvent(event))
        {
            if(event.type==Event::Closed)
                window.close();
            if(Mouse::isButtonPressed(Mouse::Left)) {
                Vector2i globalPosition = Mouse::getPosition(window);
                if (globalPosition.x >= 800 && globalPosition.x <= 1000) {
                    if (globalPosition.y >= 420 && globalPosition.y <= 500) {
                        str1 = "";
                        window.draw(text1);
                        tmp = 1;
                    } else if (globalPosition.y >= 520 && globalPosition.y <= 600) {
                        str2 = "";
                        window.draw(text2);
                        tmp = 2;
                    }
                }
                else if(globalPosition.x >= 1100 && globalPosition.x <= 1600){
                    if (globalPosition.y >= 620 && globalPosition.y <= 700){
                        text1.setString("");
                        text2.setString("");
                        tmp=0;
                    }
                }
            }
            if(tmp==1){
                if (event.type == sf::Event::TextEntered)
                {
                    if (event.text.unicode< 128)
                    {
                        str1 += static_cast<char>(event.text.unicode);
                        if(str1[str1.length()-1]==8){
                            str1.pop_back();
                            str1.pop_back();
                            text1.setString(str1);
                            window.draw(text1);
                        }
                        text1.setString(str1);
                        window.draw(text1);
                        if(str1[str1.length()-1]==13) {
                            text1.setString(str1);
                            to_be_paid = stoi(str1);
                            str1="";
                        }
                    }
                }
            }
            if(tmp==2){
                if (event.type == sf::Event::TextEntered)
                {
                    if (event.text.unicode< 128)
                    {
                        str2 += static_cast<char>(event.text.unicode);
                        text2.setString(str2);
                        window.draw(text2);
                        if(str2[str2.length()-1]==8){
                            str2.pop_back();
                            str2.pop_back();
                            text2.setString(str2);
                            window.draw(text2);
                        }
                        if(str2[str2.length()-1]==13) {
                            text2.setString(str2);
                            paid = stoi(str2);
                            add_money_to_cash_register(paid, money);
                            str2="";
                            rest= paid - to_be_paid;
                            tmp=3;
                        }
                    }
                }
            }
        }
        if(tmp==3){
            text15.setString(to_string(rest));
            pay_rest(rest,money);
            tmp=4;
        }
        if(tmp==4){
            window.draw(textBackgroud5);
            window.draw(text16);
            window.draw(textBackgroud4);
            window.draw(text14);
            window.draw(text15);
        }
        text3.setString(to_string(money[0].getQuantity()));
        text4.setString(to_string(money[1].getQuantity()));
        text5.setString(to_string(money[2].getQuantity()));
        text6.setString(to_string(money[3].getQuantity()));
        text7.setString(to_string(money[4].getQuantity()));
        text8.setString(to_string(money[5].getQuantity()));
        text9.setString(to_string(money[6].getQuantity()));
        text10.setString(to_string(money[7].getQuantity()));
        text11.setString(to_string(money[8].getQuantity()));
        window.draw(textBackgroud1);
        window.draw(textBackgroud2);
        window.draw(textBackgroud3);
        window.draw(text1);
        window.draw(text2);
        window.draw(text3);
        window.draw(text4);
        window.draw(text5);
        window.draw(text6);
        window.draw(text7);
        window.draw(text8);
        window.draw(text9);
        window.draw(text10);
        window.draw(text11);
        window.draw(text12);
        window.draw(text13);
        window.draw(banknot500);
        window.draw(banknot200);
        window.draw(banknot100);
        window.draw(banknot50);
        window.draw(banknot20);
        window.draw(banknot10);
        window.draw(moneta5);
        window.draw(moneta2);
        window.draw(moneta1);
        window.display();
    }
}