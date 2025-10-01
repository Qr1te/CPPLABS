#ifndef LAB3_ARTICLECOLLECTIONCARD_H
#define LAB3_ARTICLECOLLECTIONCARD_H

#include "ArticleCard.h"
#include "IndependentPublicationCard.h"
#include <vector>
#include <cstring>
#include <memory>


class ArticleCollectionCard : public IndependentPublicationCard {
private:
    static const int MAX_ARTICLES = 100;
    std::vector<std::unique_ptr<ArticleCard>> articleCards;
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
