#include "LibraryCard.h"
#include <cstring>

using namespace std;

LibraryCard::LibraryCard(const string& a, const string& t, const string& as, const string& in, const string& tc)
    : author(a), title(t), authorSign(as), inventoryNumber(in), thematicCode(tc) {}

string LibraryCard::getAuthor() const { return author; }

string LibraryCard::getTitle() const { return title; }

string LibraryCard::getAuthorSign() const { return authorSign; }

string LibraryCard::getInventoryNumber() const { return inventoryNumber; }

string LibraryCard::getThematicCode() const { return thematicCode; }

string LibraryCard::getAlphabeticalSearch() const { return author + title; }

LibraryCard::~LibraryCard() = default;

IndependentPublicationCard::IndependentPublicationCard(const string& a, const string& t, const string& as, const string& in, const string& tc,
                                                       const string& p, int y, int c, int pg)
    : LibraryCard(a, t, as, in, tc), publisher(p), year(y), circulation(c), pages(pg) {}

string IndependentPublicationCard::getPublisher() const { return publisher; }

int IndependentPublicationCard::getYear() const { return year; }

int IndependentPublicationCard::getCirculation() const { return circulation; }

int IndependentPublicationCard::getPages() const { return pages; }

ArticleCard::ArticleCard(const string& as, const string& in, const string& tc,
                         const Article& art, IndependentPublicationCard* pub)
    : LibraryCard(art.getAuthor(), art.getTitle(), as, in, tc),
      article_(art), publication_(pub) {}

const Article& ArticleCard::getArticle() const { return article_; }

IndependentPublicationCard* ArticleCard::getPublication() const { return publication_; }

ArticleCollectionCard::ArticleCollectionCard(const string& a, const string& t, const string& as, const string& in, const string& tc,
                                             const string& p, int y, int c, int pg)
    : IndependentPublicationCard(a, t, as, in, tc, p, y, c, pg){
    memset(articleCards_, 0, sizeof(articleCards_));
}

ArticleCollectionCard::~ArticleCollectionCard() {
    for (int i = 0; i < articleCount_; ++i) {
        delete articleCards_[i];
    }
}

void ArticleCollectionCard::addArticle(const Article& art, const string& as, const string& in, const string& tc) {
    if (articleCount_ < MAX_ARTICLES) {
        articleCards_[articleCount_++] = new ArticleCard(as, in, tc, art, this);
    }
}

int ArticleCollectionCard::getArticleCount() const { return articleCount_; }

const ArticleCard* ArticleCollectionCard::getArticleCard(int index) const {
    if (index >= 0 && index < articleCount_) {
        return articleCards_[index];
    }
    return nullptr;
}

BookCard::BookCard(const string& as, const string& in, const string& tc,
                   const string& p, int y, int c, int pg, const Article& art)
    : IndependentPublicationCard(art.getAuthor(), art.getTitle(), as, in, tc, p, y, c, pg), article_(art) {}

const Article& BookCard::getArticle() const { return article_; }