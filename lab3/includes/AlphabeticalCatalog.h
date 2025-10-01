#ifndef LAB3_ALPHABETICALCATALOG_H
#define LAB3_ALPHABETICALCATALOG_H

#include "Catalog.h"

class AlphabeticalCatalog : public Catalog {
public:
    int search(const std::string_view & query, LibraryCard** results, int maxResults) const;
};


#endif//LAB3_ALPHABETICALCATALOG_H
