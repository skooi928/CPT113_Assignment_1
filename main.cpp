#include <iostream>
#include "shop.h"
#include "user.h"
#include "inventory.h"
#include "pastry.h"
#include "cart.h"
#include "view.h"
using namespace std;

const int MAX_STREAM_SIZE = 32767;

int main(){
    Shop shop;
    shop.main();
    return 0;
}