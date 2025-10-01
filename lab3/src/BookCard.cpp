#include "../includes/BookCard.h"

using namespace std;

BookCard::BookCard(const string& as, const string& in, const string& tc,const Article& art)
    : IndependentPublicationCard(art.getAuthor(), art.getTitle(), as, in, tc), article_(art) {}

const Article& BookCard::getArticle() const { return article_; }