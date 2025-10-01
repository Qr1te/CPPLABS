#ifndef INHERITANCE_LAB3_LIBRARYCARD_H
#define INHERITANCE_LAB3_LIBRARYCARD_H

#include "Article.h"
#include <string>

class LibraryCard {
private:
    std::string author;
    std::string title;
    std::string authorSign;
    std::string inventoryNumber;
    std::string thematicCode;
public:
    LibraryCard(const std::string& a, const std::string& t, const std::string& as, const std::string& in, const std::string& tc);
    std::string getAuthor() const;
    std::string getTitle() const;
    std::string getAuthorSign() const;
    std::string getInventoryNumber() const;
    std::string getThematicCode() const;
    std::string getAlphabeticalSearch() const;
    virtual ~LibraryCard() ;
};







#endif//INHERITANCE_LAB3_LIBRARYCARD_H
