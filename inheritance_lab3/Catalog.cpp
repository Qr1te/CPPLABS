#include "Catalog.h"
#include <cstring>

Catalog::Catalog(){
    memset(cards_, 0, sizeof(cards_));
}

Catalog::~Catalog() {
    for (int i = 0; i < cardCount_; ++i) {
        delete cards_[i];
    }
}

Catalog::Catalog(const Catalog& other) : cardCount_(other.cardCount_) {
    for (int i = 0; i < cardCount_; ++i) {
        if (other.cards_[i]) {
            cards_[i] = new LibraryCard(*other.cards_[i]);
        } else {
            cards_[i] = nullptr;
        }
    }
    for (int i = cardCount_; i < MAX_CARDS; ++i) {
        cards_[i] = nullptr;
    }
}

Catalog &Catalog::operator=(const Catalog& other) {
    if (this != &other) {
        for (int i = 0; i < cardCount_; ++i) {
            delete cards_[i];
        }
        cardCount_ = other.cardCount_;
        for (int i = 0; i < cardCount_; ++i) {
            if (other.cards_[i]) {
                cards_[i] = new LibraryCard(*other.cards_[i]);
            } else {
                cards_[i] = nullptr;
            }
        }
        for (int i = cardCount_; i < MAX_CARDS; ++i) {
            cards_[i] = nullptr;
        }
    }
    return *this;
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

int ThematicCatalog::search(const std::string_view & code, LibraryCard** results, int maxResults) const {
    int count = 0;
    for (int i = 0; i < cardCount_ && count < maxResults; ++i) {
        if (cards_[i] != nullptr && cards_[i]->getThematicCode() == code) {
            results[count++] = cards_[i];
        }
    }
    return count;
}

int AlphabeticalCatalog::search(const std::string_view & query, LibraryCard** results, int maxResults) const {
    int count = 0;
    for (int i = 0; i < cardCount_ && count < maxResults; ++i) {
        if (cards_[i] != nullptr && cards_[i]->getAlphabeticalSearch() == query) {
            results[count++] = cards_[i];
        }
    }
    return count;
}
