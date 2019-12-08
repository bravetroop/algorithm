/*
 * lru.cpp
 *
 *  Created on: Dec 8, 2019
 *      Author: shijie
 */

#include <map>

using namespace std;

struct cacheNode {
    int key;
    int val;
    struct cacheNode* preNode;
    struct cacheNode* nextNode;
};

class LRUCache {
public:
    LRUCache(int capacity) {
        cache = new map<int, cacheNode*>;
        this->capacity = capacity;
        head = new cacheNode;
        tail = new cacheNode;

        head->preNode = 0;
        head->nextNode = 0;

        tail->preNode = 0;
        tail->nextNode = 0;
    }

    ~LRUCache() {
        for(auto it = cache->begin(); it != cache->end(); ++it) {
            delete it->second;
        }
        delete cache;
        delete head;
        delete tail;
    }

    cacheNode* getNode(int key) {
    	cacheNode* node = 0;
		auto it = cache->find(key);
		if (it != cache->end()) {
			node = it->second;

			node->preNode->nextNode = node->nextNode;
			node->nextNode->preNode = node->preNode;

			tail->preNode->nextNode = node;
			node->preNode = tail->preNode;

			tail->preNode = node;
			node->nextNode = tail;
		}
		return node;
    }

    int get(int key) {
    	cacheNode* node = getNode(key);
    	if(node) {
    		return node->val;
    	}
    	return -1;
    }

    void put(int key, int value) {
    	cacheNode* node = getNode(key);
        if(0 == node) {
            if(cache->size() >= capacity) {
                node = head->nextNode;
                node->preNode->nextNode = node->nextNode;
                node->nextNode->preNode = node->preNode;

                auto it_del = cache->find(node->key);
                if(it_del != cache->end()) {
					cache->erase(it_del);
                }
                delete node;
            }

            node = new cacheNode();
            node->key = key;
            node->val = value;
            cache->insert(make_pair(key, node));

            if(head->nextNode == 0) {
                head->nextNode = node;
                node->preNode = head;

                tail->preNode = node;
                node->nextNode = tail;
            } else {
                tail->preNode->nextNode = node;
                node->preNode = tail->preNode;

                tail->preNode = node;
                node->nextNode = tail;
            }
        } else {
        	node->val = value;
        }
    }

private:
    int capacity;
    map<int, cacheNode*> *cache;
    cacheNode* head;
    cacheNode* tail;
};

int main() {
	LRUCache cache(1);
	cache.put(2, 1);
	cache.get(2);

	cache.put(3, 2);
	cache.get(2);
	cache.get(3);
	return 0;
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */


