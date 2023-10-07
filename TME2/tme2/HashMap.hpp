#include <iostream>
#include <vector>
#include <forward_list>
#include <functional>

template <typename K, typename V>
class HashTable
{
private:
    struct Entry
    {
        const K key;
        V value;
        Entry(const K &k, const V &v) : key(k), value(v) {}
    };

    std::vector<std::forward_list<Entry>> buckets;

public:
    HashTable(size_t bucketSize) : buckets(bucketSize) {}

    V *get(const K &key)
    {
        size_t hash = std::hash<K>()(key);
        size_t index = hash % buckets.size();

        for (auto &entry : buckets[index])
        {
            if (entry.key == key)
            {
                return &entry.value;
            }
        }
        return nullptr;
    }

    bool put(const K &key, const V &value)
    {
        size_t hash = std::hash<K>()(key);
        size_t index = hash % buckets.size();

        for (auto &entry : buckets[index])
        {
            if (entry.key == key)
            {
                entry.value = value;
                return true; // Key already exists, value updated
            }
        }
        buckets[index].emplace_front(key, value);
        return false; // New key-value pair inserted
    }

    size_t size() const
    {
        size_t count = 0;
        for (const auto &bucket : buckets)
        {
            count += std::distance(bucket.begin(), bucket.end());
        }
        return count;
    }
};
