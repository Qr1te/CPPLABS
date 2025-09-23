#include "Catalog.h"
#include <cstring>

Catalog::Catalog() : cardCount_(0) {
    memset(cards_, 0, sizeof(cards_));
}

Catalog::~Catalog() {
    for (int i = 0; i < cardCount_; ++i) {
        delete cards_[i];
    }
}

void Catalog::addCard(LibraryCard* card) {
    if (cardCount_ < MAX_CARDS && card != nullptr) {
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

int ThematicCatalog::search(const string_view & code, LibraryCard** results, int maxResults) const {
    int count = 0;
    for (int i = 0; i < cardCount_ && count < maxResults; ++i) {
        if (cards_[i] != nullptr && cards_[i]->getThematicCode() == code) {
            results[count++] = cards_[i];
        }
    }
    return count;
}

int AlphabeticalCatalog::search(const string_view & query, LibraryCard** results, int maxResults) const {
    int count = 0;
    for (int i = 0; i < cardCount_ && count < maxResults; ++i) {
        if (cards_[i] != nullptr && cards_[i]->getAlphabeticalSearch() == query) {
            results[count++] = cards_[i];
        }
    }
    return count;
}
