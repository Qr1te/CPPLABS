#ifndef LAB3_ALPHABETICALCATALOG_H
#define LAB3_ALPHABETICALCATALOG_H

#include "Catalog.h"
#include <span>

class AlphabeticalCatalog : public Catalog {
public:
    int search(const std::string_view& query, std::span<LibraryCard*> results) const;
};


#endif//LAB3_ALPHABETICALCATALOG_H
