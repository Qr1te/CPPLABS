#include "../includes/LibraryCard.h"
#include <cstring>

using namespace std;

LibraryCard::LibraryCard(const string& a, const string& t, const string& as, const string& in, const string& tc)
    : author(a), title(t), authorSign(as), inventoryNumber(in), thematicCode(tc) {}

string LibraryCard::getAuthor() const { return author; }

string LibraryCard::getTitle() const { return title; }

string LibraryCard::getAuthorSign() const { return authorSign; }

string LibraryCard::getInventoryNumber() const { return inventoryNumber; }

string LibraryCard::getThematicCode() const { return thematicCode; }

string LibraryCard::getAlphabeticalSearch() const { return author + title; }

LibraryCard::~LibraryCard() = default;







