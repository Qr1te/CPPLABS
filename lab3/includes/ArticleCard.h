#ifndef LAB3_ARTICLECARD_H
#define LAB3_ARTICLECARD_H

#include "LibraryCard.h"
#include "IndependentPublicationCard.h"


class ArticleCard : public LibraryCard {
private:
    Article article;
    IndependentPublicationCard* publication;
public:
    ArticleCard(const std::string& as, const std::string& in, const std::string& tc,
                const Article& art, IndependentPublicationCard* pub);
    const Article& getArticle() const;
    IndependentPublicationCard* getPublication() const;
};



#endif//LAB3_ARTICLECARD_H
