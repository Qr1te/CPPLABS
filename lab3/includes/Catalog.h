#ifndef INHERITANCE_LAB3_CATALOG_H
#define INHERITANCE_LAB3_CATALOG_H

#include "LibraryCard.h"
#include <string>

class Catalog {
private:
    LibraryCard* cards_[100];
    int cardCount_ = 0;

protected:
    LibraryCard** getCards() { return cards_; }
    int getCardCountInternal() const { return cardCount_; }

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
