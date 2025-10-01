#include "../includes/Catalog.h"
#include <cstring>

Catalog::Catalog() = default;

Catalog::~Catalog() {
    cards_.clear();
}

Catalog::Catalog(const Catalog& other) {
    for (const auto& card : other.cards_) {
        if (card) {
            cards_.push_back(std::make_unique<LibraryCard>(*card));
        }
    }
}

Catalog& Catalog::operator=(const Catalog& other) {
    if (this != &other) {
        cards_.clear();
        for (const auto& card : other.cards_) {
            if (card) {
                cards_.push_back(std::make_unique<LibraryCard>(*card));
            }
        }
    }
    return *this;
}

void Catalog::addCard(LibraryCard* card) {
    if (card != nullptr) {
        cards_.push_back(std::make_unique<LibraryCard>(*card));
        delete card;
    }
}

int Catalog::getCardCount() const {
    return cards_.size();
}

LibraryCard* Catalog::getCard(int index) const {
    if (index >= 0 && index < cards_.size()) {
        return cards_[index].get();
    }
    return nullptr;
}


