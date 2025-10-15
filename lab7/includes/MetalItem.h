#ifndef LAB7_METALITEM_H
#define LAB7_METALITEM_H

#include <iostream>

struct MetalItem{
    int id;
    std::string name;
    double cost;
    int count;
    MetalItem(): id(0), name(" "), cost(0),count(0){};
};

#endif//LAB7_METALITEM_H
