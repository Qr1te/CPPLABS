#include "../includes/AlphabeticalCatalog.h"

int AlphabeticalCatalog::search(const std::string_view& query, std::span<LibraryCard*> results) const {
    int count = 0;
    const int totalCards = getCardCount();

    for (int i = 0; i < totalCards; ++i) {
        if (count >= results.size()) {
            break;
        }

        LibraryCard* card = getCard(i);
        if (card != nullptr && card->getAlphabeticalSearch() == query) {
            results[count] = card;
            ++count;
        }
    }
    return count;
}