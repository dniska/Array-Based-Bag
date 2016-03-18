template <typename ItemType>
ArrayBag<ItemType>::ArrayBag()
  : itemCount(0),
    maxItems(DEFAULT_CAPACITY) {
    }

template <typename ItemType>
int ArrayBag<ItemType>::getCurrentSize() const {

  return itemCount;
}

template <typename ItemType>
bool ArrayBag<ItemType>::isEmpty() const {

  return itemCount == 0;
}

template <typename ItemType>
int ArrayBag<ItemType>::add(const ItemType& newEntry) {

  int i = 0;
  bool found = false;
  
  for(i = 0; (i<DEFAULT_CAPACITY)&&(found==false); i++) {
    if(inUse[i] == false) {
        items[i] = newEntry;
        cout << "Added " << newEntry << " at array index " << i << "\n\n";
        inUse[i] = true;
	++itemCount;   
        found = true;
    }
  }
  if(i<DEFAULT_CAPACITY)
    return i+1;
  else
    return 0;
}

template <typename ItemType>
const ItemType ArrayBag<ItemType>::remove(int i){

  ItemType temp;
  i = i-1;
  if(i<0)
    return NULL;

  if(i<itemCount)
    {
      ItemType temp = items[i];
      items[i] = items[itemCount - 1];
      inUse[itemCount] = false;
    }
  else
    {
    return NULL;
    }
  return temp;
} 

template <typename ItemType>
void ArrayBag<ItemType>::clear() {

  itemCount = 0;
}

template <typename ItemType>
bool ArrayBag<ItemType>::contains(const ItemType& anEntry) const {

  bool found = false;
  int curIndex = 0;

  while (!found && curIndex < itemCount) {
    if (anEntry == items[curIndex]) {
      found = true;
    }
    ++curIndex;
  }

  return found;
}

template <typename ItemType>
int ArrayBag<ItemType>::getFrequencyOf(const ItemType& anEntry) const {

  int frequency = 0;
  int curIndex = 0;
  
  cout << "\nItem count is " 
       << itemCount
       << " at frequency test\n";  

  while (curIndex < itemCount) {
    if (items[curIndex] == anEntry) {
      ++frequency;
    }
    ++curIndex;
  }

  return frequency;
}

template <typename ItemType>
vector<ItemType> ArrayBag<ItemType>::toVector() const {

  vector<ItemType> bagContents;

  for (int i = 0; i < itemCount; ++i) {
    bagContents.push_back(items[i]);
  }

  return bagContents;
}

template <typename ItemType>
int ArrayBag<ItemType>::getIndexOf(const ItemType& target) const {

  bool found = false;
  int result = -1;
  int searchIndex = 0;

  while (!found && searchIndex < itemCount) {
    if (items[searchIndex] == target) {
      found = true;
      result = searchIndex;
    }
    else {
      ++searchIndex;
    }
  }

  return result;
}
