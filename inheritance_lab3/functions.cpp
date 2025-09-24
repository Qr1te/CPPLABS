#include <iostream>
#include <string>
#include <limits>
#include "functions.h"

using namespace std;

void clearInputBuffer() {
    cin.clear();
    cin.ignore(10000, '\n');
}

void displayMenu() {
    cout << "\nLibrary Catalog System Menu:\n";
    cout << "1. Create an Article\n";
    cout << "2. Create a BookCard\n";
    cout << "3. Create an ArticleCollectionCard and add ArticleCards\n";
    cout << "4. Add card to ThematicCatalog\n";
    cout << "5. Add card to AlphabeticalCatalog\n";
    cout << "6. Search in ThematicCatalog\n";
    cout << "7. Search in AlphabeticalCatalog\n";
    cout << "8. Exit\n";
    cout << "Enter your choice: ";
}

Article* createArticle() {
    string title;
    string author;
    cout << "Enter article title: ";
    getline(cin, title);
    cout << "Enter article author: ";
    getline(cin, author);
    return new Article(title, author);
}

BookCard* createBookCard() {
    string authorSign;
    string inventoryNumber;
    string thematicCode;
    string publisher;
    cout << "Enter author sign: ";
    clearInputBuffer();
    getline(cin, authorSign);
    cout << "Enter inventory number: ";
    getline(cin, inventoryNumber);
    cout << "Enter thematic code: ";
    getline(cin, thematicCode);
    Article* article = createArticle();
    auto book = new BookCard(authorSign, inventoryNumber, thematicCode, *article);
    delete article;
    return book;
}

ArticleCollectionCard* createArticleCollectionCard() {
    string author;
    string title;
    string authorSign;
    string inventoryNumber;
    string thematicCode;
    string publisher;
    int numArticles;
    cout << "Enter collection author: ";
    clearInputBuffer();
    getline(cin, author);
    cout << "Enter collection title: ";
    getline(cin, title);
    cout << "Enter author sign: ";
    getline(cin, authorSign);
    cout << "Enter inventory number: ";
    getline(cin, inventoryNumber);
    cout << "Enter thematic code: ";
    getline(cin, thematicCode);
    auto collection = new ArticleCollectionCard(author, title, authorSign, inventoryNumber, thematicCode);
    cout << "Enter number of articles to add: ";
    cin >> numArticles;
    for (int i = 0; i < numArticles; ++i) {
        cout << "\nArticle " << i + 1 << ":\n";
        string artAuthorSign;
        string artInventoryNumber;
        string artThematicCode;
        cout << "Enter article author sign: ";
        clearInputBuffer();
        getline(cin, artAuthorSign);
        cout << "Enter article inventory number: ";
        getline(cin, artInventoryNumber);
        cout << "Enter article thematic code: ";
        getline(cin, artThematicCode);
        Article* article = createArticle();
        collection->addArticle(*article, artAuthorSign, artInventoryNumber, artThematicCode);
        delete article;
    }
    return collection;
}

void displayCard(const LibraryCard* card) {
    if (!card) return;
    cout << "Author: " << card->getAuthor() << ", Title: " << card->getTitle()
         << ", Author Sign: " << card->getAuthorSign() << ", Inventory Number: " << card->getInventoryNumber()
         << ", Thematic Code: " << card->getThematicCode() << endl;
}

void menu(ThematicCatalog& thematicCatalog, AlphabeticalCatalog& alphabeticalCatalog) {
    int choice;
    while (true) {
        displayMenu();
        cin >> choice;
        if (choice == 8) break;

        switch (choice) {
            case 1: {
                Article* article = createArticle();
                cout << "Created Article - Author: " << article->getAuthor() << ", Title: " << article->getTitle() << endl;
                delete article;
                break;
            }
            case 2: {
                BookCard* book = createBookCard();
                cout << "Created BookCard - Author: " << book->getAuthor() << ", Title: " << book->getTitle()
                     << ", Publisher: " << book->getPublisher() << ", Year: " << book->getYear() << endl;
                delete book;
                break;
            }
            case 3: {
                ArticleCollectionCard* collection = createArticleCollectionCard();
                cout << "Created ArticleCollectionCard - Author: " << collection->getAuthor()
                     << ", Title: " << collection->getTitle() << ", Articles: " << collection->getArticleCount() << endl;
                delete collection;
                break;
            }
            case 4: {
                cout << "Creating card for ThematicCatalog (1 for BookCard, 2 for ArticleCollectionCard): ";
                int type;
                cin >> type;
                LibraryCard* card = nullptr;
                if (type == 1) {
                    card = createBookCard();
                } else if (type == 2) {
                    card = createArticleCollectionCard();
                }
                if (card) {
                    thematicCatalog.addCard(card);
                    cout << "Added card to ThematicCatalog.\n";
                }
                break;
            }
            case 5: {
                cout << "Creating card for AlphabeticalCatalog (1 for BookCard, 2 for ArticleCollectionCard): ";
                int type;
                cin >> type;
                LibraryCard* card = nullptr;
                if (type == 1) {
                    card = createBookCard();
                } else if (type == 2) {
                    card = createArticleCollectionCard();
                }
                if (card) {
                    alphabeticalCatalog.addCard(card);
                    cout << "Added card to AlphabeticalCatalog.\n";
                }
                break;
            }
            case 6: {
                string code;
                cout << "Enter thematic code to search: ";
                clearInputBuffer();
                getline(cin, code);
                LibraryCard* results[100];
                int count = thematicCatalog.search(code, results, 100);
                cout << "Found " << count << " results:\n";
                for (int i = 0; i < count; ++i) {
                    displayCard(results[i]);
                }
                break;
            }
            case 7: {
                string author;
                string title;
                cout << "Enter author: ";
                clearInputBuffer();
                getline(cin, author);
                cout << "Enter title: ";
                getline(cin, title);
                string query = author + title;
                LibraryCard* results[100];
                int count = alphabeticalCatalog.search(query, results, 100);
                cout << "Found " << count << " results:\n";
                for (int i = 0; i < count; ++i) {
                    displayCard(results[i]);
                }
                break;
            }
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}