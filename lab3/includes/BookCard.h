#ifndef LAB3_BOOKCARD_H
#define LAB3_BOOKCARD_H

#include "IndependentPublicationCard.h"

class BookCard : public IndependentPublicationCard {
private:
    Article article_;
public:
    BookCard(const std::string& as, const std::string& in, const std::string& tc,const Article& art);
    const Article& getArticle() const;
};


#endif//LAB3_BOOKCARD_H
