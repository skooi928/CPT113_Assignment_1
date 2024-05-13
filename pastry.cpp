#include "Pastry.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;


Pastry :: Pastry(){}
Pastry :: Pastry( string name,float pricePiece,float priceWeight,int amount){
  itemName=name;
  pricePiece=pricePiece;
  priceWeight=priceWeight;
  amount=amount;
}     

string Pastry :: getName(){
  return itemName;
}
float Pastry :: getPricePiece(){
  return pricePiece;
}
float Pastry :: getPriceWeight(){
  return priceweight;
}
int Pastry :: getAmount(){
  return amount;
}

