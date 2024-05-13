#ifndef PASTRY_H
#define PASTRY_H
#include <string>
#include <fstream>
using namespace std;

class Pastry{
    private:
        string type;
        string flavour;
        float weightperpiece;
        float priceperweight;
        float piece;
        float weight;
    public:
        // Default constructor
        Pastry();
        friend void storeInfo(fstream&, Pastry*, int);
        string getType(){return type;};
        string getFlavour(){return flavour;};
        float getWPP(){return weightperpiece;};
        float getPPP(){return (priceperweight*weightperpiece);};
        float getPPW(){return priceperweight;};
        float getPiece(){return piece;};
        float getWeight(){return weight;};
        float getPrice(){return(priceperweight*weight);};
        void setPiece(float);
        void setWeight(float);
        Pastry& operator-=(const Pastry&);
        Pastry& operator+=(const Pastry&);
        bool operator==(const Pastry&);
};

#endif