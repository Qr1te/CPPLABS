#include "../includes/ArticleCollectionCard.h"

using namespace std;

ArticleCollectionCard::ArticleCollectionCard(const string& a, const string& t, const string& as, const string& in, const string& tc)
    : IndependentPublicationCard(a, t, as, in, tc){
    memset(articleCards, 0, sizeof(articleCards));
}

ArticleCollectionCard::ArticleCollectionCard(const ArticleCollectionCard &other): IndependentPublicationCard(other){
    for (int i = 0; i < articleCount; ++i) {
        articleCards[i] = new ArticleCard(*other.articleCards[i]);
    }
}

ArticleCollectionCard &ArticleCollectionCard:: operator=(const ArticleCollectionCard& other) {
    if (this != &other) {
        IndependentPublicationCard::operator=(other);
        for (int i = 0; i < articleCount; ++i) {
            delete articleCards[i];
        }
        articleCount = other.articleCount;
        for (int i = 0; i < articleCount; ++i) {
            articleCards[i] = new ArticleCard(*other.articleCards[i]);
        }
    }
    return *this;
}

ArticleCollectionCard::~ArticleCollectionCard() {
    for (int i = 0; i < articleCount; ++i) {
        delete articleCards[i];
    }
}

void ArticleCollectionCard::addArticle(const Article& art, const string& as, const string& in, const string& tc) {
    if (articleCount < MAX_ARTICLES) {
        articleCards[articleCount++] = new ArticleCard(as, in, tc, art, this);
    }
}

int ArticleCollectionCard::getArticleCount() const { return articleCount; }

const ArticleCard* ArticleCollectionCard::getArticleCard(int index) const {
    if (index >= 0 && index < articleCount) {
        return articleCards[index];
    }
    return nullptr;
}