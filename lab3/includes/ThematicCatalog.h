#ifndef LAB3_THEMATICCATALOG_H
#define LAB3_THEMATICCATALOG_H

#include "Catalog.h"

class ThematicCatalog : public Catalog {
public:
    int search(const std::string_view & code, LibraryCard** results, int maxResults) const;
};

#endif//LAB3_THEMATICCATALOG_H
