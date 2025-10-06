#ifndef LAB5_MENU_H
#define LAB5_MENU_H

#include "Queue.h"

void clearInputBuffer();
void displayTypeMenu();
void displayQueueMenu();
template <typename T>
void processQueueMenu(Queue<T>& queue);
void menu();



#endif//LAB5_MENU_H
