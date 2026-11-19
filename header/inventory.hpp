#pragma once
#include <string>
#include <unordered_map>
#include <entities/item.hpp>

using std::string;
using std::unordered_map;
//class responsible for managing the stock of all items
class Inventory{
    private:
        unordered_map<string,Item*> item_map_;
        unordered_map<string, int> stock_map_;

    public:
        
        void add_item(string code,Item* item, int quantity);
        Item* get_item(string code);
        bool is_available(string code);
        void reduce_stock(string code);


};