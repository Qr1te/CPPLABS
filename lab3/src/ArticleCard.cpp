#include "../includes/ArticleCard.h"

using namespace std;

ArticleCard::ArticleCard(const string& as, const string& in, const string& tc,
                         const Article& art, IndependentPublicationCard* pub)
    : LibraryCard(art.getAuthor(), art.getTitle(), as, in, tc),
      article(art), publication(pub) {}

[[maybe_unused]] const Article& ArticleCard::getArticle() const { return article; }

IndependentPublicationCard* ArticleCard::getPublication() const { return publication; }

