#include "Article.h"

using namespace std;

Article::Article(const string& t, const string& a) : title(t), author(a) {}

string Article::getTitle() const { return title; }

string Article::getAuthor() const { return author; }