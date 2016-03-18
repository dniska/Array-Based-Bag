#ifndef _ARRAY_BAG
#define _ARRAY_BAG

#include "BagInterface.h"

/** @class ArrayBag ArrayBag.h "ArrayBag.h"
 *
 *  Specification of an array-based ADT bag. */
template <typename ItemType>
class ArrayBag : public BagInterface<ItemType> {
 private:
  /** Maximum capacity of this bag. */
  static const int DEFAULT_CAPACITY = 6;
  static const int MAX_CAPACITY = DEFAULT_CAPACITY;
  bool inUse[DEFAULT_CAPACITY];


  /** Number of items in this bag. */
  int itemCount;

  /** Maximum capacity of this bag. */
  int maxItems;

  /** Data storage. */
  ItemType items[DEFAULT_CAPACITY];

  /** Gets the index of target in the array 'items' in this bag.
   *
   * @param target The ItemType value to retrieve the index of.
   *
   * @return The index of the element in the array 'items' that
   *         contains 'target' or -1 if the array does not contain
   *         'target'. */
  int getIndexOf(const ItemType& target) const;

 public:
  /** Default constructor. */
  ArrayBag();

  int getCurrentSize() const;

  bool isEmpty() const;

  int add(const ItemType& newEntry);

  const ItemType remove(int i);

  void clear();

  int getFrequencyOf(const ItemType& anEntry) const;

  bool contains(const ItemType& anEntry) const;

  vector<ItemType> toVector() const;
};

#include "ArrayBag.cpp"

#endif
