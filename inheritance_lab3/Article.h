#ifndef INHERITANCE_LAB3_ARTICLE_H
#define INHERITANCE_LAB3_ARTICLE_H

#include <string>

class Article {
private:
    std::string title;
    std::string author;
public:
    Article(std::string  title, std::string  author);
    [[nodiscard]] std::string getTitle() const;
    [[nodiscard]] std::string getAuthor() const;
};

#endif//INHERITANCE_LAB3_ARTICLE_H
