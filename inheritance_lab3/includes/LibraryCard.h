#ifndef INHERITANCE_LAB3_LIBRARYCARD_H
#define INHERITANCE_LAB3_LIBRARYCARD_H

#include "Article.h"
#include <string>

class LibraryCard {
private:
    std::string author;
    std::string title;
    std::string authorSign;
    std::string inventoryNumber;
    std::string thematicCode;
public:
    LibraryCard(const std::string& a, const std::string& t, const std::string& as, const std::string& in, const std::string& tc);
    std::string getAuthor() const;
    std::string getTitle() const;
    std::string getAuthorSign() const;
    std::string getInventoryNumber() const;
    std::string getThematicCode() const;
    std::string getAlphabeticalSearch() const;
    virtual ~LibraryCard() ;
};

class IndependentPublicationCard : public LibraryCard {
public:
    IndependentPublicationCard(const std::string& a, const std::string& t, const std::string& as, const std::string& in, const std::string& tc);
    std::string getPublisher() const;
    std::string getYear() const;
    std::string getCirculation() const;
    std::string getPages() const;
};

class ArticleCard : public LibraryCard {
private:
    Article article_;
    IndependentPublicationCard* publication_;
public:
    ArticleCard(const std::string& as, const std::string& in, const std::string& tc,
                const Article& art, IndependentPublicationCard* pub);
    const Article& getArticle() const;
    IndependentPublicationCard* getPublication() const;
};

class ArticleCollectionCard : public IndependentPublicationCard {
private:
    static const int MAX_ARTICLES = 100;
    ArticleCard* articleCards_[MAX_ARTICLES];
    int articleCount_ = 0;
public:
    ArticleCollectionCard(const std::string& a, const std::string& t, const std::string& as, const std::string& in, const std::string& tc);
    ArticleCollectionCard(const ArticleCollectionCard& other);
    ArticleCollectionCard& operator=(const ArticleCollectionCard& other);
    ~ArticleCollectionCard() override;
    void addArticle(const Article& art, const std::string& as, const std::string& in, const std::string& tc);
    int getArticleCount() const;
    const ArticleCard* getArticleCard(int index) const;
};

class BookCard : public IndependentPublicationCard {
private:
    Article article_;
public:
    BookCard(const std::string& as, const std::string& in, const std::string& tc,const Article& art);
    const Article& getArticle() const;
};



#endif//INHERITANCE_LAB3_LIBRARYCARD_H
