#ifndef INHERITANCE_LAB3_CATALOG_H
#define INHERITANCE_LAB3_CATALOG_H

#include "LibraryCard.h"
#include <string>
#include <vector>
#include <memory>

class Catalog {
private:
    std::vector<std::unique_ptr<LibraryCard>> cards_;

protected:
    std::vector<std::unique_ptr<LibraryCard>>& getCards() { return cards_; }
    const std::vector<std::unique_ptr<LibraryCard>>& getCards() const { return cards_; }
    int getCardCountInternal() const { return cards_.size(); }

public:
    Catalog();
    ~Catalog();
    Catalog(const Catalog& other);
    Catalog& operator=(const Catalog& other);
    void addCard(LibraryCard* card);
    int getCardCount() const;
    LibraryCard* getCard(int index) const;
};

#endif//INHERITANCE_LAB3_CATALOG_H
