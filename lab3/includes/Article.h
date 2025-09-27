#ifndef INHERITANCE_LAB3_ARTICLE_H
#define INHERITANCE_LAB3_ARTICLE_H

#include <string>

class Article {
private:
    std::string title;
    std::string author;
public:
    Article(const std::string& t, const std::string& a);
    std::string getTitle() const;
    std::string getAuthor() const;
};

#endif//INHERITANCE_LAB3_ARTICLE_H
