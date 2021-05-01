#include <iostream>
#include <fstream>
#include <string>
#include "UnsortedList.h"
#include "Student.h"

using namespace std;
  
  template<class ItemType>
  UnsortedList<ItemType>::UnsortedList() {
    Max_Items = 50;
    info = new ItemType[Max_Items];
    length = 0;
  }//constructor

  template<class ItemType>
  UnsortedList<ItemType>::UnsortedList(int size) {
    Max_Items = size;
    info = new ItemType[Max_Items];
    length = 0;
  }//constructor  

  template<class ItemType>
  UnsortedList<ItemType>::~UnsortedList() {
    delete []info; //deallocate the memory
  } //destructor

  template<class ItemType>
  bool UnsortedList<ItemType>::isEmpty() const {
    if (length == 0) {
      return true;
    } //if
    return false;
  } //isEmpty

  template<class ItemType>
  bool UnsortedList<ItemType>::isFull() const {
    if (length == Max_Items) {
      return true;
    } //if
    return false;
  } //isFull

  template<class ItemType>
  int UnsortedList<ItemType>::getLength() const {
    return length;
  } //getLength

  template<class ItemType>
  ItemType UnsortedList<ItemType>::getAt(int index) const {
    if (index < 0 ||index > length) {
      throw OutOfBound();
    } //if
    return info[index];
  } //getAt

  template<class ItemType>
  void UnsortedList<ItemType>::makeEmpty() {
    delete []info;
    info = new ItemType[Max_Items];
    length = 0;
    return;
  } //makeEmpty

  template<class ItemType>
  int UnsortedList<ItemType>::findIndex(ItemType item) const{
    int index = -1;
    if (length == 0) {
      return index;
    } //if
    for (int i = 0; i < length; i++) {
      if (info[i] == item) {
	index = i;
      } //if
    } //for
    return index;
  } //findIndex

  template<class ItemType>
  void UnsortedList<ItemType>::putItem(ItemType newItem) {
    int duplicate = findIndex(newItem);
    if (duplicate != -1) {
      throw DuplicateItem();
    } //if
    if (length == Max_Items) {
      throw FullList();
    } //if
    info[length] = newItem;
    length++;
    return;
  } //putItem

  template<class ItemType>
  void UnsortedList<ItemType>::deleteItem(ItemType item) {
    int duplicate = findIndex(item);
    if (duplicate == -1 || length == 0) {
      throw ItemNotFound();
    } //if
    info[duplicate] = info[length - 1];
    info[length - 1] = info[length]; 
    length--;
    return;
  } //deleteItem
