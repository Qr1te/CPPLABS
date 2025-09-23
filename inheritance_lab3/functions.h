#ifndef INHERITANCE_LAB3_FUNCTIONS_H
#define INHERITANCE_LAB3_FUNCTIONS_H

#include "Article.h"
#include "LibraryCard.h"
#include "Catalog.h"

void clearInputBuffer();
void displayMenu();
Article* createArticle();
BookCard* createBookCard();
ArticleCollectionCard* createArticleCollectionCard();
void displayCard(const LibraryCard* card);
void menu(ThematicCatalog& thematicCatalog, AlphabeticalCatalog& alphabeticalCatalog);

#endif//INHERITANCE_LAB3_FUNCTIONS_H
