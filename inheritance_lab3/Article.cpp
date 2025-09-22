#include "Article.h"

using namespace std;

Article::Article(string  title, string  author) : title(std::move(title)), author(std::move(author)) {}
string Article::getTitle() const { return title; }
string Article::getAuthor() const { return author; }