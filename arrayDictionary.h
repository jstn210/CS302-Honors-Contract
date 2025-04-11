// NAME: Justin Ly
// ASSIGNMENT: Honors Contract
// PURPOSE: Header file for the array implementation of the Dictionary ADT

#ifndef ARRAYDICTIONARY_H
#define ARRAYDICTIONARY_H

#include "dictionary.h"
#include "entry.h"
#include <iostream>
using namespace std;

template<class KeyType, class ValueType> 
class ArrayDictionary : public DictionaryInterface<KeyType, ValueType>{
    private:
        static const int DEFAULT_CAPACITY = 100;
        Entry<KeyType, ValueType> entries[DEFAULT_CAPACITY];
        int itemCount;

    public:
        ArrayDictionary();
        ArrayDictionary(const ArrayDictionary& rhs);
        bool isEmpty() const override; 
        int getNumberOfEntries() const override;
        bool add(const KeyType& newKey, const ValueType& newValue) override; 
        bool remove(const KeyType& targetKey) override; 
        void clear() override; 
        bool contains(const KeyType& targetKey) const override;
        ValueType getValue(const KeyType& targetKey) const override;
        
        friend ostream& operator <<(ostream& cout, const ArrayDictionary<KeyType, ValueType>& rhs){
            cout << "CONTACTS" << endl;
            for (int i = 0; i < rhs.itemCount; i++){
                cout << "Name: " << rhs.entries[i].getKey() << "    Phone #: " << rhs.entries[i].getValue() << endl;
            }
            cout << endl;
            return cout;
        }
};
#include "arrayDictionary.cpp"
#endif