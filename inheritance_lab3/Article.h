#ifndef INHERITANCE_LAB3_ARTICLE_H
#define INHERITANCE_LAB3_ARTICLE_H

#include <string>

#include <string>

using namespace std;

class Article {
private:
    string title;
    string author;
public:
    Article(const string& t, const string& a);
    string getTitle() const;
    string getAuthor() const;
};

#endif//INHERITANCE_LAB3_ARTICLE_H
