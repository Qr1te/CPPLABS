#include "Catalog.h"

using namespace std;

Catalog::Catalog() : cardCount_(0) {
    for (int i = 0; i < MAX_CARDS; ++i) {
        cards_[i] = nullptr;
    }
}

void Catalog::addCard(LibraryCard* card) {
    if (cardCount_ < MAX_CARDS) {
        cards_[cardCount_++] = card;
    }
}

int Catalog::getCardCount() const { return cardCount_; }

LibraryCard* Catalog::getCard(int index) const {
    if (index >= 0 && index < cardCount_) {
        return cards_[index];
    }
    return nullptr;
}

int ThematicCatalog::search(const string& code, LibraryCard** results, int maxResults) const {
    int count = 0;
    for (int i = 0; i < cardCount_ && count < maxResults; ++i) {
        if (cards_[i]->getThematicCode() == code) {
            results[count++] = cards_[i];
        }
    }
    return count;
}

int AlphabeticalCatalog::search(const string& query, LibraryCard** results, int maxResults) const {
    int count = 0;
    for (int i = 0; i < cardCount_ && count < maxResults; ++i) {
        if (cards_[i]->getAlphabeticalSearch() == query) {
            results[count++] = cards_[i];
        }
    }
    return count;
}

Catalog::~Catalog() {
    for (int i = 0; i < cardCount_; ++i) {
        delete cards_[i];
    }
}
