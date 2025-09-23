#ifndef INHERITANCE_LAB3_LIBRARYCARD_H
#define INHERITANCE_LAB3_LIBRARYCARD_H

#include <string>
#include "Article.h"

using namespace std;

class LibraryCard {
protected:
    string author;
    string title;
    string authorSign;
    string inventoryNumber;
    string thematicCode;
public:
    LibraryCard(const string& a, const string& t, const string& as, const string& in, const string& tc);
    string getAuthor() const;
    string getTitle() const;
    string getAuthorSign() const;
    string getInventoryNumber() const;
    string getThematicCode() const;
    string getAlphabeticalSearch() const;
    virtual ~LibraryCard() ;
};

class IndependentPublicationCard : public LibraryCard {
protected:
    string publisher;
    int year;
    int circulation;
    int pages;
public:
    IndependentPublicationCard(const string& a, const string& t, const string& as, const string& in, const string& tc,
                               const string& p, int y, int c, int pg);
    string getPublisher() const;
    int getYear() const;
    int getCirculation() const;
    int getPages() const;
};

class ArticleCard : public LibraryCard {
private:
    Article article_;
    IndependentPublicationCard* publication_;
public:
    ArticleCard(const string& as, const string& in, const string& tc,
                const Article& art, IndependentPublicationCard* pub);
    const Article& getArticle() const;
    IndependentPublicationCard* getPublication() const;
};

class ArticleCollectionCard : public IndependentPublicationCard {
private:
    static const int MAX_ARTICLES = 100;
    ArticleCard* articleCards_[MAX_ARTICLES];
    int articleCount_;
public:
    ArticleCollectionCard(const string& a, const string& t, const string& as, const string& in, const string& tc,
                          const string& p, int y, int c, int pg);
    ~ArticleCollectionCard() final;
    void addArticle(const Article& art, const string& as, const string& in, const string& tc);
    int getArticleCount() const;
    const ArticleCard* getArticleCard(int index) const;
};

class BookCard : public IndependentPublicationCard {
private:
    Article article_;
public:
    BookCard(const string& as, const string& in, const string& tc,
             const string& p, int y, int c, int pg, const Article& art);
    const Article& getArticle() const;
};



#endif//INHERITANCE_LAB3_LIBRARYCARD_H
