#include "../includes/Storage.h"

#include <sstream>

template <typename T> T getInput(const char *msg){
    T value;
    std::cout << msg;

    while (true)
    {
        if (std::cin >> value)
        {
            if (std::cin.get() == '\n')
            {
                return value;
            }
            std::cin.clear();
            while (std::cin.get() != '\n' && !std::cin.eof())
                ;
            std::cout << "Error, invalid input. Please try again: ";
        }
        else
        {
            std::cin.clear();
            while (std::cin.get() != '\n' && !std::cin.eof())
                ;
            std::cout << "Error, invalid input. Please try again: ";
        }
    }
}

bool Storage::readRecord(long pos, MetalItem& item) {
    file.seekg(pos, std::ios::beg);
    std::string line;
    if (!std::getline(file, line)) {
        return false;
    }

    std::stringstream ss(line);
    std::string field;
    if (!std::getline(ss, field, '|')) return false;
    item.id = std::stoi(field);
    if (!std::getline(ss, item.name, '|')) return false;
    if (!std::getline(ss, field, '|')) return false;
    item.count = std::stoi(field);
    if (!std::getline(ss, field, '|')) return false;
    item.cost = std::stod(field);
    return true;
}


void Storage::writeRecord(long pos, const MetalItem& item) {
    std::vector<std::string> lines;
    file.seekg(0, std::ios::beg);
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    file.clear();
    std::stringstream ss;
    ss << item.id << "|" << item.name << "|" << item.count << "|" << item.cost;
    std::string newRecord = ss.str();
    if (pos == -1) {
        lines.push_back(newRecord);
    } else {

        long currentPos = 0;
        int lineNum = 0;
        file.seekg(0, std::ios::beg);
        while (currentPos < pos && std::getline(file, line)) {
            currentPos = file.tellg();
            lineNum++;
        }
        if (lineNum < lines.size()) {
            lines[lineNum] = newRecord;
        } else {
            lines.push_back(newRecord);
        }
    }

    file.close();
    file.open(fileName, std::ios::out | std::ios::trunc);
    for (const auto& l : lines) {
        file << l << "\n";
    }
    file.flush();
    file.close();
    file.open(fileName, std::ios::in | std::ios::out);
    file.close();
    file.open(fileName, std::ios::out | std::ios::trunc);
    for (const auto& l : lines) {
        file << l << "\n";
    }
    file.flush();
    file.close();
    file.open(fileName, std::ios::in | std::ios::out);
}

long Storage::findMetalItemPosition(int id) {
    file.seekg(0, std::ios::beg);
    std::string line;
    long pos = 0;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string field;

        if (std::getline(ss, field, '|'); field.empty()) {
            pos = file.tellg();
            continue;
        }
        int recordId = std::stoi(field);
        if (recordId == id) {
            return pos;
        }

        pos = file.tellg();
    }
    return -1;
}


Storage::Storage(const std::string& fname ) : fileName(fname) {
    file.open(fileName, std::ios::in | std::ios::out);
    if (!file) {
        file.open(fileName, std::ios::out);
        file.close();
        file.open(fileName, std::ios::in | std::ios::out);
    }
    if (!file) {
        std::cerr << "Error opening file!" << std::endl;
    }
}

Storage::~Storage() {
    if(file.is_open()){
        file.close();
    }
}

void Storage::addItem() {
    MetalItem item;
    item.id = getInput<int>("Enter ID of this item: ");
    item.name = getInput<std::string>("Enter name of the item: ");
    item.count = getInput<int>("Enter count of this item: ");
    item.cost = getInput<double>("Enter cost of this item: ");
    writeRecord(-1, item);
    std::cout << "Metal item added successfully." << std::endl;
}

void Storage::listItem() {
    file.seekg(0, std::ios::beg);
    MetalItem item;
    int count = 0;
    double totalValue = 0.0;

    std::cout << "List of metal items:" << std::endl;
    long pos = 0;
    while (readRecord(pos, item)) {
        std::cout << "ID: " << item.id << std::endl;
        std::cout << "Description: " << item.name << std::endl;
        std::cout << "Quantity: " << item.count << std::endl;
        std::cout << "Cost: " << item.cost << std::endl;
        std::cout << "------------------------" << std::endl;
        count++;
        totalValue += item.count * item.cost;
        pos = file.tellg();
    }

    std::cout << "Total different metal items: " << count << std::endl;
    std::cout << "Total inventory value: " << totalValue << std::endl;

    file.clear();
}

void Storage::deleteItem(int id) {
    long pos = findMetalItemPosition(id);
    std::vector<std::string> lines;
    file.seekg(0, std::ios::beg);
    std::string line;
    long currentPos = 0;
    while (std::getline(file, line)) {
        if (currentPos != pos) {
            lines.push_back(line);
        }
        currentPos = file.tellg();
    }
    file.clear();
    file.close();
    file.open(fileName, std::ios::out | std::ios::trunc);
    for (const auto& l : lines) {
        file << l << "\n";
    }
    file.flush();
    file.close();
    file.open(fileName, std::ios::in | std::ios::out);

    std::cout << "Metal item deleted successfully." << std::endl;
}

void Storage::updateItem(int id) {
    long pos = findMetalItemPosition(id);
    if (pos == -1) {
        std::cout << "Metal item not found!" << std::endl;
        return;
    }
    MetalItem item;
    readRecord(pos, item);

    std::cout << "Current description: " << item.name << ". Enter new (or press enter to keep): ";
    std::cin.ignore();
    std::string desc;
    std::getline(std::cin, desc);
    if (!desc.empty()) {
        item.name = desc;
    }

    std::cout << "Current quantity: " << item.count << ". Enter new: ";
    std::cin >> item.count;

    std::cout << "Current cost: " << item.cost << ". Enter new: ";
    std::cin >> item.cost;

    writeRecord(pos, item);
    std::cout << "Metal item updated successfully." << std::endl;

}

