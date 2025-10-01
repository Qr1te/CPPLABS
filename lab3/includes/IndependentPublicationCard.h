#ifndef LAB3_INDEPENDENTPUBLICATIONCARD_H
#define LAB3_INDEPENDENTPUBLICATIONCARD_H

#include "LibraryCard.h"

class IndependentPublicationCard : public LibraryCard {
public:
    IndependentPublicationCard(const std::string& a, const std::string& t, const std::string& as, const std::string& in, const std::string& tc);
    std::string getPublisher() const;
    std::string getYear() const;
    std::string getCirculation() const;
    std::string getPages() const;
};

#endif//LAB3_INDEPENDENTPUBLICATIONCARD_H
