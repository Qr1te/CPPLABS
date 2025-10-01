#include "../includes/IndependentPublicationCard.h"

using namespace std;

IndependentPublicationCard::IndependentPublicationCard(const string& a, const string& t, const string& as, const string& in, const string& tc): LibraryCard(a, t, as, in, tc) {}

string IndependentPublicationCard::getPublisher() const { return "Publisher: Book"; }

string IndependentPublicationCard::getYear() const { return "Year: 2025"; }

string IndependentPublicationCard::getCirculation() const { return "Circulation: 12"; }

string IndependentPublicationCard::getPages() const { return "Pages: 200"; }