#include "../includes/ThematicCatalog.h"

int ThematicCatalog::search(const std::string_view & code, LibraryCard** results, int maxResults) const {
    int count = 0;
    for (int i = 0; i < getCardCount() && count < maxResults; ++i) {
        LibraryCard* card = getCard(i);
        if (card != nullptr && card->getThematicCode() == code) {
            results[count++] = card;
        }
    }
    return count;
}