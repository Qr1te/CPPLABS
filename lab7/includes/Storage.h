#ifndef LAB7_STORAGE_H
#define LAB7_STORAGE_H

#include <iostream>
#include <fstream>
#include <vector>
#include "MetalItem.h"

class Storage {
private:
    std::fstream file;
    std::string fileName;

    long findMetalItemPosition(int id);
    bool readRecord(long pos, MetalItem& item);
    void writeRecord(long pos, const MetalItem& item);
public:
    explicit Storage(const std::string& fname = "storage.txt");
    ~Storage();
    void addItem();
    void deleteItem(int id);
    void listItem();
    void updateItem(int id);
};


#endif//LAB7_STORAGE_H
