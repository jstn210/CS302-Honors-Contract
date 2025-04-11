// NAME: Justin Ly
// ASSIGNMENT: Honors Contract
// PURPOSE: Source file for the array implementation of the Dictionary ADT

#include "arrayDictionary.h"

template<class KeyType, class ValueType> 
ArrayDictionary<KeyType, ValueType>::ArrayDictionary(){
    itemCount = 0;
}

template<class KeyType, class ValueType> 
ArrayDictionary<KeyType, ValueType>::ArrayDictionary(const ArrayDictionary<KeyType, ValueType>& rhs){
    itemCount = rhs.itemCount;
    for (int i = 0; i < itemCount; i++){
        Entry<KeyType, ValueType> entry = Entry<KeyType, ValueType>(rhs.entries[i].getKey(), rhs.entries[i].getValue());
        entries[i] = entry;
    }
}

template<class KeyType, class ValueType> 
bool ArrayDictionary<KeyType, ValueType>::isEmpty() const{
    return itemCount == 0;
} 

template<class KeyType, class ValueType>
int ArrayDictionary<KeyType, ValueType>::getNumberOfEntries() const{
    return itemCount;
}

// Adds in order
template<class KeyType, class ValueType>
bool ArrayDictionary<KeyType, ValueType>::add(const KeyType& newKey, const ValueType& newValue){
    bool canAdd = (itemCount < DEFAULT_CAPACITY) && (!contains(newKey));

    if (canAdd){
        int i = itemCount;
        if (itemCount != 0){
            while (i > 0 && entries[i - 1].getKey() > newKey){
                entries[i] = entries[i - 1];
                i--;
            }
        }
        entries[i] = Entry<KeyType, ValueType>(newKey, newValue);
        itemCount++;
    }
    return canAdd;
}

template<class KeyType, class ValueType>
bool ArrayDictionary<KeyType, ValueType>::remove(const KeyType& targetKey){
    bool canRemove = (itemCount > 0);

    if (canRemove){
        int i = 0;
        while (i < itemCount && !(targetKey == entries[i].getKey())){
            i++;
        }
        for (int j = i; j < itemCount - 1; j++){
            entries[j] = entries[j + 1];
        }
        itemCount--;
    }
    return canRemove;
}

template<class KeyType, class ValueType>
void ArrayDictionary<KeyType, ValueType>::clear(){
    itemCount = 0;
}

template<class KeyType, class ValueType>
bool ArrayDictionary<KeyType, ValueType>::contains(const KeyType& targetKey) const{
    for (int i = 0; i < itemCount; i++){
        KeyType temp = entries[i].getKey();
        if (temp == targetKey){
            return true;
        }
    }
    return false;
}

template<class KeyType, class ValueType>
ValueType ArrayDictionary<KeyType, ValueType>::getValue(const KeyType& targetKey) const{
    for (int i = 0; i < itemCount; i++){
        KeyType temp = entries[i].getKey();
        if (temp == targetKey){
            return entries[i].getValue();
        }
    }
    throw "value not found";
}