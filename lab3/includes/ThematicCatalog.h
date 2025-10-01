#ifndef LAB3_THEMATICCATALOG_H
#define LAB3_THEMATICCATALOG_H

#include "Catalog.h"
#include <span>

class ThematicCatalog : public Catalog {
public:
    int search(const std::string_view& code, std::span<LibraryCard*> results) const;
};

#endif//LAB3_THEMATICCATALOG_H
