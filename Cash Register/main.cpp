//
//  main.cpp
//  Cash Register
//
//  Created by Manvir Singh on 01/05/21.
//  Copyright © 2021 Manvir Singh. All rights reserved.
//
/*
 
 Write a program that computes how much a customer has to pay after purchasing
 two items.
 The price is calculated according to the following rules:
 • Buy one get one half off promotion: the lower price item is half price.
 • If the customer is a club card member, additional 10% off.
 • Tax is added.
 
 Inputs to the program include:
 • Two items’ prices
 • Have club card or not (User enters ‘Y’ or ‘y’ for “yes”; ‘N’ or ‘n’ for “no”)
 • Tax rate (User enters the percentage as a number; for example, they enter
 8.25 if the tax rate is 8.25%)
 
 Program displays:
 • Base price - the price before the discounts and taxes
 • Price after discounts - the price after the buy one get one half off promotion
 and the member’s discount, if applicable
 • Total price – the amount of money the customer has to pay (after tax)
 printed with the precision of 2 decimal digits.
 
 Hint: In order to print a number in a specific precision, you can use the round
 function passing 2 arguments to it. Use help(round) to get a brief explanation of
 this function, and try playing with it, to better understand what it does.
 To format to two decimal places you can use the string format function with the format of 2.2f.
 For example, an execution could look like this:
 
 Enter price of the first item: 10
 Enter price of the second item: 20
 Does customer have a club card? (Y/N): y
 Enter tax rate, e.g. 5.5 for 5.5% tax: 8.25
 Base price = 30.00
 Price after discounts = 22.50
 Total price = 24.36
 
 */

#include <iostream>
#include <string>
using namespace std;

int promtionOffer(double baseafter, double price1, double price2);
int main() {
    double price1;
    double price2;
    string yesOrNo;
    double taxRate;
    double basePrice;
    double baseafter;
    double tax;
    double totalPrice;
    
    cout<<"Enter price of the first item: ";
    cin>>price1;
    
    cout<<"Enter price of the second item: ";
    cin>>price2;
    
    cout<<"Does customer have a club card? (y/n): ";
    cin>>yesOrNo;
    
    cout<<"Enter tax rate, e.g. 5.5 for 5.5% tax: ";
    cin>>taxRate;
    
    basePrice = price1 + price2;
    
    cout<<"Base price = "<<basePrice<<endl;
    baseafter= price1 + (price2 * 0.5);
    if (yesOrNo == "y" && price1 < price2) {
        baseafter = price2 + (price1 * 0.5) - (baseafter/100 * 10);
        cout<<"Price after discounts = "<<baseafter<<endl;
    }
    else
        promtionOffer(baseafter, price1, price2);
    
    tax = baseafter / 100 * taxRate;
    totalPrice = baseafter + tax;
    cout<<"Total price = "<<totalPrice<<endl;
    
    return 0;
}

int promtionOffer(double baseafter, double price1, double price2){
    
    if(price1 == price2){
        baseafter = price1 + (price2 * 0.5);
        cout<<"Price after discounts = "<<baseafter<<endl;
    }
    else if(price1 > price2) {
        baseafter = price1 + (price2 * 0.5);
        
        cout<<"Price after discounts = "<<baseafter<<endl;
    }
    else if (price1 < price2){
        baseafter = price2 + (price1 * 0.5);
        cout<<"Price after discounts = "<<baseafter<<endl;
    }
    
    
    return baseafter;
}
