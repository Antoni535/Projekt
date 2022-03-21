#ifndef PROJEKT_SHOP_H
#define PROJEKT_SHOP_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "money.h"
using namespace std;
using namespace sf;


class Shop{
    Money *money=new Money[9];
    RenderWindow window;
    RectangleShape textBackgroud1,textBackgroud2,textBackgroud3,textBackgroud4,textBackgroud5;
    Texture t500,t200,t100,t50,t20,t10,t5,t2,t1;
    RectangleShape banknot500,banknot200,banknot100,banknot50,banknot20,banknot10,moneta5,moneta2,moneta1;
    Font font;
    Text text1,text2,text3,text4,text5,text6,text7,text8,text9,text10,text11,text12,text13,text14,text15,text16;
public:
    Shop(){
        window.create(VideoMode(1800,800,60),"");
        font.loadFromFile("C:\\Users\\anton\\Desktop\\Semestr 4\\C++\\Projekt\\arial.ttf");
        fillTextBackgroud(textBackgroud1, 200, 80, Color::White, 800, 420);
        fillTextBackgroud(textBackgroud2,200,80,Color::White,800,520);
        fillTextBackgroud(textBackgroud3,1800,100,Color::Green,0,300);
        fillTextBackgroud(textBackgroud4,200,80,Color::White,800,620);
        fillTextBackgroud(textBackgroud5,500,80,Color::Red,1100,620);
        t500.loadFromFile( "C:\\Users\\anton\\Desktop\\Semestr 4\\C++\\Projekt\\images\\banknot500.jpg");
        t200.loadFromFile("C:\\Users\\anton\\Desktop\\Semestr 4\\C++\\Projekt\\images\\banknot200.jpg");
        t100.loadFromFile("C:\\Users\\anton\\Desktop\\Semestr 4\\C++\\Projekt\\images\\banknot100.jpg");
        t50.loadFromFile("C:\\Users\\anton\\Desktop\\Semestr 4\\C++\\Projekt\\images\\banknot50.jpg");
        t20.loadFromFile("C:\\Users\\anton\\Desktop\\Semestr 4\\C++\\Projekt\\images\\banknot20.jpg");
        t10.loadFromFile("C:\\Users\\anton\\Desktop\\Semestr 4\\C++\\Projekt\\images\\banknot10.jpg");
        t5.loadFromFile("C:\\Users\\anton\\Desktop\\Semestr 4\\C++\\Projekt\\images\\5zl.jpg");
        t2.loadFromFile("C:\\Users\\anton\\Desktop\\Semestr 4\\C++\\Projekt\\images\\2zl.jpg");
        t1.loadFromFile("C:\\Users\\anton\\Desktop\\Semestr 4\\C++\\Projekt\\images\\1zl.jpg");
        fillMoneyGraphic(banknot500,200,300,t500,0,0);
        fillMoneyGraphic(banknot200,200,300,t200,200,0);
        fillMoneyGraphic(banknot100,200,300,t100,400,0);
        fillMoneyGraphic(banknot50,200,300,t50,600,0);
        fillMoneyGraphic(banknot20,200,300,t20,800,0);
        fillMoneyGraphic(banknot10,200,300,t10,1000,0);
        fillMoneyGraphic(moneta5,200,200,t5,1200,50);
        fillMoneyGraphic(moneta2,200,200,t2,1400,50);
        fillMoneyGraphic(moneta1,200,200,t1,1600,50);
        fillText(text1,"",60,Color::Red,805,425);
        fillText(text2,"",60,Color::Red,805,525);
        fillText(text3,"",80,Color::Yellow,55,305);
        fillText(text4,"",80,Color::Yellow,255,305);
        fillText(text5,"",80,Color::Yellow,455,305);
        fillText(text6,"",80,Color::Yellow,655,305);
        fillText(text7,"",80,Color::Yellow,855,305);
        fillText(text8,"",80,Color::Yellow,1055,305);
        fillText(text9,"",80,Color::Yellow,1255,305);
        fillText(text10,"",80,Color::Yellow,1455,305);
        fillText(text11,"",80,Color::Yellow,1655,305);
        fillText(text12,"Podaj kwote do zaplacenia:",60,Color::Blue,55,425);
        fillText(text13,"Podaj kwote zaplacona:",60,Color::Blue,55,525);
        fillText(text14,"Reszta:",60,Color::Blue,55,625);
        fillText(text15,"",60,Color::Red,805,625);
        fillText(text16,"Nastepny klient",60,Color::Yellow,1145,625);
    }

    static void fillTextBackgroud(RectangleShape &textBackgroud, float X, float Y, Color color, float x, float y) {
        textBackgroud.setSize(Vector2f(X, Y));
        textBackgroud.setFillColor(color);
        textBackgroud.setPosition(x, y);
    }
    static void fillMoneyGraphic(RectangleShape &moneyGraphics,float X,float Y, Texture &texture,float x,float y){
        moneyGraphics.setSize(Vector2f(X,Y));
        moneyGraphics.setTexture(&texture);
        moneyGraphics.setPosition(x,y);
    }
    void fillText(Text &text, string str,int fontSize, Color color,float x, float y){
        text.setFont(font);
        text.setCharacterSize(fontSize);
        text.setFillColor(color);
        text.setString(str);
        text.setPosition(x,y);
    }
    bool change_money(int i,Money * money);
    void pay_rest(int &rest,Money *money);
    void add_money_to_cash_register(int amount_paid, Money * money);
    void run();
};
#endif //PROJEKT_SHOP_H
