#ifndef HEADER_H
#define HEADER_H

void printArray(int* a, int len);
void expandArray(int*& a, int& len);
void addElement(int*& a, int& len, int element);
void contractArray(int*& a, int& len);
bool indexValid(int index, int len);
int extractElement(int*& a, int& len, int index);
void printReverseArray(int* a, int len);
void printMenu();
void swapPlaces(int* a, int len);
void withoutDublicates(int*& a, int& len);
void Sort(int*& a, int& len);

#endif
