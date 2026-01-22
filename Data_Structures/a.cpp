#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <bits/stdc++.h>

using namespace std;

template <class K, class V>
class HashMap {
private:
    vector<list<pair<K, V>>> map;
    size_t capacity;
    size_t size;

    static constexpr size_t DEFAULT_CAPACITY = 8;
	static constexpr double RESIZE_FACTOR = 0.75;

	static constexpr size_t MAX_SIZE_T = -1;

    static std::hash<K> hashFunc;

    size_t hash(const K& key, size_t customCap) const {
        return hashFunc(key) % customCap;
    }

    size_t hash(const K& key) const {
        return hashFunc(key) % capacity;
    }

	void resize() {
		if (capacity > MAX_SIZE_T / 2) {
			return;
		}

        size_t newCap = capacity * 2;
        vector<list<pair<K, V>>> newMap(newCap);
        for (auto& bucket : map) {
            for (auto& _pair : bucket) {
                auto& newBucket = newMap[hash(_pair.first, newCap)];
                newBucket.push_back(std::move(_pair));
            }
        }
        
        map = std::move(newMap);
        capacity = newCap;
	}

public:

    HashMap(int capacity = DEFAULT_CAPACITY) : capacity(capacity), size(0), map(capacity) {}

    const V& get(const K& key) const {
        auto& bucket = map[hash(key)];
        for (auto& _pair : bucket) {
            if (_pair.first == key) {
                return _pair.second;
            }
        }
        throw out_of_range("The key has not been found");
    }

    void put(const K& key, const V& value) {
        if (size > RESIZE_FACTOR * capacity) {
            resize();
        }
        auto& bucket = map[hash(key)];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (key == it->first) {
                it->second = value;
                return;
            }
        }
        ++size;
        bucket.emplace_back(key, value);
    }

	size_t getSize() const {
		return size;
	}

	bool contains(const K& key) const {
		auto& bucket = map[hash(key)];
        for (auto& _pair : bucket) {
            if (_pair.first == key) {
                return true;
            }
        }
		return false;
	}
	
	void remove(const K& key) {
        auto& bucket = map[hash(key)];
		for (auto it = bucket.begin(); it != bucket.end(); ++it) {
			if (key == it->first) {
				bucket.erase(it);
				--size;
				return;
			}
		}
    }
};
template<typename K, typename V>
std::hash<K> HashMap<K, V>::hashFunc;
