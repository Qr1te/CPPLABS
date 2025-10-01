#include "../includes/ThematicCatalog.h"

int ThematicCatalog::search(const std::string_view& code, LibraryCard** results, int maxResults) const {
    int count = 0;
    const int totalCards = getCardCount();

    for (int i = 0; i < totalCards; ++i) {
        if (count >= maxResults) break;

        LibraryCard* card = getCard(i);
        if (card && card->getThematicCode() == code) {
            results[count] = card;
            ++count;
        }
    }
    return count;
}