#ifndef TREEMAP_H
#define TREEMAP_H

#include "tree.h"

template<typename Key, typename Value>
class KeyValuePair {
    
public:
    
    const Key k;
    Value v;

    KeyValuePair<Key, Value>(const Key& K, const Value& V):k(K), v(V) {}

    KeyValuePair<Key, Value>(const Key& k):k(k) {}

    bool operator <(const KeyValuePair& rightKey){
        return (this->k < rightKey.k);
    }

    bool operator==(const KeyValuePair& rightKey){
        return (this->k == rightKey.k);
    }

    
};



template<typename Key, typename Value>
ostream & operator<< (ostream & o, const KeyValuePair<Key,Value> & kv){
    o << kv.k << "," << kv.v;
    return o;
}



template<typename Key, typename Value>
class TreeMap {
  
private:
    BinarySearchTree<KeyValuePair<Key,Value> > tree;
    
public:
    
    KeyValuePair<Key,Value> * insert(const Key & k, const Value & v) {
        return &(tree.insert(KeyValuePair<Key,Value>(k,v))->data);
    }
    
    void write(ostream & o) const {
        tree.write(o);
    }

    KeyValuePair<Key,Value> * find(const Key & k){

        auto found = tree.find((KeyValuePair<Key, Value>(k)));

        if (found){
            return &(found->data);
        }
        else {
            return nullptr;
        }

    }
    
};


// do not edit below this line

#endif
