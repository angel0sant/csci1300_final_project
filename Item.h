#ifndef ITEM_H
#define ITEM_H
#include <string>

using namespace std;

class Item {
private:
    string item_name;
    string item_type;
    bool is_collected;
public:
    Item();
    Item(string n, string t);
    string getName();
    string getType();
    bool isCollected();
    void setCollected(bool status);
    void displayItem();
};
#endif