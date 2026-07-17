#include "Item.h"
#include <iostream>

using namespace std;

Item::Item() {
    item_name = "Unknown Element";
    item_type = "None";
    is_collected = false;
}

Item::Item(string n, string t) {
    item_name = n;
    item_type = t;
    is_collected = false;
}

string Item::getName() { 
    return item_name; 
}

string Item::getType() { 
    return item_type; 
}

bool Item::isCollected() { 
    return is_collected; 
}

void Item::setCollected(bool status) { 
    is_collected = status; 
}

void Item::displayItem() {
    cout<<"- "<<item_name<<" ("<<item_type<<")"<<endl;
}