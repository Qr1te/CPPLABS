#ifndef LAB3_ARTICLECOLLECTIONCARD_H
#define LAB3_ARTICLECOLLECTIONCARD_H

#include "IndependentPublicationCard.h"
#include "ArticleCard.h"
#include <string>
#include <cstring>


class ArticleCollectionCard : public IndependentPublicationCard {
private:
    static const int MAX_ARTICLES = 100;
    ArticleCard* articleCards[MAX_ARTICLES];
    int articleCount = 0;
public:
    ArticleCollectionCard(const std::string& a, const std::string& t, const std::string& as, const std::string& in, const std::string& tc);
    ArticleCollectionCard(const ArticleCollectionCard& other);
    ArticleCollectionCard& operator=(const ArticleCollectionCard& other);
    ~ArticleCollectionCard() override;
    void addArticle(const Article& art, const std::string& as, const std::string& in, const std::string& tc);
    int getArticleCount() const;
    const ArticleCard* getArticleCard(int index) const;
};



#endif//LAB3_ARTICLECOLLECTIONCARD_H
