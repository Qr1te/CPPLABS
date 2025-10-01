#include "../includes/ArticleCollectionCard.h"
#include <memory>

using namespace std;

ArticleCollectionCard::ArticleCollectionCard(const string& a, const string& t, const string& as, const string& in, const string& tc)
    : IndependentPublicationCard(a, t, as, in, tc) {
}

ArticleCollectionCard::ArticleCollectionCard(const ArticleCollectionCard &other): IndependentPublicationCard(other) {
    for (const auto& card : other.articleCards) {
        articleCards.push_back(make_unique<ArticleCard>(*card));
    }
}

ArticleCollectionCard &ArticleCollectionCard::operator=(const ArticleCollectionCard& other) {
    if (this != &other) {
        IndependentPublicationCard::operator=(other);
        articleCards.clear();
        for (const auto& card : other.articleCards) {
            articleCards.push_back(make_unique<ArticleCard>(*card));
        }
    }
    return *this;
}

ArticleCollectionCard::~ArticleCollectionCard() = default;  // деструктор не нужен!

void ArticleCollectionCard::addArticle(const Article& art, const string& as, const string& in, const string& tc) {
    if (articleCards.size() < MAX_ARTICLES) {
        articleCards.push_back(make_unique<ArticleCard>(as, in, tc, art, this));
    }
}

int ArticleCollectionCard::getArticleCount() const {
    return articleCards.size();
}

const ArticleCard* ArticleCollectionCard::getArticleCard(int index) const {
    if (index >= 0 && index < articleCards.size()) {
        return articleCards[index].get();
    }
    return nullptr;
}