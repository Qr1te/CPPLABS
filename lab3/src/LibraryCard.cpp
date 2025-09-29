#include "../includes/LibraryCard.h"
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

IndependentPublicationCard::IndependentPublicationCard(const string& a, const string& t, const string& as, const string& in, const string& tc): LibraryCard(a, t, as, in, tc) {}

string IndependentPublicationCard::getPublisher() const { return "Publisher: Book"; }

string IndependentPublicationCard::getYear() const { return "Year: 2025"; }

string IndependentPublicationCard::getCirculation() const { return "Circulation: 12"; }

string IndependentPublicationCard::getPages() const { return "Pages: 200"; }

ArticleCard::ArticleCard(const string& as, const string& in, const string& tc,
                         const Article& art, IndependentPublicationCard* pub)
    : LibraryCard(art.getAuthor(), art.getTitle(), as, in, tc),
      article_(art), publication_(pub) {}

[[maybe_unused]] const Article& ArticleCard::getArticle() const { return article_; }

IndependentPublicationCard* ArticleCard::getPublication() const { return publication_; }

ArticleCollectionCard::ArticleCollectionCard(const string& a, const string& t, const string& as, const string& in, const string& tc)
    : IndependentPublicationCard(a, t, as, in, tc){
    memset(articleCards_, 0, sizeof(articleCards_));
}

ArticleCollectionCard::ArticleCollectionCard(const ArticleCollectionCard &other): IndependentPublicationCard(other){
    for (int i = 0; i < articleCount_; ++i) {
        articleCards_[i] = new ArticleCard(*other.articleCards_[i]);
    }
}

ArticleCollectionCard &ArticleCollectionCard:: operator=(const ArticleCollectionCard& other) {
    if (this != &other) {
        IndependentPublicationCard::operator=(other);
        for (int i = 0; i < articleCount_; ++i) {
            delete articleCards_[i];
        }
        articleCount_ = other.articleCount_;
        for (int i = 0; i < articleCount_; ++i) {
            articleCards_[i] = new ArticleCard(*other.articleCards_[i]);
        }
    }
    return *this;
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

BookCard::BookCard(const string& as, const string& in, const string& tc,const Article& art)
    : IndependentPublicationCard(art.getAuthor(), art.getTitle(), as, in, tc), article_(art) {}

const Article& BookCard::getArticle() const { return article_; }