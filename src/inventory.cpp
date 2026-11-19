#include "inventory.hpp"
#include <stdexcept>



void Inventory::add_item(string code, Item* item, int quantity) {
    item_map_[code]=item;
    stock_map_[code]=quantity;
}

Item* Inventory::get_item(string code) {
    if(item_map_.contains(code)){
        return item_map_[code];
    }
    return nullptr;
}

bool Inventory::is_available(string code) {
    if(stock_map_.contains(code)){
        return stock_map_[code]>0;
    }
    return false;
}

void Inventory::reduce_stock(string code) {
    auto it=stock_map_.find(code);
    if(it==stock_map_.end()){
        throw std::out_of_range("there is no such item "+ code);
    }
    if(it->second<=0){
        throw std::out_of_range("item is out of stock "+ code);
    }
    --it->second;
}


