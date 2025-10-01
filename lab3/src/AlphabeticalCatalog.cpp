#include "../includes/AlphabeticalCatalog.h"

int AlphabeticalCatalog::search(const std::string_view & query, LibraryCard** results, int maxResults) const {
    int count = 0;
    for (int i = 0; i < getCardCount() && count < maxResults; ++i) {
        LibraryCard* card = getCard(i);
        if (card != nullptr && card->getAlphabeticalSearch() == query) {
            results[count++] = card;
        }
    }
    return count;
}