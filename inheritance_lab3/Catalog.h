#ifndef INHERITANCE_LAB3_CATALOG_H
#define INHERITANCE_LAB3_CATALOG_H

#include "LibraryCard.h"
#include <string>

class Catalog {
protected:
    static const int MAX_CARDS = 1000;
    LibraryCard* cards_[MAX_CARDS];
    int cardCount_ = 0;
public:
    Catalog();
    ~Catalog();
    Catalog(const Catalog& other);
    Catalog& operator=(const Catalog& other);
    void addCard(LibraryCard* card);
    int getCardCount() const;
    LibraryCard* getCard(int index) const;
};

class ThematicCatalog : public Catalog {
public:
    int search(const std::string_view & code, LibraryCard** results, int maxResults) const;
};

class AlphabeticalCatalog : public Catalog {
public:
    int search(const std::string_view & query, LibraryCard** results, int maxResults) const;
};

#endif//INHERITANCE_LAB3_CATALOG_H
